/* Independently written from scratchpad spec specs/func_80009134.md. */

#include "podcruise/types.h"

extern f32 D_8009AD10[];
extern f32 D_8009AD30[];

s32 func_80009134(s32 arg0, s32 arg1) {
    if ((arg0 == 0) || (arg0 == 1)) {
        if (D_8009AD30[arg1] > 0.0f) {
            return 1;
        }
        return 0;
    }
    if (D_8009AD10[arg0] > 0.0f) {
        return 1;
    }
    return 0;
}
