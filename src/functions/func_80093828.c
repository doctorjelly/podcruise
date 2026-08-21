/* Specification: specs/func_80093828.md (entry corrected to 0x80093820) */
#include "podcruise/types.h"

extern s32 D_800A7FB0;
extern u8 D_8014C4D8[];

extern void func_800937D0(void);
extern void func_80087E80(void *, void *, s32);

void func_80093820(void) {
    s32 status;

    if (D_800A7FB0 == 0) {
        func_800937D0();
    }
    func_80087E80(D_8014C4D8, &status, 1);
}
