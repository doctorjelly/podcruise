from __future__ import annotations

import unittest
from pathlib import Path

from tools.analyze_mips import jal_target, post_return_candidate, sign16
from tools.compiler_probe import probe
from tools.cross_version_map import normalize_instruction
from tools.make_report import render_report
from tools.make_region_symbols import format_symbol
from tools.rebuild_roundtrip import relative_argument


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
        roundtrip_start = report.index("## Untouched split round trips")
        self.assertLess(confidence_end, roundtrip_start)


if __name__ == "__main__":
    unittest.main()
