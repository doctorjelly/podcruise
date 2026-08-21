/* Specification: $S/specs/func_8008807C.md */
#include "podcruise/types.h"

extern s32 D_800A6990;
extern void func_8008D410();

void func_80088074(void) {
    if (D_800A6990 != 0) {
        func_8008D410();
        D_800A6990 = 0;
    }
}
