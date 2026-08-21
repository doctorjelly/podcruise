# Runtime state wait wrapper

`func_8002E548` is a 140-byte USA routine at `0x8002E548`. Its complete
return sequence establishes the boundary. While `D_800A2680` is nonzero it
calls `func_8002E124` and `func_8002E2FC` repeatedly. It then clears
`D_800A2670`, stores one in `D_800A2674`, calls `func_80088AD0`, passes the
word at `D_801488C0` to both `func_8008AFBC` and `func_8008B14C`, and finally
calls `func_8002DFB0(1, 0)`. Japan and Europe contain structurally equivalent
bodies at `0x8002EFA8` and `0x80031AE8`; global and callee relocations remain
to be mapped before a regional matching unit is added.

Status: byte-matching C under IDO 5.3 `-O2`; substituted in all four regional
round trips.
