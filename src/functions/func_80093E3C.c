/* Independently written from the specification $S/specs/func_80093E3C.md. */
#include "podcruise/types.h"

typedef struct Entry {
    /* 0x00 */ struct Entry *unk00;
    /* 0x04 */ struct Entry *unk04;
    /* 0x08 */ unsigned long long unk08;
    /* 0x10 */ unsigned long long unk10;
    /* 0x18 */ void *unk18;
    /* 0x1C */ s32 unk1C;
} Entry;

extern Entry *D_800A7FC0;
extern u32 D_8014C520;

extern u32 func_8008C550(void);
extern s32 func_8008C930(void *, s32, s32);
extern void func_80093FB4(long long);
extern long long func_80094028(Entry *);
extern void func_80097980(u32);

void func_80093E3C(void) {
    Entry *entry;
    u32 now;
    u32 delta;

    if (D_800A7FC0->unk00 == D_800A7FC0) {
        return;
    }
    for (;;) {
        entry = D_800A7FC0->unk00;
        if (entry == D_800A7FC0) {
            func_80097980(0);
            D_8014C520 = 0;
            return;
        }
        now = func_8008C550();
        delta = now - D_8014C520;
        D_8014C520 = now;
        if (delta < entry->unk10) {
            entry->unk10 -= delta;
            func_80093FB4(entry->unk10);
            return;
        }
        entry->unk04->unk00 = entry->unk00;
        entry->unk00->unk04 = entry->unk04;
        entry->unk00 = 0;
        entry->unk04 = 0;
        if (entry->unk18 != 0) {
            func_8008C930(entry->unk18, entry->unk1C, 0);
        }
        if (entry->unk08 != 0) {
            entry->unk10 = entry->unk08;
            func_80094028(entry);
        }
    }
}
