/* Independently written from the specification in scratchpad specs/func_80066A80.md. */

#include "podcruise/types.h"

typedef struct PcRaceState {
    u8 pad00[0x50];
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    u8 pad5C[0x4];
    /* 0x60 */ u32 unk60;
    /* 0x64 */ u32 unk64;
    u8 pad68[0xD8];
    /* 0x140 */ void *unk140;
    u8 pad144[0x28];
    /* 0x16C */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    u8 pad178[0x28];
    /* 0x1A0 */ f32 unk1A0;
    u8 pad1A4[0x14];
    /* 0x1B8 */ f32 unk1B8;
    /* 0x1BC */ f32 unk1BC;
    /* 0x1C0 */ f32 unk1C0;
    /* 0x1C4 */ f32 unk1C4;
    /* 0x1C8 */ f32 unk1C8;
    /* 0x1CC */ f32 unk1CC;
    u8 pad1D0[0x58];
    /* 0x228 */ f32 unk228;
    u8 pad22C[0x14];
    /* 0x240 */ f32 unk240;
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    u8 pad24C[0x4];
    /* 0x250 */ f32 unk250;
    u8 pad254[0x18];
    /* 0x26C */ u32 unk26C;
    u8 pad270[0x1728];
    /* 0x1998 */ s32 unk1998;
} PcRaceState;

typedef struct PcRaceRule {
    /* 0x00 */ s16 unk00;
    u8 pad02[0x2A];
    /* 0x2C */ u32 unk2C;
    u8 pad30[0x4];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u32 unk38;
    /* 0x3C */ void *unk3C;
} PcRaceRule;

extern u32 func_800183A8(const void *object);
extern void func_800665A4(PcRaceState *state, void *owner);

extern u32 D_8009B7D8;
extern void *D_800A66D4;
extern f32 D_800AD4B0;
extern f32 D_800AD4B4;
extern u32 D_800D76F0;
extern u32 D_800D7700;
extern f64 D_80120BF0;

void func_80066A80(PcRaceState *state) {
    f32 goalB;
    f32 goalA;
    f32 goalC;
    f32 level;
    PcRaceRule *rule;

    goalA = 0.0f;
    goalC = 1.0f;
    goalB = 1.0f;

    if (state->unk60 & 0x02000000) {
        if (state->unk1A0 < 75.0f) {
            goalA = 75.0f - state->unk1A0;
        }
    }
    state->unk64 &= 0xFF63FB1E;
    if (state->unk140 != 0) {
        rule = (PcRaceRule *)(unsigned long)func_800183A8(state->unk140);
        if (rule != 0) {
            state->unk26C &= ~rule->unk34;
            state->unk26C |= rule->unk38;
            state->unk26C &= ~0xFF;
            if (rule->unk00 & 0x10) {
                state->unk64 |= 0x80;
            }
            if (rule->unk00 & 0x20) {
                state->unk64 |= 0x400;
            }
            if (rule->unk2C & 0x2000) {
                state->unk64 |= 0x40000;
            }
            if (rule->unk2C & 0x4000) {
                state->unk64 |= 0x80000;
            }
            if (rule->unk2C & 0x20000) {
                if (state->unk60 & 0x80) {
                    if (!(state->unk64 & 0x04000000)) {
                        state->unk64 |= 0x800000;
                    }
                }
            }
            if (rule->unk2C & 0x8000) {
                state->unk64 |= 0x100000;
            }
            if (D_8009B7D8 & 0x2000) {
                if (D_800D7700 & 0x100) {
                    if (D_800D76F0 & 0x80) {
                        state->unk60 ^= 0x02000000;
                    }
                }
            }
            if (rule->unk2C & 0x1) {
                state->unk60 |= 0x02000000;
            }
            if (rule->unk2C & 0x2) {
                if (state->unk60 & 0x02000000) {
                    state->unk60 &= ~0x02000000;
                    state->unk228 = 3.0f;
                    state->unk1B8 = state->unk50 - state->unk16C;
                    state->unk1BC = state->unk54 - state->unk170;
                    state->unk1C0 = state->unk58 - state->unk174;
                    state->unk1C4 = 0.0f;
                    state->unk1C8 = 0.0f;
                    state->unk1CC = 0.0f;
                    state->unk60 |= 0x04000000;
                }
            }
            if (rule->unk2C & 0x4) {
                goalA = 200.0f;
            }
            if (rule->unk2C & 0x8) {
                goalB = 0.75f;
                if (state->unk60 & 0x02000000) {
                    state->unk60 &= ~0x00800000;
                }
            }
            if (rule->unk2C & 0x10) {
                goalB = D_800AD4B0;
                state->unk60 &= ~0x00800000;
            }
            if (rule->unk2C & 0x20) {
                goalC = D_800AD4B4;
            }
            if (state->unk64 & 0x02000000) {
                goalC = 1.0f;
            }
            if (rule->unk2C & 0x400) {
                state->unk64 |= 0x1;
            }
            if (rule->unk3C != 0) {
                func_800665A4(state, rule->unk3C);
            }
            if (rule->unk2C & 0x1000) {
                state->unk64 |= 0x40;
            }
            if (rule->unk2C & 0x20000000) {
                state->unk64 |= 0x20;
            }
        }
    }
    if (D_800A66D4 != 0) {
        func_800665A4(state, D_800A66D4);
    }
    if (state->unk240 < goalA) {
        state->unk240 = state->unk240 + D_80120BF0 * 25.0;
        if (state->unk240 > goalA) {
            state->unk240 = goalA;
        }
    } else if (goalA < state->unk240) {
        state->unk240 = state->unk240 - D_80120BF0 * 25.0;
        if (state->unk240 < goalA) {
            state->unk240 = goalA;
        }
    }
    if (state->unk244 < goalB) {
        state->unk244 = state->unk244 + D_80120BF0 / (f32)2.0;
        if (state->unk244 > goalB) {
            state->unk244 = goalB;
        }
    } else if (goalB < state->unk244) {
        state->unk244 = state->unk244 - D_80120BF0 / (f32)2.0;
        if (state->unk244 < goalB) {
            state->unk244 = goalB;
        }
    }
    if (state->unk248 < goalC) {
        state->unk248 = state->unk248 + D_80120BF0 / (f32)2.0;
        if (state->unk248 > goalC) {
            state->unk248 = goalC;
        }
    } else if (goalC < state->unk248) {
        state->unk248 = state->unk248 - D_80120BF0 / (f32)2.0;
        if (state->unk248 < goalC) {
            state->unk248 = goalC;
        }
    }
    state->unk250 = 0.0f;
    (void)level;
    if (((((f32)state->unk1998 - 400.0f) / 600.0f) < 1.0) || (state->unk60 & 0x20) || (state->unk64 & 0x04000000)) {
        if (state->unk64 & 0x00080000) {
            if (!(state->unk64 & 0x200)) {
                state->unk60 |= 0x1000;
            }
        }
    }
}
