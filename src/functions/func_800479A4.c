/* Recovered from specification specs/func_800479A4.md */
#include "podcruise/types.h"

extern void func_80015268(f32 *out, f32 x, f32 y, f32 z);
extern void func_80086A20(s32 index, f32 *a, f32 *b, f32 *c);

void func_800479A4(void) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_80015268(sp34, 255.0f, 255.0f, 255.0f);
    func_80015268(sp28, 255.0f, 255.0f, 255.0f);
    func_80015268(sp1C, 0.0f, 120.0f, 0.0f);
    func_80086A20(0, sp34, sp28, sp1C);
    func_80015268(sp34, 0.0f, 0.0f, 0.0f);
    func_80015268(sp28, 128.0f, 128.0f, 128.0f);
    func_80086A20(1, sp34, sp28, sp1C);
}
