/* Specification: scratchpad specs/func_80033B38.md (corrected boundary: func_80033B14) */
#include "podcruise/types.h"

typedef struct Target {
    u8 pad_00[0x100];
    u32 unk_100;
} Target;

typedef struct Owner {
    Target *unk_00;
} Owner;

s32 func_80033B14(Owner *owner) {
    Target *target;

    if (owner == 0) {
        return 0;
    }
    target = owner->unk_00;
    if (target == 0) {
        return 0;
    }
    if (target->unk_100 & 0x20000000) {
        return 1;
    }
    return 0;
}
