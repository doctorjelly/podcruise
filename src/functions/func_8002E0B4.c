/* Independently written from the combined 0x8002E0B4 boundary evidence. */

#include "podcruise/runtime_leaves.h"

extern u8 D_800A26D0;
extern s32 D_800A26B8;
extern void func_80087E80(void *first, void *second, s32 mode);
extern void func_80089C34(void *value);
extern void func_800316A8(void);
extern void func_80089BB0(void *value);
extern void *D_800D9C28;
extern void *D_800D74C0;

void func_8002E0B4(void) {
    if (D_800A26D0 & 1) {
        if (D_800A26B8 == 0) {
            func_80087E80(&D_800D9C28, 0, 1);
            func_80089C34(&D_800D74C0);
        }
        func_800316A8();
        func_80089BB0(&D_800D9C28);
        D_800A26B8 = 0;
    }
}
