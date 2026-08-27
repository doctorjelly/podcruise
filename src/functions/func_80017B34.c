/* Independently written from specs/func_80017B34.md. */

#include "podcruise/types.h"

extern void func_8001734C(f32 *rotation, f32 first, f32 second, f32 third);

void func_80017B34(void *object, f32 first, f32 second, f32 third) {
    void *saved = object;
    func_8001734C((f32 *)((u8 *)saved + 0x1C), first, second, third);
    *(u16 *)((u8 *)saved + 0x0C) |= 3;
}
