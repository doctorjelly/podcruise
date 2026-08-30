/* Independently written from specs/functions/recovered/func_8004CA50.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct Context8004CA50 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 mode;
    /* 0x0C */ s32 previousMode;
    /* 0x10 */ s32 option10;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ s32 trackIndex;
    /* 0x38 */ s32 stage;
    /* 0x3C */ s32 previousStage;
    /* 0x40 */ s32 objectIndex;
    /* 0x44 */ u8 pad44[0x0C];
    /* 0x50 */ s8 randomChoice;
    /* 0x51 */ u8 pad51[0x1B];
    /* 0x6C */ s8 side;
    /* 0x6D */ u8 pad6D[3];
    /* 0x70 */ s8 riderCount;
} Context8004CA50;

typedef struct TrackNode8004CA50 {
    /* 0x00 */ PcVec3f position;
    /* 0x0C */ PcVec3f heading;
    /* 0x18 */ s16 kind;
    /* 0x1A */ u8 pad1A[6];
} TrackNode8004CA50;

typedef struct SceneObject8004CA50 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 state;
    /* 0x0C */ u8 pad0C[8];
    /* 0x14 */ s32 enabled;
    /* 0x18 */ u8 pad18[0x94];
    /* 0xAC */ f32 distance;
} SceneObject8004CA50;

typedef struct Transform8004CA50 {
    PcVec3f direction;
    PcVec3f rotation;
} Transform8004CA50;

typedef struct Transition8004CA50 {
    /* 0x00 */ f32 progress;
    /* 0x04 */ s32 active;
    /* 0x08 */ s32 secondaryActive;
    /* 0x0C */ f32 secondaryProgress;
    /* 0x10 */ s32 value10;
    /* 0x14 */ s32 value14;
    /* 0x18 */ s32 value18;
    /* 0x1C */ s32 value1C;
    /* 0x20 */ s32 value20;
    /* 0x24 */ s32 value24;
    /* 0x28 */ s32 pad28;
    /* 0x2C */ s32 mode2C;
} Transition8004CA50;

extern s32 D_800A21B0;
extern s32 D_800A4B30;
extern s16 D_800A4B36;
extern s32 D_800A4B38;
extern s16 D_800A4B3A;
extern s16 D_800A4BC0;
extern TrackNode8004CA50 D_800A4C00[];
extern PcVec3f D_800A4C6C;
extern PcVec3f D_800A5080;
extern PcVec3f D_800A508C;
extern PcVec3f D_800A5100[];
extern PcVec3f D_800A5130;
extern PcVec3f D_800A513C;
extern PcVec3f D_800A5160;
extern PcVec3f D_800A516C;
extern PcVec3f D_800A519C;
extern PcVec3f D_800A51A8;
extern PcVec3f D_800A51B4;
extern u8 D_800AAE4C[];
extern u8 D_800AAE50[];
extern f32 D_800AB1D0;
extern f32 D_800AB1D4;
extern f32 D_800AB1D8;
extern f32 D_800AB228;
extern f32 D_800AB240;
extern f64 D_800AB248;
extern f32 D_800AB250;
extern f32 D_800AB254;
extern f32 D_800AB258;
extern u8 D_80113E60[];
extern u8 D_80113E7C;
extern PcVec3fSlot D_80118D20[4];
extern PcVec3fSlot D_80118D60[4];
extern PcVec3f D_80118D90;
extern PcVec3fSlot D_80118DA0[4];
extern PcVec3fSlot D_80118DE0[4];
extern PcVec3fSlot D_80118E20[4];
extern PcVec3f D_80118E50;
extern PcVec3fSlot D_80118E60[4];
extern PcVec3fSlot D_80118EA0[4];
extern f32 D_80118EE0[6];
extern f32 D_80118F00[6];
extern f32 D_80118F18[6];
extern PcVec3f D_801195F0;
extern Transition8004CA50 D_8011A240;

extern void func_8000AC90(u16 value);
extern void func_8000AEFC(s16 index, s16 second, u32 third, s16 fourth);
extern void func_8000B02C(s16 index, s32 value, s16 mode);
extern void func_8000B0E0(s16 slot, void *object);
extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern f32 func_80014F54(f32 x, f32 y);
extern void func_80016F0C(const void *matrix, f32 *output);
extern void func_800174B8(void *matrix, const void *transform);
extern void *func_80017F28(s32 index);
extern s32 func_8002D968(u8 *left, u8 *right);
extern void func_80038DBC(s32 flag);
extern SceneObject8004CA50 *func_8003F800(u32 tag, s32 index);
extern void func_800513E0(void *context, s32 mirrored);
extern void func_80063084(s32 objectId, s32 mode, PcVec3f *position,
                          PcVec3f *target, f32 angle, f32 targetAngle);
extern s32 func_80082BE0(void);
extern void func_800862D8(s32 index, s32 left, s32 top, s32 right, s32 bottom);
extern void func_8008635C(s32 slot, s32 value);
extern void func_80086730(s32 index, f32 fov, f32 aspect, f32 near, f32 far,
                          f32 scale);
extern void func_80086A20(s32 slot, PcVec3f *ambient, PcVec3f *diffuse,
                          PcVec3f *direction);

void func_8004CA50(Context8004CA50 *context) {
    PcVec3f position;
    Transform8004CA50 transformA;
    Transform8004CA50 transformB;
    PcVec3f direction;
    PcVec3f diffuse;
    PcVec3f ambient;
    SceneObject8004CA50 *object;
    TrackNode8004CA50 *track;
    f32 angle;
    f32 targetAngle;
    f32 sine;
    f32 cosine;
    f32 farPlane;
    f32 firstAngle;
    s32 savedDisplayValue;
    s32 firstChoice;
    s32 nextChoice;
    s32 objectId;
    s32 objectMode;
    s32 firstObject;
    s32 secondObject;
    s32 remaining;
    s16 i;

    farPlane = D_800AB1D0;
    savedDisplayValue = D_800A4B38;
    func_8000AC90(0x3800);
    D_800A4BC0 = 0;

    D_8011A240.progress = 0.0f;
    D_8011A240.active = 0;
    D_8011A240.secondaryActive = 0;
    D_8011A240.secondaryProgress = 0.0f;
    D_8011A240.value10 = 0;
    D_8011A240.value14 = 0;
    D_8011A240.value18 = 0;
    D_8011A240.value1C = 0;
    D_8011A240.value20 = 0;
    D_8011A240.value24 = 0;

    ambient.x = 80.0f;
    ambient.y = 75.0f;
    ambient.z = 50.0f;
    diffuse.x = 255.0f;
    diffuse.y = 255.0f;
    diffuse.z = 200.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = D_800AB1D4;

    func_80015268(&transformA.direction, 0.0f, 1.0f, 0.0f);
    func_80015268(&transformA.rotation, 0.0f, 0.0f, 0.0f);
    func_80015268(&transformB.direction, 0.0f, 1.0f, 0.0f);
    func_80015268(&transformB.rotation, 0.0f, 0.0f, 0.0f);
    func_800174B8(D_80118D20, &transformA);
    func_800174B8(D_80118D60, &transformA);
    func_800174B8(D_80118E20, &transformB);
    func_80038DBC(0);

    context->trackIndex = 0x24;
    context->objectIndex = -1;
    i = 0;
    while (i < context->riderCount) {
        object = func_8003F800(0x456C6D6F, i + 0x1C);
        if (object != 0) {
            object->enabled = 0;
        }
        i++;
    }

    if ((context->stage == 3) && (context->previousStage != 3)) {
        func_80015288(&position, &D_800A516C);
        angle = ((f32)func_80082BE0() / 2147483648.0f) * 360.0f;
        func_80063084(0x38, 0x11, &position, &position, angle, angle);

        firstChoice =
            (s32)(((f32)func_80082BE0() / 2147483648.0f) * 3.0f);
        func_80015288(&position, &D_800A5100[firstChoice + 10]);
        object = func_8003F800(0x456C6D6F, 0x39);
        if (object->state == 1) {
            func_80063084(0x39, 0, &position, &position, angle, angle);
        } else {
            func_80063084(0x39, 0x11, &position, &position, angle, angle);
        }

        do {
            nextChoice =
                (s32)(((f32)func_80082BE0() / 2147483648.0f) * 3.0f) + 10;
        } while (nextChoice == firstChoice + 10);
        context->randomChoice = (s8)(nextChoice - 9);
        func_80015288(&position, &D_800A5100[nextChoice]);
        angle = ((f32)func_80082BE0() / 2147483648.0f) * 360.0f;
        func_80063084(0x17, 0x2E, &position, &position, angle, angle);
        func_80015288(&position, &D_800A5160);
        func_80063084(0x16, 0x2A, &position, &position, D_800AB1D8,
                      D_800AB1D8);
    }

    switch ((u32)context->mode) {
    case 9:
        if (context->previousMode == 0xC) {
            context->trackIndex = 0x25;
        }
        D_8011A240.active = 1;
        D_8011A240.secondaryActive = 1;
        break;

    case 12:
        if (context->previousMode == 0xD) {
            context->trackIndex = 0x25;
            D_8011A240.progress = 1.0f;
        }
        D_8011A240.active = 1;
        break;

    case 13:
        if (context->previousMode == 0xC) {
            context->trackIndex = 0x25;
            D_8011A240.progress = 1.0f;
        }
        D_8011A240.active = 1;
        break;

    case 8:
        farPlane = D_800AB228;
        context->trackIndex = 0x14;
        D_8011A240.mode2C = 7;
        break;

    case 7:
        if (D_800A21B0 == 2) {
            context->option10 = 1;
        } else if (D_800A21B0 == 1) {
            context->option10 = 0;
        }
        context->trackIndex = context->option10 == 1 ? 2 : 1;

        func_80015288(&position, &D_800A5130);
        func_80015288(&D_801195F0, &position);
        firstAngle = func_80014F54(position.x - 12.0f,
                                  -116.0f - position.y);
        angle = firstAngle;
        objectMode = 0x1D;
        if (context->previousMode == 4) {
            func_80015288(
                &position, &D_800A4C00[context->trackIndex].heading);
            position.z = -40.0f;
            angle = func_80014F54(position.x - D_801195F0.x,
                                  D_801195F0.y - position.y);
            objectMode = 0x1E;
        }
        func_80063084(0x15, objectMode, &position, &D_801195F0, angle,
                      firstAngle);

        func_80015288(&D_801195F0, &D_800A5130);
        if ((s32)(((f32)func_80082BE0() / 2147483648.0f) * 2.0f) == 0) {
            func_80015288(&position, &D_800A519C);
            angle = func_80014F54(position.x - D_801195F0.x,
                                  D_801195F0.y - position.y);
            targetAngle = angle -
                          90.0f * ((f32)func_80082BE0() / 2147483648.0f);
        } else {
            func_80015288(&position, &D_800A51A8);
            targetAngle = func_80014F54(position.x - D_801195F0.x,
                                        D_801195F0.y - position.y);
        }
        angle = targetAngle;
        objectId =
            (s32)(((f32)func_80082BE0() / 2147483648.0f) * 5.0f) + 0x17;
        switch (objectId) {
        case 0x17:
            objectMode = 0x2E;
            break;
        case 0x18:
            objectMode = 0x32;
            break;
        case 0x19:
            objectMode = 0x37;
            break;
        case 0x1A:
            objectMode = 0x3C;
            break;
        default:
            objectMode = 0x41;
            break;
        }
        func_80063084(objectId, objectMode, &position, &position, targetAngle,
                      targetAngle);

        i = 0;
        while (i < context->riderCount) {
            func_80015268(&position, (f32)((f64)i * 50.0 + 200.0),
                          -200.0f, -60.0f);
            if (context->previousMode == 4) {
                func_80015288(
                    &position, &D_800A4C00[context->trackIndex].heading);
            }
            position.z = -60.0f;
            func_80015268(&position, -20.0f, -100.0f, -60.0f);
            func_80015268(&D_801195F0, 0.0f, 0.0f, -60.0f);
            angle = func_80014F54(position.x - D_801195F0.x,
                                  D_801195F0.y - position.y);
            func_80063084(i + 0x1C, 0x13, &position, &D_801195F0, angle,
                          angle);
            i++;
        }

        i = 0;
        remaining = 4 - D_80113E7C;
        if (remaining > 0) {
            firstAngle = 256.0f * D_800AB240;
            while (i < remaining) {
                func_80014CC0((f32)(0x122 - i * 10), &sine, &cosine);
                func_80015268(&position, firstAngle * cosine + 12.0f,
                              firstAngle * sine - 116.0f, -60.0f);
                angle = func_80014F54(position.x - 12.0f,
                                      -116.0f - position.y);
                func_80063084(i + 0x34, 5, &position, &position, angle,
                              angle);
                i++;
            }
        }
        break;

    case 4:
        ambient.x = 120.0f;
        ambient.y = 135.0f;
        ambient.z = 140.0f;
        context->trackIndex = 4;
        for (objectId = 4; objectId < 0x13; objectId++) {
            if (D_800A4C00[objectId].kind == 4) {
                context->trackIndex = objectId;
                break;
            }
        }

        i = 0;
        while (i < context->riderCount) {
            func_80015268(&position,
                          (f32)((f64)i * 50.0 + D_800AB248), -569.0f,
                          -145.0f);
            func_800513E0(context, i);
            track = &D_800A4C00[context->trackIndex];
            angle = func_80014F54(track->heading.x - track->position.x,
                                  track->position.y - track->heading.y);
            func_80063084(i + 0x1C, 0x14, &position, &D_801195F0, angle,
                          angle + 180.0f);
            i++;
        }

        func_80015288(&position, &D_800A4C6C);
        position.z = -125.0f;
        func_80015288(&D_801195F0, &D_800A513C);
        angle = func_80014F54(position.x - D_801195F0.x,
                              D_801195F0.y - position.y);
        func_80063084(0x15, 0x1E, &position, &D_801195F0, angle,
                      angle + 90.0f);

        func_80015268(&position, 0.0f, 0.0f, 0.0f);
        i = 0;
        remaining = 4 - D_80113E7C;
        while (i < remaining) {
            func_80063084(i + 0x34, 0, &position, &position, 0.0f, 0.0f);
            i++;
        }

        func_80015288(&position, &D_800A51B4);
        if (func_8002D968(D_80113E60, D_800AAE4C) != 0) {
            func_80063084(0x13, 0x28, &position, &position, 180.0f, 180.0f);
        } else if (func_8002D968(D_80113E60, D_800AAE50) != 0) {
            angle = 192.0f;
            position.y -= 20.0f;
            func_80063084(0x14, 0x29, &position, &position, angle, angle);
        }
        break;

    case 18:
        if (context->side == 0) {
            firstObject = 0x38;
            secondObject = 0x39;
        } else {
            firstObject = 0x39;
            secondObject = 0x38;
        }
        context->trackIndex = 0x27;
        context->objectIndex = firstObject;
        D_8011A240.active = 1;
        D_8011A240.progress = 1.0f;

        func_80015288(&position, &D_800A5080);
        func_80015630(&position, 0.6f, &D_800A5080, 0.4f,
                      &D_800A508C);
        position.z = -60.0f;
        func_80015288(&D_801195F0, &D_800A508C);
        angle = func_80014F54(position.x - D_801195F0.x,
                              D_801195F0.y - position.y);
        object = func_8003F800(0x456C6D6F, firstObject);
        if (object->state == 1) {
            func_80063084(firstObject, 2, &position, &position, angle, angle);
        } else {
            func_80063084(firstObject, 0x11, &position, &position, angle,
                          angle);
            object->distance = 100.0f;
        }

        func_80015288(&position, &D_800A516C);
        angle = ((f32)func_80082BE0() / 2147483648.0f) * 360.0f;
        object = func_8003F800(0x456C6D6F, secondObject);
        if (object->state == 1) {
            func_80063084(secondObject, 0, &position, &position, angle,
                          angle);
        } else {
            func_80063084(secondObject, 0x11, &position, &position, angle,
                          angle);
        }
        break;

    case 15:
        farPlane = D_800AB250;
        context->trackIndex = 0x14;
        for (i = 0; i < 2; i++) {
            func_80015268(&D_801195F0, 200.0f, -300.0f, -157.0f);
            angle = (f32)(180 - i * 180);
            D_801195F0.y -= (f32)(i * 200);
            func_80063084(i + 0x1C, 0x14, &D_801195F0,
                          &D_801195F0, angle, angle);
        }
        break;

    case 16:
        farPlane = D_800AB254;
        for (i = 0; i < 3; i++) {
            func_80015268(&D_801195F0, 0.0f, (f32)i * -150.0f, 0.0f);
            if (i == 2) {
                D_801195F0.y += 450.0f;
            }
            func_80063084(i + 0x1C, 0x1C, &D_801195F0,
                          &D_801195F0, -90.0f, -90.0f);
        }
        break;

    case 17:
        farPlane = D_800AB258;
        context->trackIndex = 0x1A;
        func_80015268(&position, 0.0f, -1000.0f, -157.0f);
        func_80063084(0x34, 0x10, &position, &position, 0.0f, 0.0f);
        break;
    }

    func_800862D8(0, 8, 8, 0x138, 0xE8);
    func_800862D8(D_800A4B30, 8, 8, 0x138, 0xE8);
    func_8008635C(D_800A4B30, savedDisplayValue);
    func_8000B0E0((s16)savedDisplayValue, func_80017F28(D_800A4B30));
    func_8000AEFC(D_800A4B36, 1, (u32)(unsigned long)D_80118D20, 0);
    func_8000AEFC(D_800A4B3A, 2, (u32)(unsigned long)D_80118D60, 0);
    func_8000B02C(D_800A4B3A, (s32)(unsigned long)D_80118E20, 0);
    func_80086730(D_800A4B30, 45.0f, -1.0f, 100.0f, farPlane, -1.0f);

    if (context->trackIndex != -1) {
        func_80015288(&D_80118D90,
                      &D_800A4C00[context->trackIndex].position);
        func_80015288(&D_80118E50,
                      &D_800A4C00[context->trackIndex].heading);
    }
    func_800156DC(D_80118DA0, D_80118D60);
    func_800156DC(D_80118DE0, D_80118D60);
    func_800156DC(D_80118E60, D_80118E20);
    func_800156DC(D_80118EA0, D_80118E20);
    func_80016F0C(D_80118D20, D_80118EE0);
    func_80016F0C(D_80118D20, D_80118F18);
    func_80016F0C(D_80118D20, D_80118F00);
    if (context->stage != 3) {
        func_80086A20(-1, &ambient, &diffuse, &direction);
    }
}
