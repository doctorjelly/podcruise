/* Independently written from specs/functions/recovered/func_80069EC0.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3;

typedef struct {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u32 kind;
    /* 0x08 */ f32 value;
} Message;

typedef struct {
    /* 0x000 */ u8 pad000[0x30];
    /* 0x030 */ Vec3 unk30;
    /* 0x03C */ u8 pad03C[0x24];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ u8 pad068[0x12C];
    /* 0x194 */ Vec3 unk194;
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ f32 unk1A4;
    /* 0x1A8 */ u8 pad1A8[0x28];
    /* 0x1D0 */ Vec3 unk1D0;
    /* 0x1DC */ u8 pad1DC[0x18];
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ u8 pad1F8[0x6C];
    /* 0x264 */ f32 unk264;
} Body;

extern f32 D_800AD588;
extern f32 D_800AD58C;
extern f32 D_800AD590;
extern f32 D_800AD594;
extern f32 D_800AD598;
extern f32 D_800AD59C;
extern f32 D_800AD5A0;
extern f32 D_800AD5A4;
extern f32 D_800AD5A8;
extern f64 D_80120BF0;

extern f32 func_800153C0(Vec3 *);
extern f32 func_800154D0(Vec3 *);
extern void func_80015538(Vec3 *, Vec3 *, Vec3 *);
extern void func_8003F99C(Body *, Message *);
extern f32 func_80081700(f32, f32);

void func_80069EC0(Body *body, Vec3 *vel, Vec3 *normal) {
    f32 dot;
    f32 forward;
    f32 side;
    f32 speed;
    Vec3 vecs[3];
    f32 t;
    f32 push;
    f32 len;
    f32 scale;
    f32 strength;
    f32 magForward;
    f32 magSide;
    f32 value;
    Message msg;
    s32 pad0;
    s32 hit;
    s32 pad1;
    s32 pad2;
    f32 impact;
    s32 pad3;

    pad0 = 0; pad1 = 0; pad2 = 0; pad3 = 0;
    (void)pad0; (void)pad1; (void)pad2; (void)pad3;
    hit = 0;
    vecs[2].x = normal->x;
    vecs[2].y = normal->y;
    vecs[2].z = normal->z;
    dot = vel->x * vecs[2].x + vel->y * vecs[2].y + vecs[2].z * vel->z;
    len = func_800153C0(vel);
    if (len < D_800AD588) {
        t = 0.0f;
    } else {
        t = D_800AD58C - dot / len;
    }
    if (t < 0.0f) {
        t = 0.0f;
    } else {
        t = t / D_800AD590;
    }
    push = -dot;
    vel->x = vecs[2].x * push + vel->x;
    vel->y = vecs[2].y * push + vel->y;
    vel->z = vecs[2].z * push + vel->z;
    vecs[1].x = vel->x;
    vecs[1].y = vel->y;
    vecs[1].z = vel->z;
    speed = func_800153C0(&vecs[1]);
    if (D_800AD594 <= speed) {
        scale = 1.0f / speed;
        vecs[1].x = vecs[1].x * scale;
        vecs[1].y = vecs[1].y * scale;
        vecs[1].z = vecs[1].z * scale;
        forward = vecs[1].x * body->unk30.x + vecs[1].y * body->unk30.y + body->unk30.z * vecs[1].z;
        func_80015538(&vecs[0], &body->unk194, &body->unk30);
        func_800154D0(&vecs[0]);
        side = vecs[1].x * vecs[0].x + vecs[1].y * vecs[0].y + vecs[0].z * vecs[1].z;
        impact = t * forward * forward;
        if (D_800AD598 < impact) {
            body->unk60 &= ~0x10;
            hit = 1;
            if ((body->unk60 & 0x7000) == 0) {
                body->unk264 = D_800AD59C;
            }
        }
        strength = 1.5f * impact * body->unk1A0;
        body->unk1D0.x = vecs[1].x * strength + body->unk1D0.x;
        body->unk1D0.y = vecs[1].y * strength + body->unk1D0.y;
        body->unk1D0.z = vecs[1].z * strength + body->unk1D0.z;
        if (body->unk64 & 0x400) {
            body->unk1F4 = 0.0f;
        } else {
            if (forward < 0.0f) {
                if (side < 0.0f) {
                    value = (side + forward + 1.0f) / D_800AD5A0;
                    body->unk1F4 = value;
                    if (0.0f < value) {
                        body->unk1F4 = 0.0f;
                    }
                } else {
                    value = (side - forward - 1.0f) / D_800AD5A4;
                    body->unk1F4 = value;
                    if (value < 0.0f) {
                        body->unk1F4 = 0.0f;
                    }
                }
            } else {
                body->unk1F4 = 0.0f;
            }
            body->unk1F4 = body->unk1F4 * (-150.0f * t);
        }
        if (0.0 < impact && 100.0 < body->unk1A0) {
            body->unk1A4 = body->unk1A4 * func_80081700(50.0f, D_80120BF0);
            if (D_800AD5A8 < impact) {
                body->unk60 |= 0x40000;
            }
            msg.tag = 0x48697474;
            if (hit != 0) {
                msg.kind = 0x4B506F77;
            } else {
                if (forward < 0.0f) {
                    magForward = -forward;
                } else {
                    magForward = forward;
                }
                if (side < 0.0f) {
                    magSide = -side;
                } else {
                    magSide = side;
                }
                if (magSide < magForward) {
                    if (side < 0.0) {
                        msg.kind = 0x52744674;
                    } else {
                        msg.kind = 0x4C744674;
                    }
                } else {
                    if (side < 0.0) {
                        msg.kind = 0x52745364;
                    } else {
                        msg.kind = 0x4C745364;
                    }
                }
            }
            msg.value = speed / D_80120BF0;
            func_8003F99C(body, &msg);
        }
    }
}
