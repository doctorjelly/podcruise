/* Independently written from specs/functions/recovered/func_8006907C.md. */

#include "podcruise/types.h"

typedef struct Obj6907C {
    u8 pad000[0x60];
    u32 unk060;
    u32 unk064;
    u8 pad068[0x13C - 0x68];
    s32 unk13C;
    u8 pad140[0x154 - 0x140];
    f32 unk154;
    f32 unk158;
    f32 unk15C;
    u8 pad160[0x18C - 0x160];
    f32 unk18C;
    u8 pad190[0x1A4 - 0x190];
    f32 unk1A4;
    u8 pad1A8[0x1C4 - 0x1A8];
    f32 unk1C4;
    f32 unk1C8;
    f32 unk1CC;
    f32 unk1D0;
    f32 unk1D4;
    f32 unk1D8;
    f32 unk1DC;
    f32 unk1E0;
    f32 unk1E4;
    u8 pad1E8[0x1998 - 0x1E8];
    s32 unk1998;
} Obj6907C;

extern f32 D_800AD534;
extern f32 D_800AD538;
extern f64 D_80120BF0;

f32 sqrtf(f32);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif
extern f32 func_800153C0(f32 *vector);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *offset);
extern s32 func_80033140(f32 *arg0, f32 *arg1, s32 arg2, f32 *arg3);
extern f32 func_80068410(Obj6907C *object);
extern f32 func_800689A0(Obj6907C *object);
extern void func_80068D04(Obj6907C *object, f32 amount, f32 *direction,
                          f32 *velocity);
extern f32 func_80081700(f32 arg0, f32 arg1);

void func_8006907C(Obj6907C *object, f32 *arg1, f32 *position, f32 *direction) {
    f32 velocity[3];
    f32 amount;
    f32 dot;
    f32 planar;
    f32 length;
    f32 previous[3];
    f32 scratch[3];
    s32 count;

    amount = func_80068410(object);
    amount = func_800689A0(object) + amount;
    func_80068D04(object, amount, direction, velocity);

    if (!(object->unk064 & 0x400) && !(object->unk060 & 0x2000000)) {
        if (0.0f < velocity[2]) {
            planar = velocity[0] * velocity[0] + velocity[1] * velocity[1];
            if (planar * D_800AD534 < velocity[2] * velocity[2]) {
                velocity[2] = sqrtf(planar) / 5.0f;
            }
        }
    }

    velocity[0] = velocity[0] + object->unk1DC;
    velocity[1] = velocity[1] + object->unk1E0;
    velocity[2] = velocity[2] + object->unk1E4;

    object->unk1D0 = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1D0;
    object->unk1D4 = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1D4;
    object->unk1D8 = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1D8;
    object->unk1DC = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1DC;
    object->unk1E0 = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1E0;
    object->unk1E4 = func_80081700(4.0f, (f32)D_80120BF0) * object->unk1E4;

    if (!(object->unk060 & 0x5000)) {
        if (D_800AD538 < object->unk18C || D_800AD538 < -object->unk18C ||
            !(object->unk060 & 0x2000)) {
            dot = object->unk1CC * velocity[2] +
                  (velocity[0] * object->unk1C4 + velocity[1] * object->unk1C8);
            if (dot < 0.0f) {
                velocity[0] = object->unk1C4 + velocity[0];
                velocity[1] = object->unk1C8 + velocity[1];
                velocity[2] = object->unk1CC + velocity[2];
            } else {
                length = func_800153C0(&object->unk1C4);
                if (1.0f < length) {
                    if (1.0f < amount) {
                        planar = dot / (60.0f * amount);
                        if (0.0f < planar) {
                            object->unk1A4 = object->unk1A4 +
                                ((f32)D_80120BF0 + (f32)D_80120BF0) * planar;
                        }
                    }
                    planar = (dot / length) / 100.0f;
                    if (planar < 1.0f) {
                        planar = 1.0f;
                    }
                    func_800155EC(velocity, velocity, planar, &object->unk1C4);
                } else {
                    velocity[0] = object->unk1C4 + velocity[0];
                    velocity[1] = object->unk1C8 + velocity[1];
                    velocity[2] = object->unk1CC + velocity[2];
                }
            }
        }
    }

    func_800155EC(position, arg1, (f32)D_80120BF0, velocity);

    if ((f32)(((f32)object->unk1998 - 400.0f) / 600.0f) < 1.0 ||
        (object->unk060 & 0x20) || (object->unk064 & 0x4000000)) {
        if (object->unk064 & 0x800000) {
            object->unk154 = 0.0f;
            object->unk158 = 0.0f;
            object->unk15C = 0.0f;
        } else {
            previous[0] = position[0];
            previous[1] = position[1];
            previous[2] = position[2];
            count = 0;
            while (func_80033140(position, arg1, object->unk13C, scratch)) {
                count++;
                if (count == 6) {
                    break;
                }
            }
            if (count > 0) {
                if (object->unk060 & 0x80) {
                    object->unk1A4 =
                        object->unk1A4 * func_80081700(5.0f, (f32)D_80120BF0);
                }
            }
            previous[0] = position[0] - previous[0];
            previous[1] = position[1] - previous[1];
            previous[2] = position[2] - previous[2];
            object->unk154 = previous[0];
            object->unk158 = previous[1];
            object->unk15C = previous[2];
        }
    } else {
        object->unk154 = 0.0f;
        object->unk158 = 0.0f;
        object->unk15C = 0.0f;
    }
}
