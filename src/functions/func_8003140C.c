/* Implements the specification in specs/func_8003140C.md */
#include "podcruise/types.h"

extern void func_800313D8(void *, s32, u32);
extern void func_80008F28(void);

void *func_8003140C(void *arg0, s32 arg1, u32 arg2) {
    u8 *p;
    u32 n;
    register u32 chunk;
    register u32 limit;

    chunk = 0x10000;
    limit = chunk;
    p = (u8 *)arg0;
    n = arg2;
    while (n >= limit) {
        func_800313D8(p, arg1, chunk);
        func_80008F28();
        n -= chunk;
        p += chunk;
    }
    if (n != 0) {
        func_800313D8(p, arg1, n);
        func_80008F28();
    }
    return arg0;
}
