/* Recovered from specs/functions/recovered/medium_core_tranche.md. */
#include "podcruise/types.h"

typedef struct Vec3f8007E988 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3f8007E988;

typedef struct Obj8007E988 {
    /* 0x000 */ u8 pad00[0x20];
    /* 0x020 */ f32 unk20[4][4];
    /* 0x060 */ u8 pad60[0xAC - 0x60];
    /* 0x0AC */ u8 unkAC[4];
    /* 0x0B0 */ u8 padB0[0x1A0 - 0xB0];
    /* 0x1A0 */ f32 unk1A0;
} Obj8007E988;

extern f32 D_800A66E0[];
extern f32 D_800ADC34;
extern Vec3f8007E988 D_8011DC50[];

extern s32 func_80082BE0(void);
extern void func_800156DC(f32 [4][4], const f32 [4][4]);
extern void func_8003B184(void *, void *, f32);

void func_8007E988(Obj8007E988 *obj) {
    f32 scratch;
    f32 base[4][4];
    f32 target[4][4];
    s32 i;
    s32 count;
    Vec3f8007E988 *point;

    func_80082BE0();
    func_80082BE0();
    (void)scratch;
    count = 8;
    for (i = 0; i != count; i++) {
        if (D_800A66E0[i] <= 0.0f) {
            point = &D_8011DC50[i];
            D_800A66E0[i] = (f32)func_80082BE0() / 2147483648.0f * 6.0f + 2.0f;
            func_800156DC(base, obj->unk20);
            func_8003B184(obj->unkAC, target,
                          D_800A66E0[i] / 3.5f * D_800ADC34 * (obj->unk1A0 / 300.0f));
            point->x = target[3][0];
            point->y = target[3][1];
            point->z = target[3][2] - 8.0f;
            point->x = (((f32)func_80082BE0() / 2147483648.0f) * 200.0f + -100.0f) + point->x;
            point->y = (((f32)func_80082BE0() / 2147483648.0f) * 200.0f + -100.0f) + point->y;
        }
    }
}
