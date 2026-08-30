/* Independently written from specs/functions/recovered/func_80008718.md. */

#include "podcruise/types.h"

s32 func_80008718(s32 value) {
    if ((value >= 142) && (value < 158)) {
        return 1;
    }
    if (value == 34) {
        return 1;
    }
    return 0;
}
