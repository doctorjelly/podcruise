/* Independently written from the specification for func_80029A3C. */

#include "podcruise/types.h"


/* One 0x2C-byte record of the per-slot table reset by this routine. */
typedef struct {
    /* 0x00 */ u8  unk00[3];
    /* 0x03 */ u8  unk03;
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  unk05;
    /* 0x06 */ u8  unk06;
    /* 0x07 */ s8  unk07;
    /* 0x08 */ u8  unk08;
    /* 0x09 */ u8  unk09;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
    /* 0x0C */ s16 unk0C[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8  unk1C;
    /* 0x1D */ u8  unk1D[7];
    /* 0x24 */ u8  unk24[7];
    /* 0x2B */ u8  unk2B;
} SlotRecord;

/* The second table is preceded by a 0x14-byte header inside the same object. */
typedef struct {
    /* 0x00 */ u8         unk00[0x14];
    /* 0x14 */ SlotRecord records[4];
} SlotGroup;

extern SlotRecord D_80113E60[];
extern SlotGroup D_80113680;

void func_80029A3C(s32 arg0, s32 arg1) {
    s32 i;

    switch (arg0) {
    case 0:
        D_80113E60[arg1].unk03 = 0;
        D_80113E60[arg1].unk04 = 0;
        D_80113E60[arg1].unk05 = 0xFF;
        D_80113E60[arg1].unk18 = 0x190;
        D_80113E60[arg1].unk1C = 1;
        D_80113E60[arg1].unk06 = 0;
        D_80113E60[arg1].unk14 = 0x22E01;
        D_80113E60[arg1].unk07 = -1;
        for (i = 0; i < 4;) {
            D_80113E60[arg1].unk0C[i] = 0;
            i++;
        }
        D_80113E60[arg1].unk08 = 1;
        D_80113E60[arg1].unk09 = 1;
        D_80113E60[arg1].unk0A = 1;
        D_80113E60[arg1].unk0B = 0;
        for (i = 0; i < 7; i++) {
            D_80113E60[arg1].unk1D[i] = 0;
            D_80113E60[arg1].unk24[i] = 0xFF;
        }
        for (i = 0; i < 3;) {
            D_80113E60[arg1].unk00[i] = 0;
            i++;
        }
        break;
    case 1:
        D_80113680.records[arg1].unk03 = 0;
        D_80113680.records[arg1].unk04 = 0;
        D_80113680.records[arg1].unk05 = arg1;
        D_80113680.records[arg1].unk18 = 0x190;
        D_80113680.records[arg1].unk1C = 1;
        D_80113680.records[arg1].unk06 = 0;
        D_80113680.records[arg1].unk14 = 0x22E01;
        D_80113680.records[arg1].unk07 = -1;
        for (i = 0; i < 4;) {
            D_80113680.records[arg1].unk0C[i] = 0;
            i++;
        }
        D_80113680.records[arg1].unk08 = 1;
        D_80113680.records[arg1].unk09 = 1;
        D_80113680.records[arg1].unk0A = 1;
        D_80113680.records[arg1].unk0B = 0;
        for (i = 0; i < 7; i++) {
            D_80113680.records[arg1].unk1D[i] = 0;
            D_80113680.records[arg1].unk24[i] = 0xFF;
        }
        for (i = 0; i < 3;) {
            D_80113680.records[arg1].unk00[i] = 0;
            i++;
        }
        D_80113680.records[arg1].unk2B = 0;
        break;
    }
}
