/* Specification: $S/specs/func_8002F194.md */
#include "podcruise/types.h"

extern s32 D_800A26F4;
extern void func_8002F06C(void);
extern void func_8002F144(void);

void func_8002F18C(void) {
    if (D_800A26F4 == 0) {
        func_8002F06C();
    } else {
        func_8002F144();
    }
}
