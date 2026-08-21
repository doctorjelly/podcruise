/* Independently written from $S/specs/func_80008694.md. */

#include "podcruise/types.h"

extern s32 D_8009A2C0;

s32 func_80008694(s32 request) {
    if (request == 0) {
        D_8009A2C0 = 1;
    } else if (request == 1) {
        D_8009A2C0 = 0;
    } else if (request == -1) {
        D_8009A2C0 = (D_8009A2C0 == 0);
    }
    return D_8009A2C0 == 0;
}
