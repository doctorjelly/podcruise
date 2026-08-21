/* Recovered from specification scratchpad specs/func_80060030.md */
#include "podcruise/types.h"

extern void func_80086A20(s32, f32 *, f32 *, f32 *);

void func_80060030(s32 arg0) {
    f32 a[3];
    f32 b[3];
    f32 c[3];

    (void)arg0;

    a[0] = 64.0f;
    a[1] = 64.0f;
    a[2] = 64.0f;
    b[0] = 255.0f;
    b[1] = 255.0f;
    b[2] = 255.0f;
    c[0] = 0.0f;
    c[1] = 0.0f;
    c[2] = -100.0f;
    func_80086A20(-1, a, b, c);
}
