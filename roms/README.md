# Local ROM inputs

This directory is where the build expects to find the retail images it verifies
against. It is empty in the repository and stays that way: every ROM extension
is Git-ignored, and no ROM data is committed here or anywhere else in this
project.

**You must already lawfully possess the game.** This project does not
distribute ROM images, does not describe how to obtain them, and is not a
substitute for owning the software. Nothing here is an invitation to download
copyrighted material.

## Verification

Analysis is pinned to specific retail builds, identified by cryptographic hash:

| Build | SHA-1 |
|---|---|
| USA retail | `3542d5597c8a56ea8f5c63bceae97a24c4c08d58` |
| Japan retail | `9577ccd2d069d0e7e306cf21ddb0e4765a308072` |
| Europe retail | `899a8245da017289c88e97327fdcd6694b770a25` |
| USA revision 1 | `f71908f15a14ee124f9b471467432ade87e0951c` |

These hashes exist so the tooling can confirm it is reading the build it
expects, and so that a reported byte match is unambiguous about what it matched
against. They are identifiers, not a manifest of files to acquire.

The expected paths are recorded in `config/versions.json`. Run `make inventory`
from the repository root to validate whatever is present before analysis.
