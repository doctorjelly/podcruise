/* Independently written from scratchpad spec specs/func_80032F2C.md. */

#include "podcruise/types.h"

typedef struct {
    f32 unk_00[15];
} Struct80032F2C;

extern void func_800321F0(Struct80032F2C *target, s32 selector, s32 mode,
                          f32 value);

void func_80032F2C(Struct80032F2C *target, Struct80032F2C *source,
                   u8 *modes, u8 *levels) {
    f32 value;
    s32 mode;
    s32 index;

    *target = *source;
    for (index = 0; index < 7; index++) {
        mode = modes[index];
        value = (f32)(u32)levels[index] / 255.0f;
        func_800321F0(target, index, mode, value);
    }
}
