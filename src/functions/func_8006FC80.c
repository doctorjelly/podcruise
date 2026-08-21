/* Independently written from $S/specs/func_8006FC80.md. */

#include "podcruise/types.h"

extern void func_8003F99C(void *object, void *tag);

extern f32 D_800AD7F4;
extern f64 D_80120BF0;

void func_8006FC80(u8 *object) {
    f32 unused[6];
    s32 index;
    f32 limit;
    u32 tag;

    (void)unused;

    *(s32 *)(object + 0x60) &= ~0x10;
    *(f32 *)(object + 0x1A4) = 0.0f;
    *(f32 *)(object + 0x310) -= (f32)D_80120BF0;

    if (*(f32 *)(object + 0x310) <= 0.0f) {
        tag = 0x536E6170;
        func_8003F99C(object, &tag);

        limit = D_800AD7F4;
        for (index = 0; index < 6; index++) {
            ((s32 *)(object + 0x2A0))[index] &= ~8;
            if (((f32 *)(object + 0x288))[index] > limit) {
                ((f32 *)(object + 0x288))[index] = limit;
            }
        }

        *(s32 *)(object + 0x60) &= ~0x800;
    }
}
