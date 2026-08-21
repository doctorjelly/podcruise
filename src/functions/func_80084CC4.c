/* Specification: $S/specs/func_80084CC4.md */
#include "podcruise/types.h"

extern s32 D_800A40F0;
extern s32 D_800A68AC;
extern u8 D_800D9DB0;
extern u8 D_800D9DB1;
extern void func_80039CD8(s32);
extern void func_8008A360(s32);

void func_80084CC4(void) {
    func_8008A360(D_800A68AC);
    D_800D9DB0 = D_800D9DB0 + 1;
    if (D_800D9DB0 >= 3) {
        D_800D9DB0 = 0;
    }
    D_800D9DB1 = 1 - D_800D9DB1;
    if (D_800A40F0 != 0) {
        func_80039CD8(0);
        D_800A40F0 = 0;
    }
}
