/* Independently written from specs/functions/recovered/func_8008DEA0.md. */

#include "podcruise/types.h"

typedef struct Cmd8008DEA0 {
    u32 w0;
    u32 w1;
} Cmd8008DEA0;

typedef struct Chan8008DEA0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 unkC[0x20];
} Chan8008DEA0;

typedef struct Geom8008DEA0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} Geom8008DEA0;

typedef struct Src8008DEA0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 pad9[3];
    /* 0x0C */ Chan8008DEA0 *unkC;
    /* 0x10 */ Geom8008DEA0 *unk10;
} Src8008DEA0;

struct State8008DEA0;

typedef Cmd8008DEA0 *(*Handler8008DEA0)(struct State8008DEA0 *, s16 *, s32, s32,
                                        Cmd8008DEA0 *);

typedef struct State8008DEA0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Handler8008DEA0 unk4;
    /* 0x08 */ u8 pad8[0x10];
    /* 0x18 */ u8 *unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ Src8008DEA0 *unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[8];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
} State8008DEA0;

extern Cmd8008DEA0 *func_8008E54C(State8008DEA0 *, s16 *, s32, s32, Cmd8008DEA0 *);
extern Cmd8008DEA0 *func_8008E074(State8008DEA0 *, s16 *, s32, s32, Cmd8008DEA0 *);
extern void func_80096710(u8 *, u8 *, s32);

void func_8008DEA0(State8008DEA0 *state, s32 mode, Src8008DEA0 *source) {
    Src8008DEA0 *src;
    Geom8008DEA0 *geom;

    if (mode == 4) {
        src = state->unk28;
        state->unk3C = 0;
        state->unk40 = 1;
        state->unk38 = 0;
        if (src != 0) {
            state->unk44 = src->unk0;
            if (src->unk8 == 0) {
                if (src->unkC != 0) {
                    state->unk24 = src->unkC->unk8;
                }
            } else if (src->unk8 == 1) {
                if (src->unkC != 0) {
                    state->unk24 = src->unkC->unk8;
                }
            }
        }
    } else if (mode == 5) {
        state->unk28 = source;
        state->unk38 = 0;
        state->unk44 = source->unk0;
        if (source->unk8 == 0) {
            state->unk4 = func_8008E54C;
            state->unk28->unk4 = state->unk28->unk4 / 9 * 9;
            src = state->unk28;
            geom = src->unk10;
            state->unk2C = (geom->unk0 << 4) * geom->unk4;
            if (src->unkC != 0) {
                state->unk1C = src->unkC->unk0;
                state->unk20 = src->unkC->unk4;
                state->unk24 = src->unkC->unk8;
                func_80096710(src->unkC->unkC, state->unk18, 0x20);
            } else {
                state->unk1C = state->unk20 = state->unk24 = 0;
            }
        } else if (source->unk8 == 1) {
            state->unk4 = func_8008E074;
            src = state->unk28;
            if (src->unkC != 0) {
                state->unk1C = src->unkC->unk0;
                state->unk20 = src->unkC->unk4;
                state->unk24 = src->unkC->unk8;
            } else {
                state->unk1C = state->unk20 = state->unk24 = 0;
            }
        }
    }
}
