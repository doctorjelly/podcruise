/* See specs/func_80027A0C.md (worker specification): intro sequence step. */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0xEC];
    void *unkEC;
} Obj80027A0C;

extern s32 D_800A4BBC;
extern s32 D_800A2198;
extern s32 D_800A4BA4;
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern f32 D_800D7148;
extern s32 D_800D714C;
extern f32 D_800D7150[];
extern f32 D_800D715C[];
extern f32 D_80118D60[];
extern f32 D_80118D90[];
extern f32 D_80118DD0[];
extern f32 D_80118DE0[];
extern f32 D_80118E10[];
extern f32 D_80118E50[];
extern f32 D_80118E58;
extern f32 D_80118E90[];
extern f32 D_80118ED0[];
extern Obj80027A0C *D_8011A544;
extern void *D_8011A5D8;
extern f32 D_80120BF8;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_800174B8(f32 *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80018480(void *, f32 *, s32, f32, f32, f32, f32, s32, f32, f32);
extern void func_80033590(void *, f32 *);

void func_80027A0C(s32 arg0) {
    f32 start;
    f32 matrix[16];

    (void)arg0;
    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        start = 12.0f;
        D_800D7148 = start;
        D_800D714C = 0;
        func_80015268(D_800D7150, 0, start * 100.0f, 50.0f);
        func_80015268(D_800D715C, 0.0f, 0.0f, 0);
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
        func_80018480(D_8011A544, matrix, 0, 70.0f, 70.0f, 70.0f, -157.0f, 1, 0.0f, 0.0f);
        if (D_8011A544->unkEC != 0) {
            func_800181BC(D_8011A544->unkEC, 2, 3, 0x10, 2);
        }
    }

    if (D_800A4BDC != -1) {
        if (0 <= D_800D7148) {
            D_800D7148 -= D_80120BF8;
            if (D_800D7148 <= 0) {
                D_800A4BDC = -1;
                D_800A2198 = 5;
                return;
            }
        }
        if ((D_800A4BA4 & 1) || (D_800A4BA4 & 2)) {
            D_800D7148 = 0;
            D_800A4BDC = -1;
            D_800A2198 = 5;
        }
    }
}
