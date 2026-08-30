/* Independently written from specs/functions/recovered/func_8004F790.md. */

#include "podcruise/types.h"

typedef struct {
    f32 unk_00[15];
} Profile;

typedef struct {
    u8  pad00[0x14];
    u32 unk14;
    u8  pad18[0x5];
    u8  unk1D[7];
    u8  unk24[7];
    u8  pad2B[1];
} Choice;

typedef struct {
    s32     unk00;
    u32     unk04;
    u32     unk08;
    Choice *unk0C;
    u8      unk10;
    u8      unk11;
    u8      pad12[2];
    s32     unk14;
    void   *unk18;
    Profile unk1C;
    u8      pad58[0x30];
} Slot;

typedef struct {
    u8  pad00[0x5D];
    s8  unk5D;
    u8  pad5E[6];
    s32 unk64;
    u8  pad68[8];
    s8  unk70;
    s8  unk71;
    s8  unk72[1];
} Holder;

typedef struct {
    u8 pad00[0x34];
} Style;

extern s8 D_800A21B8[];
extern Style D_800A31E0[];
extern Profile D_800A368C[];
extern Profile D_800A3BF0;
extern Choice D_80113E60[];
extern Slot D_80118F90[];
extern f32 D_80119838[];
extern f32 D_80119858[];

extern s32 func_80082BE0(void);
extern void func_80032F2C(Profile *target, Profile *source, u8 *modes,
                          u8 *levels);
extern void func_800320E0(f32 *settings, Profile *source);
extern s32 func_8004FE30(Holder *holder);

Slot *func_8004F790(Holder *holder, s32 enable) {
    s32 order[15];
    s32 mask;
    s32 index;
    s32 sub;
    s32 retry;
    s32 best;
    Slot *slot;
    s16 counter;

    mask = 0x0FFFFFFF;
    if (enable == 0) {
        return D_80118F90;
    }

    for (index = 0; index < holder->unk70; index++) {
        mask |= D_80113E60[index].unk14;
    }

    if (holder->unk64 == 2) {
        holder->unk72[0] = (s8)((f32)func_80082BE0() / (f32)2147483648.0 * 23.0f);
    }

    for (index = holder->unk70; index < holder->unk71; index++) {
        do {
            retry = 0;
            holder->unk72[index] = (s8)((f32)func_80082BE0() / (f32)2147483648.0 * 23.0f);
            if (index == 1 &&
                holder->unk72[0] != D_800A21B8[holder->unk5D * 12 + 10]) {
                holder->unk72[index] = D_800A21B8[holder->unk5D * 12 + 10];
                continue;
            }
            for (sub = 0; sub < index; sub++) {
                if (holder->unk72[index] == holder->unk72[sub]) {
                    retry = 1;
                }
                if (((1 << holder->unk72[index]) & mask) == 0) {
                    retry = 1;
                }
            }
        } while (retry);
    }

    counter = 0;
    for (index = 0, slot = D_80118F90; index < holder->unk71; index++, slot++) {
        order[index] = index;
        if (index < 2) {
            slot->unk0C = &D_80113E60[index];
        } else {
            slot->unk0C = 0;
        }
        slot->unk00 = index;
        if (index < holder->unk70) {
            slot->unk04 = 0x4C6F636C;
            if (holder->unk64 != 0) {
                slot->unk04 = 0x41414949;
            }
        } else {
            slot->unk04 = 0x41414949;
        }
        slot->unk08 = slot->unk08 & ~1;
        if (index < holder->unk70) {
            if ((slot->unk08 & 1) != 0) {
                slot->unk10 = counter++;
                slot->unk11 = counter++;
            } else {
                slot->unk10 = counter;
                slot->unk11 = counter++;
            }
        }
        slot->unk14 = order[index];
        slot->unk18 = &D_800A31E0[holder->unk72[index]];
        if (slot->unk04 == 0x41414949) {
            slot->unk1C = D_800A3BF0;
            slot->unk1C.unk_00[10] =
                D_800A368C[holder->unk72[index]].unk_00[10];
            slot->unk1C.unk_00[12] =
                D_800A368C[holder->unk72[index]].unk_00[12];
            slot->unk1C.unk_00[14] =
                D_800A368C[holder->unk72[index]].unk_00[14];
        } else {
            u8 modes[8];
            u8 levels[8];

            if (slot->unk0C != 0) {
                for (sub = 0; sub < 7; sub++) {
                    modes[sub] = slot->unk0C->unk1D[sub];
                    levels[sub] = slot->unk0C->unk24[sub];
                }
            } else {
                for (sub = 0; sub < 7; sub++) {
                    modes[sub] = 0;
                    levels[sub] = 255;
                }
            }
            func_80032F2C(&slot->unk1C,
                          &D_800A368C[holder->unk72[index]], modes, levels);
            func_800320E0(D_80119838, &D_800A368C[holder->unk72[index]]);
            func_800320E0(D_80119858, &slot->unk1C);
        }
    }

    for (index = 0; index < holder->unk70; index++) {
    }

    best = func_8004FE30(holder);
    for (index = 0, slot = D_80118F90; index < holder->unk71; index++, slot++) {
        if (best == index) {
            slot->unk08 = slot->unk08 | 0x20;
        } else {
            slot->unk08 = slot->unk08 & ~0x20;
        }
    }

    return D_80118F90;
}
