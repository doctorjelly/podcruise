/* Independently written from specs/functions/recovered/func_8006D0C0.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x58];
    f32 threshold;
    u8 pad5C[8];
    u32 flags;
    u8 pad68[0x11C];
    f32 alternate;
    u8 pad188[0x174];
    f32 result;
} PcObject8006D0C0;

typedef struct {
    u8 pad00[8];
    f32 z;
} PcPoint8006D0C0;

void func_8006D0C0(PcObject8006D0C0 *object, void *unused,
                   PcPoint8006D0C0 *point, s32 allow_alternate) {
    f32 candidate;

    (void)unused;
    if (point->z < object->threshold) {
        candidate = 0.0f;
    } else {
        if (object->flags & 0x200) {
            goto use_default;
        }
        if (allow_alternate != 0) {
            goto use_alternate;
        }
use_default:
        candidate = 500.0f;
        goto candidate_ready;
use_alternate:
        candidate = object->alternate;
    }

candidate_ready:
    if (400.0f < candidate) {
        object->result = -1.0f;
    } else {
        object->result = 0.0f;
    }
}
