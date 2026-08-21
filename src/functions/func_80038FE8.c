/* Specification: $S/specs/func_80038FE8.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x19];
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 pad1B[1];
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 unk1E;
    /* 0x1F */ u8 pad1F[1];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 pad23[5];
} Slot;

extern s32 D_800A3FA8[];
extern Slot D_800A3DC8[];

void func_80038FE8(s32 index, s32 mode, u8 *colors, s16 *offsets) {
    u8 value;

    if (index >= 0 && index < 12) {
        if (mode == 0) {
            D_800A3FA8[index] = 1;
        } else {
            D_800A3FA8[index] = 2;
            value = colors[1]; D_800A3DC8[index].unk19 = value; D_800A3DC8[index].unk1C = value;
            value = colors[3]; D_800A3DC8[index].unk19 = value; D_800A3DC8[index].unk1D = value;
            value = colors[5]; D_800A3DC8[index].unk1A = value; D_800A3DC8[index].unk1E = value;
            D_800A3DC8[index].unk20 = -offsets[0];
            D_800A3DC8[index].unk21 = -offsets[1];
            D_800A3DC8[index].unk22 = -offsets[2];
        }
    }
}
