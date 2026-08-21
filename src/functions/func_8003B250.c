/* Independently written from scratchpad spec specs/func_8003B250.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u8 unk06[0x3C];
    /* 0x42 */ s16 unk42[9];
} Record8003B250; /* 0x54 */

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u8 unk04[8];
    /* 0x0C */ Record8003B250 *unk0C;
} Table8003B250;

typedef struct {
    /* 0x00 */ Table8003B250 *unk00;
    /* 0x04 */ u8 unk04[0xC];
    /* 0x10 */ s32 unk10[7];
    /* 0x2C */ s32 unk2C;
} Holder8003B250;

void func_8003B250(Holder8003B250 *holder, s32 index) {
    Table8003B250 *table;

    table = holder->unk00;
    holder->unk10[0] = index;
    holder->unk10[1] = index;
    holder->unk10[2] = index;
    holder->unk10[3] = index;
    if (table->unk0C[index].unk00 != 0) {
        holder->unk10[1] = table->unk0C[holder->unk10[1]].unk04;
        if (table->unk00 == 0) {
            if (table->unk0C[holder->unk10[1]].unk00 != 0) {
                holder->unk10[2] = table->unk0C[holder->unk10[1]].unk04;
                if (table->unk0C[holder->unk10[2]].unk00 != 0) {
                    holder->unk10[3] = table->unk0C[holder->unk10[2]].unk04;
                }
            }
        }
    }
}
