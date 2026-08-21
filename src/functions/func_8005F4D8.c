/* Independently written from scratchpad spec specs/func_8005F4D8.md (race entry setup). */

#include "podcruise/types.h"

typedef struct Flagged5F4D8 {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u32 unk10;
} Flagged5F4D8;

typedef struct Node5F4D8 {
    /* 0x00 */ u8 pad00[0x0E];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
} Node5F4D8;

typedef struct Owner5F4D8 {
    /* 0x000 */ Node5F4D8 *unk00;
    /* 0x004 */ Flagged5F4D8 *unk04;
    /* 0x008 */ Flagged5F4D8 *unk08;
    /* 0x00C */ Flagged5F4D8 *unk0C;
    /* 0x010 */ Flagged5F4D8 *unk10;
    /* 0x014 */ Flagged5F4D8 *unk14;
    /* 0x018 */ u8 pad018[0x1C - 0x18];
    /* 0x01C */ void *unk1C;
    /* 0x020 */ u8 pad020[4];
    /* 0x024 */ void *unk24;
    /* 0x028 */ u8 pad028[0x70 - 0x28];
    /* 0x070 */ Flagged5F4D8 *unk70;
    /* 0x074 */ Flagged5F4D8 *unk74;
    /* 0x078 */ u8 pad078[0xA8 - 0x78];
    /* 0x0A8 */ Flagged5F4D8 *unkA8;
    /* 0x0AC */ Flagged5F4D8 *unkAC;
    /* 0x0B0 */ u8 pad0B0[0x104 - 0xB0];
    /* 0x104 */ void *unk104;
    /* 0x108 */ void *unk108;
    /* 0x10C */ u8 pad10C[0x11C - 0x10C];
    /* 0x11C */ Flagged5F4D8 *unk11C;
    /* 0x120 */ void *unk120;
    /* 0x124 */ void *unk124;
} Owner5F4D8;

typedef struct Slot5F4D8 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u8 pad0C[0x58 - 0x0C];
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 pad5E[2];
    /* 0x60 */ f32 unk60[5];
    /* 0x74 */ f32 unk74;
    /* 0x78 */ s32 unk78;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ struct Entry5F4D8 *unk84;
} Slot5F4D8;

typedef struct Entry5F4D8 {
    /* 0x0000 */ u8 pad0000[4];
    /* 0x0004 */ s16 unk04;
    /* 0x0006 */ u8 pad0006[0x20 - 6];
    /* 0x0020 */ u32 unk20;
    /* 0x0024 */ u8 pad0024[0x60 - 0x24];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u8 pad0064[0x300 - 0x64];
    /* 0x0300 */ s32 unk300;
    /* 0x0304 */ u8 pad0304[0x348 - 0x304];
    /* 0x0348 */ void *unk348;
    /* 0x034C */ s32 unk34C;
    /* 0x0350 */ u8 pad0350[0x1994 - 0x350];
    /* 0x1994 */ void *unk1994;
    /* 0x1998 */ u8 pad1998[0x1E70 - 0x1998];
    /* 0x1E70 */ Node5F4D8 *unk1E70;
} Entry5F4D8;

typedef struct Root5F4D8 {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ void *unk2C;
    /* 0x30 */ void *unk30;
    /* 0x34 */ u8 pad34[0x1BC - 0x34];
    /* 0x1BC */ void *unk1BC;
} Root5F4D8;

typedef struct Pool5F4D8 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 count;
    /* 0x18 */ void **items;
} Pool5F4D8;

typedef struct Scene5F4D8 {
    u8 pad00[0x10];
    u32 unk10x;
    s32 unk14;
    void *unk18;
    u8 pad1C[0x58 - 0x1C];
} Scene5F4D8;

extern Pool5F4D8 D_8011ACC0;
extern s32 D_8011AD24;
extern void **D_8011AD28;
extern Scene5F4D8 D_8011AD60[];
extern s32 D_8011B180[];
extern void *D_8011B1B0;
extern void *D_8011B1B4;
extern s32 D_800A52BC;

extern Entry5F4D8 *func_8003FBD4(s32 tag);
extern void func_80018324(void *object, u32 flags);
extern void func_80017874(f32 *destination);
extern void func_80017BA8(void *destination, f32 *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_8005F31C(void *slot, void *value);
extern void func_8005F33C(void *owner, f32 *mover, s32 position);
extern s32 func_80051FF4(void);
extern void func_80072AD0(Entry5F4D8 *entry, void *a1, Owner5F4D8 *owner,
                          void *a3, s32 a4, f32 *a5, s32 a6, void *a7, s32 a8,
                          s32 a9);
extern void func_80086CA0(s32 argument);
extern void func_8000AEFC(s16 index, s16 second, void *third, s16 fourth);

void func_8005F4D8(Root5F4D8 *root, Slot5F4D8 *slot, s32 arg2, Owner5F4D8 *owner,
                   s32 arg4, void *arg5, s32 arg6, s32 arg7) {
    Scene5F4D8 *scene;
    s32 i;
    Entry5F4D8 *entry;
    f32 mover[20];
    s32 index;
    void *record;
    f32 spare[4];
    f32 transform[12];

    (void)arg4;
    (void)spare;

    slot->unk58 = 0;
    slot->unk78 = 0;
    slot->unk5C = -1;
    slot->unk74 = 0;
    for (i = 0; i < 5; i++) {
        slot->unk60[i] = -1.0f;
    }
    slot->unk08 &= ~1;
    slot->unk7C = 0;
    slot->unk08 &= ~2;
    slot->unk60[0] = 0.0f;

    entry = func_8003FBD4(0x54657374);
    slot->unk84 = entry;
    entry->unk1E70 = (Node5F4D8 *)slot;

    if (owner != 0) {
        D_8011ACC0.items[D_8011ACC0.count] = owner->unk00;
        D_8011ACC0.count = D_8011ACC0.count + 1;
        index = D_8011AD24;
        scene = &D_8011AD60[index];
        record = scene;
        func_80018324(scene, 0xD065);
        D_8011AD28[index] = record;
        scene->unk14 = 1;
        scene->unk18 = &D_8011B180[index];
        scene->unk18 = owner->unk00->unk18;
        func_80017874(transform);
        transform[10] = -1.0f;
        func_80017BA8(scene, transform);
        scene->unk10x |= 1;
        /* The cursor is reached through the word below the slot-pointer
           array so that its address is materialised independently of the
           store, as the original does. */
        D_8011AD24 = ((s32 *)&D_8011AD28)[-1] + 1;

        func_8005F31C(owner->unk1C, &D_8011B1B0);
        func_8005F31C(owner->unk24, &D_8011B1B0);
        if (owner->unk120 != 0) {
            func_800181BC(owner->unk120, 2, -4, 0x10, 3);
        }
        if (owner->unk124 != 0) {
            func_800181BC(owner->unk124, 2, -4, 0x10, 3);
        }
        func_8005F31C(owner->unk104, &D_8011B1B4);
        func_8005F31C(owner->unk108, &D_8011B1B4);
    } else if (arg5 != 0) {
        D_8011ACC0.items[D_8011ACC0.count] = arg5;
        D_8011ACC0.count = D_8011ACC0.count + 1;
        if (arg5 != 0) {
            func_800181BC(arg5, 2, 3, 0x10, 2);
        }
        record = 0;
    }

    func_8005F33C(root, mover, entry->unk1E70->unk14);
    func_80072AD0(entry, root->unk2C, owner, root->unk30, entry->unk04, mover,
                  arg2, root->unk1BC, func_80051FF4(), arg7);
    entry->unk348 = arg5;
    entry->unk34C = arg6;
    entry->unk1994 = record;

    if (owner != 0) {
        if (entry->unk60 & 0x20) {
            owner->unk00->unk10 |= 0xC;
            owner->unk00->unk0E = entry->unk300;
            if (D_800A52BC < 2) {
                if (owner->unk04 != 0) {
                    owner->unk04->unk10 |= 0x10;
                }
                if (owner->unk08 != 0) {
                    owner->unk08->unk10 |= 0x10;
                }
                if (owner->unk0C != 0) {
                    owner->unk0C->unk10 |= 0x10;
                }
                if (owner->unk10 != 0) {
                    owner->unk10->unk10 |= 0x10;
                }
                if (owner->unk14 != 0) {
                    owner->unk14->unk10 |= 0x10;
                }
                if (owner->unk11C != 0) {
                    owner->unk11C->unk10 |= 0x10;
                }
                if (owner->unkA8 != 0) {
                    owner->unkA8->unk10 |= 0x100;
                }
                if (owner->unkAC != 0) {
                    owner->unkAC->unk10 |= 0x100;
                }
                if (owner->unk70 != 0) {
                    owner->unk70->unk10 |= 0x100;
                }
                if (owner->unk74 != 0) {
                    owner->unk74->unk10 |= 0x100;
                }
            }
        }
    }

    func_80086CA0(entry->unk300);
    if (entry->unk60 & 0x100) {
        func_8000AEFC(1, 1, &entry->unk20, 0);
    }
}
