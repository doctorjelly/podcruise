/* Implements specs/functions/recovered/late_mismatch_audit_tranche.md. */

#include "podcruise/types.h"

extern s32 D_800A6758;
extern f64 D_800A6750;
extern u64 D_800A26A0;
extern u64 D_800A26A8;
extern u64 D_800A26B0;
extern f64 D_800ADC90;
extern f32 D_800ADC98;
extern f32 D_800ADC9C;
extern f32 D_800ADCA0;
extern f32 D_800ADCA4;
extern s32 D_80120BE8[1];
extern f64 D_80120BF0[1];
extern f32 D_80120BF8[1];
extern f64 D_80120C00[1];
extern f64 D_80120C20[1];

extern void func_80081260(void);
extern u64 func_800811DC(void);
extern f64 func_8008126C(void);

void func_80081360(void) {
    u64 microseconds;
    f64 now;
    f64 delta;

    if (D_800A6758 != 0) {
        func_80081260();
        microseconds = (func_800811DC() * 64) / 3000;
        D_800A26B0 = D_800A26A8 = D_800A26A0 = microseconds;
        now = func_8008126C();
        D_80120C20[0] = now;
        D_80120C00[0] = now;
        D_80120BF0[0] = D_800ADC90;
        D_800A6758 = 0;
    } else if (D_800A6750 <= 0.0) {
        now = func_8008126C();
        delta = now - D_80120C00[0];
        D_80120C20[0] = now;
        D_80120BF0[0] = delta;
        D_80120BF8[0] = (f32)delta;
        if (D_80120BF8[0] < D_800ADC98) {
            D_80120BF8[0] = D_800ADC9C;
        }
        if (D_800ADCA0 < D_80120BF8[0]) {
            D_80120BF8[0] = D_800ADCA4;
        }
        D_80120C00[0] = now;
    } else {
        D_80120BF0[0] = D_800A6750;
        D_80120C00[0] = D_80120C20[0];
        D_80120C20[0] = D_80120C20[0] + D_800A6750;
    }
    D_80120BE8[0] = D_80120BE8[0] + 1;
}
