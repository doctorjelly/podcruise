/* Recovered per specs/func_80081360.md (frame timing accumulator update). */
#include "podcruise/types.h"

extern s32 D_800A6758;
extern f64 D_800A6750;
extern u64 D_800A26A0;
extern u64 D_800A26A8;
extern u64 D_800A26B0;
extern f64 D_80120BF0;
extern volatile f32 D_80120BF8;
extern volatile f64 D_80120C00;
extern f64 D_80120C20;
extern volatile s32 D_80120BE8;

extern void func_80081260(void);
extern u64 func_800811DC(void);
extern f64 func_8008126C(void);
extern u64 func_8008AB48(u64, u64);
extern u64 func_8008AC48(u64, u64);

void func_80081360(void) {
    f64 prev;
    u64 ticks;

    if (D_800A6758) {
        func_80081260();
        ticks = func_8008AB48(func_8008AC48(func_800811DC(), 64), 3000);
        D_800A26B0 = D_800A26A8 = D_800A26A0 = ticks;
        D_80120C20 = func_8008126C();
        D_80120BF0 = 0.002;
        D_80120C00 = D_80120C20;
        D_800A6758 = 0;
    } else if (D_800A6750 <= 0.0) {
        prev = D_80120C20 = func_8008126C();
        D_80120BF0 = D_80120C20 - D_80120C00;
        D_80120BF8 = (f32)D_80120BF0;
        if (D_80120BF8 < 0.002f) {
            D_80120BF8 = 0.002;
        }
        if (0.05f < D_80120BF8) {
            D_80120BF8 = 0.05;
        }
        D_80120C00 = prev;
    } else {
        D_80120C00 = D_80120C20;
        D_80120BF0 = D_800A6750;
        D_80120C20 = D_80120C20 + D_800A6750;
    }
    D_80120BE8 = D_80120BE8 + 1;
}
