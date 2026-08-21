/* Independently written from scratchpad spec specs/func_8003F64C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[6];
    /* 0x06 */ s16 unk06;
} PcSweepItem;

typedef struct PcSweepGroup {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 stride;
    /* 0x10 */ PcSweepItem *items;
    /* 0x14 */ u8 unk14[0xC];
    /* 0x20 */ void (*visit)(PcSweepItem *item);
} PcSweepGroup;

extern PcSweepGroup **D_800A2170;
extern void func_80008F28(void);

void func_8003F64C(void) {
    PcSweepGroup **cursor;
    PcSweepGroup *group;
    PcSweepItem *item;
    void (*visit)(PcSweepItem *item);
    s16 index;

    cursor = D_800A2170;
    while (*cursor != 0) {
        group = *cursor;
        if (group->visit != 0) {
            visit = group->visit;
            item = group->items;
            for (index = 0; index < group->count; index++) {
                if ((item->unk06 & 0x1100) == 0) {
                    visit(item);
                }
                item = (PcSweepItem *)((u8 *)item + group->stride);
            }
            func_80008F28();
        }
        cursor++;
    }
}
