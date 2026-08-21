/* Specification: $S/specs/func_8000FFF8.md */
#include "podcruise/types.h"

extern u8 D_800D5C38[];

void func_8000FFF8(s32 arg0) {
    if (arg0 < 0x28) {
        D_800D5C38[arg0] = 0;
    }
}
