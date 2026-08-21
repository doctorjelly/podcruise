/* Independently written from the specification for the display slot enable flag. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u32 flags;
    /* 0x004 */ s32 value;
    /* 0x008 */ u8 rest[0x168];
} DisplaySlot; /* size 0x170 */

extern DisplaySlot D_80120DF0[];

void func_8008635C(s32 slot, s32 value) {
    if (value < 0) {
        D_80120DF0[slot].flags &= ~1;
    } else {
        D_80120DF0[slot].flags |= 1;
    }
    D_80120DF0[slot].value = value;
}
