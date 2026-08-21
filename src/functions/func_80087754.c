/* Independently written from scratchpad spec specs/func_80087754.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x170];
} PcSlot;

extern PcSlot D_80120DF0[4];
extern void func_80018114(PcSlot *slot, void *arg);

void func_80087754(void *arg) {
    s32 index;

    for (index = 0; index < 4; index++) {
        func_80018114(&D_80120DF0[index], arg);
    }
}
