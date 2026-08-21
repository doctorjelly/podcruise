/* Independently written from scratchpad spec specs/func_800509E8.md. */

#include "podcruise/types.h"

typedef struct Vec3f800509E8 {
    f32 x;
    f32 y;
    f32 z;
} Vec3f800509E8;

typedef struct Obj800509E8 {
    u8 unk00[0x8];
    s32 unk08;
    u8 unk0C[0x34 - 0xC];
    s32 unk34;
    s32 unk38;
} Obj800509E8;

extern s32 D_800A2198;
extern s16 D_800A219C;
extern s16 D_800A4BC0;
extern s32 D_800A4BC4;
extern s32 D_800A4BD0;
extern s32 D_800A4BDC;
extern u8 D_800A4BF8;
extern f32 D_800A5260;
extern f32 D_800A5264;
extern Vec3f800509E8 D_800A5268;
extern f32 D_80118D60[4][4];
extern Vec3f800509E8 D_80118D90;
extern f32 D_80118DA0[4][4];
extern f32 D_80118DD0[4][4];
extern Vec3f800509E8 D_80118E10;
extern f32 D_80118E20[4][4];
extern Vec3f800509E8 D_80118E50;
extern f32 D_80118E60[4][4];
extern f32 D_80118E90[4][4];
extern Vec3f800509E8 D_80118ED0;

extern u8 func_800152CC(const Vec3f800509E8 *left, const Vec3f800509E8 *right);
extern void func_80015288(Vec3f800509E8 *output, const Vec3f800509E8 *source);
extern void func_8001535C(Vec3f800509E8 *output, const Vec3f800509E8 *left, const Vec3f800509E8 *right);
extern f32 func_800153C0(const Vec3f800509E8 *vector);
extern f32 func_800154D0(Vec3f800509E8 *vector);
extern void func_800155EC(Vec3f800509E8 *output, const Vec3f800509E8 *base, f32 scale, const Vec3f800509E8 *offset);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern s32 func_80050C00(Obj800509E8 *object, f32 *value, const Vec3f800509E8 *from, const Vec3f800509E8 *to, f32 matrix[4][4], f32 scale);
extern void func_800469B4(Obj800509E8 *object);

void func_800509E8(Obj800509E8 *arg0) {
    s32 mode;
    s32 first;
    s32 second;
    s32 flag;
    f32 pad1[4];
    Vec3f800509E8 delta;
    Vec3f800509E8 pad2;

    (void)pad1;
    (void)pad2;
    if (func_800152CC(&D_800A5268, &D_80118ED0) == 0) {
        func_80015288(&D_800A5268, &D_80118ED0);
        func_8001535C(&delta, &D_80118E50, &D_80118D90);
        if (func_800153C0(&delta) > 500.0f) {
            func_800154D0(&delta);
            func_800155EC(&D_80118E50, &D_80118D90, 500.0f, &delta);
        }
    }

    first = func_80050C00(arg0, &D_800A5264, &D_80118ED0, &D_80118E50, D_80118E90, 1.5f);
    second = func_80050C00(arg0, &D_800A5260, &D_80118E10, &D_80118D90, D_80118DD0, 1.0f);
    if ((second != 0) && (first != 0)) {
        D_800A4BC0 = 5;
        D_800A4BF8 = 1;
        if (arg0->unk08 == 8) {
            D_800A4BC0 = 0;
        }
        if (D_800A4BD0 != 0) {
            D_800A4BD0 = 0;
            flag = D_800A4BC4;
            D_800A4BC4 = (flag == 0);
            if (arg0->unk38 == 1) {
                if (arg0->unk34 != 3) {
                    if (D_800A4BC4 != 0) {
                        D_800A219C = 1;
                    }
                }
            }
        }
        func_800156DC(D_80118E60, D_80118E20);
        func_800156DC(D_80118DA0, D_80118D60);
        mode = D_800A2198;
        if (mode != -1) {
            if (D_800A219C == 0) {
                D_800A4BC4 = 0;
                if (D_800A4BDC == 0) {
                    func_800469B4(arg0);
                }
            }
        }
    }
}
