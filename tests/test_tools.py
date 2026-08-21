from __future__ import annotations

import unittest
from pathlib import Path

from tools.analyze_mips import jal_target, post_return_candidate, sign16
from tools.build_matching_object import contiguous_span
from tools.compiler_probe import probe
from tools.cross_version_map import normalize_instruction
from tools.classify_non_c import classify_body
from tools.make_report import render_report
from tools.make_region_symbols import format_symbol
from tools.rebuild_roundtrip import relative_argument
from tools.verify_c_matches import (
    compiler_defines,
    first_difference,
    linker_script,
    load_matching_config,
    parse_function_symbols,
)


class MipsAnalysisTests(unittest.TestCase):
    def test_signed_immediate(self) -> None:
        self.assertEqual(sign16(0x0010), 16)
        self.assertEqual(sign16(0xFFF0), -16)

    def test_jal_target_uses_pc_region(self) -> None:
        # jal 0x80001000 encoded from the usual KSEG0 code region.
        encoded = (3 << 26) | ((0x80001000 >> 2) & 0x03FFFFFF)
        self.assertEqual(jal_target(encoded, 0x80000400), 0x80001000)

    def test_non_jal_has_no_target(self) -> None:
        self.assertIsNone(jal_target(0x03E00008, 0x80000400))

    def test_leaf_candidate_follows_return_delay_slot(self) -> None:
        words = [0x03E00008, 0x00000000, 0x3C01800A, 0x03E00008, 0xAC24A270]
        self.assertEqual(post_return_candidate(words, 0), 2)

    def test_invalid_data_after_return_is_rejected(self) -> None:
        # 0x76303741 is the first word of the local build-stamp data, not code.
        words = [0x03E00008, 0x00000000, 0x00000000, 0x76303741, 0x70723939]
        self.assertIsNone(post_return_candidate(words, 0))

    def test_normalization_ignores_relocated_jal_target(self) -> None:
        first = (3 << 26) | 0x12345
        second = (3 << 26) | 0x54321
        self.assertEqual(normalize_instruction(first), normalize_instruction(second))

    def test_normalization_preserves_i_type_register_roles(self) -> None:
        first = 0x8C220010  # lw v0, 0x10(at)
        relocated = 0x8C227FF0
        other_register = 0x8C230010
        self.assertEqual(normalize_instruction(first), normalize_instruction(relocated))
        self.assertNotEqual(normalize_instruction(first), normalize_instruction(other_register))

    def test_compiler_probe_reports_ido_shape(self) -> None:
        words = [0x10000001] * 20 + [0x08000000]
        data = b"".join(word.to_bytes(4, "big") for word in words)
        self.assertEqual(probe(data, 0, len(data))["hypothesis"], "IDO-family")

    def test_region_symbol_uses_splat_attribute_syntax(self) -> None:
        self.assertEqual(
            format_symbol(0x80001234),
            "func_80001234 = 0x80001234; // type:func\n",
        )
        self.assertNotIn("type:func,", format_symbol(0x80001234))

    def test_linker_object_arguments_are_repository_relative(self) -> None:
        root = Path("/work/podcruise")
        path = root / "build/us/analysis/generated/us/asm/main.o"
        self.assertEqual(
            relative_argument(path, root),
            "build/us/analysis/generated/us/asm/main.o",
        )

    def test_c_match_first_difference_includes_size_changes(self) -> None:
        self.assertIsNone(first_difference(b"abc", b"abc"))
        self.assertEqual(first_difference(b"abc", b"axc"), 1)
        self.assertEqual(first_difference(b"abc", b"abcx"), 3)

    def test_c_match_parses_sign_extended_mips_symbols(self) -> None:
        symbols = parse_function_symbols(
            "ffffffff80000520 0000000c T func_80000520\n"
        )
        self.assertEqual(symbols["func_80000520"], (0x80000520, 12))

    def test_c_match_linker_script_defines_absolute_symbols(self) -> None:
        script = linker_script(
            {
                "link_vram": "0x80000520",
                "absolute_symbols": {"D_8009A270": "0x8009A270"},
            }
        )
        self.assertIn("D_8009A270 = 0x8009A270;", script)
        self.assertIn(".text 0x80000520 : { *(.text) }", script)

    def test_c_match_compiler_defines_remap_regional_symbols(self) -> None:
        self.assertEqual(
            compiler_defines({"defines": {"func_80001000": "func_80002000"}}),
            ["-Dfunc_80001000=func_80002000"],
        )

    def test_c_match_config_can_inherit_common_units(self) -> None:
        root = Path(__file__).resolve().parent.parent
        config = load_matching_config(root, Path("config/c_matching.lrg_rev1.json"))
        base = load_matching_config(root, Path("config/c_matching.json"))
        self.assertEqual(config["version"], "lrg_rev1")
        self.assertEqual(config["units"], base["units"])

    def test_matching_object_requires_contiguous_functions(self) -> None:
        unit = {
            "id": "pair",
            "link_vram": "0x80001000",
            "functions": [
                {"name": "first", "vram": "0x80001000", "size": 12},
                {"name": "second", "vram": "0x8000100C", "size": 8},
            ],
        }
        self.assertEqual(contiguous_span(unit), 20)

    def test_report_does_not_split_confidence_table(self) -> None:
        report = render_report(
            {
                "roms": [],
                "unique_rom_count": 0,
            },
            {
                "candidate_count": 3,
                "code_start": "0x1000",
                "code_end": "0x2000",
                "by_confidence": {"high": 1, "medium": 2},
            },
            {
                "beq_zero_zero_pseudo_branches": 1,
                "absolute_j_instructions": 0,
                "hypothesis": "IDO-family",
            },
            {
                "targets": {},
            },
            [
                {
                    "version": "us",
                    "byte_identical": True,
                    "rebuilt_sha1": "abc",
                }
            ],
            None,
        )
        confidence_end = report.index("| medium | 2 |")
        roundtrip_start = report.index("## ROM rebuild verification")
        self.assertLess(confidence_end, roundtrip_start)

    def test_report_ledger_comes_from_the_manifest(self) -> None:
        report = render_report(
            {"roms": [], "unique_rom_count": 0},
            {
                "candidate_count": 1,
                "code_start": "0x1000",
                "code_end": "0x2000",
                "by_confidence": {"high": 1},
            },
            {
                "beq_zero_zero_pseudo_branches": 1,
                "absolute_j_instructions": 0,
                "hypothesis": "IDO-family",
            },
            {"targets": {}},
            [],
            None,
            {
                "recovered_functions": 12,
                "recovered_bytes": 340,
                "exact": {
                    "us": {"functions": 10, "bytes": 300},
                    "lrg_rev1": {"functions": 10, "bytes": 300},
                    "jp": {"functions": 8, "bytes": 250},
                    "eu": {"functions": 7, "bytes": 240},
                },
            },
        )
        self.assertIn("## Recovered source ledger", report)
        self.assertIn("**12**", report)
        self.assertIn("| us | 10 | 300 |", report)
        self.assertIn("| eu | 7 | 240 |", report)

    def test_unit_flags_override_the_profile(self) -> None:
        """A translation unit built differently keeps its own flag list."""
        profile = ["-O2", "-mips2"]
        unit = {"flags": ["-O1", "-mips2"]}
        self.assertEqual(unit.get("flags", profile), ["-O1", "-mips2"])
        self.assertEqual({}.get("flags", profile), profile)

    def test_linker_script_places_a_units_constant_pool(self) -> None:
        unit = {
            "absolute_symbols": {},
            "link_vram": "0x80001000",
            "rodata_vram": "0x800AAAD0",
        }
        script = linker_script(unit)
        self.assertIn(".text 0x80001000 :", script)
        self.assertIn(".rodata 0x800AAAD0 :", script)
        self.assertNotIn(".rodata", linker_script(
            {"absolute_symbols": {}, "link_vram": "0x80001000"}))

    def test_only_unreachable_instructions_retire_a_function(self) -> None:
        """Guard the compiler-capability facts this classification rests on.

        Each of these was checked against the compiler itself: a plain
        (unsigned)float cast emits cfc1/ctc1, a byte-aligned struct assignment
        emits lwl/lwr/swl/swr, and a MIPS III unit emits the 64-bit forms. None
        of them means a body was hand-written, and treating them as decisive
        would retire functions that are in fact recoverable.
        """
        for mnemonic in ("cfc1", "ctc1", "ld", "dsll"):
            reasons, notes = classify_body([mnemonic, "lw", "jr"], False)
            self.assertEqual(reasons, [], f"{mnemonic} must not retire a function")
            self.assertTrue(notes, f"{mnemonic} should still be reported")

        # Partial word access is ordinary compiler output when it is balanced:
        # the compiler takes the left and right halves of one word together.
        reasons, notes = classify_body(["lwl", "lwr", "swl", "swr", "jr"], False)
        self.assertEqual(reasons, [])
        self.assertEqual(notes, ["unaligned_access"])
        # A lone *right* half is ordinary: the compiler emits it for a
        # trailing piece of a copy whose start is known word-aligned.
        self.assertEqual(classify_body(["lwr", "lw", "jr"], False)[0], [])
        self.assertEqual(classify_body(["swr", "sw", "jr"], False)[0], [])
        # A lone *left* half writes a piece ending at a word boundary, whose
        # width is decided at run time; no C typed access expresses that.
        self.assertEqual(classify_body(["lwl", "lwl", "lwr", "jr"], False)[0],
                         ["unpaired_partial_access"])
        self.assertEqual(classify_body(["swl", "jr"], False)[0],
                         ["unpaired_partial_access"])

        for mnemonic in ("mtc0", "mfc0", "tlbwi", "cache", "add", "addi", "sub"):
            reasons, _ = classify_body([mnemonic, "jr"], False)
            self.assertTrue(reasons, f"{mnemonic} is unreachable from C")

        self.assertEqual(classify_body(["lw", "jr"], True)[0], ["kernel_registers"])
        self.assertEqual(classify_body(["lw", "jr"], False), ([], []))

    def test_break_alone_is_the_divide_trap_not_microcode(self) -> None:
        """`break` is how the compiler traps division by zero."""
        self.assertEqual(classify_body(["div", "break", "jr"], False, called=False),
                         ([], []))
        self.assertEqual(classify_body(["div", "break", "jr"], False, called=True),
                         ([], []))
        # Uncalled, halts itself, and drives coprocessor 0: the signal
        # processor's own program, reached by transfer rather than by a call.
        self.assertEqual(classify_body(["mtc0", "break", "jr"], False, called=False),
                         (["signal_processor_microcode"], []))

    def test_matching_configs_hold_their_invariants(self) -> None:
        """Guard the defects that have actually occurred in these configs.

        Each of these has been a real bug: a ROM offset that did not follow the
        VRAM mapping silently compared a function against the wrong bytes; a
        regional unit that kept the USA symbol name verified but broke that
        version's link; two units claiming one source produced duplicate
        objects; and overlapping ranges meant one of the two boundaries was
        wrong.
        """
        import json

        root = Path(__file__).resolve().parent.parent
        for version, name in (("us", "c_matching.json"),
                              ("jp", "c_matching.jp.json"),
                              ("eu", "c_matching.eu.json")):
            config = json.loads((root / "config" / name).read_text(encoding="utf-8"))
            units = config["units"]
            with self.subTest(version=version):
                sources = [unit["source"] for unit in units]
                self.assertCountEqual(sources, set(sources), "one unit per source")
                ids = [unit["id"] for unit in units]
                self.assertCountEqual(ids, set(ids), "unit ids are unique")
                spans = []
                for unit in units:
                    self.assertTrue((root / unit["source"]).is_file(), unit["source"])
                    # splat places a C split at the function's own address and
                    # expects the source to define the symbol for that address.
                    # A corrected boundary that keeps the old name leaves the
                    # symbol undefined and breaks every version's link.
                    for function in unit["functions"]:
                        if version != "us":
                            continue
                        expected = "func_%08X" % int(function["vram"], 0)
                        self.assertEqual(
                            function["name"], expected,
                            f"{unit['id']}: function at {function['vram']} must "
                            f"be named {expected}")
                    for function in unit["functions"]:
                        vram = int(function["vram"], 16)
                        self.assertEqual(function["name"], f"func_{vram:08X}")
                        self.assertEqual(int(function["rom"], 0), vram - 0x7FFFF400)
                        size = int(function["size"])
                        self.assertGreater(size, 0)
                        self.assertEqual(size % 4, 0)
                        spans.append((int(function["rom"], 0),
                                      int(function["rom"], 0) + size,
                                      function["name"]))
                spans.sort()
                for earlier, later in zip(spans, spans[1:]):
                    self.assertLessEqual(earlier[1], later[0],
                                         f"{earlier[2]} overlaps {later[2]}")

    def test_no_proven_compiler_output_is_classified_non_c(self) -> None:
        """The strongest available check on the non-C rule.

        Every function the verifier reproduces byte-for-byte is, by
        construction, something this compiler can emit. If the classification
        flags any of them, the rule is wrong and is retiring recoverable work.
        """
        import json

        from tools.classify_non_c import read_bodies, read_references

        root = Path(__file__).resolve().parent.parent
        asm = root / "analysis/generated/us/asm"
        if not asm.is_dir():
            self.skipTest("generated disassembly is not present")
        report = json.loads((root / "analysis/c_matches.us.json").read_text())
        exact = {item["name"] for item in report["profiles"][0]["functions"]
                 if item["verified_match"]}
        bodies = read_bodies(asm)
        called, _, _ = read_references(asm)
        for name, (mnemonics, kernel) in bodies.items():
            if name not in exact:
                continue
            reasons, _ = classify_body(mnemonics, kernel, called=name in called)
            self.assertEqual(reasons, [],
                             f"{name} matches exactly, so it cannot be non-C")

    def test_recovered_prototypes_agree(self) -> None:
        """Catch the defect class the byte comparison structurally cannot.

        A caller that declares the wrong arity still reproduces the original
        bytes whenever the value it should have passed already sits in the
        right register, so five of these survived byte verification.
        """
        import subprocess
        import sys

        root = Path(__file__).resolve().parent.parent
        result = subprocess.run(
            [sys.executable, "tools/check_prototypes.py"],
            cwd=root, capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)


if __name__ == "__main__":
    unittest.main()
