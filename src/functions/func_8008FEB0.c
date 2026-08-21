/* Independently written from specs/func_8008FEB0.md (worker scratchpad). */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *unk00;
    /* 0x04 */ struct Link *unk04;
} Link;

typedef struct Info {
    /* 0x00 */ s8 pad00[0x16];
    /* 0x16 */ s16 unk16;
} Info;

typedef struct Item {
    /* 0x00 */ struct Item *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ Info *unk08;
    /* 0x0C */ s8 pad0C[0xCC];
    /* 0xD8 */ s32 unkD8;
} Item;

typedef struct Owner {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ Item *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ Link unk0C;
    /* 0x14 */ Item *unk14;
} Owner;

extern void func_80088020(Link *arg0);
extern void func_80088050(Link *arg0, Link *arg1);

s32 func_8008FEB0(owner, out, limit)
Owner *owner;
Item **out;
s16 limit;
{
    Item *item;
    s32 unused1;
    s32 found;
    s32 unused2;

    found = 0;
    (void)unused1;
    (void)unused2;

    item = owner->unk14;
    if (item != 0) {
        *out = item;
        func_80088020((Link *)item);
        func_80088050((Link *)item, &owner->unk0C);
    } else {
        item = owner->unk04;
        if (item != 0) {
            *out = item;
            func_80088020((Link *)item);
            func_80088050((Link *)item, &owner->unk0C);
        } else {
            for (item = (Item *)owner->unk0C.unk00; item != 0; item = item->unk00) {
                if (limit >= item->unk08->unk16 && item->unkD8 == 0) {
                    *out = item;
                    limit = item->unk08->unk16;
                    found = 1;
                }
            }
        }
    }

    return found;
}
