PYTHON ?= python3
VENV_PYTHON := .venv/bin/python
US_ROM := roms/originals/baserom.us.z64
JP_ROM := roms/originals/baserom.jp.z64
EU_ROM := roms/originals/baserom.eu.z64

.PHONY: all setup inventory analyze probe map region-symbols bootstrap-evidence report split-us split-jp split-eu roundtrip-us roundtrip-jp roundtrip-eu roundtrip-all host-check test safety status

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
		--output analysis/bootstrap_functions.json

report: inventory analyze probe map region-symbols bootstrap-evidence
	$(PYTHON) tools/make_report.py \
		--inventory analysis/roms.json \
		--functions analysis/functions.us.json \
		--compiler analysis/compiler_probe.us.json \
		--mappings analysis/cross_version_functions.json \
		--bootstrap analysis/bootstrap_functions.json \
		--output analysis/REPORT.md

split-us:
	$(VENV_PYTHON) -m splat split config/us.yaml

split-jp:
	$(VENV_PYTHON) -m splat split config/jp.yaml

split-eu:
	$(VENV_PYTHON) -m splat split config/eu.yaml

roundtrip-us: split-us
	$(PYTHON) tools/rebuild_roundtrip.py --version us --output analysis/rebuild.us.json

roundtrip-jp: split-jp
	$(PYTHON) tools/rebuild_roundtrip.py --version jp --output analysis/rebuild.jp.json

roundtrip-eu: split-eu
	$(PYTHON) tools/rebuild_roundtrip.py --version eu --output analysis/rebuild.eu.json

roundtrip-all: roundtrip-us roundtrip-jp roundtrip-eu

host-check:
	$(CC) -std=c11 -Wall -Wextra -Werror -I include -fsyntax-only src/bootstrap_state.c

test: host-check
	$(PYTHON) -m unittest discover -s tests -v

safety:
	$(PYTHON) tools/check_repository_safety.py

status:
	git status --short --ignored
