PYTHON ?= python3
VENV_PYTHON := .venv/bin/python
US_ROM := roms/originals/baserom.us.z64
JP_ROM := roms/originals/baserom.jp.z64
EU_ROM := roms/originals/baserom.eu.z64
GLOBAL_STATE_SRCS := $(wildcard src/functions/*.c)

# tests/test_global_state.c defines observable stand-ins for some callees so
# that a caller's interactions can be asserted. Once a callee is recovered for
# real, linking both would be a duplicate definition, so the recovered source
# is dropped from the host-test link only. Its correctness is still proven by
# the byte-match verifier, which is the stronger check.
# make counts literal parentheses inside $(shell ...) even within quotes.
LPAREN := (
HOST_TEST_DOUBLES := $(shell grep -oE '^[A-Za-z_][A-Za-z0-9_ *]*func_[0-9A-F]{8}[$(LPAREN)]' tests/test_global_state.c | grep -oE 'func_[0-9A-F]{8}')
HOST_TEST_SRCS := src/bootstrap_state.c \
	$(filter-out $(patsubst %,src/functions/%.c,$(HOST_TEST_DOUBLES)),$(GLOBAL_STATE_SRCS))

.PHONY: all setup inventory analyze probe map region-symbols bootstrap-evidence manifest classify prototypes report match-c split-us split-jp split-eu split-lrg roundtrip-us roundtrip-jp roundtrip-eu roundtrip-lrg roundtrip-all host-check host-test test safety status

all: inventory analyze probe map region-symbols bootstrap-evidence report

setup:
	$(PYTHON) -m venv .venv
	$(VENV_PYTHON) -m pip install --upgrade pip
	$(VENV_PYTHON) -m pip install -r requirements-lock.txt

inventory:
	$(PYTHON) tools/rom_inventory.py --config config/versions.json --output analysis/roms.json --check

analyze:
	$(PYTHON) tools/analyze_mips.py \
		--rom "$(US_ROM)" \
		--code-start 0x1000 \
		--code-end 0x99000 \
		--vram-start 0x80000400 \
		--csv analysis/functions.us.csv \
		--symbols config/us/symbol_addrs.auto.txt \
		--summary analysis/functions.us.json

probe:
	$(PYTHON) tools/compiler_probe.py \
		--rom "$(US_ROM)" \
		--code-start 0x1000 \
		--code-end 0x98000 \
		--output analysis/compiler_probe.us.json

map: analyze
	$(PYTHON) tools/cross_version_map.py \
		--source-rom "$(US_ROM)" \
		--source-functions analysis/functions.us.csv \
		--target "jp=$(JP_ROM)" \
		--target "eu=$(EU_ROM)" \
		--scan-start 0x1000 \
		--scan-end 0xA4000 \
		--window 32 \
		--output analysis/cross_version_functions.csv \
		--summary analysis/cross_version_functions.json

region-symbols: map
	$(PYTHON) tools/make_region_symbols.py \
		--mappings analysis/cross_version_functions.csv \
		--target jp \
		--output config/jp/symbol_addrs.auto.txt
	$(PYTHON) tools/make_region_symbols.py \
		--mappings analysis/cross_version_functions.csv \
		--target eu \
		--output config/eu/symbol_addrs.auto.txt

bootstrap-evidence: map
	$(PYTHON) tools/bootstrap_function_evidence.py \
		--versions config/versions.json \
		--mappings analysis/cross_version_functions.csv \
		--matches analysis/c_matches.us.json \
		--match-profile ido53_o2 \
		--output analysis/bootstrap_functions.json

prototypes:
	$(PYTHON) tools/check_prototypes.py

classify:
	$(PYTHON) tools/classify_non_c.py \
		--asm-root analysis/generated/us/asm \
		--output analysis/non_c_functions.json

manifest:
	$(PYTHON) tools/make_source_manifest.py \
		--output analysis/source_manifest.json \
		--strict

report: inventory analyze probe map region-symbols bootstrap-evidence manifest
	$(PYTHON) tools/make_report.py \
		--inventory analysis/roms.json \
		--functions analysis/functions.us.json \
		--compiler analysis/compiler_probe.us.json \
		--mappings analysis/cross_version_functions.json \
		--bootstrap analysis/bootstrap_functions.json \
		--manifest analysis/source_manifest.json \
		--output analysis/REPORT.md

match-c:
	$(PYTHON) tools/verify_c_matches.py \
		--config config/c_matching.json \
		--output analysis/c_matches.us.json
	$(PYTHON) tools/verify_c_matches.py \
		--config config/c_matching.jp.json \
		--output analysis/c_matches.jp.json
	$(PYTHON) tools/verify_c_matches.py \
		--config config/c_matching.eu.json \
		--output analysis/c_matches.eu.json
	$(PYTHON) tools/verify_c_matches.py \
		--config config/c_matching.lrg_rev1.json \
		--output analysis/c_matches.lrg_rev1.json

split-us:
	$(VENV_PYTHON) -m splat split config/us.yaml

split-jp:
	$(VENV_PYTHON) -m splat split config/jp.yaml

split-eu:
	$(VENV_PYTHON) -m splat split config/eu.yaml

split-lrg:
	$(VENV_PYTHON) -m splat split config/lrg_rev1.yaml

roundtrip-us: split-us
	$(PYTHON) tools/rebuild_roundtrip.py --version us --output analysis/rebuild.us.json

roundtrip-jp: split-jp
	$(PYTHON) tools/rebuild_roundtrip.py --version jp --output analysis/rebuild.jp.json

roundtrip-eu: split-eu
	$(PYTHON) tools/rebuild_roundtrip.py --version eu --output analysis/rebuild.eu.json

roundtrip-lrg: split-lrg
	$(PYTHON) tools/rebuild_roundtrip.py --version lrg_rev1 --output analysis/rebuild.lrg_rev1.json

roundtrip-all: roundtrip-us roundtrip-jp roundtrip-eu roundtrip-lrg

host-check:
	$(CC) -std=c11 -Wall -Wextra -Werror -I include -fsyntax-only \
		src/bootstrap_state.c $(GLOBAL_STATE_SRCS)

# -Wno-error=return-type: at least one recovered function reproduces an
# original path that falls off the end without setting the return register.
# That is undefined in C and is exactly what the ROM does; adding a return
# statement changes the generated bytes and breaks the match.
host-test:
	mkdir -p build/host
	$(PYTHON) tools/gen_host_stubs.py
	$(CC) -std=c11 -Wall -Wextra -Werror -Wno-error=return-type -I include \
		$(HOST_TEST_SRCS) tests/test_global_state.c tests/host_link_stubs.c \
		-o build/host/test_global_state -lm
	build/host/test_global_state

test: host-check host-test prototypes
	$(PYTHON) -m unittest discover -s tests -v

safety:
	$(PYTHON) tools/check_repository_safety.py

status:
	git status --short --ignored
