/* Independently written from the specification for func_8005F31C. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
} Slot;

void func_8005F31C(Slot *slot, void *value) {
    if (slot != 0) {
        slot->unk14++;
        slot->unk18 = value;
    }
}
