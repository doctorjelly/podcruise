/* Specification: scratchpad specs/func_8003A54C.md (corrected boundary: func_8003A50C) */
#include "podcruise/types.h"

typedef struct Record {
    u8 pad_00[0x40];
    s16 unk_40;
    u8 pad_42[0x12];
} Record;

typedef struct Holder {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    Record *unk_0C;
} Holder;

s32 func_8003A50C(Holder *holder, s32 value, s32 start) {
    s32 i;

    for (i = start; i < holder->unk_04; i++) {
        if (holder->unk_0C[i].unk_40 == value) {
            return i;
        }
    }
    return -1;
}
