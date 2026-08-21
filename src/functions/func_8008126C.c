/* Recovered per specification specs/func_8008126C.md. */
#include "podcruise/types.h"
extern f32 D_800ADC80;
extern u64 D_80120BE0;
extern f64 D_80120C08;

extern u64 func_800811DC(void);
extern u64 func_8008AB48(u64, u64);
extern u64 func_8008AC48(u64, u64);
extern f32 func_8008C738(u64);

void func_8008126C(void) {
    D_80120BE0 = func_800811DC();
    D_80120C08 = func_8008C738(func_8008AB48(func_8008AC48(D_80120BE0, 0x40), 0xBB8)) / D_800ADC80;
}
