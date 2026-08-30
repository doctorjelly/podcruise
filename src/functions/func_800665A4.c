/* Independently written from specs/functions/recovered/func_800665A4.md. */
#include "podcruise/types.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct PcTrigOwner {
    f32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    void *unk20;
    s16 unk24;
    s16 unk26;
    struct PcTrigOwner *unk28;
} PcTrigOwner;

typedef struct PcTrigMode {
    u8 pad00[0x78];
    s32 unk78;
} PcTrigMode;

typedef struct PcTrigActor {
    u8 pad00[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[0x4];
    s32 unk60;
    u8 pad64[0x108];
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x28];
    f32 unk1A0;
    u8 pad1A4[0x1CCC];
    PcTrigMode *unk1E70;
} PcTrigActor;

extern f64 D_800AD4A8;
extern void *func_8007C4C8(PcTrigOwner *);
extern void func_8007CD50(void *, PcTrigActor *, s32);

void func_800665A4(PcTrigActor *actor, PcTrigOwner *owner) {
    f32 spareTop[4];
    f32 origin[3];
    f32 base[3];
    f32 far[3];
    f32 near[3];
    f32 point[3];
    f32 spareA[3];
    f32 spareB[3];
    f32 spareC[3];
    f32 delta[3];
    f32 halfLength;
    f32 halfHeight;
    f32 lengthSquared;
    f32 fraction;
    f32 alongAxis;
    f32 alongOwner;
    f32 alongActor;
    void *trigger;
    s32 blocked;
    s16 flags;

    while (owner != 0) {
        flags = owner->unk26;
        blocked = 0;
        if (flags != 0) {
            if (flags & 1) {
                blocked = 1;
            }
            if ((flags & 2) && actor->unk1A0 < 150.0f) {
                blocked = 1;
            }
            if (!(actor->unk60 & 0x20) && (flags & 0x20)) {
                blocked = 1;
            }
            if (actor->unk1E70->unk78 == 0 && (flags & 4)) {
                blocked = 1;
            }
            if (actor->unk1E70->unk78 == 1 && (flags & 8)) {
                blocked = 1;
            }
            if (actor->unk1E70->unk78 == 2 && (flags & 0x10)) {
                blocked = 1;
            }
        }
        if (blocked == 0) {
            trigger = func_8007C4C8(owner);
            if (trigger != 0) {
                origin[0] = actor->unk50;
                origin[1] = actor->unk54;
                origin[2] = actor->unk58;
                base[0] = owner->unk00;
                base[1] = owner->unk04;
                base[2] = owner->unk08;
                halfLength = owner->unk18 * 0.5f;
                halfHeight = owner->unk1C * 0.5f;
                far[0] = base[0] + owner->unk10 * halfLength;
                far[1] = base[1] - owner->unk0C * halfLength;
                far[2] = origin[2];
                near[0] = base[0] - owner->unk10 * halfLength;
                near[1] = base[1] + owner->unk0C * halfLength;
                near[2] = origin[2];
                delta[0] = near[0] - far[0];
                delta[1] = near[1] - far[1];
                delta[2] = near[2] - far[2];
                lengthSquared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
                if ((f64)lengthSquared <= D_800AD4A8) {
                    fraction = 0.0f;
                    point[0] = far[0];
                    point[1] = far[1];
                    point[2] = far[2];
                } else {
                    fraction = ((origin[0] * delta[0] + origin[1] * delta[1] + origin[2] * delta[2]) -
                                (far[0] * delta[0] + far[1] * delta[1] + far[2] * delta[2])) / lengthSquared;
                    if (fraction <= 0.0f) {
                        point[0] = far[0];
                        point[1] = far[1];
                        point[2] = far[2];
                    } else if (1.0f <= fraction) {
                        point[0] = near[0];
                        point[1] = near[1];
                        point[2] = near[2];
                    } else {
                        point[0] = far[0] + delta[0] * fraction;
                        point[1] = far[1] + delta[1] * fraction;
                        point[2] = far[2] + delta[2] * fraction;
                    }
                }
                if (owner->unk24 == 0x66 || owner->unk24 == 0x68) {
                    if (0.0f < fraction && fraction < 1.0f && origin[2] < base[2] + halfHeight &&
                        base[2] - halfHeight < origin[2]) {
                        alongAxis = actor->unk16C * owner->unk0C + actor->unk170 * owner->unk10 +
                                    actor->unk174 * owner->unk14;
                        alongOwner = base[0] * owner->unk0C + base[1] * owner->unk10 + base[2] * owner->unk14;
                        alongActor = origin[0] * owner->unk0C + origin[1] * owner->unk10 +
                                     origin[2] * owner->unk14;
                        if ((alongOwner < alongAxis) == (alongActor < alongOwner)) {
                            func_8007CD50(trigger, actor, 0);
                        }
                    }
                } else {
                    if ((point[0] - origin[0]) * (point[0] - origin[0]) +
                            (point[1] - origin[1]) * (point[1] - origin[1]) <
                        halfLength * halfLength) {
                        if (origin[2] < base[2] + halfHeight && base[2] - halfHeight < origin[2]) {
                            func_8007CD50(trigger, actor, 0);
                        }
                    }
                }
            }
        }
        owner = owner->unk28;
    }
    (void)point[2];
    (void)spareTop;
    (void)spareA;
    (void)spareB;
    (void)spareC;
}
