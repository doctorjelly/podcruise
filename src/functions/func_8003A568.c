/* Independently written from scratchpad spec specs/func_8003A568.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u8 unk06[0x3C];
    /* 0x42 */ s16 unk42[9];
} Record8003A568; /* 0x54 */

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u8 unk04[8];
    /* 0x0C */ Record8003A568 *unk0C;
} Table8003A568;

typedef struct {
    /* 0x00 */ Table8003A568 *unk00;
    /* 0x04 */ u8 unk04[0xC];
    /* 0x10 */ s32 unk10[7];
    /* 0x2C */ s32 unk2C;
} Holder8003A568;

s32 func_8003A568(Holder8003A568 *holder, s32 index) {
    s32 value;
    s32 entry;
    s32 shifted;

    value = holder->unk2C;
    if (value == 0) {
        return holder->unk10[index];
    }
    entry = holder->unk10[index];
    if (index == 0) {
        shifted = value;
    } else {
        shifted = value >> index;
    }
    return holder->unk00->unk0C[entry].unk42[shifted];
}
