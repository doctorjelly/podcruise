/* Independently written from scratchpad spec specs/func_80095AA0.md. */

#include "podcruise/types.h"

struct Handler80095AA0 {
    s32 unk00;
    void *unk04;
    void *unk08;
    s16 unk0C;
    s16 unk0E;
    s32 unk10;
};

void func_80095AA0(struct Handler80095AA0 *slot, void *first, void *second, s32 tag) {
    slot->unk00 = 0;
    slot->unk04 = first;
    slot->unk08 = second;
    slot->unk0C = 0;
    slot->unk0E = 0;
    slot->unk10 = tag;
}
