/* Independently written from scratchpad spec specs/func_8006D7F0.md. */

#include "podcruise/types.h"

typedef struct Vec3fD7 {
    f32 x;
    f32 y;
    f32 z;
} Vec3fD7;

typedef struct NeighborD7 {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ s32 unk60;
} NeighborD7;

typedef struct RacerD7 {
    /* 0x000 */ u8 pad000[0x30];
    /* 0x030 */ Vec3fD7 unk030;
    /* 0x03C */ u8 pad03C[0x50 - 0x3C];
    /* 0x050 */ Vec3fD7 unk050;
    /* 0x05C */ u8 pad05C[0x150 - 0x5C];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ u8 pad154[0x194 - 0x154];
    /* 0x194 */ Vec3fD7 unk194;
    /* 0x1A0 */ u8 pad1A0[0x1F0 - 0x1A0];
    /* 0x1F0 */ f32 unk1F0;
} RacerD7;

extern f32 sqrtf(f32 value);

#ifndef __GNUC__
#pragma intrinsic (sqrtf)
#endif

extern s32 func_8003FDCC(s32 tag, Vec3fD7 *origin, f32 limit, RacerD7 *exclude,
                         s32 capacity, f32 *distances, Vec3fD7 *offsets,
                         NeighborD7 **results);
extern void func_80015538(Vec3fD7 *output, const Vec3fD7 *left,
                          const Vec3fD7 *right);

void func_8006D7F0(RacerD7 *racer) {
    s32 count;
    Vec3fD7 offsets[4];
    Vec3fD7 cross;
    f32 distances[4];
    NeighborD7 *results[4];
    f32 sign;
    f32 dot;
    f32 span;

    racer->unk150 = 0.0f;
    sign = 1.0f;
    count = func_8003FDCC(0x54657374, &racer->unk050, 2500.0f, racer, 4,
                          distances, offsets, results);
    if (count > 0) {
        func_80015538(&cross, &racer->unk030, offsets);
        dot = racer->unk194.z * cross.z +
              (cross.x * racer->unk194.x + cross.y * racer->unk194.y);
        span = sqrtf(distances[0]);
        if (count == 1) {
            if ((results[0]->unk60 & 0x20) != 0) {
                if (racer->unk030.x * offsets[0].x +
                        racer->unk030.y * offsets[0].y +
                        offsets[0].z * racer->unk030.z < 0) {
                    sign = -1.0f;
                }
            }
        }
        if (dot > 0.0f) {
            racer->unk1F0 = racer->unk1F0 +
                sign * ((50.0f - span) / 5.0f * ((50.0f - span) / 5.0f) / 10.0f * 8.0f);
        } else if (dot < 0.0f) {
            racer->unk1F0 = racer->unk1F0 -
                sign * ((50.0f - span) / 5.0f * ((50.0f - span) / 5.0f) / 10.0f * 8.0f);
        }
    }
}
