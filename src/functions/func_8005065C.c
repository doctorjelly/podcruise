/* Independently written from specs/functions/recovered/medium_resource_tranche.md. */

#include "podcruise/types.h"

typedef struct Vec3f8005065C {
    f32 x;
    f32 y;
    f32 z;
} Vec3f8005065C;

typedef struct Obj8005065C {
    u8 unk00[0x8];
    s32 unk08;
    u8 unk0C[0x34 - 0xC];
    s32 unk34;
    s32 unk38;
} Obj8005065C;

extern s32 D_800A2198;
extern s16 D_800A219C;
extern s16 D_800A4BC0;
extern s32 D_800A4BC4;
extern s32 D_800A4BD0;
extern s32 D_800A4BD4;
extern f32 D_800AB350;
extern f32 D_80118D60[4][4];
extern Vec3f8005065C D_80118D90;
extern f32 D_80118DA0[4][4];
extern f32 D_80118DE0[4][4];
extern f32 D_80118E20[4][4];
extern Vec3f8005065C D_80118E50;
extern f32 D_80118E60[4][4];
extern f32 D_80118E90;
extern f32 D_80118E94;
extern f32 D_80118E98;
extern f32 D_80118EA0[4][4];
extern f32 D_80118ED0;
extern f32 D_80118ED4;
extern f32 D_80118ED8;
extern f32 D_8011AC24;
extern f32 D_8011AC28;
extern f32 D_8011AC2C;
extern f32 D_8011AC30;
extern f32 D_8011AC34;
extern f32 D_8011AC38;
extern f32 D_8011AC3C;
extern f32 D_8011AC40;
extern f32 D_80120BF8;

extern void func_80015288(Vec3f8005065C *output, const Vec3f8005065C *source);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);

void func_8005065C(Obj8005065C *arg0) {
    Vec3f8005065C first;
    Vec3f8005065C second;
    f32 dy;
    f32 dz;
    f32 fraction;
    f32 dx;
    s32 flag;

    func_80015288(&first, &D_80118D90);
    func_80015288(&second, &D_80118E50);

    if (D_800A4BD4 != 0) {
        dx = D_80118EA0[3][0] - D_80118E90;
        D_8011AC24 = dx;
        D_8011AC28 = D_80118EA0[3][1] - D_80118E94;
        D_8011AC2C = D_80118EA0[3][2] - D_80118E98;
        D_8011AC30 = D_80118DE0[3][0] - D_80118DA0[3][0];
        D_8011AC34 = D_80118DE0[3][1] - D_80118DA0[3][1];
        D_8011AC38 = D_80118DE0[3][2] - D_80118DA0[3][2];
        D_8011AC3C = 0.0f;
        D_8011AC40 = 0.5f;
        if (dx < 500.0f) {
            D_8011AC24 = dx;
            if (dx > -500.0f) {
                if (D_8011AC28 < 500.0f) {
                    if (D_8011AC28 > -500.0f) {
                        if (arg0->unk38 == 1) {
                            D_8011AC40 = D_800AB350;
                        }
                    }
                }
            }
        }
        D_800A4BD4 = 0;
    }

    if (D_8011AC3C < D_8011AC40) {
        D_8011AC3C = D_8011AC3C + D_80120BF8;
        dy = D_80118ED4 - D_80118E94;
        dz = D_80118ED8 - D_80118E98;
        if (D_8011AC40 < D_8011AC3C) {
            D_8011AC3C = D_8011AC40;
        }
        fraction = D_8011AC3C / D_8011AC40;
        D_80118E20[3][0] = (D_80118ED0 - D_80118E90) * fraction + D_80118E90;
        D_80118E20[3][1] = dy * fraction + D_80118E94;
        D_80118E20[3][2] = dz * fraction + D_80118E98;
        if (D_800A4BC0 != 3) {
            D_80118D60[3][0] = (D_80118DE0[3][0] - D_80118DA0[3][0]) * fraction + D_80118DA0[3][0];
            D_80118D60[3][1] = (D_80118DE0[3][1] - D_80118DA0[3][1]) * fraction + D_80118DA0[3][1];
            D_80118D60[3][2] = (D_80118DE0[3][2] - D_80118DA0[3][2]) * fraction + D_80118DA0[3][2];
        }
    } else {
        D_800A4BC0 = 5;
        if (arg0->unk08 == 8) {
            D_800A4BC0 = 0;
        }
        D_800A4BD4 = 1;
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
        if (D_800A2198 != -1) {
            if (D_800A219C == 0) {
                D_800A4BC4 = 0;
            }
        }
    }
}
