/* Independently written from the specification for func_8001F464. */

#include "podcruise/types.h"

extern u32 D_80113688;

s32 func_8001F464(void) {
    if (D_80113688 & 2) {
        return 1;
    }
    return 0;
}
