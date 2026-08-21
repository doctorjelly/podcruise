/* Independently written from $S/specs/func_8003FB34.md: tagged query message dispatch. */
#include "podcruise/types.h"

extern void func_8003F99C(void *target, s32 *message);

s32 func_8003FB34(void *target, s32 value) {
    s32 message[16];
    s32 result;

    result = 0;
    message[0] = 0x51657279;
    message[1] = value;
    message[2] = (s32)(long)&result;
    message[3] = 0x51657279;
    func_8003F99C(target, message);
    return result;
}
