/* Recovered per specs/func_800815CC.md (boundary corrected: real entry is func_80081530). */
#include "podcruise/types.h"

s32 func_80081530(u8 *left, u8 *right, s32 length) {
    s32 i;

    for (i = 0; i < length; i++) {
        if (left[i] != right[i]) {
            return 0;
        }
    }
    return 1;
}
