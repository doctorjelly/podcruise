/* Independently written from scratchpad spec specs/func_800503E8.md. */

#include "podcruise/types.h"

extern s32 D_800A2198;
extern u8 D_800A4C00[];

extern void func_8005058C(void *, void *, s32, s32, s32);

void func_800503E8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[13] = arg1;

    func_8005058C(&D_800A4C00[arg1 * 32], &D_800A4C00[arg1 * 32 + 12], 1, 0, arg3);

    if (arg2 != -1) {
        D_800A2198 = arg2;
    }
}
