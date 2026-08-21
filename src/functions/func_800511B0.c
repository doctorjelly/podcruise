/* Specification: $S/specs/func_800511B0.md */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f800511B0;

typedef struct {
    Vec3f800511B0 unk00;
    Vec3f800511B0 unk0C;
    u8 pad18[0x14];
} Entry800511B0;

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
} Owner800511B0;

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    f32 unk34;
} Block800511B0;

extern s32 D_800A2198;
extern s16 D_800A4BC0;
extern s32 D_800A4BD0;
extern Entry800511B0 D_800A4C00[];
extern Vec3f800511B0 D_800A5148;
extern f32 D_800AB364;
extern Block800511B0 D_80118DE0;
extern Vec3f800511B0 D_80118E10[];
extern f32 D_80118E18;
extern Vec3f800511B0 D_80118ED0[];

extern void func_80015288(Vec3f800511B0 *output, const Vec3f800511B0 *source);
extern void func_80015328(Vec3f800511B0 *output, const Vec3f800511B0 *left,
                          const Vec3f800511B0 *right);
extern void func_8001535C(Vec3f800511B0 *output, const Vec3f800511B0 *left,
                          const Vec3f800511B0 *right);
extern void func_800155EC(Vec3f800511B0 *output, const Vec3f800511B0 *base,
                          f32 scale, const Vec3f800511B0 *offset);
extern void func_80015630(Vec3f800511B0 *output, f32 first_scale,
                          const Vec3f800511B0 *second, f32 second_scale,
                          const Vec3f800511B0 *first);
extern f32 func_80051934(void);
extern s32 func_80082BE0(void);

void func_800511B0(Owner800511B0 *owner, s32 mode) {
    Vec3f800511B0 delta;
    Vec3f800511B0 step;
    f32 pick;

    if (mode != 0) {
        if (D_800A2198 != -1) {
            func_8001535C(&delta, D_80118ED0, D_80118E10);
            func_800155EC(D_80118ED0, D_80118ED0, 10.0f, &delta);
        }
        func_80015630(D_80118E10, 0.3333f, D_80118E10, 0.6667f, D_80118ED0);
        if (owner->unk34 == 1) {
            func_80015288(D_80118E10, &D_800A5148);
            pick = func_80051934();
            D_80118DE0.unk30 = D_80118DE0.unk30 +
                (180.0f + 10.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) * pick;
            D_80118DE0.unk34 = D_80118DE0.unk34 +
                (D_800AB364 + 125.0f * ((f32)func_80082BE0() / (f32)2147483648.0));
            D_80118E18 = ((f32)func_80082BE0() / (f32)2147483648.0) * 30.0f + 40.0f;
            func_80015288(D_80118ED0, &D_800A5148);
            func_8001535C(&step, D_80118ED0, D_80118E10);
            func_80015328(D_80118ED0, D_80118ED0, &step);
        }
    } else {
        func_80015288(D_80118ED0, &D_800A4C00[owner->unk34].unk0C);
        func_80015288(D_80118E10, &D_800A4C00[owner->unk34].unk00);
    }
    D_800A4BC0 = 1;
    D_800A4BD0 = 1;
}
