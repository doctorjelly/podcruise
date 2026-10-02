/* Recovered from specs/functions/recovered/medium_service_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ void *unk18;
} SlotRecord;

extern SlotRecord D_800DB8A0[4];
extern s32 D_800DB910[4];
extern s32 D_800A290C[4];
extern s32 D_800A291C;
extern s32 D_800A2918[2];
extern s32 D_800A2910[4];

extern void func_8002E82C(s32 index);
extern s32 func_8002F054(void);
extern s32 func_8008B1B0(void *record, s32 value);

void func_800316A8(void) {
    SlotRecord *slot;
    s32 index;
    s32 one;
    s32 changed;
    u16 bits;

    one = 1;
    for (index = 0; index < 4; index++) {
        if (D_800DB910[index] != 0) {
            func_8002E82C(index);
            D_800DB910[index] = 0;
        }
        slot = &D_800DB8A0[index];
        if (slot->unk10 != 0) {
            if (func_8002F054() == 1) {
                if (D_800A291C == 0) {
                    D_800A2918[1] = one;
                    func_8002E82C(-1);
                }
            } else {
                D_800A2910[3] = 0;
            }
            if (func_8002F054() == 1 || slot->unk0C == 0) {
                slot->unk08 = 0;
                if (slot->unk0A != 0) {
                    func_8008B1B0(slot->unk18, 0);
                    func_8008B1B0(slot->unk18, 0);
                    func_8008B1B0(slot->unk18, 0);
                    D_800A290C[index] = -1;
                    if (slot->unk0A > 0) {
                        slot->unk0A = -2;
                    } else {
                        slot->unk0A = slot->unk0A + 1;
                    }
                }
            } else {
                if (slot->unk08 == 0) {
                    changed = 0;
                } else if (slot->unk08 != 2) {
                    bits = slot->unk06;
                    if ((bits & slot->unk04) != 0) {
                        changed = 1;
                    } else {
                        changed = 0;
                    }
                    slot->unk06 = (u32)bits >> 1;
                    if (slot->unk06 == 0) {
                        if (slot->unk08 == 1) {
                            slot->unk06 = 0x8000;
                        } else {
                            slot->unk08 = 0;
                        }
                    }
                } else {
                    slot->unk14 = slot->unk14 + slot->unk16;
                    if (slot->unk14 > 0x400) {
                        slot->unk14 = slot->unk14 - 0x400;
                        changed = 1;
                    } else {
                        changed = 0;
                    }
                }
                if (changed == 0) {
                    if (slot->unk0A > 0) {
                        slot->unk0A = -3;
                    }
                    if (slot->unk0A < 0) {
                        func_8008B1B0(slot->unk18, 0);
                        func_8008B1B0(slot->unk18, 0);
                        func_8008B1B0(slot->unk18, 0);
                        D_800A290C[index] = -1;
                        slot->unk0A = slot->unk0A + 1;
                    }
                } else {
                    if (slot->unk0A <= 0) {
                        func_8008B1B0(slot->unk18, 1);
                        slot->unk0A = 1;
                    }
                }
            }
        }
    }
}
