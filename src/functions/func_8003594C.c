/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u8 unk06[8];
    /* 0x0E */ u8 unk0E[8];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u8 unk20[10];
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 unk2B;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
} Obj8003594C;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
} Src8003594C;

extern u32 D_800A3D9C;
extern u32 D_800A3DA0;
extern u32 D_800A3DA4;
extern u32 D_800A3DA8;
extern u32 D_800A4740;
extern u32 D_800D697C;

void func_8003594C(Obj8003594C *object, Src8003594C *source) {
    u8 scratch[64];
    s32 index;
    u8 *slots[2];

    (void)scratch;

    if (D_800A4740 == 0) {
        object->unk18 &= ~0x10;
        object->unk18 &= ~0x20;
        object->unk1C &= ~0x10;
        object->unk1C &= ~0x20;
    }

    if ((D_800D697C & 0x40) != 0) {
        if (object->unk04 == 2) {
            if ((object->unk18 & 0xFFFF0000) == 0xC8000000) {
                object->unk18 &= 0xFFFF;
                object->unk18 |= 0x0C080000;
            }
        }
    }

    if (((D_800D697C & 0x10) != 0) || (source == 0) || (source->unk08 == 0)) {
        slots[0] = object->unk06;
        slots[1] = object->unk0E;
        for (index = 0; index < 2; index++) {
            if (slots[index][0] == 1 || slots[index][0] == 2 || slots[index][0] == 8 || slots[index][0] == 9) { slots[index][0] = 6; }
            if (slots[index][1] == 1 || slots[index][1] == 2 || slots[index][1] == 8 || slots[index][1] == 9) { slots[index][1] = 4; }
            if (slots[index][2] == 1 || slots[index][2] == 2 || slots[index][2] == 8 || slots[index][2] == 9) { slots[index][2] = 4; }
            if (slots[index][3] == 1 || slots[index][3] == 2 || slots[index][3] == 8 || slots[index][3] == 9) { slots[index][3] = 6; }
            if (slots[index][4] == 1 || slots[index][4] == 2) { slots[index][4] = 6; }
            if (slots[index][5] == 1 || slots[index][5] == 2) { slots[index][5] = 6; }
            if (slots[index][6] == 1 || slots[index][6] == 2) { slots[index][6] = 4; }
            if (slots[index][7] == 1 || slots[index][7] == 2) { slots[index][7] = 6; }
        }
    }

    if (D_800A3DA8 != 0) {
        object->unk18 &= ~0x10;
        object->unk1C &= ~0x10;
    }

    if (D_800A3D9C != 0) {
        object->unk18 = D_800A3DA0;
        object->unk1C = D_800A3DA4;
        if (D_800A3DA0 == 0xF5504040) {
            object->unk2A = 0x80;
            object->unk2B = 0;
            object->unk2C = 0xFF;
            object->unk2D = 0x28;
            object->unk00 |= 4;
        }
    }
}
