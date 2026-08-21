/* Independently written from $S/specs/func_8005058C.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 D_80118D60[4][4];
extern Vec3f D_80118D90;
extern f32 D_80118DA0[4][4];
extern void *D_80118E10;
extern f32 D_80118E20[4][4];
extern Vec3f D_80118E50;
extern f32 D_80118E60[4][4];
extern void *D_80118ED0;
extern s16 D_800A4BC0;

extern void func_80015288(void *destination, void *source);
extern void func_80015328(void *output, void *left, Vec3f *right);
extern void func_8001535C(Vec3f *output, Vec3f *left, Vec3f *right);
extern void func_800156DC(f32 output[4][4], f32 source[4][4]);

void func_8005058C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    Vec3f offset;

    if (arg4 == 0) {
        func_800156DC(D_80118E60, D_80118E20);
        func_800156DC(D_80118DA0, D_80118D60);
    }

    func_80015288(&D_80118E10, arg0);
    func_80015288(&D_80118ED0, arg1);

    D_800A4BC0 = arg2;
    if (D_800A4BC0 == 3) {
        if (arg3 != 0) {
            func_8001535C(&offset, &D_80118D90, &D_80118E50);
            func_80015328(&D_80118E10, &D_80118ED0, &offset);
        }
    }
}
