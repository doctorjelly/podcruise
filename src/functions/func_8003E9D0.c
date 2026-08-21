/* Spec: specs/func_8003E9D0.md (run the four update passes when either queue is non-empty) */
#include "podcruise/types.h"

extern s32 D_800A4970;
extern s32 D_800A4984;
extern void func_8003D110(void);
extern void func_8003D370(void);
extern void func_8003E59C(void);
extern void func_8003E870(void);

void func_8003E9D0(void) {
    if ((D_800A4984 > 0) || (D_800A4970 > 0)) {
        func_8003D110();
        func_8003E870();
        func_8003E59C();
        func_8003D370();
    }
}
