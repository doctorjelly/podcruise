/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

extern u8 D_80120DF0[4][0x170];

void *func_80017F28(s32 index) {
    if ((index < 0) || (index >= 4)) {
        return 0;
    }

    return D_80120DF0[index];
}
