/* Recovered per specs/functions/func_8006E034.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x50];
    /* 0x050 */ f32 unk50[4];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u8 pad064[0x268 - 0x64];
    /* 0x268 */ f32 unk268;
} Object8006E034;

typedef struct {
    /* 0x000 */ u8 pad000[0x314];
    /* 0x314 */ void *unk314;
} Inner8006E034;

extern f64 D_800AD708;
extern f64 D_800AD710;
extern f64 D_800AD718;
extern f64 D_800AD720;

extern void func_80008BC4(s32, s32, f32, f32, void *, s32, s32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void *func_80065810(s32, s32, f32, f32 *, f32);
extern void func_80065CB0(void *, void *);
extern s32 func_80082BE0(void);

void func_8006E034(Object8006E034 *object) {
    Inner8006E034 *inner;
    f32 vector[10];

    inner = (Inner8006E034 *)((u8 *)object + 8);
    if (((object->unk60 & 0x4000) == 0) && ((object->unk60 & 0x2000) == 0) &&
        (inner->unk314 == 0)) {
        func_80008BC4(0x87, 6,
                      (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD708 + D_800AD710),
                      1.0f, object->unk50, 0, 1, 50.0f, 500.0f);
        func_80008BC4(0x88, 7,
                      (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD718 + D_800AD720),
                      1.0f, object->unk50, 0, 1, 50.0f, 500.0f);
        object->unk268 = 15.0f;
        func_80015288(&vector[5], object->unk50);
        inner->unk314 = func_80065810(8, 0, 8.0f, &vector[5], 2.0f);
        func_80065CB0(inner->unk314, &inner->unk314);
    }
}
