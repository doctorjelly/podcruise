/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

extern void func_80016F0C(const void *object, f32 *output);

void func_80017F64(const void *object, f32 *first, f32 *second) {
    f32 values[6];

    func_80016F0C((const u8 *)object + 0xB0, values);
    first[0] = values[0];
    first[1] = values[1];
    first[2] = values[2];
    second[0] = values[3];
    second[1] = values[4];
    second[2] = values[5];
}
