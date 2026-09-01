/* Implements the specification in specs/func_80081360.md (frame timer advance). */
#include "podcruise/types.h"

extern s32 D_800A6758;
extern f64 D_800A6750;
extern s64 D_800A26A0;
extern s64 D_800A26A8;
extern s64 D_800A26B0;
extern volatile f64 D_80120BF0[];
extern volatile f32 D_80120BF8[];
extern volatile f64 D_80120C00[];
extern volatile f64 D_80120C20[];
extern volatile s32 D_80120BE8[];

extern void func_80081260(void);
extern s64 func_800811DC(void);
extern s64 func_8008AC48(s64, s64);
extern s64 func_8008AB48(s64, s64);
extern f64 func_8008126C(void);

void func_80081360(void) {
    f64 now;
    f64 diff;

    if (D_800A6758 != 0) {
        func_80081260();
        D_800A26B0 = D_800A26A8 = D_800A26A0 =
            func_8008AB48(func_8008AC48(func_800811DC(), 64), 3000);
        now = func_8008126C();
        D_80120C20[0] = now;
        D_80120C00[0] = now;
        D_80120BF0[0] = 0.002;
        D_800A6758 = 0;
    } else if (D_800A6750 <= 0.0) {
        now = func_8008126C();
        diff = now - D_80120C00[0];
        D_80120C20[0] = now;
        D_80120BF0[0] = diff;
        D_80120BF8[0] = (f32)diff;
        if (D_80120BF8[0] < 0.002f) {
            D_80120BF8[0] = 0.002;
        }
        if (0.05f < D_80120BF8[0]) {
            D_80120BF8[0] = 0.05;
        }
        D_80120C00[0] = now;
    } else {
        now = D_80120C20[0];
        D_80120BF0[0] = D_800A6750;
        D_80120C20[0] = now + D_800A6750;
        D_80120C00[0] = now;
    }
    D_80120BE8[0] = D_80120BE8[0] + 1;
}
