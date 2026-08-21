/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_80014CC0(f32 argument, f32 *numerator, f32 *denominator);

f32 func_80014D20(f32 argument) {
    struct {
        f32 denominator;
        f32 numerator;
        s32 unused;
    } values;

    func_80014CC0(argument, &values.numerator, &values.denominator);
    return values.numerator / values.denominator;
}
