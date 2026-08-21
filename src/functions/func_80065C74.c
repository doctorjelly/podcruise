/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/vector_math.h"

void func_80065C74(u8 *record, const PcVec3f *source) {
    if (record != 0) {
        func_80015288((PcVec3f *)(record + 0x74), source);
    }
}
