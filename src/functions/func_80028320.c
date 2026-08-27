/* Implements specification $S/specs/func_80028320.md */
#include "podcruise/types.h"

typedef struct Actor {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Actor;

extern s32 D_800A2198;
extern s16 D_800A219C;
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern f32 D_800D6CC0;
extern f32 D_80120BF8;

extern void func_800469B4(Actor *actor, s32 mode);

s32 func_80028320(Actor *actor, s32 arg1, s32 arg2) {
    s32 changed;
    s32 proceed;
    s16 ticks;

    changed = 0;
    proceed = 1;
    if (arg1 != 0) {
        if ((actor->unk8 == 7) || (actor->unk8 == 4)) {
            return 0;
        }
        D_800A219C = 1;
        D_800D6CC0 = -300.0f;
        D_800A2198 = -1;
        proceed = 0;
    }

    ticks = D_800A219C;
    if (ticks != 0) {
        if (proceed != 0) {
            D_800D6CC0 = (f32)((f64)D_800D6CC0 + (f64)(300.0f * D_80120BF8 * (f32)ticks) / 0.25);
            if (D_800D6CC0 <= -300.0f) {
                D_800D6CC0 = -300.0f;
                changed = 1;
            }
            if ((f32)arg2 <= D_800D6CC0) {
                D_800D6CC0 = (f32)arg2;
                changed = 1;
            }
            if (changed != 0) {
                D_800A219C = 0;
                if (D_800A2198 != -1) {
                    if (D_800A4BDC == 0) {
                        if (D_800A4BC0 == 0) {
                            func_800469B4(actor, D_800A2198);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
