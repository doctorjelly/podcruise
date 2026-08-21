/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/types.h"

void func_80017D58(void *object, s32 index, f32 value) {
    if ((index < 8) && (index >= 0)) {
        *(f32 *)((u8 *)object + 0x1C + index * 4) = value;
    }
}
