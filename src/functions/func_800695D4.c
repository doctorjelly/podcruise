/* spec: specs/func_800695D4.md */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    f32 unk34;
    u8 pad38[0x194 - 0x38];
    f32 unk194;
    f32 unk198;
    f32 unk19C;
    u8 pad1A0[0x1C4 - 0x1A0];
    Vec3 unk1C4;
    u8 pad1D0[0x1F8 - 0x1D0];
    f32 unk1F8;
} Obj;

extern f32 func_80014D4C(f32);
extern void func_80015268(Vec3 *, f32, f32, f32);
extern void func_80015288(Vec3 *, Vec3 *);
extern f32 func_800153C0(Vec3 *);
extern f32 func_800154D0(Vec3 *);
extern void func_80015538(Vec3 *, Vec3 *, Vec3 *);
extern void func_800155C0(Vec3 *, f32, Vec3 *);
extern void func_800155EC(Vec3 *, Vec3 *, f32, Vec3 *);

extern f64 D_800AD540;
extern f64 D_800AD548;
extern f32 D_800AD550;
extern f32 D_800AD554;
extern f32 D_800AD558;
extern f32 D_800AD55C;
extern f32 D_800AD560;
extern f32 D_8011C854;
extern f64 D_80120BF0;

void func_800695D4(Obj *obj, f32 arg1, f32 arg2, f32 arg3, Vec3 *arg4, Vec3 *arg5, Vec3 *arg6) {
    Vec3 sp88[2];
    f32 dead1;
    f32 v;
    f32 dead2[6];
    Vec3 vec[2];
    f32 t;
    f32 ret;
    f32 d;
    f32 f;
    f32 q;

    (void)arg1;
    (void)arg2;
    (void)dead1;
    (void)dead2;
    (void)q;

    d = obj->unk19C * arg4->z + (arg4->x * obj->unk194 + arg4->y * obj->unk198);
    if ((f64)d < D_800AD540 || (f64)d > D_800AD548) {
        func_80015268(arg5, 0.0f, 0.0f, 0.0f);
        func_800155C0(&obj->unk1C4, 0.9f, &obj->unk1C4);
        func_80015288(arg6, &obj->unk1C4);
        obj->unk1F8 = 0.0f;
    } else {
        func_80015538(&sp88[1], arg4, (Vec3 *)&obj->unk194);
        func_80015538(arg5, arg4, &sp88[1]);
        func_800154D0(arg5);
        v = obj->unk19C * arg5->z + (arg5->x * obj->unk194 + arg5->y * obj->unk198);
        D_8011C854 = func_80014D4C(v);
        if (50.0f < arg3) {
            v = 0.0f;
        } else {
            v = (1.0f - arg3 / 50.0f) * v;
        }
        t = v * v * 400.0f;
        func_800155C0(&sp88[0], -t, arg5);
        func_800155EC(arg6, &obj->unk1C4, (f32)D_80120BF0 * (f32)2.0, &sp88[0]);
        ret = func_800153C0(arg6);
        if (ret < 0.0f) {
            f = -ret;
        } else {
            f = ret;
        }
        if (t < 0.0f) {
            d = -t;
        } else {
            d = t;
        }
        if (d < f) {
            ret = t / ret;
            if (ret < 0.0f) {
                d = -ret;
            } else {
                d = ret;
            }
            func_800155C0(arg6, d, arg6);
        }
        func_80015288(&obj->unk1C4, arg6);
        vec[0].x = arg5->x;
        vec[0].y = arg5->y;
        vec[0].z = 0.0f;
        vec[1].x = obj->unk30;
        vec[1].y = obj->unk34;
        vec[1].z = 0.0f;
        if (func_800154D0(&vec[0]) < D_800AD550) {
            vec[0].x = -arg4->x;
            vec[0].y = -arg4->y;
            vec[0].z = -arg4->z;
        }
        func_800154D0(&vec[1]);
        d = vec[0].x * vec[1].x + vec[0].y * vec[1].y + vec[0].z * vec[1].z;
        if (d < 0.0f) {
            f = 0.0f;
        } else {
            if (D_800AD554 < d) {
                d = ((1.0f - d) / D_800AD558) * D_800AD554;
            }
            if (vec[1].x * vec[0].y < vec[0].x * vec[1].y) {
                f = ((vec[0].x * arg5->x + vec[0].y * arg5->y + arg5->z * vec[0].z) * d) / 0.5f;
            } else {
                f = -((vec[0].x * arg5->x + vec[0].y * arg5->y + arg5->z * vec[0].z) * d) / 0.5f;
            }
        }
        v = v + D_800AD55C;
        if (0.0f <= v) {
            obj->unk1F8 = 0.0f;
        } else {
            v = v / D_800AD560;
            obj->unk1F8 = f * (v * v) * 600.0f;
        }
    }
}
