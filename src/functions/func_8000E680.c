/* Independently written from scratchpad spec specs/func_8000E680.md. */

#include "podcruise/types.h"

extern s16 D_80114470[2];

extern void func_8000AA04(s16 index, s16 x, s16 y);

void func_8000E680(s16 arg0, s16 arg1, s16 arg2) {
    f32 x;
    f32 y;

    x = arg1 / (f32)D_80114470[0] * 320.0f;
    y = arg2 / (f32)D_80114470[1] * 240.0f;
    func_8000AA04(arg0, x, y);
}
