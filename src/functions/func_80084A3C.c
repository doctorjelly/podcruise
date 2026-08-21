/* Specification: specs/func_80084A3C.md (worker-authored) */
#include "podcruise/types.h"

extern s32 D_800A6894;
extern s32 D_800A6898;
extern f32 D_800ADD38;
extern f32 D_80120D80[3];
extern f32 D_80120D90[3];
extern s32 D_80120D9C;

extern void func_800845A0(s32 arg0, s32 arg1, f32 (*arg2)[4], s32 arg3, s32 arg4,
                          f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg8);

void func_80084A3C(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6) {
    f32 mtx[4][4];
    f32 fov;
    f32 eye[3];
    f32 up[3];

    D_800A6898 = 0;
    D_80120D9C = arg4;
    if (arg3 > 20) {
        arg3 = 20;
    }
    D_800A6894 = arg3;

    eye[0] = arg2[0];
    eye[1] = arg2[1];
    eye[2] = arg2[2];
    up[1] = 0.0;
    up[0] = 0.0;
    up[2] = 1.0;

    D_80120D80[0] = eye[0]; D_80120D80[1] = eye[1]; D_80120D80[2] = eye[2];
    D_80120D90[0] = up[0]; D_80120D90[1] = up[1]; D_80120D90[2] = up[2];

    fov = D_800ADD38;
    mtx[3][3] = 1.0f;
    mtx[3][2] = 0.0f;
    mtx[3][1] = 0.0f;
    mtx[3][0] = 0.0f;
    mtx[2][3] = 0.0f;
    mtx[2][2] = 1.0f;
    mtx[2][1] = 0.0f;
    mtx[2][0] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[1][2] = 0.0f;
    mtx[1][1] = 1.0f;
    mtx[1][0] = 0.0f;
    mtx[0][3] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[0][1] = 0.0f;
    mtx[0][0] = 1.0f;

    func_800845A0(arg1, arg0, mtx, 0, 0, &fov, arg2, eye, up);

    arg5[0] = D_80120D80[0];
    arg5[1] = D_80120D80[1];
    arg5[2] = D_80120D80[2];
    arg6[0] = D_80120D90[0];
    arg6[1] = D_80120D90[1];
    arg6[2] = D_80120D90[2];
}
