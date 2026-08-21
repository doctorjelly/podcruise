/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/types.h"

u32 func_80017DB4(const void *object, s32 index) {
    if (object == 0) {
        return 0;
    }

    return (*(u32 *const *)((const u8 *)object + 0x18))[index];
}
