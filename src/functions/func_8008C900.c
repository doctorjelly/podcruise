/* Independently written from the specification for func_8008C900. */

#include "podcruise/types.h"

extern s32 D_800A7B80;
extern s32 D_800A7B88;

s32 func_8008C900(void) {
    if (D_800A7B80 == 0) {
        return 0;
    }
    return D_800A7B88;
}
