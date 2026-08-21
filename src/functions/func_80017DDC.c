/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/types.h"

s16 func_80017DDC(const void *object) {
    return *(const s16 *)((const u8 *)object + 0x20);
}

s16 func_80017DE4(const void *object) {
    return *(const s16 *)((const u8 *)object + 0x22);
}

u32 func_80017DEC(const void *object) {
    return *(const u32 *)((const u8 *)object + 0x24);
}
