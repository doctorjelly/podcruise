/* Independently written from scratchpad spec specs/func_80090B24.md. */

#include "podcruise/types.h"

s32 func_80090B24(u16 *values, u16 *total, u16 *complementTotal) {
    s32 index;
    u16 value;

    *complementTotal = 0;
    *total = 0;

    for (index = 0; index < 14; index++) {
        value = values[index];
        *total = *total + value;
        *complementTotal = *complementTotal + ~value;
    }

    return 0;
}
