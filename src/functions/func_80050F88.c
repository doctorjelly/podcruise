/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Obj;

extern s32 D_800A21A4;
extern s16 D_800A4BC0;
extern u8 D_800A4BF8;
extern f32 D_800A5278[1];
extern Vec3f D_800A527C;
extern Vec3f D_800A5288;
extern u8 D_800A5294;
extern f32 D_80118D60[4][4];
extern Vec3f D_80118D90;
extern f32 D_80118DE0[4][4];
extern Vec3f D_80118E10;
extern f32 D_80118E20[4][4];
extern f32 D_80118EA0[4][4];
extern Vec3f D_80118ED0;
extern f32 D_80120BF8;

extern void func_80014CC0(f32 angle, f32 *outB, f32 *outA);
extern void func_80015268(Vec3f *output, f32 x, f32 y, f32 z);
extern void func_80015288(Vec3f *output, const Vec3f *source);
extern u8 func_800152CC(const Vec3f *left, const Vec3f *right);
extern void func_800155EC(Vec3f *output, const Vec3f *base, f32 scale,
                          const Vec3f *offset);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_80028D60(void);
extern s32 func_80082BE0(void);

void func_80050F88(Obj *obj) {
    f32 cosine;
    f32 sine;
    Vec3f position;
    Vec3f scratch;

    if (D_800A21A4 != 0) {
        D_800A4BC0 = 0;
        func_80015268(&D_800A527C, 0.0f, 0.0f, 0.0f);
        return;
    }
    if (obj->unk_08 == 8) {
        D_800A4BC0 = 0;
        return;
    }
    func_80015288(&scratch, &D_80118D90);
    /* The spin angle is accumulated in the cosine slot; func_80014CC0
       overwrites that slot before the value is read as a cosine, and the
       original reserved no separate local for it. */
    cosine = D_800A5278[0] + 40.0f * D_80120BF8;
    D_800A5278[0] = cosine;
    if (cosine > 360.0f) {
        cosine = cosine - 360.0f;
        D_800A5278[0] = cosine;
    }
    if (D_800A4BF8 != 0 || D_800A5294 != 5 ||
        !func_800152CC(&D_800A527C, &D_80118E10) ||
        !func_800152CC(&D_800A5288, &D_80118ED0)) {
        D_800A4BF8 = 0;
        func_80028D60();
        func_800156DC(D_80118DE0, D_80118D60);
        func_800156DC(D_80118EA0, D_80118E20);
        func_80015288(&D_800A527C, &D_80118E10);
        func_80015288(&D_800A5288, &D_80118ED0);
        D_800A5294 = 5;
        D_800A5278[0] = (f32)(s32)((f32)func_80082BE0() / 2147483648.0f * (f32)2.0) * 180.0f;
    }
    func_80014CC0(D_800A5278[0], &cosine, &sine);
    func_80015288(&position, &D_800A527C);
    func_800155EC(&position, &position, 8.0f * cosine, (const Vec3f *)D_80118DE0);
    func_80015288(&D_80118D90, &position);
}
