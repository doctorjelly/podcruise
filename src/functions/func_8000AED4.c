/* Independently written from the specification for the entry table writers. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u8 unk0C[0x70];
} TableEntry;

extern TableEntry *D_8009B790;

void func_8000AED4(s32 index, u32 bits) {
    D_8009B790[index].unk00 |= bits;
}
