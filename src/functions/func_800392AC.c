/* Specification: specs/func_800392AC.md (entry corrected to 0x800392A4) */
#include "podcruise/types.h"

extern s32 D_800A26B8;
extern u8 D_800D9C28[];
extern u8 D_800D74C0[];

extern void func_80087E80(void *, void *, s32);
extern void func_80089C34(void *);

void func_800392A4(void) {
    if (D_800A26B8 == 0) {
        func_80087E80(D_800D9C28, 0, 1);
        func_80089C34(D_800D74C0);
    }
}
