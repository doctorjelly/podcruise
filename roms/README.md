# Local ROM inputs

Place local ROM images under `roms/originals/`. The directory may contain the
descriptive filenames below; every ROM extension is ignored by Git.

| Build | Expected filename | SHA-1 |
|---|---|---|
| USA retail | `baserom.us.z64` | `3542d5597c8a56ea8f5c63bceae97a24c4c08d58` |
| Japan retail | `baserom.jp.z64` | `9577ccd2d069d0e7e306cf21ddb0e4765a308072` |
| Europe retail | `baserom.eu.z64` | `899a8245da017289c88e97327fdcd6694b770a25` |
| Limited Run Games Rev 1 | `baserom.us.rev1.z64` | `f71908f15a14ee124f9b471467432ade87e0951c` |
| Limited Run Games alias | `baserom.us.rev1.alias1.z64` | `f71908f15a14ee124f9b471467432ade87e0951c` |
| Revision 1, third alias | `baserom.us.rev1.alias2.z64` | `f71908f15a14ee124f9b471467432ade87e0951c` |

The final three files are byte-identical. They remain in the local working copy
to preserve provenance, but analysis treats them as one post-link revision.

Run `make inventory` from the repository root to validate every file before
analysis.
