/* Independently written from scratchpad spec specs/func_80007218.md. */
#include "podcruise/types.h"

typedef struct Entry80007218 {
    struct Entry80007218 *unk00;
    struct Entry80007218 *unk04;
    u8 unk08[0x10 - 0x8];
    s32 unk10;
} Entry80007218;

typedef struct Anchor80007218 {
    s32 unk00;
    Entry80007218 *unk04;
} Anchor80007218;

typedef struct Region80007218 {
    u32 unk00;
    u32 unk04;
    s32 unk08;
    s32 unk0C;
} Region80007218;

typedef struct PcBoot80007218 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
} PcBoot80007218;

extern u8 D_800B05B8[];
extern u32 D_800D1D20;
extern Region80007218 D_800D1D28;
extern Entry80007218 D_800AFAC8[];
extern Entry80007218 D_800AFE74;
extern Entry80007218 D_800AFE88;
extern Anchor80007218 D_800AFAC0;
extern s32 D_800A81A8;
extern s32 D_8009A2B8;

extern u32 func_80007710(void **destination);
extern s32 func_80006FE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80007034(PcBoot80007218 *object);
extern void func_80007B10(void);
extern void func_80088020(Entry80007218 *list);
extern void func_80088050(Entry80007218 *link, Entry80007218 *anchor);
extern void func_80088110(Region80007218 *region, u32 base, s32 size);
extern s32 func_80088150(u32 rate);

void func_80007218(void) {
    Region80007218 *region;
    Entry80007218 *entry;
    u32 i;
    PcBoot80007218 boot;
    u32 n;

    n = 0x21768;
    i = 0;
    do {
        D_800B05B8[i] = 0;
        i++;
    } while (i < n);
    region = &D_800D1D28;
    D_800D1D20 = ((u32)(unsigned long)D_800B05B8 + 0x3F) & ~0x3F;
    func_80088110(region, D_800D1D20, 0x21728);

    entry = D_800AFAC8;
    do {
        entry->unk00 = 0;
        entry->unk04 = 0;
        entry++;
    } while (entry < &D_800AFE88);
    func_80088020(D_800AFAC8);
    for (i = 0; i < 48; i++) {
        if (&D_800AFAC8[i] < &D_800AFE74) {
            func_80088050(&D_800AFAC8[i + 1], &D_800AFAC8[i]);
        }
        D_800AFAC8[i].unk10 = func_80006FE4((s32)(unsigned long)&D_800A81A8, (s32)(unsigned long)region, 1, 0x400);
    }
    D_800AFAC0.unk00 = 0;
    D_800AFAC0.unk04 = D_800AFAC8;

    boot.unk00 = 8;
    boot.unk04 = 8;
    boot.unk08 = 0x40;
    boot.unk10 = (s32)(unsigned long)&func_80007710;
    boot.unk1C = 0;
    boot.unk18 = func_80088150(0x5622);
    boot.unk14 = (s32)(unsigned long)region;
    func_80007034(&boot);
    func_80007B10();
    D_8009A2B8 = 1;
}
