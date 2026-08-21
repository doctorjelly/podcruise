/* Independently written from scratchpad spec specs/func_80007CE4.md. */

#include "podcruise/types.h"

extern s32 D_800AFA54;
extern s32 D_8009A32C[];
extern s32 D_8009A388[];

s32 func_80007CE4(s32 arg0) {
    s32 kind;

    if ((arg0 & 0x8000) == 0) {
        return D_800AFA54;
    }
    kind = (arg0 >> 24) & 0xFF;
    if ((kind == 0) || (kind == 1)) {
        return D_8009A32C[(arg0 >> 16) & 0xFF];
    }
    return D_8009A388[kind];
}
