/* Independently written from scratchpad spec specs/func_80039914.md. */

#include "podcruise/types.h"

typedef struct {
    u32 words[11];
} Slot80113680; /* 0x2C bytes */

typedef struct {
    u8 unk_00[0x14];
    Slot80113680 unk_14[16];
} Bank80113680;

extern Bank80113680 D_80113680;
extern Slot80113680 D_80113E60[16];

void func_80039914(s32 destIndex, s32 sourceIndex) {
    D_80113E60[destIndex] = D_80113680.unk_14[sourceIndex];
}
