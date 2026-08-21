/* Independently written from scratchpad spec specs/func_80069A64.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct Obj80069A64 {
    u8 unk000[0x30];
    f32 unk030;
    f32 unk034;
    u8 unk038[0x194 - 0x38];
    PcVec3f unk194;
    f32 unk1A0;
    u8 unk1A4[0x1C4 - 0x1A4];
    PcVec3f unk1C4;
    u8 unk1D0[0x1F8 - 0x1D0];
    f32 unk1F8;
} Obj80069A64;

extern f32 func_80014D4C(f32 value);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(PcVec3f *output, const PcVec3f *left, const PcVec3f *right);

extern f64 D_800AD568;
extern f64 D_800AD570;
extern f32 D_800AD578;
extern f32 D_800AD57C;
extern f32 D_800AD580;
extern f32 D_800AD584;
extern f64 D_80120BF0;

#define ABSF(x) ((x) < 0.0f ? -(x) : (x))

void func_80069A64(Obj80069A64 *object, s32 unused1, s32 unused2, s32 unused3, PcVec3f *direction, PcVec3f *side, PcVec3f *result) {
    PcVec3f cross;
    PcVec3f scaled;
    f32 alignment;
    f32 sideAlignment;
    f32 amount;
    f32 value;
    f32 angle;
    f32 length;

    (void)unused1;
    (void)unused2;
    (void)unused3;

    alignment = object->unk194.z * direction->z + (direction->x * object->unk194.x + direction->y * object->unk194.y);
    if ((f64)alignment < D_800AD568 || D_800AD570 < (f64)alignment) {
        func_80015268(side, 0.0f, 0.0f, 0.0f);
        func_800155C0(&object->unk1C4, 0.9f, &object->unk1C4);
        func_80015288(result, &object->unk1C4);
        object->unk1F8 = 0.0f;
        return;
    }

    func_80015538(&cross, direction, &object->unk194);
    func_800154D0((f32 *)&cross);
    func_80015538(side, direction, &cross);

    sideAlignment = object->unk194.z * side->z + (side->x * object->unk194.x + side->y * object->unk194.y);
    value = func_80014D4C(sideAlignment);
    angle = (-100.0f * value) / 90.0f;
    amount = angle;
    if (object->unk1A0 < 200.0f) {
    } else if (object->unk1A0 < 250.0f) {
        amount = (angle - 25.0f) / 0.75f;
    } else if (object->unk1A0 < 300.0f) {
        amount = (angle - 40.0f) / D_800AD578;
    } else if (object->unk1A0 < 350.0f) {
        amount = (angle - 60.0f) / D_800AD57C;
    } else {
        amount = (angle - 80.0f) / D_800AD580;
    }
    if (amount < 0.0f) {
        amount = 0.0f;
    }
    if (87.0f < value) {
        amount = amount + amount;
    }

    func_800155C0(&scaled, -amount, side);
    func_800155EC(result, &object->unk1C4, (f32)D_80120BF0 + (f32)D_80120BF0, &scaled);
    length = func_800153C0(result);
    if (ABSF(length) > ABSF(amount)) {
        func_800155C0(result, ABSF(amount / length), result);
    }
    func_80015288(&object->unk1C4, result);

    {
        f32 second[3];
        f32 first[3];
        f32 planarDot;
        f32 crossDot;
        f32 signedAngle;

        first[0] = side->x;
        first[1] = side->y;
        first[2] = 0.0f;
        second[0] = object->unk030;
        second[1] = object->unk034;
        second[2] = 0.0f;
        if (func_800154D0(first) < D_800AD584) {
            first[0] = -direction->x;
            first[1] = -direction->y;
            first[2] = -direction->z;
        }
        func_800154D0(second);

        signedAngle = first[0] * second[0] + first[1] * second[1] + first[2] * second[2];
        planarDot = signedAngle;
        crossDot = cross.x * second[0] + cross.y * second[1] + second[2] * cross.z;
        if (planarDot < 0.0f) {
            signedAngle = 0.0f;
        } else {
            if (0.0f < crossDot) {
                signedAngle = -func_80014D4C(planarDot);
            } else {
                signedAngle = func_80014D4C(planarDot);
            }
        }
        signedAngle *= -sideAlignment;
        object->unk1F8 = signedAngle;
    }
}
