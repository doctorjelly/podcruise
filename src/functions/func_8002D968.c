/* Independently written from the specification for func_8002D968. */

#include "podcruise/types.h"

extern u32 D_8009B7D8;

s32 func_8002D968(u8 *arg0, u8 *arg1) {
    s32 same;

    if ((D_8009B7D8 & 0x4000) == 0) {
        return 0;
    }
    same = (arg0[0] == arg1[0]) && (arg0[1] == arg1[1]) && (arg0[2] == arg1[2]);
    return same;
}
