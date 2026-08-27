/* Recovered from specs/func_8003F8FC.md (behavioral specification). */
#include "podcruise/types.h"

extern void func_80018450(u32 selector, u32 *message);

void func_8003F8FC(u32 arg0, u32 arg1, u32 *arg2) {
    u32 message[17];
    s32 i;

    message[0] = arg0;
    message[1] = arg1;
    for (i = 2; i < 16; i++) {
        message[i] = arg2[i - 2];
    }
    func_80018450(0xEE06, message);
}
