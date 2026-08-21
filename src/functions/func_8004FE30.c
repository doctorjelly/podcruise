/* Independently written from scratchpad spec specs/func_8004FE30.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x5D];
    s8 unk5D;
    u8 unk5E[0x6];
    s32 unk64;
    u8 unk68[0x9];
    s8 unk71;
    s8 unk72[1];
} Holder;

typedef struct {
    s32 unk00;
    u32 unk04;
    u8 unk08[0x80];
} Slot;

extern s8 D_800A21C2[];
extern Slot D_80118F90[];

s32 func_8004FE30(Holder *holder) {
    s32 found;
    s32 index;

    found = -1;
    if (holder->unk64 != 0) {
        for (index = 0; index < holder->unk71; index++) {
            if (holder->unk72[index] == D_800A21C2[holder->unk5D * 12]) {
                found = index;
            }
        }
        if (found == -1) {
            found = 0;
        }
    } else {
        for (index = 0; index < holder->unk71; index++) {
            if (holder->unk72[index] == D_800A21C2[holder->unk5D * 12] && D_80118F90[index].unk04 == 0x41414949) {
                found = index;
            }
        }
        if (found == -1) {
            index = 0;
            while (found == -1 && index < holder->unk71) {
                if (D_80118F90[index].unk04 == 0x41414949) {
                    found = index;
                } else {
                    index++;
                }
            }
        }
    }
    return found;
}
