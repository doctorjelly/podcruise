/* Behavior-recovered from the USA runtime-state body. */

#include "podcruise/runtime_leaves.h"

extern s32 D_800A2680;
extern s32 D_800A2670;
extern s32 D_800A2674;
extern s32 D_801488C0;
extern void func_8002E124(void);
extern void func_8002E2FC(void);
extern void func_80088AD0(void);
extern void func_8008AFBC(s32 value);
extern void func_8008B14C(s32 value);

void func_8002E548(void) {
    while (D_800A2680 != 0) {
        func_8002E124();
        func_8002E2FC();
    }
    D_800A2670 = 0;
    D_800A2674 = 1;
    func_80088AD0();
    func_8008AFBC(D_801488C0);
    func_8008B14C(D_801488C0);
    func_8002DFB0(1, 0);
}
