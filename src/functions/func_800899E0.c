/* Independently written from scratchpad spec specs/func_800899E0.md. */

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
} SourceRecord;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} DestinationRecord;

extern SourceRecord D_80149C70[];
extern u8 D_80149CB1;

void func_800899E0(u8 *statusOut, DestinationRecord *destination) {
    SourceRecord *cursor;
    SourceRecord entry;
    s32 index;
    u8 status;

    status = 0;
    cursor = D_80149C70;

    for (index = 0; index < D_80149CB1; index++, cursor++) {
        entry = *cursor;
        destination->unk3 = (entry.unk2 & 0xC0) >> 4;
        if (destination->unk3 == 0) {
            destination->unk0 = (entry.unk5 << 8) | entry.unk4;
            destination->unk2 = entry.unk6;
            status |= 1 << index;
        }
        destination++;
    }

    *statusOut = status;
}
