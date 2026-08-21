/* Recovered from specs/func_8003F8FC.md (behavioral specification). */
#include "podcruise/types.h"

extern void func_80018450(u32 selector, u32 *message);

void func_8003F8FC(u32 arg0, u32 arg1, u32 *arg2) {
    u32 message[16];
    s32 i;

    message[0] = arg0;
    message[1] = arg1;
    for (i = 0; i < 14; i++) {
        message[i + 2] = arg2[i];
    }
    func_80018450(0xEE06, message);
}
