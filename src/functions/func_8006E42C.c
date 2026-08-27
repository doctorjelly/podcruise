/* Specification: scratchpad specs/func_8006E42C.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x10];
    u8 unk10;
} SlotE42C;

typedef struct {
    u8 unk00[0x50];
    u8 unk50[0x10];
    s32 unk60;
    u8 unk64[0x210 - 0x64];
    s32 unk210;
    f32 unk214;
    u8 unk218[0x1E70 - 0x218];
    SlotE42C *unk1E70;
} ObjectE42C;

extern void func_80008BC4(void *arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8);
extern s32 func_80082BE0(void);

extern s32 D_8009B7D8;
extern f32 D_800AD728;
extern f32 D_800AD72C;
extern f32 D_800AD730;
extern f32 D_800AD734;
extern f64 D_800AD738;
extern f64 D_800AD740;
extern s32 D_800D76F0[];
extern s32 D_800D7700[];
extern f32 D_800D7730[];
extern f64 D_80120BF0;

s32 func_8006E42C(ObjectE42C *object, s32 index) {
    f32 limit;
    f32 scratch[3];
    s32 result;
    s32 ready;
    s32 pressed;
    s32 flags;
    s32 second;

    (void)scratch;
    ready = D_800D76F0[index] & 1;
    pressed = D_800D7700[index] & 1;

    if (D_8009B7D8 & 0x2000000) {
        if (object->unk1E70->unk10 == 0) {
            index = 0;
        } else {
            index = 1;
        }
        second = index + 2;
        limit = D_800AD728;
        ready = limit < D_800D7730[index] || limit < D_800D7730[second]; pressed = (D_800D7700[index] & 0x100) != 0 || (D_800D7700[second] & 0x100) != 0;
    }

    result = 0;
    flags = object->unk60;
    if (!(flags & 0x200000) || (flags & 0x800000)) {
        object->unk60 = flags & ~0x400000;
        object->unk210 = 0;
    } else {
        switch (object->unk210) {
            case 0:
                if (ready) {
                    if (D_800AD72C < D_800D7730[index]) {
                        object->unk210 = 1;
                        object->unk214 = 0.0f;
                    }
                }
                break;
            case 1:
                if (!ready) {
                    object->unk210 = 0;
                } else if (D_800AD730 < D_800D7730[index]) {
                    object->unk214 = object->unk214 + D_80120BF0;
                    if (1.0f < object->unk214) {
                        object->unk210 = 2;
                    }
                } else {
                    object->unk210 = 0;
                }
                break;
            case 2:
                if (D_800D7730[index] < D_800AD734) {
                    object->unk210 = 0;
                } else if (pressed) {
                    object->unk210 = 0;
                    result = 1;
                    func_80008BC4((void *)114, 7,
                                  (f32)((f64)((f32)func_80082BE0() / 2147483648.0f) * D_800AD738 + D_800AD740),
                                  1.0f, object->unk50, 0, 1, 10.0f, 500.0f);
                }
                break;
            default:
                object->unk210 = 0;
                break;
        }
    }
    return result;
}
