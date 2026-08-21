/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

void func_80017EFC(void *object, u32 mask) {
    *(u32 *)object |= mask;
}

void func_80017F0C(void *object, u32 mask) {
    *(u32 *)object &= ~mask;
}
