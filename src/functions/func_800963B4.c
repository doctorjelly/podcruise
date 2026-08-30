/* Independently written from specs/functions/recovered/func_800963B4.md. */

#include "podcruise/types.h"

s32 func_800963B4(void **destination, s32 mode, void *value) {
    if (mode == 1) {
        *destination = value;
    }
    return 0;
}
