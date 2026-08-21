/* Specification: $S/specs/func_8002F02C.md (boundary corrected to 0x8002F024) */
#include "podcruise/types.h"

extern s32 D_800A26F8;
extern void func_8002F1EC(void);

void func_8002F024(void) {
    if (D_800A26F8 == 0) {
        func_8002F1EC();
    }
}
