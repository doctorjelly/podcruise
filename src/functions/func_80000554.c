/* Specification: $S/specs/func_80000554.md */
#include "podcruise/types.h"

void func_80000554(s32 *buffer, s32 count) {
    s32 index;

    for (index = 0; index < count; index++) {
        buffer[index] = 0;
    }
}
