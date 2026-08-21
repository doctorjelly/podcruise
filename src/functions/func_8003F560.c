/* Independently written from specs/func_8003F560.md (worker scratchpad). */

#include "podcruise/types.h"

typedef struct Entry {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ u8 *unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ void (*unk1C)(u8 *);
} Entry;

extern Entry **D_800A2170;
extern s16 D_800A4AA0;

extern void func_80008F28(void);

void func_8003F560(void) {
    Entry **cursor;
    Entry *entry;
    void (*handler)(u8 *);
    u8 *item;
    s16 index;

    cursor = D_800A2170;
    while (*cursor != 0) {
        entry = *cursor;
        if (entry->unk1C != 0) {
            handler = entry->unk1C;
            if ((entry->unk04 & D_800A4AA0) == 0) {
                item = entry->unk10;
                for (index = 0; index < entry->unk08; index++) {
                    if ((*(s16 *)(item + 6) & 0x1100) == 0) {
                        handler(item);
                    }
                    item += entry->unk0C;
                    func_80008F28();
                }
            }
        }
        cursor++;
    }
}
