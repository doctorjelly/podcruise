/* Independently written from scratchpad spec specs/func_8000EEE0.md. */

#include "podcruise/types.h"

extern f32 D_800A8688;
extern f32 D_800A868C;
extern s16 D_80114470[2];

extern void func_8000A920(s16, s32);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, u8, u8, u8, u8);
extern void func_8000E680(s16, s16, s16);

void func_8000EEE0(s16 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 red, u8 green, u8 blue) {
    register s32 index;
    s32 x;
    s32 y;
    f32 scale;

    index = arg0;
    x = (arg1 - D_80114470[0] / 2) * arg4 + D_80114470[0] / 2;
    y = (arg2 - D_80114470[1] / 2) * arg4 + D_80114470[1] / 2;
    func_8000E680(index, (s16)x, (s16)y);
    func_8000AB24(index, red, green, blue, (u8)(u32)(arg5 * 130.0f));
    scale = (f32)arg3 * ((1.0f - arg5) * D_800A8688 + D_800A868C);
    func_8000AAC0(index, scale, scale);
    func_8000A920(index, 1);
}
