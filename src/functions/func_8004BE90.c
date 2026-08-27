/* Independently written from the specification specs/func_8004BE90.md. */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x8];
    s32 kind;
    u8 pad0C[0x2C];
    s32 phase;
    s32 previous;
    u8 pad40[0x11];
    s8 unk51;
    u8 pad52[0xB];
    s8 unk5D;
    u8 pad5E[0x12];
    s8 count;
    s8 pad71;
    s8 entries[0x42];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    u8 slots[4];
} PcRaceState;

typedef struct {
    u8 pad00[0x4];
    s32 unk04;
    s32 unk08;
    u8 pad0C[0x14];
    f32 unk20;
    u8 pad24[0xC];
    s32 unk30;
} PcRacerRecord;

typedef struct {
    u8 pad00[0x8];
    s32 unk08;
    u8 pad0C[0x4];
    s32 unk10;
} PcOptionBlock;

typedef struct {
    u8 pad00[0x1C];
    u8 unk1C;
} PcNameBlock;

extern PcRacerRecord D_800A31E0[];
extern s8 D_800A21C2[];
extern u8 D_800AAE44[];
extern u8 D_800AAE48[];
extern PcOptionBlock D_80113680;
extern PcNameBlock D_80113E60;
extern u8 D_80113E7C;
extern s32 D_800D76F0;
extern s32 *D_8011A508[];
extern s32 *D_8011A544;

extern void func_80051898(s32 arg0);
extern void func_8000A44C(s16 index, s32 arg1);
extern void func_80005B80(void);
extern void func_80046870(void);
extern s32 func_80030154(s32 argument);
extern void func_8000AC34(s16 index, u32 bits);
extern void func_8000AC60(s16 index, u32 bits);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_8004B3FC(void);
extern void func_8004B084(void);
extern void func_8004B18C(void);
extern void func_80046670(s32 arg0, s32 arg1, s32 slot, s32 arg3);
extern void func_8004AFD4(void);
extern s32 func_80082BE0(void);
extern void func_800517D8(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
extern void func_8004B568(void);
extern void func_8002963C(void *owner);
extern void func_8004B6E8(void);
extern s32 func_8002D968(u8 *arg0, u8 *arg1);
extern void func_8002FB90(void);

void func_8004BE90(PcRaceState *state) {
    PcRacerRecord *record;
    s32 *target;
    s32 index;
    s32 slot;
    s32 racer;
    s32 mode;
    s32 stride;

    mode = 3;
    stride = 0x34;
    switch (state->kind) {
    case 1:
    case 2:
    case 3:
    case 5:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 18:
        state->phase = 3;
        break;
    case 8:
    case 15:
    case 17:
        state->phase = 2;
        break;
    case 4:
        state->phase = 1;
        break;
    case 7:
        state->phase = 0;
        break;
    case 16:
        state->phase = 0x4C;
        break;
    case 0:
        state->phase = -1;
        break;
    case 14:
        return;
    default:
        state->phase = -1;
        break;
    }

    if (mode == state->previous && mode == state->phase) {
        return;
    }

    func_80051898(2);
    for (index = 0; index < 0xB5; index++) {
        if (index < 0x9F || index >= 0xB5) {
            func_8000A44C((s16)index, 0);
        }
    }
    func_80005B80();
    func_80046870();

    if (state->phase == 3) {
        if ((D_80113680.unk08 & 0x40) && (D_800D76F0 & 4)) {
            func_8000A44C(0x4D, func_80030154(0xAA));
            state->unk51 = 1;
        } else {
            func_8000A44C(0x4D, func_80030154(0xA0));
            if (D_80113680.unk08 & 0x20) {
                func_8000AC34(0x4D, 4);
            }
            state->unk51 = 0;
        }
        func_8000AC60(0x4D, 1);
        func_8000AC34(0x4D, 2);
        func_8000A44C(0x4E, func_80030154(0xA1));
        func_8000A44C(0x51, func_80030154(0xA2));
        func_8000A44C(0x4F, func_80030154(0xA4));
        func_8000A44C(0x50, func_80030154(0xA5));
        func_8004B3FC();
        func_8004B084();
        func_8004B18C();
        func_8000A44C(0x45, func_80030154(0x89));
        func_8000A44C(0x46, func_80030154(0x82));
        func_8000A44C(0x47, func_80030154(0x83));
        func_8000A44C(0x48, func_80030154(0x84));
        func_8000A44C(0x49, func_80030154(0x85));
        func_8000A44C(0x4A, func_80030154(0x86));
        func_8000A44C(0x4B, func_80030154(0x87));
        func_8000A44C(0x4C, func_80030154(0x88));
        func_80046670(0x78, -1, 0x53, 0);
        func_8004AFD4();
        func_80046670(0x30, -1, 6, 0);
        do {
            racer = (s32)(((f32)func_80082BE0() / 2147483648.0f) * 22.0f) + 1;
        } while (((1 << racer) & D_80113680.unk10) == 0);
        record = (PcRacerRecord *)(racer * stride + (u8 *)D_800A31E0);
        func_800517D8(record->unk30, 0x38, 2, record->unk20);
        if ((D_80113680.unk10 << 13) != 0) {
            func_800517D8(0x6D, 0x39, 1, -1.0f);
        } else {
            do {
                racer = (s32)(((f32)func_80082BE0() / 2147483648.0f) * 23.0f);
            } while (((1 << racer) & D_80113680.unk10) != 0);
            record = (PcRacerRecord *)(racer * stride + (u8 *)D_800A31E0);
            func_800517D8(record->unk30, 0x39, 2, record->unk20);
        }
        func_800517D8(0xEF, 0x16, 7, -1.0f);
        func_800517D8(0xF2, 0x17, 0xA, -1.0f);
        state->unkC8 = func_80030154(0x1A);
        for (index = 0; index < 4; index++) {
            func_8000A44C((s16)(index + 0x7F), state->unkC8);
        }
        state->unkB4 = func_80030154(0x5C);
        state->unkB8 = func_80030154(0x5D);
        state->unkBC = func_80030154(0x5E);
        state->unkC0 = func_80030154(0x5F);
        state->unkC4 = func_80030154(0x61);
        func_8000A44C(0x5F, func_80030154(0x60));
        func_8000AC34(0x5F, 0x8000);
        func_8000AB24(0x5F, 0x32, 0xFF, 0xFF, 0xFE);
        func_80051898(3);
        for (index = 0; index != 1; index++) {
            record = (PcRacerRecord *)(state->entries[index] * stride + (u8 *)D_800A31E0);
            func_800517D8(record->unk30, index + 0x1C, 2, record->unk20);
        }
    } else {
        switch (state->kind) {
        case 0:
            break;
        case 8:
            func_8004B3FC();
            func_8004B568();
            for (index = 0; index < state->count; index++) {
                racer = state->entries[index];
                record = (PcRacerRecord *)(racer * stride + (u8 *)D_800A31E0);
                func_80046670(record->unk04, record->unk08, index + 0xF, 0);
                target = D_8011A508[index + 0xF];
                if (target != 0) {
                    target[0x3C] = racer;
                }
            }
            func_80046670(0x3C, -1, 0x55, 0);
            func_80046670(0x44, -1, 0x56, 0);
            slot = 0x57;
            func_80046670(0x45, -1, slot++, 0);
            func_80046670(0x44, -1, slot, 0);
            for (index = 0; index < 4; index++) {
                func_80046670(0x46, -1, index + 0x59, 0);
                func_80046670(0x130, -1, index + 7, 0);
                func_80046670(0x131, -1, index + 0xB, 0);
            }
            func_80046670(0x92, -1, 0x61, 1);
            for (index = 0; index < 4; index++) {
                func_80046670(0x31, -1, index + 0x5D, 1);
            }
            for (index = 0; index < state->count; index++) {
                record = (PcRacerRecord *)(state->entries[index] * stride + (u8 *)D_800A31E0);
                func_800517D8(record->unk30, index + 0x1C, 2, record->unk20);
            }
            index = 0;
            if (D_80113E7C > 0) {
                do {
                    func_800517D8(0x6D, index + 0x34, 1, -1.0f);
                    index++;
                } while (index < D_80113E60.unk1C);
            }
            func_8002963C(state);
            func_80046670(0x6D, -1, 0x95, 0);
            func_800517D8(0x6F, 0x13, 4, -1.0f);
            func_800517D8(0x70, 0x14, 5, -1.0f);
            break;
        case 4:
        case 7:
            func_8004B3FC();
            func_8004B6E8();
            func_80046670(0x78, -1, 0x53, 0);
            func_8002963C(state);
            func_800517D8(0x6E, 0x15, 3, -1.0f);
            for (index = 0; index < state->count; index++) {
                record = (PcRacerRecord *)(state->entries[index] * stride + (u8 *)D_800A31E0);
                func_800517D8(record->unk30, index + 0x1C, 2, record->unk20);
            }
            for (index = 0; index < 4 - D_80113E60.unk1C; index++) {
                func_800517D8(0x6D, index + 0x34, 1, -1.0f);
            }
            for (index = 0; index != 4; index++) {
                func_80046670(0x131, -1, index + 0xB, 0);
            }
            func_800517D8(0xF2, 0x17, 0xA, -1.0f);
            func_800517D8(0xF1, 0x1B, 9, -1.0f);
            func_800517D8(0x12F, 0x19, 0xB, -1.0f);
            func_800517D8(0xF3, 0x18, 0xC, -1.0f);
            func_800517D8(0xF0, 0x1A, 8, -1.0f);
            if (func_8002D968((u8 *)&D_80113E60, D_800AAE44)) {
                func_800517D8(0x6F, 0x13, 4, -1.0f);
            } else if (func_8002D968((u8 *)&D_80113E60, D_800AAE48)) {
                func_800517D8(0x70, 0x14, 5, -1.0f);
            }
            break;
        case 15:
            slot = func_80030154(0x1A);
            for (index = 0; index != 2; index++) {
                func_8000A44C((s16)(index + 0x7F), slot);
                if (index == 0) {
                    racer = state->entries[0];
                } else {
                    racer = D_800A21C2[state->unk5D * 12];
                }
                record = (PcRacerRecord *)(racer * stride + (u8 *)D_800A31E0);
                func_800517D8(record->unk30, index + 0x1C, 2, record->unk20);
                func_80046670(record->unk04, record->unk08, index + 0xF, 0);
                target = D_8011A508[index + 0xF];
                if (target != 0) {
                    target[0x3C] = racer;
                }
            }
            break;
        case 16:
            for (index = 0; index != 3; index++) {
                record = (PcRacerRecord *)(state->slots[index] * stride + (u8 *)D_800A31E0);
                func_800517D8(record->unk30, index + 0x1C, 2, record->unk20);
                func_80046670(0x7C, -1, index + 0x4D, 0);
            }
            func_80046670(0x7B, -1, 0x50, 0);
            func_80046670(0x7D, -1, 0x51, 0);
            func_80046670(0x7E, -1, 0x52, 0);
            func_80046670(0x7F, -1, 0x4C, 0);
            break;
        case 17:
            slot = func_80030154(0x1A);
            for (index = 0; index != 2; index++) {
                func_8000A44C((s16)(index + 0x7F), slot);
            }
            racer = D_800A21C2[state->unk5D * 12];
            record = (PcRacerRecord *)(racer * stride + (u8 *)D_800A31E0);
            func_80046670(record->unk04, record->unk08, 0xF, 0);
            target = D_8011A544;
            if (target != 0) {
                target[0x3C] = racer;
            }
            func_800517D8(0x6D, 0x34, 1, -1.0f);
            break;
        default:
            break;
        }
    }

    func_8002FB90();
}
