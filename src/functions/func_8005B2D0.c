/* Implements the specification in specs/func_8005B2D0.md (worker batch 17). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x1AC];
    s32 unk1AC;
    u8 pad1B0[0x10];
    s32 unk1C0;
} Actor8005B2D0;

typedef struct {
    u8 pad0[0x50];
    f32 unk50;
    f32 unk54;
    u8 pad58[0xC];
    s32 unk64;
    u8 pad68[0xA4];
    s16 unk10C;
    u8 pad10E[0x32];
    void *unk140;
    u8 pad144[0x5C];
    f32 unk1A0;
} State8005B2D0;

extern s16 *func_800183A8(void *);
extern f32 D_800ACFA0;
extern f32 D_800ACFA4;
extern f32 D_800ACFA8;
extern f32 D_800ACFAC;

s32 func_8005B2D0(Actor8005B2D0 *actor, State8005B2D0 *state) {
    s32 result;
    s16 *entry;

    if (actor->unk1AC == 1 && actor->unk1C0 == 3 &&
        D_800ACFA0 < state->unk50 && state->unk50 < D_800ACFA4 &&
        D_800ACFA8 < state->unk54 && state->unk54 < D_800ACFAC &&
        state->unk140 != 0) {
        entry = func_800183A8(state->unk140);
        if (entry != 0 && (entry[0] & 8)) {
            return 0;
        }
    }
    result = 0;
    if (!(state->unk64 & 0x2000000)) {
        if (state->unk10C >= 5 || state->unk1A0 < 60.0) {
            result = 1;
        }
    }
    return result;
}
