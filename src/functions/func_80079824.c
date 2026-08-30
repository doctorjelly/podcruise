/* Independently written from specs/functions/recovered/func_80079824.md. */

#include "podcruise/types.h"

typedef struct Parts80079824 {
    void *entries[60];
} Parts80079824;

typedef struct Kind80079824 {
    u8 pad00[0x10];
    u8 primaryController;
    u8 secondaryController;
    u8 pad12[6];
    s32 *kind;
} Kind80079824;

typedef struct Object80079824 {
    u8 pad0000[0x20];
    f32 baseMatrix[4][4];
    u32 flags;
    u8 pad0064[0x1A0 - 0x64];
    f32 steeringScale;
    u8 pad01A4[0x1F0 - 0x1A4];
    f32 steering;
    u8 pad01F4[0x344 - 0x1F4];
    Parts80079824 *parts;
    u8 pad0348[0x17A0 - 0x348];
    f32 cyclicAngle;
    u8 pad17A4[0x1998 - 0x17A4];
    s32 age;
    u8 pad199C[0x1E70 - 0x199C];
    Kind80079824 *kindData;
} Object80079824;

extern f64 D_800ADAC8;
extern f64 D_800ADAD0;
extern f64 D_800ADAD8;
extern f64 D_800ADAE0;
extern f64 D_800ADAE8;
extern f64 D_800ADAF0;
extern f32 D_800D7720[];
extern f32 D_800D7730[];
extern f64 D_80120BF0;

extern void func_800156DC(f32 [4][4], const f32 [4][4]);
extern void func_8001745C(f32 [4][4], f32, f32, f32);
extern void func_80017BA8(void *, const void *);
extern s32 func_800181BC(void *, s32, u32, s32, s32);
extern f32 func_80079714(
    Object80079824 *, s32, f32, f32, f32, f32, f32, f32);

#define SET_ROTATION(first, second, third) \
    func_8001745C(rotation, (first), (second), (third))

#define APPLY_PART(offset)                                      \
    do {                                                        \
        void *part_ = parts->entries[(offset) / 4];             \
        if (part_ != 0) {                                       \
            func_80017BA8(part_, rotation);                     \
        }                                                       \
    } while (0)

void func_80079824(Object80079824 *object) {
    Parts80079824 *parts;
    Kind80079824 *kindData;
    f32 unusedBaseMatrix[4][4];
    f32 rotation[4][4];
    f32 lowerSteering;
    f32 upperSteering;
    f32 normalizedSteering;
    f32 angle114;
    f32 angle10C;
    f32 angle120;
    f32 angle124;
    f32 angle118;
    f32 angle11C;
    f32 heading;
    f32 cyclicAngle;
    s32 controlMode;
    u32 kind;

    parts = object->parts;
    if (parts == 0) {
        return;
    }

    kindData = object->kindData;
    kind = (u32)*kindData->kind;
    if (parts->entries[0xEC / 4] != 0) {
        func_800181BC(parts->entries[0xEC / 4], 2, 3, 0x10, 2);
    }
    func_800156DC(unusedBaseMatrix, object->baseMatrix);

    controlMode = 2;
    if (kindData->primaryController == kindData->secondaryController) {
        controlMode = 1;
    }
    if (object->flags & 0x20) {
        f32 primaryX = D_800D7720[kindData->primaryController];
        f32 primaryY = D_800D7730[kindData->primaryController];
        f32 secondaryY = D_800D7730[kindData->secondaryController];

        if (controlMode == 1) {
            lowerSteering = -(primaryY + primaryX) / 2.0f;
            upperSteering = -(primaryY - primaryX) / 2.0f;
        } else {
            lowerSteering = -primaryY;
            upperSteering = -secondaryY;
        }
    } else {
        lowerSteering = 0.0f;
        upperSteering = 0.0f;
    }

    normalizedSteering = (f32)((f64)object->steering * D_800ADAC8);
    if (normalizedSteering < -1.0f) {
        normalizedSteering = -1.0f;
    } else if (1.0f < normalizedSteering) {
        normalizedSteering = 1.0f;
    }
    lowerSteering = -(1.0f + normalizedSteering) / 2.0f;
    upperSteering = -(1.0f - normalizedSteering) / 2.0f;

    if ((object->age >= 0x4C) || (object->parts == 0)) {
        return;
    }

    angle114 = func_80079714(
        object, 0x2E, (upperSteering - lowerSteering) * 40.0f,
        0.0f, 75.0f, 75.0f, -40.0f, 40.0f);
    angle10C = func_80079714(
        object, 0x2F, 0.0f, 45.0f, 20.0f, 50.0f, 0.0f, 30.0f);
    angle120 = func_80079714(
        object, 0x20, (upperSteering - lowerSteering) * 30.0f,
        45.0f, 20.0f, 50.0f, 0.0f, 30.0f);
    angle124 = func_80079714(
        object, 0x12, (lowerSteering - upperSteering) * 30.0f,
        45.0f, 20.0f, 50.0f, 0.0f, 30.0f);
    angle118 = func_80079714(
        object, 0x23, (upperSteering - lowerSteering) * 30.0f,
        45.0f, 80.0f, 80.0f, 0.0f, 30.0f);
    angle11C = func_80079714(
        object, 0x15, (lowerSteering - upperSteering) * 30.0f,
        45.0f, 80.0f, 80.0f, 0.0f, 30.0f);

    heading = object->steeringScale * 2.0f;
    if ((f64)heading < 100.0) {
        heading = 100.0f;
    }
    if (D_800ADAD0 < (f64)heading) {
        heading = 700.0f;
    }
    cyclicAngle = (f32)D_80120BF0 * heading + object->cyclicAngle;
    if ((f64)cyclicAngle < D_800ADAD8) {
        cyclicAngle = (f32)((f64)cyclicAngle + D_800ADAE0);
    }
    if (D_800ADAE8 < (f64)cyclicAngle) {
        cyclicAngle = (f32)((f64)cyclicAngle - D_800ADAF0);
    }
    object->cyclicAngle = cyclicAngle;

    switch (kind) {
        case 0:
            SET_ROTATION(0.0f, angle120, 0.0f);
            APPLY_PART(0x80); APPLY_PART(0x84); APPLY_PART(0x88);
            SET_ROTATION(0.0f, angle124, 0.0f);
            APPLY_PART(0x48); APPLY_PART(0x4C); APPLY_PART(0x50);
            SET_ROTATION(-angle118, 0.0f, 0.0f);
            APPLY_PART(0x8C);
            SET_ROTATION(angle118, 0.0f, 0.0f);
            APPLY_PART(0x58); APPLY_PART(0xBC);
            SET_ROTATION(-angle11C, 0.0f, 0.0f);
            APPLY_PART(0x54); APPLY_PART(0xB8);
            SET_ROTATION(angle11C, 0.0f, 0.0f);
            APPLY_PART(0x90);
            break;
        case 1:
            SET_ROTATION(0.0f, 0.0f, cyclicAngle);
            APPLY_PART(0x80); APPLY_PART(0x48);
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x84); APPLY_PART(0x88);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x4C); APPLY_PART(0x50);
            SET_ROTATION(angle114, 0.0f, 0.0f);
            APPLY_PART(0xB8); APPLY_PART(0xBC);
            break;
        case 2:
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x80); APPLY_PART(0x84);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x48); APPLY_PART(0x4C);
            break;
        case 3:
            SET_ROTATION(0.0f, 0.0f, cyclicAngle);
            APPLY_PART(0x80); APPLY_PART(0x48);
            SET_ROTATION(0.0f, angle120, 0.0f);
            APPLY_PART(0xB8);
            SET_ROTATION(0.0f, angle124, 0.0f);
            APPLY_PART(0xBC);
            SET_ROTATION(angle114, 0.0f, 0.0f);
            APPLY_PART(0xC0); APPLY_PART(0xC4);
            APPLY_PART(0xC8); APPLY_PART(0xCC);
            break;
        case 4:
            SET_ROTATION(-angle120, 0.0f, 0.0f);
            APPLY_PART(0x80); APPLY_PART(0x84);
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x88); APPLY_PART(0x8C);
            SET_ROTATION(-angle124, 0.0f, 0.0f);
            APPLY_PART(0x48); APPLY_PART(0x4C);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x50); APPLY_PART(0x54);
            SET_ROTATION(0.0f, 0.0f, -angle114);
            APPLY_PART(0xB8); APPLY_PART(0xCC);
            break;
        case 5:
            SET_ROTATION(0.0f, 0.0f, cyclicAngle);
            APPLY_PART(0x80); APPLY_PART(0x88); APPLY_PART(0x8C);
            APPLY_PART(0x90); APPLY_PART(0x48); APPLY_PART(0x50);
            APPLY_PART(0x54); APPLY_PART(0x58);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x4C); APPLY_PART(0x58); APPLY_PART(0x64);
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x84); APPLY_PART(0x90); APPLY_PART(0x9C);
            break;
        case 6:
            SET_ROTATION(angle114, 0.0f, 0.0f);
            APPLY_PART(0xC8); APPLY_PART(0xD0);
            SET_ROTATION(0.0f, 0.0f, -angle114);
            APPLY_PART(0xCC); APPLY_PART(0xD4);
            break;
        case 7:
            SET_ROTATION(0.0f, angle120, 0.0f);
            APPLY_PART(0x80);
            SET_ROTATION(0.0f, angle124, 0.0f);
            APPLY_PART(0x48);
            break;
        case 8:
            SET_ROTATION(0.0f, 0.0f, cyclicAngle);
            APPLY_PART(0x80); APPLY_PART(0x48);
            SET_ROTATION(0.0f, -2.0f * angle124, 0.0f);
            APPLY_PART(0x4C); APPLY_PART(0x50); APPLY_PART(0x54);
            SET_ROTATION(0.0f, -2.0f * angle120, 0.0f);
            APPLY_PART(0x84); APPLY_PART(0x88); APPLY_PART(0x8C);
            break;
        case 10:
            SET_ROTATION(-angle120, 0.0f, 0.0f); APPLY_PART(0x80);
            SET_ROTATION(angle120, 0.0f, 0.0f); APPLY_PART(0x4C);
            SET_ROTATION(-angle124, 0.0f, 0.0f); APPLY_PART(0x48);
            SET_ROTATION(angle124, 0.0f, 0.0f); APPLY_PART(0x84);
            SET_ROTATION(angle10C, 0.0f, 0.0f);
            APPLY_PART(0xC8); APPLY_PART(0xCC);
            break;
        case 12:
            SET_ROTATION(0.0f, angle10C, 0.0f);
            APPLY_PART(0xD0); APPLY_PART(0xD8);
            SET_ROTATION(0.0f, (f32)((f64)angle114 * 0.5), 0.0f);
            APPLY_PART(0xC8); APPLY_PART(0xD4);
            SET_ROTATION(0.0f, (f32)((f64)-angle114 * 0.5), 0.0f);
            APPLY_PART(0xCC); APPLY_PART(0xDC);
            break;
        case 13:
            SET_ROTATION(0.0f, 0.0f, cyclicAngle);
            APPLY_PART(0x80); APPLY_PART(0x88);
            APPLY_PART(0x48); APPLY_PART(0x50);
            SET_ROTATION(0.0f, angle124, 0.0f);
            APPLY_PART(0x4C); APPLY_PART(0x54);
            SET_ROTATION(0.0f, angle120, 0.0f);
            APPLY_PART(0x84); APPLY_PART(0x8C);
            break;
        case 14:
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x90); APPLY_PART(0x94); APPLY_PART(0x98);
            APPLY_PART(0x9C); APPLY_PART(0xA0); APPLY_PART(0xA4);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x58); APPLY_PART(0x5C); APPLY_PART(0x60);
            APPLY_PART(0x64); APPLY_PART(0x68); APPLY_PART(0x6C);
            break;
        case 15:
            SET_ROTATION(0.0f, -angle120, 0.0f);
            APPLY_PART(0x80); APPLY_PART(0x84);
            APPLY_PART(0x88); APPLY_PART(0x8C);
            SET_ROTATION(0.0f, -angle124, 0.0f);
            APPLY_PART(0x48); APPLY_PART(0x4C);
            APPLY_PART(0x50); APPLY_PART(0x54);
            break;
        case 22:
            SET_ROTATION(angle114, 0.0f, 0.0f);
            APPLY_PART(0xC0); APPLY_PART(0xC4);
            break;
        default:
            break;
    }
}

#undef APPLY_PART
#undef SET_ROTATION
