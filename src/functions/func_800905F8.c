/* Specification: specs/func_800905F8.md (entry corrected to 0x800905F0) */
#include "podcruise/types.h"

extern s32 D_800A7EC0;
extern u8 D_8014C3B8[];

extern void func_800905A0(void);
extern void func_80087E80(void *, void *, s32);

void func_800905F0(void) {
    s32 status;


    if (D_800A7EC0 == 0) {
        func_800905A0();
    }
    func_80087E80(D_8014C3B8, &status, 1);
}
