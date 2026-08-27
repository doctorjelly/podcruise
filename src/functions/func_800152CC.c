/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

u8 func_800152CC(const PcVec3f *left, const PcVec3f *right) {
    if (right->x == left->x) {
        if (right->y == left->y) {
            if (right->z == left->z) {
                return 1;
            }
        }
    }
    return 0;
}
