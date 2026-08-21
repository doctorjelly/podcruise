/* Independently written from specs/functions/recovered/medium_control_tranche.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct Bands {
    s32 width[10];
} Bands;

typedef struct Mover {
    /* 0x00 */ PcVec3f unk_00;
    /* 0x0C */ u8 unk_0C[0x4];
    /* 0x10 */ PcVec3f unk_10;
    /* 0x1C */ u8 unk_1C[0x14];
    /* 0x30 */ PcVec3f unk_30;
} Mover;

extern Bands D_800A5A04;

extern void func_8003B184(void *request, void *context, f32 offset);

void func_8005F33C(u8 *owner, Mover *mover, s32 position) {
    f32 amount;
    f32 rotation;
    f32 findex;
    f32 fspan;
    f32 fremain;
    s32 index;
    s32 work;
    f32 half;
    s32 span;
    s32 total;
    s32 origin;
    Bands bands;

    bands = D_800A5A04;
    origin = *(s32 *)(owner + 0x1BC);
    func_8003B184(owner + 0x34, mover, 0.0f);

    mover->unk_30.x = mover->unk_10.x * -100.0f + mover->unk_30.x;
    mover->unk_30.y = mover->unk_10.y * -100.0f + mover->unk_30.y;
    mover->unk_30.z = mover->unk_10.z * -100.0f + mover->unk_30.z;

    index = 0;
    work = position;
    span = bands.width[0];
    total = span - origin;
    if (position >= span) {
        do {
            work -= span;
            index++;
            span = bands.width[index];
            total += span;
        } while (work >= span);
    }
    if (total > 0) {
        span -= total;
    }

    findex = (f32)index;
    fspan = (f32)span;
    fremain = (f32)work;
    rotation = findex * -30.0f;
    half = (fspan - 1.0f) * 0.5f;
    amount = fremain * 20.0f + half * -20.0f;
    func_800155EC(&mover->unk_30, &mover->unk_30, rotation, &mover->unk_10);
    func_800155EC(&mover->unk_30, &mover->unk_30, amount, &mover->unk_00);
}
