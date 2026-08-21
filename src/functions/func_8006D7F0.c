/* Recovered from specification specs/func_8006D7F0.md (proximity influence accumulator). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    /* 0x00 */ u8 unk00[0x30];
    /* 0x30 */ PcVec3f unk30;
    /* 0x3C */ u8 unk3C[0x14];
    /* 0x50 */ PcVec3f unk50;
    /* 0x5C */ u8 unk5C[0xF4];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ u8 unk154[0x40];
    /* 0x194 */ PcVec3f unk194;
    /* 0x1A0 */ u8 unk1A0[0x50];
    /* 0x1F0 */ f32 unk1F0;
} Actor;

typedef struct {
    /* 0x00 */ u8 unk00[0x60];
    /* 0x60 */ s32 unk60;
} Target;

extern void func_80015538(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern s32 func_8003FDCC(s32 tag, PcVec3f *origin, f32 limit, Actor *exclude, s32 capacity,
                         f32 *distances, PcVec3f *offsets, Target **results);

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

void func_8006D7F0(Actor *actor) {
    s32 count;
    s32 flags;
    PcVec3f offsets[4];
    PcVec3f cross;
    f32 distances[4];
    Target *results[4];
    f32 pad;

    f32 distance;
    f32 side;
    f32 falloff;
    f32 scale;

    (void)pad;
    (void)flags;
    scale = 1.0f;
    actor->unk150 = 0.0f;
    count = func_8003FDCC(0x54657374, &actor->unk50, 2500.0f, actor, 4, distances, offsets, results);
    if (count > 0) {
        func_80015538(&cross, &actor->unk30, &offsets[0]);
        side = actor->unk194.z * cross.z + (cross.x * actor->unk194.x + cross.y * actor->unk194.y);
        distance = sqrtf(distances[0]);
        if (count == 1) {
            if ((results[0]->unk60 & 0x20) != 0) {
                if (actor->unk30.x * offsets[0].x + actor->unk30.y * offsets[0].y +
                        offsets[0].z * actor->unk30.z < 0) {
                    scale = -1.0f;
                }
            }
        }
        if (side > 0.0f) {
            falloff = (50.0f - distance) / 5.0f;
            actor->unk1F0 = actor->unk1F0 + scale * (falloff * falloff / 10.0f * 8.0f);
        } else if (side < 0.0f) {
            falloff = (50.0f - distance) / 5.0f;
            actor->unk1F0 = actor->unk1F0 - scale * (falloff * falloff / 10.0f * 8.0f);
        }
    }
}
