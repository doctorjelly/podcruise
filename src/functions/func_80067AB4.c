/* Recovery evidence: specs/functions/recovered/medium_runtime_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk00[0x20];
    /* 0x020 */ f32 unk20[4];
    /* 0x030 */ f32 unk30[4];
    /* 0x040 */ u8 unk40[0x20];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 unk68[0xC];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 unk78[0x1C];
    /* 0x094 */ f32 unk94;
    /* 0x098 */ u8 unk98[0xC];
    /* 0x0A4 */ f32 unkA4;
    /* 0x0A8 */ u8 unkA8[0xEC];
    /* 0x194 */ f32 unk194[0x16];
    /* 0x1EC */ f32 unk1EC;
    /* 0x1F0 */ f32 unk1F0;
    /* 0x1F4 */ u8 unk1F4[0xC];
    /* 0x200 */ f32 unk200;
    /* 0x204 */ f32 unk204;
    /* 0x208 */ f32 unk208;
} Body80067AB4;

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Triple80067AB4;

extern f32 D_800AD4E0;

extern void func_800334F4(f32 *, f32, f32, f32, f32);
extern void func_80065E54(Body80067AB4 *, void *, f32 *, f32 *, f32 *, f32, f32,
                          f32, Triple80067AB4 *);

void func_80067AB4(Body80067AB4 *body, void *context, f32 blend,
                   Triple80067AB4 *result) {
    f32 previous;
    f32 amount;
    f32 magnitude;
    f32 target;
    f32 ceiling;
    f32 half;
    f32 mean;

    half = body->unk94 * 1.5f;
    mean = (body->unk94 + (f32)2.0 * body->unkA4) / 3.0f;

    if ((body->unk64 & 0x400) == 0) {
        result->z = result->z - body->unk200;
    }

    func_80065E54(body, context, body->unk30, body->unk20, body->unk194, blend,
                  half, mean, result);

    if ((body->unk64 & 0x400) == 0) {
        result->z = result->z + body->unk200;
    }

    if ((body->unk64 & 0x400) == 0) {
        previous = body->unk200;
        if ((body->unk60 & 0x80) != 0) {
            ceiling = 300.0f;
        } else {
            ceiling = 70.0f;
        }
        func_800334F4(&body->unk200, body->unk1EC, body->unk1F0, body->unk74,
                      ceiling);
        result->z = result->z - (body->unk200 - previous) * D_800AD4E0;
    }

    if ((body->unk64 & 0x400) == 0) {
        if (body->unk208 != 0.0f) {
            target = body->unk208 * 80.0f;
            if (body->unk208 < 0.0f) {
                magnitude = -body->unk208;
            } else {
                magnitude = body->unk208;
            }
            result->z = result->z + (target - result->z) * magnitude;
        }
    }

    body->unk204 = result->z;
}
