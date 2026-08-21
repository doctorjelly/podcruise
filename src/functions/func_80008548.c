/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_8009A2C4;
extern s32 D_8009AC7C;
extern s32 D_8009AC80;
extern f32 D_8009AC84;
extern s32 func_8002F054(void);
extern f32 func_8002F060(void);
extern void func_80008B68(s32, s32, s32, s32, s32);

void func_80008548(void) {
    s32 value;
    if (D_8009A2C4 == 0) {
        value = (s32)((f32)D_8009AC80 * D_8009AC84);
        if (func_8002F054() != 0) {
            value = (s32)((f32)value / (func_8002F060() + 1.0f));
        }
        func_80008B68(D_8009AC7C, 7, 0x3E800000, (s32)(f32)value, 1);
    }
}
