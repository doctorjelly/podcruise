/* Recovered from specification $S/specs/func_8003AE64.md (batch_04). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3;

typedef struct {
    s32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} PcAnim;

extern f64 D_80120BF0;

extern void func_8003ABA0(s32 arg0, s32 arg1, PcAnim *arg2);
extern void func_8003A5D0(s32 arg0, s32 arg1, f32 arg2, void *arg3, PcVec3 *arg4);
extern f32 func_800153C0(PcVec3 *vector);

void func_8003AE64(PcAnim *anim, PcVec3 *frame) {
    f32 step;
    f32 delta;

    delta = anim->unk04;
    if (((0.0f < delta) && (anim->unk20 == 0)) || ((delta < 0.0f) && (anim->unk24 == 0))) {
        step = (f32)((f64)delta * D_80120BF0);
        anim->unk08 = anim->unk08 + step;
        if (step < 0.0f) {
            anim->unk20 = 0;
        } else if (0.0f < step) {
            anim->unk24 = 0;
        }
    }

    while ((1.0f <= anim->unk08) && (anim->unk20 == 0)) {
        anim->unk08 = anim->unk08 - 1.0f;
        func_8003ABA0(anim->unk00, 1, anim);
    }

    while ((anim->unk08 < 0.0f) && (anim->unk24 == 0)) {
        anim->unk08 = anim->unk08 + 1.0f;
        func_8003ABA0(anim->unk00, 2, anim);
    }

    if (anim->unk08 < 0.0f) {
        anim->unk08 = 0.0f;
    }
    if (1.0f < anim->unk08) {
        anim->unk08 = 1.0f;
    }

    func_8003A5D0(anim->unk00, 11, anim->unk08, &anim->unk10, frame);
    anim->unk0C = func_800153C0(&frame[1]);
}
