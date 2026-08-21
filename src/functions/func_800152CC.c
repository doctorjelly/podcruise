/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

u8 func_800152CC(const PcVec3f *left, const PcVec3f *right) {
    u8 result = 0;
    if (left->x == right->x) {
        if (left->y == right->y) {
            if (left->z == right->z) {
                result = 1;
            }
        }
    }
    return result;
}
