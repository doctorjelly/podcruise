/* Independently written from scratchpad spec specs/func_80052208.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x60];
    /* 0x060 */ s32 flags;
    /* 0x064 */ u8 pad064[0xC4];
    /* 0x128 */ f32 unk128;
    /* 0x12C */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
} Sub80052208;

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 flags;
    /* 0x0C */ u8 pad0C[0x50];
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 pad5E[0x26];
    /* 0x84 */ Sub80052208 *unk84;
} Ent80052208;

typedef struct {
    /* 0x000 */ u8 pad000[0x1BC];
    /* 0x1BC */ s32 count;
    /* 0x1C0 */ u8 pad1C0[8];
    /* 0x1C8 */ s32 unk1C8;
} Ctx80052208;

extern Ent80052208 *D_8011B1B8;
extern Ent80052208 *D_8011B1BC;
extern Ent80052208 *D_8011B1C0;
extern f32 D_800ACE3C;
extern f32 D_800ACE40;
extern f32 D_800ACE44;
extern f32 D_800ACE48;

extern f32 func_80052134(Ent80052208 *);
extern f32 func_800521C0(Ent80052208 *);

void func_80052208(Ctx80052208 *ctx) {
    s32 i;
    s32 j;
    s32 k;
    f32 spread[12];
    s32 place;
    s32 pick;
    f32 best;
    f32 leader;
    f32 firstValue;
    f32 secondValue;
    f32 marker;
    s32 firstIndex;
    s32 secondIndex;
    s32 nearIndexB[3];
    f32 nearValueB[3];
    s32 nearIndexA[3];
    f32 nearValueA[3];
    f32 gapFirst;
    f32 gapSecond;

    marker = -1.0f;

    for (i = 0; i < ctx->count; i++) {
        D_8011B1B8[i].unk5C = -1;
        D_8011B1B8[i].unk84->flags &= ~0x8000;
        D_8011B1B8[i].unk84->flags &= ~0x10000;
        spread[i] = func_800521C0(&D_8011B1B8[i]);
        if (D_8011B1BC == &D_8011B1B8[i]) {
            firstIndex = i;
            firstValue = spread[i];
        }
        if (D_8011B1C0 == &D_8011B1B8[i]) {
            secondIndex = i;
            secondValue = spread[i];
        }
        if (D_8011B1B8[i].unk84->flags & 0x100) {
            if (D_8011B1B8[i].flags & 2) {
                marker = func_80052134(&D_8011B1B8[i]);
            } else {
                marker = spread[i];
            }
        }
    }

    place = 1;
    for (i = 0; &nearValueA[i] < &nearValueA[3]; i++) {
        nearIndexB[i] = -1;
        nearValueB[i] = D_800ACE3C;
        nearIndexA[i] = -1;
        nearValueA[i] = D_800ACE3C;
    }

    if (D_8011B1C0 != 0) {
        if (!(secondValue < firstValue)) {
            gapFirst = firstValue;
            firstValue = secondValue;
            k = firstIndex;
            firstIndex = secondIndex;
            secondIndex = k;
            secondValue = gapFirst;
        }
    }

    for (k = 0; k < ctx->count; k++) {
        pick = -1;
        best = 0.0f;
        for (j = 0; j < ctx->count; j++) {
            if (best < spread[j]) {
                pick = j;
                best = spread[j];
            }
        }
        if (pick != -1) {
            if (D_8011B1B8[pick].flags & 2) {
                spread[pick] = func_80052134(&D_8011B1B8[pick]);
            }
            if (place == 1) {
                leader = spread[pick];
            }
            D_8011B1B8[pick].unk84->unk128 = leader - spread[pick];
            if (D_8011B1BC == 0) {
                D_8011B1B8[pick].unk84->unk130 = -100.0f;
            } else if (D_8011B1C0 != 0) {
                if (firstIndex == pick) {
                    D_8011B1B8[pick].unk84->unk130 = 0.0;
                    D_8011B1B8[pick].unk84->unk134 = secondValue - firstValue;
                } else if (secondIndex == pick) {
                    D_8011B1B8[pick].unk84->unk134 = 0.0;
                    D_8011B1B8[pick].unk84->unk130 = firstValue - secondValue;
                } else {
                    gapFirst = firstValue - spread[pick];
                    gapSecond = secondValue - spread[pick];
                    D_8011B1B8[pick].unk84->unk130 = gapFirst;
                    D_8011B1B8[pick].unk84->unk134 = gapSecond;
                    if (gapFirst < 0.0f) {
                        gapFirst = -gapFirst;
                    }
                    if (gapFirst < nearValueB[0]) {
                        nearIndexB[2] = nearIndexB[1];
                        nearValueB[2] = nearValueB[1];
                        nearIndexB[1] = nearIndexB[0];
                        nearValueB[1] = nearValueB[0];
                        nearIndexB[0] = pick;
                        nearValueB[0] = gapFirst;
                    } else if (gapFirst < nearValueB[1]) {
                        nearIndexB[2] = nearIndexB[1];
                        nearValueB[2] = nearValueB[1];
                        nearIndexB[1] = pick;
                        nearValueB[1] = gapFirst;
                    } else if (gapFirst < nearValueB[2]) {
                        nearIndexB[2] = pick;
                        nearValueB[2] = gapFirst;
                    }
                    if (gapSecond < 0.0f) {
                        gapFirst = -gapSecond;
                    } else {
                        gapFirst = gapSecond;
                    }
                    if (gapFirst < nearValueA[0]) {
                        nearIndexA[2] = nearIndexA[1];
                        nearValueA[2] = nearValueA[1];
                        nearIndexA[1] = nearIndexA[0];
                        nearValueA[1] = nearValueA[0];
                        nearIndexA[0] = pick;
                        nearValueA[0] = gapFirst;
                    } else if (gapFirst < nearValueA[1]) {
                        nearIndexA[2] = nearIndexA[1];
                        nearValueA[2] = nearValueA[1];
                        nearIndexA[1] = pick;
                        nearValueA[1] = gapFirst;
                    } else if (gapFirst < nearValueA[2]) {
                        nearIndexA[2] = pick;
                        nearValueA[2] = gapFirst;
                    }
                }
            } else if (firstIndex == pick) {
                D_8011B1B8[pick].unk84->unk130 = 0.0;
            } else {
                gapFirst = firstValue - spread[pick];
                D_8011B1B8[pick].unk84->unk130 = gapFirst;
                if (gapFirst < 0.0f) {
                    gapFirst = -gapFirst;
                }
                if (gapFirst < nearValueB[0]) {
                    nearIndexB[2] = nearIndexB[1];
                    nearValueB[2] = nearValueB[1];
                    nearIndexB[1] = nearIndexB[0];
                    nearValueB[1] = nearValueB[0];
                    nearIndexB[0] = pick;
                    nearValueB[0] = gapFirst;
                } else if (gapFirst < nearValueB[1]) {
                    nearIndexB[2] = nearIndexB[1];
                    nearValueB[2] = nearValueB[1];
                    nearIndexB[1] = pick;
                    nearValueB[1] = gapFirst;
                } else if (gapFirst < nearValueB[2]) {
                    nearIndexB[2] = pick;
                    nearValueB[2] = gapFirst;
                }
            }
            D_8011B1B8[pick].unk84->unk12C = marker - spread[pick];
            spread[pick] = 0.0f;
            D_8011B1B8[pick].unk5C = place;
            place++;
        }
    }

    if (D_8011B1C0 != 0) {
        if (nearIndexA[0] != -1) {
            gapFirst = D_800ACE40;
            if (spread[nearIndexA[0]] < (f32)ctx->unk1C8 - gapFirst) {
                D_8011B1B8[nearIndexA[0]].unk84->flags |= 0x10000;
            }
        }
        gapFirst = D_800ACE44;
        if (nearIndexA[1] != -1) {
            if (spread[nearIndexA[1]] < (f32)ctx->unk1C8 - gapFirst) {
                D_8011B1B8[nearIndexA[1]].unk84->flags |= 0x10000;
            }
        }
    }
    gapFirst = D_800ACE48;
    if (nearIndexB[0] != -1) {
        if (spread[nearIndexB[0]] < (f32)ctx->unk1C8 - gapFirst) {
            D_8011B1B8[nearIndexB[0]].unk84->flags |= 0x8000;
            D_8011B1B8[nearIndexB[0]].unk84->flags &= ~0x10000;
        }
    }
    if (nearIndexB[1] != -1) {
        if (spread[nearIndexB[1]] < (f32)ctx->unk1C8 - gapFirst) {
            D_8011B1B8[nearIndexB[1]].unk84->flags |= 0x8000;
            D_8011B1B8[nearIndexB[1]].unk84->flags &= ~0x10000;
        }
    }
}
