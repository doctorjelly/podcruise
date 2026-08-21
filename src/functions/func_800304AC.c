/* Specification: $S/specs/func_800304AC.md */
#include "podcruise/types.h"

extern s32 *D_800D9E00[];
extern s32 D_800DB890;
extern u8 D_102ABB0[];

extern void func_80011D60(void *, void *, s32);
extern void func_80030328(void *, s32 *, s32 *, s32);

void func_800304AC(s32 index, s32 *out0, s32 *out1) {
    s32 unusedA[3];
    s32 record[3];
    s32 unusedB;

    (void)unusedA;
    (void)unusedB;
    if ((index < 0) || (index >= D_800DB890)) {
        *out0 = 0;
        *out1 = 0;
        return;
    }
    if (D_800D9E00[index] != 0) {
        *out0 = D_800D9E00[index][0];
        *out1 = D_800D9E00[index][1];
        return;
    }
    func_80011D60(&D_102ABB0[(index * 8) + 4], record, 0xC);
    func_80030328(record, out0, out1, 1);
    D_800D9E00[index] = out0;
}
