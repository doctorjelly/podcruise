/* Independently written from scratchpad spec specs/func_8004A7F8.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ void *unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ void *unk30;
} Holder8004A7F8;

extern s32 func_800181BC(void *, s32, s32, s32, s32);
extern s16 D_800A4BC0;

void func_8004A7F8(Holder8004A7F8 *holder) {
    void *first;

    first = holder->unk28;
    if (first != 0) {
        func_800181BC(first, 2, 3, 0x10, 2);
    }
    if (holder->unk30 != 0) {
        func_800181BC(holder->unk30, 2, 3, 0x10, 2);
    }
    if (D_800A4BC0 == 5) {
        D_800A4BC0 = 0;
    }
}
