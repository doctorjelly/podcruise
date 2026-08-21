/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/types.h"
void func_80017C18(const f32 *source, f32 *destination) {
    f32 zero = 0.0f;
    destination[0] = source[7];
    destination[1] = source[8];
    destination[2] = source[9];
    destination[3] = zero;
    destination[4] = source[10];
    destination[5] = source[11];
    destination[6] = source[12];
    destination[7] = zero;
    destination[8] = source[13];
    destination[9] = source[14];
    destination[10] = source[15];
    destination[11] = zero;
    destination[12] = source[16];
    destination[13] = source[17];
    destination[14] = source[18];
    destination[15] = 1.0f;
}
