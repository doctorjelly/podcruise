/* Independently written from scratchpad spec specs/func_80033B94.md. */

#include "podcruise/types.h"

typedef struct Node80033B94 {
    u8 pad0[0x114];
    f32 unk114;
} Node80033B94;

typedef struct Holder80033B94 {
    Node80033B94 *unk0;
} Holder80033B94;

f32 func_80033B94(Holder80033B94 *arg0) {
    if (arg0 == 0) {
        return 0.0f;
    }
    if (arg0->unk0 == 0) {
        return 0.0f;
    }
    return arg0->unk0->unk114;
}
