/* Specification: scratchpad/specs/func_8002E134.md (entry corrected to 0x8002E124) */
#include "podcruise/types.h"
extern u64 D_800A26A0;
extern u64 D_800A26A8;
extern u64 D_800A26B0;
extern s32 D_800A26BC;
extern u64 func_800811DC(void);
extern u64 func_8008AC48(u64, u64);
extern u64 func_8008AB48(u64, u64);
extern s32 func_8008ADA0(void);
extern void func_800073A4(void);
extern void func_8002E0B4(void);

void func_8002E124(void) {
    u64 now;
    u64 tmp;

    D_800A26A8 = D_800A26A0;
    now = func_8008AB48(func_8008AC48(func_800811DC(), 0x40), 0xBB8);
    D_800A26A0 = now;
    tmp = D_800A26A8;
    if (now < tmp) {
        now = tmp;
        D_800A26A0 = now;
    }
    tmp = D_800A26B0;
    if (tmp == 0) {
        D_800A26B0 = now + 0xBEB6;
        tmp = D_800A26B0;
    }
    if (now > tmp) {
        if (now - tmp > 0xBEB6) {
            D_800A26BC++;
        }
        if (func_8008ADA0() < 0) {
            D_800A26B0 += 0x5F5B;
        } else {
            func_800073A4();
            func_8002E0B4();
            D_800A26B0 += 0xBEB6;
        }
    }
}
