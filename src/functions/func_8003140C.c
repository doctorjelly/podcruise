/* Implements specs/functions/recovered/func_8003140C.md. */
#include "podcruise/types.h"
extern void func_800313D8(void *, s32, u32);
extern void func_80008F28(void);
void *func_8003140C(void *arg0, s32 arg1, u32 arg2) {
    u8 *p;
    s32 chunk;
    s32 fill = arg1;
    chunk = 0x10000;
    p = (u8 *)arg0;
    if (arg2 >= 0x10000) {
        do {
            func_800313D8(p, fill, chunk);
            arg2 -= chunk;
            p += chunk;
            func_80008F28();
        } while (arg2 >= (u32)chunk);
    }
    if (arg2 != 0) {
        func_800313D8(p, fill, arg2);
        func_80008F28();
    }
    return arg0;
}
