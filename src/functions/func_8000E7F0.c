/* Independently written from scratchpad spec specs/func_8000E7F0.md. */

#include "podcruise/types.h"

extern s16 D_80114470[2];
extern void func_8003EC40(s16 x, s16 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          s32 arg6);

void func_8000E7F0(s16 x, s16 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    f32 scaledX;
    f32 scaledY;

    scaledX = x / (f32)D_80114470[0] * 320.0f;
    scaledY = y / (f32)D_80114470[1] * 240.0f;
    func_8003EC40((s16)scaledX, (s16)scaledY, arg2, arg3, arg4, arg5, arg6);
}
