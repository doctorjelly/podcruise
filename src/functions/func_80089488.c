/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Entry80089488;

s32 func_80089488(Entry80089488 *entries, s32 delta) {
    s32 count;
    Entry80089488 *entry;

    entry = entries;
    for (count = 0; count < entries->unk2; count++) {
        entry->unk4 = entry->unk4 + delta;
        entry++;
    }
    return count;
}
