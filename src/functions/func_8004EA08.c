/* Independently written from specs/functions/recovered/func_8004EA08.md. */

#include "podcruise/types.h"

typedef struct {
    s32 values[8];
} Counts8004EA08;

typedef struct {
    f32 unk00;
    s32 unk04;
    s32 unk08;
    f32 unk0C;
    s32 unk10;
    s32 unk14;
    u8 pad18[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    f32 unk38;
    s32 unk3C;
    s32 unk40;
} Control8004EA08;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
    s32 unk14;
    s32 unk18;
    f32 unk1C[15];
    s32 unk58;
    s16 unk5C;
    u8 pad5E[2];
    f32 unk60[5];
    f32 unk74;
    s32 unk78;
    s32 unk7C;
    u8 pad80[4];
    s32 unk84;
} Record8004EA08;

typedef struct {
    s32 first;
    s32 last;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char name[64];
} Group8004EA08;

typedef struct {
    f32 values[6];
} Item8004EA08;

typedef struct {
    u8 pad00[8];
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    f32 unk44[3];
    u8 unk50;
    u8 unk51;
    u8 pad52[2];
    f32 unk54;
    f32 unk58;
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    u8 unk60;
    u8 pad61[0x28];
    u8 unk89;
    u8 pad8A[8];
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    u8 padAA[0xA];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    u8 unkCC[3];
} State8004EA08;

extern Counts8004EA08 D_800A5228;
extern Control8004EA08 D_8011A240;
extern s32 D_8011A2A8[151];
extern s32 D_8011A508[151];
extern s32 D_8011A768[151];
extern s32 D_8011A9C8[151];
extern Record8004EA08 D_80118F90[12];
extern Group8004EA08 D_800D6DD8[8];
extern Item8004EA08 D_80119670[15];
extern s32 D_800A4BE8;

extern char D_800AAE54[];
extern char D_800AAE64[];
extern char D_800AAE78[];
extern char D_800AAE8C[];
extern char D_800AAEA0[];
extern char D_800AAEB0[];
extern char D_800AAEC4[];
extern char D_800AAED4[];

extern void func_80028070(State8004EA08 *);
extern void func_80039828(void);
extern void func_80046974(void);
extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80050208(State8004EA08 *);
extern s32 func_80082BE0(void);
extern f32 func_80051934(void);
extern s32 func_8008A6B4(char *, const char *, ...);

void func_8004EA08(State8004EA08 *state) {
    Counts8004EA08 counts;
    Group8004EA08 *group;
    Record8004EA08 *record;
    Item8004EA08 *item;
    s32 groupIndex;
    s32 index;
    s32 total;
    s32 count;
    s32 random;
    f32 unit;
    f32 sign;

    counts = D_800A5228;

    D_8011A240.unk00 = 0.0f;
    D_8011A240.unk04 = 0;
    D_8011A240.unk08 = 0;
    D_8011A240.unk0C = 0.0f;
    D_8011A240.unk10 = 0;
    D_8011A240.unk14 = 0;
    D_8011A240.unk2C = 0;
    D_8011A240.unk30 = 0;
    D_8011A240.unk34 = 0;
    D_8011A240.unk38 = 0.0f;
    D_8011A240.unk3C = 0;
    D_8011A240.unk40 = 0;
    D_8011A240.unk20 = 0;
    D_8011A240.unk24 = 0;
    D_8011A240.unk28 = 0;

    for (index = 0; index < 151; index++) {
        D_8011A2A8[index] = 0;
        D_8011A508[index] = 0;
        D_8011A768[index] = 0;
        D_8011A9C8[index] = 0;
    }

    func_80028070(state);
    func_80039828();
    func_80046974();

    state->unk08 = 1;
    state->unk0C = 1;
    state->unk10 = -1;
    state->unk14 = 0;
    state->unk18 = 0.0f;
    state->unk1C = 3;
    state->unk20 = 0;
    state->unk24 = 0;
    state->unk2C = 0;
    state->unk28 = 0;
    state->unk30 = 0;
    state->unk34 = 0;
    state->unk3C = -1;
    state->unk38 = -1;
    state->unk40 = -1;
    func_80015268(state->unk44, 0.0f, 0.0f, 0.0f);
    state->unk50 = 0;
    state->unk51 = 0;
    state->unk54 = 0.0f;
    state->unk58 = 0.0f;
    state->unk5C = 1;
    state->unk92 = 800;
    state->unk94 = 700;
    state->unk96 = 600;
    state->unk98 = 100;
    state->unk9A = 1200;
    state->unk9C = 600;
    state->unk9E = 300;
    state->unkA0 = 100;
    state->unkA2 = 2200;
    state->unkA4 = 0;
    state->unkA6 = 0;
    state->unkA8 = 0;
    state->unk5D = 0;
    state->unk5E = 0;
    state->unk5F = 0;
    state->unk60 = 0;
    state->unk89 = 4;
    state->unkB4 = 0;
    state->unkB8 = 0;
    state->unkBC = 0;
    state->unkC0 = 0;
    state->unkC4 = 0;
    state->unkC8 = 0;
    for (index = 0; index < 3; index++) {
        state->unkCC[index] = index;
    }
    func_80050208(state);

    for (record = D_80118F90; record < &D_80118F90[12]; record++) {
        record->unk00 = -1;
        record->unk04 = -1;
        record->unk08 = -1;
        record->unk0C = 0;
        record->unk10 = 0xFF;
        record->unk11 = 0xFF;
        record->unk14 = -1;
        record->unk18 = 0;
        record->unk84 = 0;
        record->unk1C[0] = 0.0f;
        record->unk1C[1] = 0.0f;
        record->unk1C[2] = 0.0f;
        record->unk1C[3] = 0.0f;
        record->unk1C[4] = 0.0f;
        record->unk1C[5] = 0.0f;
        record->unk1C[6] = 0.0f;
        record->unk1C[7] = 0.0f;
        record->unk1C[8] = 0.0f;
        record->unk1C[9] = 0.0f;
        record->unk1C[10] = 0.0f;
        record->unk1C[11] = 0.0f;
        record->unk1C[12] = 0.0f;
        record->unk1C[13] = 0.0f;
        record->unk1C[14] = 0.0f;
        record->unk58 = 0;
        record->unk5C = 0;
        record->unk74 = 0.0f;
        record->unk78 = 0;
        record->unk7C = 0;
        for (index = 0; index < 5; index++) {
            record->unk60[index] = 0.0f;
        }
    }

    total = 0;
    for (groupIndex = 0; groupIndex < 8; groupIndex++) {
        group = &D_800D6DD8[groupIndex];
        count = counts.values[groupIndex];
        group->first = total;
        total += count;
        group->last = total - 1;
        if (count == 0) {
            group->first = -1;
            group->last = -2;
        }
    }

    for (groupIndex = 0; groupIndex < 8; groupIndex++) {
        group = &D_800D6DD8[groupIndex];

        unit = (f32)func_80082BE0() / 2147483648.0f;
        group->unk08 = (f32)((f64)unit * 360.0);
        if (groupIndex != 6 &&
            ((group->unk08 > 45.0 && group->unk08 < 135.0f) ||
             (group->unk08 > 225.0 && group->unk08 < 315.0f))) {
            group->unk08 += 90.0f;
        }

        unit = (f32)func_80082BE0() / 2147483648.0f;
        group->unk0C = (f32)((f64)unit * 360.0);
        unit = (f32)func_80082BE0() / 2147483648.0f;
        group->unk14 = (f32)((f64)unit * 360.0);

        random = func_80082BE0();
        sign = func_80051934();
        unit = (f32)random / 2147483648.0f;
        group->unk10 = (f32)((f64)sign *
                             (5.0 + 10.0 * (f64)unit));
        if (groupIndex == 6) {
            group->unk10 *= 5.0f;
        }

        random = func_80082BE0();
        sign = func_80051934();
        unit = (f32)random / 2147483648.0f;
        group->unk18 = (f32)((f64)sign *
                             (10.0 + 5.0 * (f64)unit) +
                             (f64)group->unk10);

        for (index = group->first; index <= group->last; index++) {
            item = &D_80119670[index];

            unit = (f32)func_80082BE0() / 2147483648.0f;
            item->values[3] = (f32)(
                (f64)unit * (360.0 / (f64)(group->last - group->first + 1)) +
                (f64)(index - group->first) * 360.0 / (f64)(group->last - group->first + 1));

            random = func_80082BE0();
            sign = func_80051934();
            unit = (f32)random / 2147483648.0f;
            item->values[4] = (f32)((f64)sign *
                (45.0 + 15.0 * (f64)unit - 20.0 * (f64)(index - group->first)));

            random = func_80082BE0();
            sign = func_80051934();
            unit = (f32)random / 2147483648.0f;
            item->values[0] = (f32)((f64)sign *
                (65.0 + 10.0 * (f64)unit + 40.0 * (f64)(index - group->first)));

            random = func_80082BE0();
            sign = func_80051934();
            unit = (f32)random / 2147483648.0f;
            item->values[1] = (f32)((f64)sign *
                (65.0 + 10.0 * (f64)unit + 40.0 * (f64)(index - group->first)));

            unit = (f32)func_80082BE0() / 2147483648.0f;
            item->values[2] = (f32)((f64)sign *
                (5.0 + 40.0 * (f64)unit));

            unit = (f32)func_80082BE0() / 2147483648.0f;
            item->values[5] = (f32)(
                (f32)((f64)unit * 0.01 + 0.005 +
                      0.01 * (f64)(index - group->first)) * 15.0f);
        }
    }

    func_8008A6B4(D_800D6DD8[0].name, D_800AAE54);
    func_8008A6B4(D_800D6DD8[1].name, D_800AAE64);
    func_8008A6B4(D_800D6DD8[2].name, D_800AAE78);
    func_8008A6B4(D_800D6DD8[3].name, D_800AAE8C);
    func_8008A6B4(D_800D6DD8[4].name, D_800AAEA0);
    func_8008A6B4(D_800D6DD8[5].name, D_800AAEB0);
    func_8008A6B4(D_800D6DD8[6].name, D_800AAEC4);
    func_8008A6B4(D_800D6DD8[7].name, D_800AAED4);

    D_800A4BE8 = 0;
}
