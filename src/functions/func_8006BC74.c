/* Independently written from scratchpad spec specs/func_8006BC74.md (two-body collision response). */

#include "podcruise/types.h"

typedef struct Actor6BC74 {
    /* 0x000 */ u8 pad000[0x50];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ u8 pad058[0x60 - 0x58];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ u8 pad068[0x9C - 0x68];
    /* 0x09C */ f32 unk9C;
    /* 0x0A0 */ u8 pad0A0[0x144 - 0xA0];
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14C */ f32 unk14C;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ u8 pad154[0x16C - 0x154];
    /* 0x16C */ f32 unk16C[3];
    /* 0x178 */ u8 pad178[0x1A0 - 0x178];
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ u8 pad1A4[0x1DC - 0x1A4];
    /* 0x1DC */ f32 unk1DC;
    /* 0x1E0 */ f32 unk1E0;
    /* 0x1E4 */ u8 pad1E4[0x2CC - 0x1E4];
    /* 0x2CC */ f32 unk2CC[3];
} Actor6BC74;

extern f32 D_800AD5EC;
extern f64 D_80120BF0;

extern s32 func_8003FDCC(s32 tag, f32 *origin, f32 limit, Actor6BC74 *exclude,
                         s32 capacity, f32 *distances, f32 *offsets,
                         Actor6BC74 **results);
extern f32 func_8006B9C8(f32 *a, f32 *b, f32 *c, f32 *d, f32 *outA, f32 *outB,
                         f32 *dirA, f32 *dirB);
extern void func_8001514C(f32 *output, f32 *left, f32 *right);
extern void func_80015170(f32 *output, f32 scale, f32 *source);
extern void func_80015190(f32 *output, f32 *base, f32 scale, f32 *offset);
extern f32 func_800151C0(f32 *vector);
extern f32 func_800151E0(f32 *vector);
extern void func_8006A3EC(Actor6BC74 *actor);
extern void func_8006BB50(Actor6BC74 *actor, f32 arg1, f32 arg2);

void func_8006BC74(Actor6BC74 *self) {
    s32 count;
    f32 offsets[12];
    f32 distances[4];
    Actor6BC74 *results[4];
    Actor6BC74 *other;
    f32 spare;
    f32 t;
    f32 dirA[3];
    f32 dirB[3];
    f32 outA[3];
    f32 outB[3];
    f32 delta[3];
    f32 mid[3];
    f32 sum[3];
    f32 push[3];
    f32 pointA[3];
    f32 pointB[3];
    f32 normal[3];
    f32 impulseA[3];
    f32 impulseB[3];
    f32 travelSelf[3];
    f32 travelOther[3];
    f32 radius;
    f32 speed;

    (void)spare;

    if (self->unk60 & 0x6000) {
        return;
    }
    if (self->unk64 & 0x02000000) {
        return;
    }

    count = func_8003FDCC(0x54657374, &self->unk50, 2500.0f, self, 4,
                          distances, offsets, results);
    self->unk150 = 0.0f;
    if (count <= 0) {
        return;
    }

    other = results[0];
    if (other->unk60 & 0x6000) {
        return;
    }
    if (other->unk64 & 0x02000000) {
        return;
    }

    radius = 10.0f;
    t = func_8006B9C8(self->unk16C, self->unk2CC, other->unk16C,
                      other->unk2CC, outA, outB, dirA, dirB);
    if (!(0.0f <= t)) {
        return;
    }

    delta[0] = outA[0] - outB[0];
    delta[1] = outA[1] - outB[1];
    if (!(delta[0] * delta[0] + delta[1] * delta[1] < radius * radius)) {
        return;
    }
    if (t < D_800AD5EC) {
        return;
    }

    func_80015170(mid, 0.5f, outA);
    func_80015190(mid, mid, 0.5f, outB);

    func_80015170(push, self->unk9C, dirA);
    func_80015190(push, push, other->unk9C, dirB);
    func_80015170(push, (1.0f - t) / (other->unk9C + self->unk9C), push);

    sum[0] = mid[0] + push[0];
    sum[1] = mid[1] + push[1];

    func_80015190(pointA, self->unk16C, t - 0.05f, dirA);
    func_80015190(pointB, other->unk16C, t - 0.05f, dirB);

    normal[0] = pointA[0] - pointB[0];
    normal[1] = pointA[1] - pointB[1];
    func_800151E0(normal);

    func_80015170(impulseA, radius * 0.5f, normal);
    func_80015170(impulseB, -radius * 0.5f, normal);

    func_8001514C(self->unk2CC, sum, impulseA);
    func_8001514C(other->unk2CC, sum, impulseB);

    travelOther[0] = other->unk2CC[0] - other->unk50;
    travelOther[1] = other->unk2CC[1] - other->unk54;
    travelSelf[0] = self->unk2CC[0] - self->unk50;
    travelSelf[1] = self->unk2CC[1] - self->unk54;

    self->unk50 = self->unk2CC[0]; self->unk54 = self->unk2CC[1];
    other->unk50 = other->unk2CC[0]; other->unk54 = other->unk2CC[1];

    if (other->unk1A0 < self->unk1A0) {
        speed = self->unk1A0;
    } else {
        speed = other->unk1A0;
    }

    self->unk150 = func_800151C0(travelSelf) / D_80120BF0;
    self->unk144 = -normal[0];
    self->unk148 = -normal[1];
    self->unk14C = 0.0f;
    func_8006A3EC(self);
    func_8006BB50(self, speed, self->unk150);

    other->unk150 = func_800151C0(travelOther) / D_80120BF0;
    other->unk144 = normal[0];
    other->unk148 = normal[1];
    other->unk14C = 0.0f;
    func_8006A3EC(other);
    func_8006BB50(other, speed, other->unk150);

    self->unk1DC = travelSelf[0] * 0.5f + self->unk1DC;
    self->unk1E0 = travelSelf[1] * 0.5f + self->unk1E0;
    other->unk1DC = travelOther[0] * 0.5f + other->unk1DC;
    other->unk1E0 = travelOther[1] * 0.5f + other->unk1E0;
}
