/* Independently written from specs/functions/recovered/func_800228C0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 name[3];
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 pad05[2];
    /* 0x07 */ s8 unk07;
    /* 0x08 */ u8 unk08[3];
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ s16 unk0C[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x10];
} PcStage800228C0;

typedef struct {
    /* 0x000 */ s32 unk000;
    /* 0x004 */ u8 unk004;
    /* 0x005 */ u8 pad005[3];
    /* 0x008 */ s32 unk008;
    /* 0x00C */ u8 unk00C[3];
    /* 0x00F */ u8 unk00F;
    /* 0x010 */ s32 unk010;
    /* 0x014 */ PcStage800228C0 stages[4];
    /* 0x0C4 */ f32 bestFinal[25][2];
    /* 0x18C */ f32 bestCombined[25][2];
    /* 0x254 */ u8 finalNames[25][2][3];
    /* 0x2EA */ u8 combinedNames[25][2][3];
    /* 0x380 */ s8 finalProfiles[25][2];
    /* 0x3B2 */ s8 combinedProfiles[25][2];
} PcSave800228C0;

typedef struct {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 *spriteId;
    /* 0x1C */ u8 pad1C[0x40];
    /* 0x5C */ s16 placement;
    /* 0x5E */ u8 pad5E[2];
    /* 0x60 */ f32 segmentTimes[4];
    /* 0x70 */ u8 pad70[4];
    /* 0x74 */ f32 finalTime;
    /* 0x78 */ u8 pad78[0x10];
} PcResult800228C0;

typedef struct {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 labelA;
    /* 0x18 */ s32 labelB;
    /* 0x1C */ u8 pad1C[0x18];
} PcEntry800228C0;

typedef struct {
    /* 0x00 */ u8 pad00[0x5D];
    /* 0x5D */ s8 track;
    /* 0x5E */ s8 group;
    /* 0x5F */ u8 pad5F[0x0D];
    /* 0x6C */ s8 specialMode;
    /* 0x6D */ s8 unk6D;
    /* 0x6E */ s8 profile;
    /* 0x6F */ s8 selectedPlayer;
    /* 0x70 */ s8 playerCount;
    /* 0x71 */ s8 resultCount;
    /* 0x72 */ u8 pad72[0x1C];
    /* 0x8E */ u8 segmentCount;
    /* 0x8F */ u8 pad8F;
    /* 0x90 */ s8 rewardTableIndex;
    /* 0x91 */ u8 pad91[0x3B];
    /* 0xCC */ s8 topSpriteIds[3];
} PcController800228C0;

typedef struct {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ s32 canScrollUp;
    /* 0x24 */ s32 canScrollDown;
    /* 0x28 */ s32 lowerScrollHint;
} PcSession800228C0;

extern s32 D_800A2198;
extern u8 D_800A21B4[];
extern s8 D_800A21C2[];
extern s32 D_800A22E8[][7];
extern s32 D_800A233C[];
extern s32 D_800A2348;
extern s32 D_800A2554;
extern s16 D_800A2558;
extern s8 D_800A255C;
extern s8 D_800A2560;
extern PcEntry800228C0 D_800A31E0[];
extern u32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern s32 D_800A4BE0;
extern char D_800A8EC4[];
extern char D_800A8ED0[];
extern char D_800A8ED8[];
extern char D_800A8EE4[];
extern char D_800A8EF4[];
extern char D_800A8F04[];
extern char D_800A8F0C[];
extern char D_800A8F18[];
extern f32 D_800A9CD4;
extern f32 D_800A9CD8;
extern f64 D_800A9CE0;
extern f64 D_800A9CE8;
extern f64 D_800A9CF0;
extern f64 D_800A9CF8;
extern f64 D_800A9D00;
extern f64 D_800A9D08;
extern PcResult800228C0 *D_800D73A8[12];
extern f32 D_800D73D8;
extern u8 D_800D73DC;
extern f32 D_800D73E0;
extern f32 D_800D7730[];
extern PcSave800228C0 D_80113680;
extern PcStage800228C0 D_80113E60[];
extern PcResult800228C0 D_80118F90[];
extern PcSession800228C0 D_8011A240;
extern s32 D_8011A268;
extern f32 D_80120BF8;

extern void func_80008B14(s32 id, s16 channel, f32 volume, f32 pan, s32 flags);
extern void func_8000A920(s16 id, s32 enabled);
extern void func_8000AA04(s16 id, s16 x, s16 y);
extern void func_8000AAC0(s16 id, f32 xScale, f32 yScale);
extern void func_8000AB24(s16 id, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_80027D24(void *owner, void *results);
extern void func_8002C780(s32 x, s32 y, s32 height);
extern void func_8002D4C4(s32 soundId);
extern s32 func_8002D9D0(s8 group, u8 index);
extern s32 func_8002DA0C(s8 group, u8 index);
extern void func_8002DD7C(PcController800228C0 *owner);
extern void func_800399F0(void);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue,
                          u8 alpha, const char *text);
extern void func_8003ECB0(s16 x, s16 y, const char *text);
extern void func_8003EFDC(s16 x, s16 y, f32 value, u8 red, u8 green,
                          u8 blue, u8 alpha, s32 mode);
extern void func_800469B4(PcController800228C0 *owner, s32 mode);
extern void func_8004A36C(s32 index, f32 spread, f32 lift, f32 scale);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

void func_800228C0(PcController800228C0 *owner) {
    PcResult800228C0 *results[12];
    f32 bestCombined[2];
    char text[0x104];
    PcResult800228C0 *result;
    PcResult800228C0 *swap;
    PcEntry800228C0 *entry;
    f32 sentinel;
    f32 y;
    f32 alpha;
    f32 scroll;
    f32 lowerLimit;
    f32 axis;
    f64 highAxis;
    s32 variant;
    s32 group;
    s32 rank;
    s32 primaryRank;
    s32 secondaryRank;
    s32 sprite;
    s32 baseSprite;
    s32 phase;
    s32 required;
    s32 reward;
    s32 rawReward;
    s32 lastIndex;
    s32 unlock;
    s32 i;
    s32 j;
    s32 count;
    u8 savedGroup;
    u8 drawAlpha;

    sentinel = D_800A9CD8;
    bestCombined[0] = D_800A9CD4;
    bestCombined[1] = D_800A9CD4;
    savedGroup = (u8)owner->group;
    D_8011A268 = (s32)((f32)owner->resultCount * -30.0f + 150.0f);
    variant = owner->segmentCount;
    if (owner->specialMode != 0) {
        variant = 3;
    }
    func_8003ECB0(0xA0, 0x14, D_800A8EC4);

    for (i = 0; i < 12; i++) {
        results[i] = 0;
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        group = owner->group;
        count = D_800A21B4[group];
        D_800D73E0 = 2.0f;
        for (i = 0; i < count; i++) {
            if (owner->track == D_800A22E8[group][i]) {
                D_800D73DC = (u8)i;
                break;
            }
        }

        D_800A2554 = 0;
        D_800D73D8 = 0.0f;
        for (i = 0; i < 12; i++) {
            D_800D73A8[i] = 0;
        }

        result = D_80118F90;
        for (i = 0; i < owner->resultCount; i++, result++) {
            results[i] = result;
            if (result == 0) {
                owner->resultCount = (s8)i;
                break;
            }
            if ((result->finalTime > sentinel) || (result->finalTime < 0.0f)) {
                result->finalTime = sentinel;
            }
            for (j = 0; j < variant; j++) {
                if ((result->segmentTimes[j] > sentinel) ||
                    (result->segmentTimes[j] < 0.0f)) {
                    result->segmentTimes[j] = sentinel;
                }
            }
            D_800D73A8[i] = result;
        }

        for (i = 1; i < owner->resultCount; i++) {
            for (j = 0; j < i; j++) {
                if (D_800D73A8[i]->placement < D_800D73A8[j]->placement) {
                    swap = D_800D73A8[i];
                    D_800D73A8[i] = D_800D73A8[j];
                    D_800D73A8[j] = swap;
                }
            }
        }

        /* The original retains this debug-controlled empty count loop. */
        if (D_800A4BE0 != 0) {
            for (i = 0; i < owner->resultCount; i++) {
            }
        }

        for (i = 0; i < owner->playerCount; i++) {
            bestCombined[i] = results[i]->segmentTimes[0];
            for (j = 1; j < variant; j++) {
                if ((results[i]->segmentTimes[j] > 0.0f) &&
                    (results[i]->segmentTimes[j] < bestCombined[i])) {
                    bestCombined[i] = results[i]->segmentTimes[j];
                }
            }
        }

        if (((D_800A2558 & 1) == 0) && (D_80113E60[0].unk04 == 0) &&
            (((variant == 3) &&
              (results[0]->finalTime <
               D_80113680.bestFinal[owner->track][owner->profile]) &&
              ((owner->playerCount == 1) ||
               (results[0]->finalTime < results[1]->finalTime))) ||
             ((bestCombined[0] <
               D_80113680.bestCombined[owner->track][owner->profile]) &&
              ((owner->playerCount == 1) ||
               (bestCombined[0] < bestCombined[1]))))) {
            owner->selectedPlayer = 0;
            D_800A2558 |= 1;
            func_800469B4(owner, 2);
            return;
        }

        if ((owner->playerCount >= 2) && ((D_800A2558 & 2) == 0) &&
            (D_80113E60[1].unk04 == 0) &&
            (((variant == 3) &&
              (results[1]->finalTime <
               D_80113680.bestFinal[owner->track][owner->profile]) &&
              (results[1]->finalTime < results[0]->finalTime)) ||
             ((bestCombined[1] <
               D_80113680.bestCombined[owner->track][owner->profile]) &&
              (bestCombined[1] < bestCombined[0])))) {
            owner->selectedPlayer = 1;
            D_800A2558 |= 2;
            func_800469B4(owner, 2);
            return;
        }

        if ((D_800A2558 & 4) == 0) {
            for (i = 0; i < owner->playerCount; i++) {
                if ((variant == 3) && (results[i]->finalTime < sentinel) &&
                    (results[i]->finalTime <
                     D_80113680.bestFinal[owner->track][owner->profile])) {
                    D_80113680.bestFinal[owner->track][owner->profile] =
                        results[i]->finalTime;
                    for (j = 0; j < 3; j++) {
                        D_80113680.finalNames[owner->track][owner->profile][j] =
                            D_80113E60[i].name[j];
                    }
                    D_80113680.finalProfiles[owner->track][owner->profile] =
                        D_80113E60[i].unk07;
                }
                if ((bestCombined[i] < sentinel) &&
                    (bestCombined[i] <
                     D_80113680.bestCombined[owner->track][owner->profile])) {
                    D_80113680.bestCombined[owner->track][owner->profile] =
                        bestCombined[i];
                    for (j = 0; j < 3; j++) {
                        D_80113680.combinedNames[owner->track][owner->profile][j] =
                            D_80113E60[i].name[j];
                    }
                    D_80113680.combinedProfiles[owner->track][owner->profile] =
                        D_80113E60[i].unk07;
                }
            }
        }

        primaryRank = (s8)results[0]->placement;
        secondaryRank = -1;
        D_800A255C = (s8)primaryRank;
        D_800A2560 = -1;
        rank = primaryRank;
        if (owner->playerCount >= 2) {
            secondaryRank = (s8)results[1]->placement;
            D_800A2560 = (s8)secondaryRank;
            if (secondaryRank < primaryRank) {
                rank = secondaryRank;
            }
        }
        if (rank >= 4) {
            scroll = (f32)(rank - 3) * -30.0f;
            lowerLimit = (f32)owner->resultCount * -30.0f + 150.0f;
            D_800D73D8 = scroll;
            if (scroll < lowerLimit) {
                D_800D73D8 = lowerLimit;
            }
        }
        D_800A2558 |= 4;

        if ((owner->playerCount == 1) && (owner->specialMode != 0) &&
            (owner->resultCount >= 4)) {
            for (i = 0; i < owner->resultCount - 1; i++) {
                if (D_800D73A8[i + 1]->finalTime ==
                    D_800D73A8[i]->finalTime) {
                    D_800D73A8[i + 1]->placement =
                        D_800D73A8[i]->placement;
                }
            }

            if ((D_800A255C == 1) && ((D_800A2558 & 8) == 0)) {
                unlock = D_800A21C2[owner->track * 12];
                if ((unlock == 2) && (owner->track != 1)) {
                    unlock = 0;
                }
                if ((unlock > 0) &&
                    ((D_80113E60[0].unk14 & (1 << unlock)) == 0)) {
                    D_80113E60[0].unk14 |= 1 << unlock;
                    D_80113680.unk010 |= D_80113E60[0].unk14;
                    func_800399F0();
                    D_800A2558 |= 8;
                    func_800469B4(owner, 0x11);
                    return;
                }
            }

            group = owner->group;
            if (func_8002D9D0((s8)group, D_800D73DC) >= D_800A255C) {
                phase = (D_80113E60[0].unk0C[group] >>
                         (D_800D73DC * 2)) % 4;
                if (func_8002DA0C((s8)group, D_800D73DC) != 0) {
                    rawReward = *(s16 *)((u8 *)owner + 0x88 +
                                         owner->rewardTableIndex * 8 +
                                         D_800A255C * 2);
                    reward = (s32)((f64)rawReward +
                                   (f64)rawReward * 0.5 * (f64)group);
                    D_80113E60[0].unk18 += reward;
                    D_800A2554 = reward;
                    if (group < 3) {
                        lastIndex = D_800A21B4[group] - 1;
                        if ((D_800D73DC == lastIndex) &&
                            ((D_80113E60[0].unk0B & (1 << group)) == 0)) {
                            D_80113E60[0].unk0B |= 1 << group;
                            owner->track = (s8)D_800A233C[group];
                            savedGroup = 3;
                        } else if ((D_800D73DC < lastIndex) &&
                                   ((D_80113E60[0].unk08[group] &
                                     (1 << (D_800D73DC + 1))) == 0)) {
                            owner->track =
                                (s8)D_800A22E8[group][D_800D73DC + 1];
                        }
                        D_80113E60[0].unk08[group] |=
                            1 << (D_800D73DC + 1);
                    }
                    func_80027D24(owner, D_80118F90);
                }

                if (((D_800D73DC + 1) == D_800A21B4[owner->group]) &&
                    (owner->group == 2)) {
                    func_8002DD7C(owner);
                }

                required = 4 - D_800A255C;
                if (phase < required) {
                    D_80113E60[0].unk0C[owner->group] &=
                        ~(3 << (D_800D73DC * 2));
                    D_80113E60[0].unk0C[owner->group] |=
                        required << (D_800D73DC * 2);
                    if ((D_80113E60[0].unk0C[0] == 0x3FFF) &&
                        (D_80113E60[0].unk0C[1] == 0x3FFF) &&
                        (D_80113E60[0].unk0C[2] == 0x3FFF)) {
                        if ((D_80113E60[0].unk0B & 8) == 0) {
                            D_80113E60[0].unk0B |= 8;
                            owner->track = (s8)D_800A2348;
                            savedGroup = 3;
                        } else if ((*((u8 *)&D_80113E60[0] + 0x12) == 0xFF) &&
                                   ((D_80113680.unk008 & 0x20) == 0)) {
                            D_80113680.unk008 |= 0x20;
                        }
                    }
                }
            }

            for (i = 0; i < 4; i++) {
                if (D_80113680.unk00C[i] <
                    *((u8 *)&D_80113E60[0] + 8 + i)) {
                    D_80113680.unk00C[i] =
                        *((u8 *)&D_80113E60[0] + 8 + i);
                }
            }
        }

        owner->group = (s8)savedGroup;
        func_800399F0();
    }

    if (D_800D73E0 > 0.0f) {
        D_800D73E0 -= D_80120BF8;
        if (D_800D73E0 <= 0.0f) {
            func_80008B14(0xAE, 7, 0.25f, 1.0f, 0);
        }
    }

    for (i = 0; i < owner->resultCount; i++) {
        result = D_800D73A8[i];
        y = (f32)(0x1E + i * 0x1E) + D_800D73D8 + 15.0f;
        alpha = 255.0f;
        if (y < 45.0f) {
            alpha = (f32)(D_800A9CE8 - (D_800A9CE0 - (f64)y) * 8.0);
        }
        if (y > 160.0f) {
            alpha = (f32)(D_800A9CF0 - ((f64)y - 160.0) * 8.0);
        }
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
        if (alpha > 255.0f) {
            alpha = 255.0f;
        }
        drawAlpha = (u8)(u32)alpha;

        baseSprite = *result->spriteId;
        sprite = baseSprite;
        for (j = 0; j < i; j++) {
            if (*D_800D73A8[j]->spriteId == baseSprite) {
                sprite += 0x17;
            }
        }
        func_8000A920((s16)sprite, 1);
        func_8000AA04((s16)sprite, 0x1E, (s16)(s32)y);
        func_8000AAC0((s16)sprite, 0.5f, 0.5f);
        func_8000AB24((s16)sprite, 0xFF, 0xFF, 0xFF, drawAlpha);

        rank = i + 1;
        if ((rank == D_800A255C) || (rank == D_800A2560)) {
            func_8008A6B4(text, D_800A8ED0, result->placement);
            func_8003EC40(0x58, (s16)(s32)(y + 10.0f), 0xA3, 0xBE,
                          0x11, drawAlpha, text);
            entry = &D_800A31E0[*result->spriteId];
            func_8008A6B4(text, D_800A8ED8, entry->labelA,
                          entry->labelB);
            func_8003EC40(0x5C, (s16)(s32)(y + 11.0f), 0xA3, 0xBE,
                          0x11, drawAlpha, text);
            func_8003EFDC(0x109, (s16)(s32)(y + 10.0f), result->finalTime,
                          0xA3, 0xBE, 0x11, drawAlpha, 1);
            if (rank == D_800A255C) {
                func_8008A6B4(text, D_800A8EE4,
                              D_80113E60[0].name[0],
                              D_80113E60[0].name[1],
                              D_80113E60[0].name[2]);
            } else {
                func_8008A6B4(text, D_800A8EF4,
                              D_80113E60[1].name[0],
                              D_80113E60[1].name[1],
                              D_80113E60[1].name[2]);
            }
            func_8003EC40(0x2E, (s16)(s32)(y + 10.0f), 0xA3, 0xBE,
                          0x11, drawAlpha, text);
        } else {
            func_8008A6B4(text, D_800A8F04, result->placement);
            func_8003EC40(0x58, (s16)(s32)(y + 10.0f), 0x32, 0xFF,
                          0xFF, drawAlpha, text);
            entry = &D_800A31E0[*result->spriteId];
            func_8008A6B4(text, D_800A8F0C, entry->labelA,
                          entry->labelB);
            func_8003EC40(0x5C, (s16)(s32)(y + 11.0f), 0x32, 0xFF,
                          0xFF, drawAlpha, text);
            func_8003EFDC(0x109, (s16)(s32)(y + 10.0f), result->finalTime,
                          0x32, 0xFF, 0xFF, drawAlpha, 1);
        }
    }

    if (owner->resultCount >= 5) {
        func_8002C780(0x122, 0x1E, 0x90);
    }
    if (D_800A2554 > 0) {
        func_8008A6B4(text, D_800A8F18, D_800A2554);
        func_8003ECB0(0x87, 0xCD, text);
        func_8004A36C(0, 7.0f, -7.0f, 1.0f);
    }

    highAxis = D_800A9D00;
    for (i = 0; i < owner->playerCount; i++) {
        scroll = D_800D73D8;
        if ((D_800A4BA4[i] & 1) != 0) {
            func_8002D4C4(0x55);
            highAxis = D_800A9D08;
            if (owner->specialMode != 0) {
                if ((D_800A255C < 4) && (D_800D73DC == 6)) {
                    for (j = 0; j < 3; j++) {
                        owner->topSpriteIds[j] =
                            (s8)*D_800D73A8[j]->spriteId;
                    }
                    D_800A2198 = 0x10;
                } else {
                    D_800A2198 = 0x0C;
                }
            } else {
                D_800A2198 = 0x0C;
            }
        }

        D_8011A240.canScrollDown = 0;
        D_8011A240.canScrollUp = 0;
        if (owner->resultCount >= 5) {
            axis = D_800D7730[i];
            if (((f64)axis < D_800A9CF8) || (highAxis < (f64)axis)) {
                scroll += 300.0f * D_80120BF8 * axis;
                lowerLimit =
                    (f32)owner->resultCount * -30.0f + 150.0f;
                if (scroll > 0.0f) {
                    scroll = 0.0f;
                }
                if (scroll < lowerLimit) {
                    scroll = lowerLimit;
                }
            }
            if (scroll < 0.0f) {
                D_8011A240.canScrollUp = 1;
            }
            if ((f32)D_8011A240.lowerScrollHint < scroll) {
                D_8011A240.canScrollDown = 1;
            }
        }
        D_800D73D8 = scroll;
    }

    if (D_800A2198 != -1) {
        D_800A4BDC = -1;
        D_800A2558 = 0;
    }
}
