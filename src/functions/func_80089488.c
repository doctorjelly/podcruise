/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Entry80089488;

void func_80089488(Entry80089488 *entries, s32 delta) {
    s32 count;

    for (count = 0; count < entries->unk2; count++) {
        entries[count].unk4 = entries[count].unk4 + delta;
    }
}
