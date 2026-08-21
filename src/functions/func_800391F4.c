/* Implements the specification in specs/func_800391F4.md (busy-wait for a scaled interval). */
#include "podcruise/types.h"

extern f64 D_800AAAF0;
extern f64 D_800A40E8;
extern f64 func_8008126C(void);
extern void func_80008F28(void);

void func_800391F4(arg0)
s16 arg0;
{
    f64 pad;
    f64 span;
    f64 limit;

    span = (f32)arg0 * D_800AAAF0;
    limit = span;
    D_800A40E8 = func_8008126C();
    while (func_8008126C() < D_800A40E8 + limit) {
        func_80008F28();
    }
    D_800A40E8 = func_8008126C();
    (void)pad;
}
