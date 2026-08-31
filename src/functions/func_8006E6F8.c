/* Recovered per specs/functions/recovered/func_8006E6F8.md. */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[6];
    u8 unk06;
} Input8006E6F8;

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ u32 unk08;
    /* 0x0C */ Input8006E6F8 *unk0C;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[7];
    /* 0x18 */ s32 *unk18;
} Control8006E6F8;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x60];
    /* 0x0060 */ u32 unk0060;
    /* 0x0064 */ u32 unk0064;
    /* 0x0068 */ u8 pad0068[0x74 - 0x68];
    /* 0x0074 */ f32 unk0074;
    /* 0x0078 */ u8 pad0078[0xD4 - 0x78];
    /* 0x00D4 */ s32 unk00D4;
    /* 0x00D8 */ u8 pad00D8[0xE0 - 0xD8];
    /* 0x00E0 */ f32 unk00E0;
    /* 0x00E4 */ u8 pad00E4[0x18C - 0xE4];
    /* 0x018C */ f32 unk018C;
    /* 0x0190 */ u8 pad0190[0x1A0 - 0x190];
    /* 0x01A0 */ f32 unk01A0;
    /* 0x01A4 */ u8 pad01A4[0x1E8 - 0x1A4];
    /* 0x01E8 */ f32 unk01E8;
    /* 0x01EC */ u8 pad01EC[4];
    /* 0x01F0 */ f32 unk01F0;
    /* 0x01F4 */ u8 pad01F4[0x224 - 0x1F4];
    /* 0x0224 */ f32 unk0224;
    /* 0x0228 */ u8 pad0228[4];
    /* 0x022C */ f32 unk022C;
    /* 0x0230 */ u8 pad0230[0x264 - 0x230];
    /* 0x0264 */ f32 unk0264;
    /* 0x0268 */ u8 pad0268[0x2F4 - 0x268];
    /* 0x02F4 */ f32 unk02F4;
    /* 0x02F8 */ u8 pad02F8;
    /* 0x02F9 */ u8 unk02F9;
    /* 0x02FA */ u8 pad02FA[2];
    /* 0x02FC */ f32 unk02FC;
    /* 0x0300 */ u8 pad0300[0x1E70 - 0x300];
    /* 0x1E70 */ Control8006E6F8 *unk1E70;
    /* 0x1E74 */ u8 pad1E74[0x1ED4 - 0x1E74];
    /* 0x1ED4 */ f32 unk1ED4;
} Object8006E6F8;

typedef struct {
    u32 tag;
    void *value;
} Message8006E6F8;

extern u32 D_80000318;
extern s32 D_8009B7D0;
extern u32 D_8009B7D8;
extern s32 D_800A5B6C;
extern f32 D_800AD76C;
extern f32 D_800AD770;
extern f32 D_800AD774;
extern f32 D_800AD778;
extern f32 D_800AD77C;
extern f32 D_800AD780;
extern f32 D_800AD784;
extern f32 D_800AD788;
extern f32 D_800AD78C;
extern f32 D_800AD790;
extern f32 D_800AD794;
extern f32 D_800AD798;
extern f32 D_800AD79C;
extern f32 D_800AD7A0;
extern f32 D_800AD7A4;
extern f32 D_800AD7A8;
extern f64 D_800AD7B0;
extern f32 D_800AD7B8;
extern f32 D_800AD7BC;
extern f32 D_800AD7C0;
extern f32 D_800AD7C4;
extern f32 D_800AD7C8;
extern f32 D_800AD7CC;
extern f32 D_800AD7D0;
extern f32 D_800AD7D4;
extern f32 D_800AD7D8;
extern f32 D_800AD7DC;
extern f32 D_800AD7E0;
extern f32 D_800AD7E4;
extern f32 D_800AD7E8;
extern f32 D_800AD7EC;
extern u32 D_800D697C;
extern u32 D_800D76F0[];
extern u32 D_800D7700[];
extern u32 D_800D7710[];
extern f32 D_800D7720[];
extern f32 D_800D7730[];
extern f64 D_80120BF0;
extern f64 D_80120C00;

extern void func_80008B14(s32, s16, f32, f32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_800319F4(s32, s32);
extern void func_8003F99C(void *, void *);
extern void func_8003FA24(u32, void *);
extern void func_8006C6D0(Object8006E6F8 *, s32);
extern s32 func_8006C708(Object8006E6F8 *);
extern f32 func_8006C828(Object8006E6F8 *);
extern void func_8006C950(Object8006E6F8 *);
extern void func_8006CA2C(Object8006E6F8 *);
extern void func_8006D9DC(Object8006E6F8 *, f32);
extern void func_8006E034(Object8006E6F8 *);
extern s32 func_8006E42C(Object8006E6F8 *, s32);
extern s32 func_80082BE0(void);

#define RANDOM_UNIT() ((f32)func_80082BE0() / 2147483648.0f)

void func_8006E6F8(Object8006E6F8 *object) {
    Control8006E6F8 *control;
    Message8006E6F8 message;
    u32 primaryFlags;
    u32 secondaryFlags;
    s32 index;
    s32 controlMode;
    s32 primaryActive;
    s32 secondaryActive;
    s32 directionA;
    s32 directionB;
    s32 steerLatch;
    s32 brakeButton;
    s32 releaseEdge;
    s32 brakeActive;
    s32 repeatedPress;
    s32 actionActive;
    s32 specialTrigger;
    s32 collisionResult;
    s32 specialMode;
    s32 tint;
    f32 axis;
    f32 steering;
    f32 pairAxisA;
    f32 pairAxisB;
    f32 pairPressureA;
    f32 pairPressureB;
    f32 amount;

    primaryActive = 0;
    secondaryActive = 0;
    directionA = 0;
    directionB = 0;
    steerLatch = 0;
    brakeButton = 0;
    releaseEdge = 0;
    brakeActive = 0;
    repeatedPress = 0;
    actionActive = 0;
    steering = 0.0f;
    axis = 0.0f;

    control = object->unk1E70;
    object->unk018C = 0.0f;
    object->unk01F0 = 0.0f;
    index = control->unk10;
    controlMode = control->unk0C->unk06;
    control->unk08 &= ~4;
    control->unk08 &= ~8;

    primaryFlags = D_800D76F0[index];
    specialMode = (object->unk0060 & 0x200000) != 0;

    switch (controlMode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        secondaryFlags = D_800D7700[index];
        primaryActive = primaryFlags & 1;
        secondaryActive = secondaryFlags & 1;
        if (controlMode == 1) {
            primaryActive = primaryActive != 0 || (primaryFlags & 0x100) != 0;
            secondaryActive = secondaryActive != 0 || (secondaryFlags & 0x100) != 0;
        }

        if (D_800D697C & 0x4000) {
            directionB = primaryFlags & 0x10;
            directionA = primaryFlags & 0x20;
            steering = -D_800D7720[index];
        } else {
            directionA = primaryFlags & 0x10;
            directionB = primaryFlags & 0x20;
            steering = D_800D7720[index];
        }

        axis = D_800D7730[index];
        steerLatch = primaryFlags & 2;
        actionActive = secondaryFlags & 4;
        brakeButton = primaryFlags & 8;

        if (secondaryFlags & 0x80) {
            if (D_80120C00 - (f64)object->unk02F4 > 0.25) {
                object->unk02F9 = 0;
            }
            object->unk02F4 = (f32)D_80120C00;
            object->unk02F9++;
            if (object->unk02F9 >= 2) {
                repeatedPress = 1;
            }
        }
        if (D_800D7710[index] & 0x80) {
            object->unk02F4 = (f32)D_80120C00;
        }
        if ((D_800D76F0[index] & 0x80) &&
            D_80120C00 - (f64)object->unk02F4 > 0.5) {
            releaseEdge = 1;
        }
        if (D_800D76F0[index] & 0x100) {
            brakeActive = 1;
        }
        if (controlMode == 1) {
            brakeActive = primaryActive == 0;
        }
        break;
    case 8:
        break;
    }

    collisionResult = func_8006E42C(object, index);

    if (D_8009B7D8 & 0x02000000) {
        index = control->unk10 == 0 ? 0 : 1;
        pairPressureA = D_800D7730[index];
        pairPressureB = D_800D7730[index + 2];
        pairAxisA = D_800D7720[index];
        pairAxisB = D_800D7720[index + 2];

        primaryActive = D_800AD76C < pairPressureA ||
                        D_800AD770 < pairPressureB;
        secondaryFlags = D_800D7700[index];
        secondaryActive = (secondaryFlags & 0x100) != 0 ||
                          (D_800D7700[index + 2] & 0x100) != 0;

        if (D_800D697C & 0x4000) {
            steering = -(pairPressureA - pairPressureB) / 2.0f;
            directionB = pairAxisA < -0.5f && pairAxisB < -0.5f;
            directionA = pairAxisA > 0.5f && pairAxisB > 0.5f;
        } else {
            steering = (pairPressureA - pairPressureB) / 2.0f;
            directionA = pairAxisA < -0.5f && pairAxisB < -0.5f;
            directionB = pairAxisA > 0.5f && pairAxisB > 0.5f;
        }

        axis = (pairPressureA + pairPressureB) * 0.5f;
        steerLatch = pairPressureA < D_800AD774 &&
                     pairPressureB < D_800AD774;
        actionActive = secondaryFlags & 4;
        brakeButton = D_800D76F0[index] & 8;

        if (secondaryFlags & 0x80) {
            if (D_80120C00 - (f64)object->unk02F4 > 0.25) {
                object->unk02F9 = 0;
            }
            object->unk02F4 = (f32)D_80120C00;
            object->unk02F9++;
            if (object->unk02F9 >= 2) {
                repeatedPress = 1;
            }
        }
        if (D_800D7710[index] & 0x80) {
            object->unk02F4 = (f32)D_80120C00;
        }
        if ((D_800D76F0[index] & 0x80) &&
            D_80120C00 - (f64)object->unk02F4 > 0.5) {
            releaseEdge = 1;
        }
        brakeActive = pairAxisA > 0.5f && pairAxisB < -0.5f;
    }

    object->unk00D4 = 0;
    if (D_800A5B6C > 0) {
        if (D_800A5B6C == 5 && D_800AD778 < object->unk00E0 &&
            object->unk00E0 < D_800AD77C) {
            object->unk00D4 = 1;
        }
        if (D_800A5B6C == 6 && D_800AD780 < object->unk00E0 &&
            object->unk00E0 < D_800AD784) {
            object->unk00D4 = 1;
        }
    }

    specialTrigger = collisionResult;
    collisionResult = func_8006C708(object);
    if (collisionResult != 0) {
        collisionResult = 1;
        directionA = 0;
        directionB = 0;
        specialTrigger = 0;
        object->unk0060 &= 0xFF7FFFFF;
    }

    if ((object->unk0060 & 0x10) && !(object->unk0060 & 0x200) &&
        !(object->unk0064 & 0x02000000)) {
        amount = func_8006C828(object);
        if (collisionResult & 1) {
            amount += D_800AD788;
        } else if (collisionResult & 2) {
            amount -= D_800AD78C;
        }
        steering += amount * D_800AD790;
    }

    if ((D_8009B7D8 & 0x100) && D_8009B7D0 != 0 &&
        ((primaryFlags & 0x800) || (primaryFlags & 0x400))) {
        message.tag = 0x536E6170;
        message.value = (primaryFlags & 0x800) ? (void *)-1 : (void *)1;
        func_8003F99C(object, &message);
    }
    if ((D_8009B7D8 & 0x100) && D_8009B7D0 != 0) {
        func_8006C6D0(object, index);
    }

    if (repeatedPress && (object->unk0060 & 0xF) == 2 &&
        !(object->unk0060 & 0x5800) && !(object->unk0064 & 0x4000)) {
        if (control->unk18[0] == 2) {
            func_8006E034(object);
        }
        if ((f64)RANDOM_UNIT() < 0.5) {
            if (D_80000318 >= 0x800000 || (object->unk0060 & 0x120)) {
                tint = control->unk18[0];
            } else {
                tint = -1;
            }
            if (control->unk18[0] == 0xE) {
                func_800093B0(1, tint, 3, 0x12, 0x12, 0x13, 0x14);
            } else {
                func_800093B0(1, tint, 3, 0x11, 0x12, 0x13, 0x14);
            }
        } else {
            if (D_80000318 >= 0x800000 || (object->unk0060 & 0x120)) {
                tint = control->unk18[0];
            } else {
                tint = -1;
            }
            func_800093B0(1, tint, 0x15, 0x16, 0x17, 0x18, 0x19);
        }
    }

    if (brakeButton) {
        object->unk0060 |= 0x100000;
    } else {
        object->unk0060 &= 0xFFEFFFFF;
    }
    if (releaseEdge) {
        object->unk0060 |= 0x400;
    } else {
        object->unk0060 &= ~0x400;
    }
    object->unk0060 &= 0x7FFFFFFF;

    if ((object->unk0060 & 0xF) && !(object->unk0060 & 0x4000) &&
        actionActive) {
        message.tag = 0x43427574;
        message.value = object;
        func_8003FA24(0x634D616E, &message);
    }

    func_8006C950(object);
    func_8006CA2C(object);

    if (object->unk0060 & 0x02000000) {
        if (axis < D_800AD794 && -axis < D_800AD798) {
            object->unk0224 = 0.0f;
        } else {
            if (axis < 0.0f) {
                axis /= D_800AD79C;
                axis = -(axis * axis) * D_800AD7A0;
            } else {
                axis /= D_800AD7A4;
                axis = axis * axis * D_800AD7A8;
            }
            object->unk0224 = -axis * object->unk0074 * 0.5f;
        }
        axis = 0.0f;
    }

    if (secondaryActive && !(object->unk0064 & 0x1000)) {
        object->unk0064 |= 0x1000;
        if (object->unk0064 & 0x800) {
            object->unk0064 |= 0x2000;
        }
    }
    if ((object->unk0064 & 0x2000) &&
        (!primaryActive || object->unk01A0 > 290.0f)) {
        object->unk0064 &= ~0x2000;
    }

    if ((object->unk0060 & 0xF) != 2 || (object->unk0060 & 0x4000)) {
        return;
    }

    if (steerLatch) {
        object->unk0060 |= 0x200;
        if ((f64)object->unk01A0 < D_800AD7B0) {
            object->unk0060 &= ~0x10;
        }
    } else {
        object->unk0060 &= ~0x200;
    }

    if (control->unk08 & 8) {
        object->unk018C = 0.5f / D_800AD7B8;
        if (object->unk018C > 1.0f) {
            object->unk018C = 1.0f;
        }
        if (object->unk018C < -1.0f) {
            object->unk018C = -1.0f;
        }
    } else if (primaryActive) {
        object->unk018C = 1.0f;
        if (collisionResult != 0) {
            object->unk018C *= 0.5f;
        }
    } else if ((f64)axis < -0.5 && (f64)object->unk01A0 < 20.0) {
        object->unk018C = D_800AD7BC * axis;
    } else if (object->unk0060 & 0x200) {
        object->unk018C = D_800AD7C0;
    } else {
        object->unk018C = D_800AD7C4;
    }

    if (object->unk0264 <= 0.0f && D_800AD7C8 < object->unk018C) {
        object->unk0060 |= 0x10;
    }
    if (object->unk0064 & 0x200) {
        brakeActive = 1;
    }
    if (brakeActive) {
        object->unk0064 |= 8;
    } else {
        object->unk0064 &= ~8;
    }

    /* The ROM compares a local 0.5f against a local 0.0f here. */
    if (primaryActive) {
        object->unk0064 &= ~4;
    } else {
        object->unk0064 |= 4;
    }

    if (brakeActive && object->unk01A0 > 100.0f) {
        object->unk01E8 =
            (f32)((f64)object->unk01E8 + D_80120BF0 * 0.5);
        if (object->unk01E8 > 1.0f) {
            object->unk01E8 = 1.0f;
        }
    } else {
        object->unk01E8 =
            (f32)((f64)object->unk01E8 - D_80120BF0 * 0.5);
        if (object->unk01E8 < 0.0f) {
            object->unk01E8 = 0.0f;
        }
    }

    if (specialTrigger && specialMode) {
        (void)func_80082BE0();
        func_800319F4(control->unk10, 4);
        object->unk0060 |= 0x800000;
    }
    if ((object->unk0060 & 0x800000) && !primaryActive) {
        object->unk0060 &= 0xFF7FFFFF;
    }

    object->unk1ED4 -= (f32)D_80120BF0;
    if ((directionA || directionB) && (object->unk0064 & 0x400)) {
        func_80008B14(0x4B, 7, 0.5f, 1.0f, 1);
    }
    if (directionA && !directionB) {
        func_8006D9DC(object, -1.0f);
    } else if (directionB && !directionA) {
        func_8006D9DC(object, 1.0f);
    } else {
        func_8006D9DC(object, 0.0f);
    }

    if (steering < D_800AD7CC && -steering < D_800AD7D0) {
        object->unk01F0 = 0.0f;
    } else {
        if (steering < 0.0f) {
            steering /= D_800AD7D4;
            steering = -(steering * steering) * D_800AD7D4;
        } else {
            steering /= D_800AD7D8;
            steering = steering * steering * D_800AD7D8;
        }
        object->unk01F0 = -steering * object->unk0074;
    }

    object->unk02FC = axis;
    if (D_800AD7DC < axis) {
        amount = D_800AD7E0 * axis;
        object->unk01F0 *= 1.0f - amount;
        if (object->unk018C > 0.5f) {
            object->unk018C += amount;
        }
    }
    if (axis < D_800AD7E4) {
        amount = D_800AD7E8 * axis;
        object->unk01F0 *= 1.0f - amount;
        if (!(object->unk0064 & 0x200) && object->unk018C > 0.5f) {
            object->unk018C += amount;
        }
    }
    if ((object->unk0060 & 0x400000) && object->unk018C < D_800AD7EC) {
        object->unk018C = D_800AD7EC;
    }
    object->unk022C = 1.0f;
}

#undef RANDOM_UNIT
