/* Independently written from scratchpad spec specs/func_800356BC.md. */

#include "podcruise/types.h"

extern u32 D_800A3DA0;
extern u32 D_800A3DA4;

void func_800356BC(u32 arg0, s32 arg1, u32 arg2) {
    if (arg0 == 0x5A425A42) {
        if (arg2 == 1) {
            if (D_800A3DA0 == 0x0C084000) {
                D_800A3DA0 = 0x00442230;
                D_800A3DA4 = 0x00112230;
            } else if (D_800A3DA0 == 0x00442048) {
                D_800A3DA0 = 0x00442078;
                D_800A3DA4 = 0x00112078;
            }
        } else {
            if (D_800A3DA0 == 0x00442230) {
                D_800A3DA0 = 0x0C084000;
                D_800A3DA4 = 0x03024000;
            } else if (D_800A3DA0 == 0x00442078) {
                D_800A3DA0 = 0x00442048;
                D_800A3DA4 = 0x00112048;
            }
        }
    } else if (arg0 == 0x4141454E) {
        if (arg2 == 1) {
            if (D_800A3DA0 == 0x0C084000) {
                D_800A3DA0 = 0x00442048;
                D_800A3DA4 = 0x00112048;
            } else if (D_800A3DA0 == 0x00442230) {
                D_800A3DA0 = 0x00442078;
                D_800A3DA4 = 0x00112078;
            }
        } else {
            if (D_800A3DA0 == 0x00442048) {
                D_800A3DA0 = 0x0C084000;
                D_800A3DA4 = 0x03024000;
            } else if (D_800A3DA0 == 0x00442078) {
                D_800A3DA0 = 0x00442230;
                D_800A3DA4 = 0x00112230;
            }
        }
    } else if (arg0 == 0x46756C6C) {
        D_800A3DA0 = arg2;
        D_800A3DA4 = arg2;
    }
    (void)arg1;
}
