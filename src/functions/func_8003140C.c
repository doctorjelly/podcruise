/* Implements the specification in specs/func_8003140C.md */
#include "podcruise/types.h"
extern void func_800313D8(void *, s32, u32);
extern void func_80008F28(void);
void *func_8003140C(void *arg0, s32 arg1, u32 arg2) {
    u8 *p;
    u32 n;
    p = (u8 *)arg0;
    n = arg2;
    if (n >= 0x10000) {
        do {
            func_800313D8(p, arg1, 0x10000);
            func_80008F28();
            n -= 0x10000;
            p += 0x10000;
        } while (n >= 0x10000);
    }
    if (n != 0) {
        func_800313D8(p, arg1, n);
        func_80008F28();
    }
    return arg0;
}
