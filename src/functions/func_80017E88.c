/* Independently written from the scratchpad specification specs/func_80017E88.md. */
#include "podcruise/types.h"

s32 func_80017E88(const void *object, s32 selector) {
    s32 result;
    u32 flags;

    result = -1;
    if (object != 0 && selector == 1) {
        flags = *(const u32 *)object;
        result = (flags & 0x08) ? 1 : 0;
        if (flags & 0x40) {
            if (result == 0) {
                result = 2;
            } else {
                result = 3;
            }
        }
    }
    return result;
}
