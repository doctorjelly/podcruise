/* Specification: $S/specs/func_8002FAC4.md */
#include "podcruise/types.h"

extern s32 D_800A2868;
extern s32 D_800D9DD8[];
extern void func_8002FC80(s32);

void func_8002FAC4(s32 arg0) {
    D_800D9DD8[D_800A2868] = arg0;
    func_8002FC80(1);
}
