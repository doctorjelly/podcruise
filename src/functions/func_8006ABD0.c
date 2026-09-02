/* Specification: scratchpad specs/func_8006ABD0.md */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f6A;

typedef struct {
    /* 0x000 */ u8 unk000[0x20];
    /* 0x020 */ f32 unk020;
    /* 0x024 */ f32 unk024;
    /* 0x028 */ f32 unk028;
    /* 0x02C */ u8 unk02C[0x38];
    /* 0x064 */ s32 unk064;
    /* 0x068 */ u8 unk068[0xC];
    /* 0x074 */ f32 unk074;
    /* 0x078 */ u8 unk078[0x184];
    /* 0x1FC */ f32 unk1FC;
    /* 0x200 */ u8 unk200[0x4C];
    /* 0x24C */ f32 unk24C;
    /* 0x250 */ u8 unk250[0x50];
    /* 0x2A0 */ s32 unk2A0[6];
} Obj6ABD0;

typedef struct {
    /* 0x00 */ u8 unk00[0x60];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 unk64[4];
    /* 0x68 */ f32 unk68;
} Ent6ABD0;

extern f64 D_80120BF0;
extern f32 D_800AD5B8;

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern s32 func_8003FDCC(s32 tag, Vec3f6A *origin, f32 limit, void *exclude, s32 capacity,
                         f32 *distances, Vec3f6A *offsets, Ent6ABD0 **results);
extern f32 func_800154D0(f32 *vector);
extern s32 func_80082BE0(void);

void func_8006ABD0(Obj6ABD0 *obj, Vec3f6A *origin) {
    f32 range;
    f32 magnitude;
    f32 distances[4];
    f32 distance;
    Vec3f6A offsets[2];
    f32 vector[3];
    Ent6ABD0 *results[2];
    f32 value;
    f32 amount;
    f32 sign;
    s32 flags;
    s32 index;
    f32 zero;

    sign = 1.0f;
    range = 75.0f;
    if (obj->unk064 & 0x10) {
        if (0.0f < obj->unk1FC) {
            obj->unk1FC = obj->unk1FC - 100.0f * (f32) D_80120BF0;
            obj->unk24C = 0.25f;
            if (obj->unk1FC < 0.0f) {
                obj->unk1FC = 0.0f;
                obj->unk064 = obj->unk064 & ~0x10;
            }
        } else {
            obj->unk1FC = obj->unk1FC + 100.0f * (f32) D_80120BF0;
            obj->unk24C = 0.25f;
            if (0.0f < obj->unk1FC) {
                obj->unk1FC = 0.0f;
                obj->unk064 = obj->unk064 & ~0x10;
            }
        }
    }

    if (func_8003FDCC(0x536D6F6B, origin, range * range, 0, 1, distances, offsets, results) > 0) {
        distance = sqrtf(distances[0]);
        if (results[0]->unk60 != 1) {
            if (results[0]->unk60 != 2) {
                return;
            }
            if (results[0]->unk68 < 2.0f) {
                return;
            }
            sign = -1.0f;
            if (distance < 30.0f) {
                if ((f64) ((f32) func_80082BE0() / (f32) 2147483648.0) < 0.25) {
                    index = (s32) ((f32) func_80082BE0() / (f32) 2147483648.0 * 7.0f + 0.5f);
                    if (index >= 6) {
                        index = 0;
                    }
                    obj->unk2A0[index] = obj->unk2A0[index] | 8;
                }
            }
        }

        magnitude = (75.0f - distance) / 70.0f * obj->unk074;
        vector[2] = 0.0f;
        vector[0] = offsets[0].y;
        vector[1] = -offsets[0].x;
        if (func_800154D0(vector) < D_800AD5B8) {
            magnitude = 1.0f;
        } else {
            magnitude = magnitude * -(vector[0] * obj->unk020 + vector[1] * obj->unk024 +
                                      vector[2] * obj->unk028);
        }

        zero = 0.0f;
        flags = obj->unk064;
        if (flags & 0x10) {
            if (magnitude < zero) {
                value = -magnitude;
            } else {
                value = magnitude;
            }
            if (obj->unk1FC < zero) {
                amount = -obj->unk1FC;
            } else {
                amount = obj->unk1FC;
            }
            if (amount < value) {
                obj->unk1FC = magnitude * sign;
            }
        } else {
            obj->unk064 = flags | 0x10;
            obj->unk1FC = magnitude * sign;
        }
    }
}
