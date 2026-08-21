#include "podcruise/types.h"

extern s32 D_800A267C;
extern s32 D_800A2680;
extern s32 D_800A2670;
extern s32 D_800A2674;
extern void func_8002DFB0(s32 code, s32 arg);
extern void func_8002E028(void);
extern void func_8002E548(void);

void func_8002E6E0(void) {
    D_800A2680 = 0;
    if (D_800A267C != 0) {
        D_800A267C = 0;
        func_8002DFB0(0x1159, 0);
        func_8002E548();
    } else {
        func_8002DFB0(0x115A, 0);
        if (D_800A2670 == 0) {
            func_8002DFB0(0x115B, 0);
            D_800A2670 = 1;
            D_800A2674 = 0;
            func_8002E028();
        }
    }
}
