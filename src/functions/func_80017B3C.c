/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/types.h"

extern void func_8001734C(void *object, f32 first, f32 second, s32 value);

void func_80017B3C(void *object, f32 first, f32 second, s32 value) {
    void *saved = object;
    func_8001734C((u8 *)saved + 0x1C, first, second, value);
    *(u16 *)((u8 *)saved + 0x0C) |= 3;
}
