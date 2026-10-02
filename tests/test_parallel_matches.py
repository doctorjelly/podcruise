from __future__ import annotations

import tempfile
import threading
import time
import unittest
from pathlib import Path
from unittest.mock import patch

from tools.verify_c_matches import verify_profile


class ParallelMatchTests(unittest.TestCase):
    def _fixture(self, root: Path):
        source_root = root / "src"
        source_root.mkdir(parents=True)
        compiler = root / "toolchain" / "ido-5.3" / "cc"
        compiler.parent.mkdir(parents=True)
        compiler.write_text("fake compiler", encoding="utf-8")
        units = []
        for unit_id in ("slow", "broken", "fast"):
            (source_root / f"{unit_id}.c").write_text("/* fixture */", encoding="utf-8")
            units.append(
                {
                    "id": unit_id,
                    "source": f"src/{unit_id}.c",
                    "link_vram": "0x80001000",
                    "absolute_symbols": {},
                    "functions": [
                        {
                            "name": f"func_{unit_id}",
                            "vram": "0x80001000",
                            "rom": "0x0",
                            "size": 4,
                        }
                    ],
                }
            )
        return compiler, units

    def _run_profile(self, temp_root: Path, jobs: int):
        compiler, units = self._fixture(temp_root)
        state = {"active": 0, "max_active": 0}
        lock = threading.Lock()

        def fake_run(command, root, env=None):
            unit_id = next((name for name in ("slow", "broken", "fast") if name in str(command)), None)
            if "-c" in command:
                with lock:
                    state["active"] += 1
                    state["max_active"] = max(state["max_active"], state["active"])
                try:
                    time.sleep(0.04 if unit_id == "slow" else 0.01)
                    if unit_id == "broken":
                        raise RuntimeError("compile failed")
                    Path(command[command.index("-o") + 1]).write_bytes(b"object")
                finally:
                    with lock:
                        state["active"] -= 1
                return ""
            if "-O" in command and "binary" in command:
                Path(command[-1]).write_bytes(b"ROM!")
                return ""
            if "ld" in Path(command[0]).name:
                Path(command[command.index("-o") + 1]).write_bytes(b"elf")
                return ""
            if "-h" in command:
                return "  0 .text 00000004 80001000 00000000 00000000 2**2\n"
            if "--defined-only" in command:
                return f"80001000 00000004 T func_{unit_id}\n"
            Path(command[-1]).write_bytes(Path(command[-2]).read_bytes())
            return ""

        with patch("tools.verify_c_matches.run", side_effect=fake_run):
            result = verify_profile(
                temp_root,
                temp_root / f"build{jobs}",
                b"ROM!",
                {"id": "test", "flags": ["-O2"], "ido_version": "5.3"},
                units,
                compiler,
                {name: Path(name) for name in ("objcopy", "ld", "objdump", "nm")},
                {},
                jobs,
            )
        return result, state

    def test_parallel_results_are_ordered_and_errors_are_preserved(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            serial, serial_state = self._run_profile(root / "serial", 1)
            parallel, parallel_state = self._run_profile(root / "parallel", 4)

        serial_results = serial["functions"]
        parallel_results = parallel["functions"]
        self.assertEqual(
            [item["name"] for item in serial_results],
            ["func_slow", "func_broken", "func_fast"],
        )
        self.assertEqual(serial_results, parallel_results)
        self.assertFalse(serial_results[1]["verified_match"])
        self.assertIn("compile failed", serial_results[1]["build_error"])
        self.assertEqual(serial["matching_functions"], parallel["matching_functions"])
        self.assertEqual(serial_state["max_active"], 1)
        self.assertGreater(parallel_state["max_active"], 1)

    def test_duplicate_unit_ids_are_rejected_before_build(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            compiler, units = self._fixture(root)
            with self.assertRaisesRegex(ValueError, "duplicate unit ids"):
                verify_profile(
                    root,
                    root / "build",
                    b"ROM!",
                    {"id": "test", "flags": [], "ido_version": "5.3"},
                    [units[0], units[0]],
                    compiler,
                    {},
                    {},
                    4,
                )


if __name__ == "__main__":
    unittest.main()
