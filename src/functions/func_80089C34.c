/* Independently written from the specification for func_80089C34. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ signed char unk06;
    /* 0x07 */ signed char unk07;
} Record;

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ signed char unk02;
    /* 0x03 */ signed char unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
} Entry;

extern Record D_80149C70[];
extern u8 D_80149CB1;

void func_80089C34(Entry *entry) {
    s32 i;
    Record record;
    Record *src;

    src = D_80149C70;
    for (i = 0; i < D_80149CB1; i++) {
        record = *src;
        entry->unk04 = (record.unk02 & 0xC0) >> 4;
        if (entry->unk04 == 0) {
            entry->unk00 = record.unk04;
            entry->unk02 = record.unk06;
            entry->unk03 = record.unk07;
        }
        src++;
        entry++;
    }
}
