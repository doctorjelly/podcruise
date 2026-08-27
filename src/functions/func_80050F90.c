/* Recovered from specification specs/func_80050F90.md (worker unc_12). */
#include "podcruise/types.h"

extern s32 D_800A21A4;
extern s16 D_800A4BC0;
extern f32 D_800A5278;
extern f32 D_800A527C[3];
extern f32 D_800A5288[3];
extern u8 D_800A4BF8;
extern u8 D_800A5294;
extern f32 D_80120BF8;
extern f32 D_80118D60[4][4];
extern f32 D_80118D90[3];
extern f32 D_80118DE0[4][4];
extern f32 D_80118E10[3];
extern f32 D_80118E20[4][4];
extern f32 D_80118EA0[4][4];
extern f32 D_80118ED0[3];

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern u8 func_800152CC(f32 *, f32 *);
extern void func_80014CC0(f32, f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80028D60(void);
extern s32 func_80082BE0(void);

void func_80050F90(s32 *arg0) {
    f32 sp34;
    f32 sp30;
    f32 sp24[3];
    f32 sp18[3];

    if (D_800A21A4 != 0) {
        D_800A4BC0 = 0;
        func_80015268(D_800A527C, 0.0f, 0.0f, 0.0f);
        return;
    }
    if (arg0[2] == 8) {
        D_800A4BC0 = 0;
        return;
    }
    func_80015288(sp18, D_80118D90);
    D_800A5278 += 40.0f * D_80120BF8;
    if (D_800A5278 > 360.0f) {
        D_800A5278 -= 360.0f;
    }
    if (D_800A4BF8 != 0 || D_800A5294 != 5 ||
        !func_800152CC(D_800A527C, D_80118E10) ||
        !func_800152CC(D_800A5288, D_80118ED0)) {
        D_800A4BF8 = 0;
        func_80028D60();
        func_800156DC(D_80118DE0, D_80118D60);
        func_800156DC(D_80118EA0, D_80118E20);
        func_80015288(D_800A527C, D_80118E10);
        func_80015288(D_800A5288, D_80118ED0);
        D_800A5294 = 5;
        D_800A5278 = (f32)(s32)((f32)func_80082BE0() / 2147483648.0f * (f32)2.0) * 180.0f;
    }
    func_80014CC0(D_800A5278, &sp34, &sp30);
    func_80015288(sp24, D_800A527C);
    func_800155EC(sp24, sp24, 8.0f * sp34, &D_80118DE0[0][0]);
    func_80015288(D_80118D90, sp24);
}
