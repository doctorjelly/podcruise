/* Recovered from specs/functions/recovered/extended_runtime_tranche.md. */

#include "podcruise/vector_math.h"

typedef struct Body68D04 {
    u8 pad00[0x64];
    u32 unk64;
    u8 pad68[0x6C - 0x68];
    f32 unk6C;
    u8 pad70[0x1B8 - 0x70];
    PcVec3f unk1B8;
    u8 pad1C4[0x22C - 0x1C4];
    f32 unk22C;
    u8 pad230[0x248 - 0x230];
    f32 unk248;
    f32 unk24C;
} Body68D04;

extern f32 D_800AD528;
extern f32 D_800AD52C;
extern f32 D_800AD530;
extern f64 D_80120BF0;

extern f32 func_800154D0(f32 *vector);

void func_80068D04(Body68D04 *body, f32 amount, PcVec3f *direction,
                   PcVec3f *velocity) {
    f32 dot;
    f32 blend;
    f32 limit;
    f32 axis[3];
    f32 scaled[3];
    f32 current[3];

    if (0.0f < amount) {
        axis[0] = direction->x;
        axis[1] = direction->y;
        axis[2] = direction->z;
    } else {
        axis[0] = -direction->x;
        axis[1] = -direction->y;
        axis[2] = -direction->z;
    }

    dot = axis[0] * body->unk1B8.x + axis[1] * body->unk1B8.y +
          axis[2] * body->unk1B8.z;
    if (dot < 0.0f) {
        body->unk1B8.x = axis[0] * -dot + body->unk1B8.x;
        body->unk1B8.y = axis[1] * -dot + body->unk1B8.y;
        body->unk1B8.z = axis[2] * -dot + body->unk1B8.z;
    }

    func_800155C0(velocity, amount, direction);

    blend = 1.0f - (body->unk6C * body->unk248 * body->unk24C) *
                        (body->unk6C * body->unk248 * body->unk24C);
    blend = blend * D_800AD528;
    if (1.0f < body->unk22C) {
        if (2.0f < body->unk22C) {
            blend = 0.0f;
        } else {
            blend = blend * (2.0f - body->unk22C);
        }
    }

    scaled[0] = velocity->x * (f32)D_80120BF0;
    scaled[1] = velocity->y * (f32)D_80120BF0;
    scaled[2] = velocity->z * (f32)D_80120BF0;
    current[0] = body->unk1B8.x * (f32)D_80120BF0;
    current[1] = body->unk1B8.y * (f32)D_80120BF0;
    current[2] = body->unk1B8.z * (f32)D_80120BF0;
    current[0] = blend * current[0] + scaled[0] * (1.0f - blend);
    current[1] = blend * current[1] + scaled[1] * (1.0f - blend);
    current[2] = blend * current[2] + scaled[2] * (1.0f - blend);
    body->unk1B8.x = current[0] * (1.0f / (f32)D_80120BF0);
    body->unk1B8.y = current[1] * (1.0f / (f32)D_80120BF0);
    body->unk1B8.z = current[2] * (1.0f / (f32)D_80120BF0);
    velocity->x = body->unk1B8.x;
    velocity->y = body->unk1B8.y;
    velocity->z = body->unk1B8.z;

    func_800154D0((f32 *)velocity);
    func_800155C0(velocity, (amount < 0.0f) ? -amount : amount, velocity);

    if (body->unk64 & 0x10) {
        return;
    }
    limit = 1.0f;
    if (body->unk64 & 4) {
        limit = limit * D_800AD52C;
    }
    if (body->unk64 & 8) {
        limit = limit * D_800AD530;
    }
    if (limit < body->unk24C) {
        body->unk24C = body->unk24C - (f32)D_80120BF0 * 2.0f;
        if (body->unk24C < limit) {
            body->unk24C = limit;
        }
    } else if (body->unk24C < limit) {
        body->unk24C = body->unk24C + (f32)D_80120BF0 * 2.0f;
        if (limit < body->unk24C) {
            body->unk24C = limit;
        }
    }
}
