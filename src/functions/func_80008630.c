/* Independently written from $S/specs/func_80008630.md. */

#include "podcruise/types.h"

extern s32 D_8009A2C4;

s32 func_80008630(s32 request) {
    if (request == 0) {
        D_8009A2C4 = 1;
    } else if (request == 1) {
        D_8009A2C4 = 0;
    } else if (request == -1) {
        D_8009A2C4 = (D_8009A2C4 == 0);
    }
    return D_8009A2C4 == 0;
}
