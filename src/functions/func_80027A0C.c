/* Independently written from $S/specs/func_80027A0C.md */

#include "podcruise/types.h"

extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *output, f32 *source);
extern void func_80033590(void *node, f32 *output);
extern void func_80008B14(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80018480(void *object, f32 *source, s32 scaleByType, f32 scaleX,
                          f32 scaleY, f32 scaleZ, f32 depth, s32 animate,
                          f32 requestX, f32 requestY);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);

extern s32 D_800A2198;
extern s32 D_800A4BA4;
extern s32 D_800A4BBC[];
extern s16 D_800A4BC0;
extern s32 D_800A4BDC[];
extern f32 D_800D7148;
extern s32 D_800D714C;
extern f32 D_800D7150[6];
extern f32 D_80118D60[16];
extern f32 D_80118D90[3];
extern f32 D_80118DD0[3];
extern f32 D_80118DE0[16];
extern f32 D_80118E10[3];
extern f32 D_80118E50[3];
extern f32 D_80118E58;
extern f32 D_80118E90[3];
extern f32 D_80118ED0[3];
extern void *D_8011A544;
extern void *D_8011A5D8;
extern f32 D_80120BF8;

void func_80027A0C(s32 arg0) {
    f32 matrix[16];
    f32 timer;

    if (D_800A4BBC[0] != 0) {
        D_800A4BBC[0] = 0;
        timer = 12.0f;
        D_800D7148 = timer;
        D_800D714C = 0;
        func_80015268(D_800D7150, 0, timer * 100.0f, 50.0f);
        func_80015268(&D_800D7150[3], 0.0f, 0.0f, 0);
        func_80033590(D_8011A5D8, D_80118E50);
        D_80118E58 = -97.0f;
        func_80015288(D_80118D90, D_80118E50);
        D_80118D60[13] += 500.0f;
        func_80008B14(0x99, 7, 0.25f, 0.8f, 0);
    }

    if (D_800D7148 <= 10.0) {
        if (D_800D714C == 0) {
            D_800D714C = 1;
            func_80015288(D_80118E90, D_80118E50);
            func_80015268(D_80118ED0, 0.0f, 0.0f, 0.0f);
            func_80015288(D_80118DD0, D_80118D90);
            func_80015288(D_80118E10, D_80118D90);
            D_80118DE0[12] += 500.0f;
            D_800A4BC0 = 1;
        }
    }

    D_800D7150[1] -= 100.0f * D_80120BF8;

    if (D_8011A544 != 0) {
        func_800174B8(matrix, D_800D7150);
        func_80018480(D_8011A544, matrix, 0, 70.0f, 70.0f, 70.0f, -157.0f, 1,
                      0.0f, 0.0f);
        if (*(void **)((u8 *)D_8011A544 + 0xEC) != 0) {
            func_800181BC(*(void **)((u8 *)D_8011A544 + 0xEC), 2, 3, 0x10, 2);
        }
    }

    if (D_800A4BDC[0] != -1) {
        if (0 <= D_800D7148) {
            D_800D7148 -= D_80120BF8;
            if (D_800D7148 <= 0) {
                D_800A4BDC[0] = -1;
                D_800A2198 = 5;
                return;
            }
        }
        if ((D_800A4BA4 & 1) || (D_800A4BA4 & 2)) {
            D_800D7148 = 0;
            D_800A4BDC[0] = -1;
            D_800A2198 = 5;
        }
    }
    (void)arg0;
}
