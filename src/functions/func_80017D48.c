/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/object_accessors.h"

void func_80017D48(void *object, s32 value) {
    *(s32 *)((u8 *)object + 0x1C) = value;
}
