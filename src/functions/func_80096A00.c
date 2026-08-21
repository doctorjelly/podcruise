/* Independently written from specs/func_80096A00.md.
 * NOTE: this translation unit only reproduces the original bytes at -O1. */

#include "podcruise/types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} PcSourceRecord;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} PcEntry;

extern u8 D_80149CB1;
extern PcSourceRecord D_8014D720[];

void func_80096A00(u8 *flags, PcEntry *entry) {
    PcSourceRecord *source;
    PcSourceRecord temp;
    s32 index;
    u8 mask;

    mask = 0;
    source = D_8014D720;
    for (index = 0; index < D_80149CB1; index++, source++) {
        temp = *source;
        entry->unk3 = (temp.unk2 & 0xC0) >> 4;
        if (entry->unk3 == 0) {
            entry->unk0 = (temp.unk5 << 8) | temp.unk4;
            entry->unk2 = temp.unk6;
            mask |= 1 << index;
        }
        entry++;
    }
    *flags = mask;
}
