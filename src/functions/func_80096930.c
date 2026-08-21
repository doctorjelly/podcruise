/* Independently written from scratchpad spec specs/func_80096930.md. */

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
} CommandRecord;

extern CommandRecord D_8014D720[];
extern u8 D_80149CB0;
extern u8 D_80149CB1;
extern s32 D_8014D75C;

void func_80096930(u8 value) {
    CommandRecord *cursor;
    CommandRecord command;
    s32 index;

    cursor = D_8014D720;
    D_80149CB0 = value;
    D_8014D75C = 1;

    command.unk0 = 0xFF;
    command.unk1 = 1;
    command.unk2 = 3;
    command.unk3 = value;
    command.unk4 = 0xFF;
    command.unk5 = 0xFF;
    command.unk6 = 0xFF;
    command.unk7 = 0xFF;

    for (index = 0; index < D_80149CB1; index++) {
        *cursor = command;
        cursor++;
    }

    cursor->unk0 = 0xFE;
}
