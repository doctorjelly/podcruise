/* Independently written from scratchpad spec specs/func_800812E8.md. */
#include "podcruise/types.h"
extern f64 D_800A6750;
extern f64 D_800ADC88;
extern s32 D_80120BE8;
extern f64 D_80120BF0;
extern f64 D_80120C00;
extern f64 D_80120C20;
extern f64 func_8008126C(void);

void func_800812E8(void) {
    if (D_800A6750 <= 0.0) {
        D_80120BF0 = D_800ADC88;
        D_80120C20 = func_8008126C();
        D_80120C00 = D_80120C20 - D_80120BF0;
    } else {
        D_80120BF0 = D_800A6750;
    }
    D_80120BE8 = 0;
}
