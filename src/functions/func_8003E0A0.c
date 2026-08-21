/* Independently written from scratchpad spec specs/func_8003E0A0.md. */

#include "podcruise/types.h"

typedef struct PcScrollExtent {
    /* 0x00 */ u8 unk00[4];
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
} PcScrollExtent;

typedef struct PcScrollState {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ PcScrollExtent *unk08;
} PcScrollState;

void func_8003E0A0(PcScrollState *state, f32 stepU, f32 stepV) {
    PcScrollExtent *extent;

    if (state == 0) {
        return;
    }

    state->unk00 |= 0x8000;
    extent = state->unk08;
    if (extent == 0) {
        return;
    }

    state->unk04 = (s16)((f32)state->unk04 + stepU * (f32)extent->unk04);
    if (state->unk04 > extent->unk04) {
        state->unk04 -= extent->unk04;
    }
    if (state->unk04 < 0) {
        state->unk04 += extent->unk04;
    }

    state->unk06 = (s16)((f32)state->unk06 + stepV * (f32)extent->unk06);
    if (state->unk06 > extent->unk06) {
        state->unk06 -= extent->unk06;
    }
    if (state->unk06 < 0) {
        state->unk06 += extent->unk06;
    }
}
