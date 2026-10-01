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

typedef struct Vec6907C {
    f32 x;
    f32 y;
    f32 z;
} Vec6907C;

void func_8006907C(Obj6907C *object, f32 *arg1, f32 *position, f32 *direction) {
    Vec6907C velocity;
    f32 amount;
    f32 length;
    f32 planar;
    f32 previous[3];
    f32 scratch[3];
    f32 speed;
    f32 dot;
    f32 pad[3];
    f32 side;

    (void)pad;
    amount = func_80068410(object);
    dot = func_800689A0(object);
    amount = amount + dot;
    func_80068D04(object, amount, direction, (f32 *)&velocity);

    if (!(object->unk064 & 0x400) && !(object->unk060 & 0x2000000)) {
        if (0.0f < velocity.z) {
            speed = velocity.y * velocity.y + velocity.x * velocity.x;
            if (speed * D_800AD534 < velocity.z * velocity.z) {
                velocity.z = sqrtf(speed) / 5.0f;
            }
        }
    }

    velocity.x = velocity.x + object->unk1DC;
    velocity.y = velocity.y + object->unk1E0;
    velocity.z = velocity.z + object->unk1E4;

    object->unk1D0 *= func_80081700(4.0f, (f32)D_80120BF0);
    object->unk1D4 *= func_80081700(4.0f, (f32)D_80120BF0);
    object->unk1D8 *= func_80081700(4.0f, (f32)D_80120BF0);
    object->unk1DC *= func_80081700(4.0f, (f32)D_80120BF0);
    object->unk1E0 *= func_80081700(4.0f, (f32)D_80120BF0);
    object->unk1E4 *= func_80081700(4.0f, (f32)D_80120BF0);

    if (!(object->unk060 & 0x5000)) {
        side = object->unk18C;
        if (D_800AD538 < side || D_800AD538 < -side ||
            !(object->unk060 & 0x2000)) {
            direction = &object->unk1C4;
            dot = object->unk1CC * velocity.z + (velocity.x * object->unk1C4 + velocity.y * object->unk1C8);
            if (dot < 0.0f) {
                velocity.x = object->unk1C4 + velocity.x;
                velocity.y = object->unk1C8 + velocity.y;
                velocity.z = object->unk1CC + velocity.z;
            } else {
                length = func_800153C0(direction);
                if (1.0f < length) {
                    if (1.0f < amount) {
                        planar = dot / (60.0f * amount);
                        if (0.0f < planar) {
                            object->unk1A4 = object->unk1A4 +
                                ((f32)D_80120BF0 + (f32)D_80120BF0) * planar;
                        }
                    }
                    dot = (dot / length) / 100.0f;
                    if (dot < 1.0f) {
                        dot = 1.0f;
                    }
                    func_800155EC((f32 *)&velocity, (f32 *)&velocity, dot, direction);
                } else {
                    velocity.x = object->unk1C4 + velocity.x;
                    velocity.y = object->unk1C8 + velocity.y;
                    velocity.z = object->unk1CC + velocity.z;
                }
            }
        }
    }

    func_800155EC(position, arg1, (f32)D_80120BF0, (f32 *)&velocity);

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
            direction = (f32 *)0L;
            while (func_80033140(position, arg1, object->unk13C, scratch) &&
                   (long)direction != 6) {
                direction = (f32 *)((long)direction + 1);
            }
            if ((long)direction > 0) {
                if (object->unk060 & 0x80) {
                    object->unk1A4 *= func_80081700(5.0f, (f32)D_80120BF0);
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
