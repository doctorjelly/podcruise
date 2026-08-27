/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

typedef struct Cell958DC {
    struct Cell958DC *next;
} Cell958DC;

typedef struct Ring958DC {
    Cell958DC *unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    u32 *unk14;
} Ring958DC;

extern u32 D_80149D44;
extern Ring958DC *D_80149D40;
extern Cell958DC *D_800A7BB8;
extern Cell958DC *func_8008D274(Cell958DC **head);
extern void func_8008D22C(Cell958DC **head, Cell958DC *entry);

void func_800958D4(void) {
    s32 index;
    Ring958DC *arg0;

    arg0 = D_80149D40;
    if (arg0 == 0) {
        return;
    }
    if (arg0->unk08 < arg0->unk10) {
        index = (arg0->unk0C + arg0->unk08) % arg0->unk10;
        arg0->unk14[index] = D_80149D44;
        arg0->unk08 = arg0->unk08 + 1;
        if (arg0->unk00->next != 0) {
            func_8008D22C(&D_800A7BB8, func_8008D274((Cell958DC **)arg0));
        }
    }
}
