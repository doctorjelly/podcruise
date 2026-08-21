/* Specification: scratchpad specs/func_800178C4.md */
#include "podcruise/types.h"

extern void func_800175E0(f32 *out, f32 a, f32 b, f32 c, f32 d);
extern void func_80015724(void *arg0, void *arg1, f32 *mat);

void func_800178C4(void *arg0, void *arg1, f32 a, f32 b, f32 c, f32 d) {
    f32 sp20[16];

    func_800175E0(sp20, a, b, c, d);
    func_80015724(arg0, arg1, sp20);
}
