/* Specification: $S/specs/func_80081640.md (boundary corrected to 0x800815FC) */
#include "podcruise/types.h"

s32 func_800815FC(u8 *arg0, u8 *arg1) {
    while (*arg0 != 0) {
        if (*arg1 == 0) {
            return 1;
        }
        if (*arg0 < *arg1) {
            return -1;
        }
        if (*arg1 < *arg0) {
            return 1;
        }
        arg0++;
        arg1++;
    }
    if (*arg1 == 0) {
        return 0;
    }
    return -1;
}
