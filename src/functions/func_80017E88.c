/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

s32 func_80017E88(const void *object, s32 selector) {
    s32 result = -1;
    u32 flags;

    if (object != 0) {
        if (selector == 1) {
            flags = *(const u32 *)object;
            result = 0;
            if (flags & 0x08) {
                result = 1;
            }
            if (flags & 0x40) {
                if (result != 0) {
                    result = 3;
                } else {
                    return 2;
                }
            }
        }
    }
    return result;
}
