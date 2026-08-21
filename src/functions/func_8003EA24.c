/* Specification: $S/specs/func_8003EA24.md */
#include "podcruise/types.h"

extern f32 D_800A4A90;
extern s32 D_800A4978;

extern void func_8003D110(void);
extern void func_8003D370(void);
extern void func_8003E2B0(void);
extern void func_8003E920(void);

void func_8003EA24(void) {
    if ((D_800A4A90 > 0.0f) || (D_800A4978 > 0)) {
        func_8003D110();
        func_8003E2B0();
        func_8003E920();
        func_8003D370();
    }
}
