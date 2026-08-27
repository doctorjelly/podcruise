/* Independently written from the scratchpad specification specs/func_80017E88.md. */
#include "podcruise/object_accessors.h"

s32 func_80017E88(const void *object, s32 selector) {
    s32 result;
    u32 flags;

    result = -1;
    if (object != 0) {
        if (selector == 1) {
            flags = *(const u32 *)object;
            if (flags & 0x08) {
                result = 1;
            } else {
                result = 0;
            }
            if (flags & 0x40) {
                if (result == 0) {
                    return 2;
                }
                result = 3;
            }
        }
    }
    return result;
}
