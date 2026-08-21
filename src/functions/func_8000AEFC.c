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

void func_8000AEFC(s16 index, s16 second, u32 third, s16 fourth) {
    D_8009B790[index].unk06 = fourth;
    D_8009B790[index].unk04 = second;
    D_8009B790[index].unk08 = third;
}
