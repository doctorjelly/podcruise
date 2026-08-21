/* Specification: $S/specs/func_800129BC.md (boundary corrected to 0x800129B8) */
#include "podcruise/types.h"

extern s32 D_800D6940[];
extern void func_800129E4(s32, s32);

void func_800129B8(s32 arg0, s32 arg1) {
    func_800129E4(arg0, D_800D6940[arg1]);
}
