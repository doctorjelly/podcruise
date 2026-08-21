/* Specification: specs/func_80085E20.md (worker scratchpad) */
#include "podcruise/types.h"

extern s32 D_800A268C;
extern s32 D_800A2690;
extern s32 D_800A6780;
extern s32 D_800A68A0;
extern s32 D_80118950;

extern void func_8002DFBC(void);
extern void func_8002E034(void);

void func_80085E20(void) {
    if (D_800A268C != 0 || D_800A2690 != 0) {
        D_80118950 = 1;
    } else {
        D_80118950 = 0;
    }
    if (D_800A6780 == 0) {
        func_8002DFBC();
        D_800A6780 = 1;
    }
    if (D_800A68A0 == 0) {
        func_8002E034();
        D_800A68A0 = 1;
    }
}
