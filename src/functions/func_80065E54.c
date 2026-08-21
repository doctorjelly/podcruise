/* Implements specs/func_80065E54.md (camera aim blending). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u8 pad00[0x60];
    u32 unk60;
    u32 unk64;
    u8 pad68[0x294];
    f32 unk2FC;
} Actor;

extern void func_80015538(Vec3f *output, Vec3f *left, Vec3f *right);
extern f32 func_800153C0(Vec3f *vector);
extern void func_800155C0(Vec3f *output, f32 scale, Vec3f *source);
extern void func_80065CD0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *out);

extern f32 D_800AD484;
extern f32 D_800AD488;
extern f64 D_80120BF0;

void func_80065E54(Actor *actor, Vec3f *arg1, Vec3f *arg2, Vec3f *arg3, f32 *arg4,
                   f32 arg5, f32 arg6, f32 arg7, f32 *arg8) {
    Vec3f sp54;
    Vec3f sp48;
    f32 length;
    f32 dy;
    f32 dz;
    f32 ratio;
    f32 angles[3];
    f32 spare0;
    f32 spare1;
    f32 saved;

    (void)spare0;
    (void)spare1;
    func_80015538(&sp48, arg2, arg1);
    length = func_800153C0(&sp48);
    if (length <= D_800AD484) {
        sp48.x = arg3->x;
        sp48.y = arg3->y;
        sp48.z = arg3->z;
    } else {
        func_800155C0(&sp48, 1.0f / length, &sp48);
    }

    func_80015538(&sp54, arg1, &sp48);
    length = func_800153C0(&sp54);
    if (length <= D_800AD488) {
        sp54.x = arg2->x;
        sp54.y = arg2->y;
        sp54.z = arg2->z;
    } else {
        func_800155C0(&sp54, 1.0f / length, &sp54);
    }

    func_80065CD0((f32 *)&sp54, (f32 *)&sp48, arg4, angles);

    if (actor->unk64 & 0x400) {
        if (angles[2] > 85.0f) {
            angles[2] = 85.0f;
        }
        if (angles[2] < -85.0f) {
            angles[2] = -85.0f;
        }
    }

    saved = arg8[2];
    dy = angles[1] - arg8[1];
    dz = angles[2] - saved;
    if (angles[1] < arg8[1]) {
        dy = dy / 3.0f;
    } else if (arg8[1] < angles[1]) {
        dy = dy / 2.0f;
    }
    dz = dz / 8.0f;

    if (!(actor->unk60 & 0x04000000)) {
        ratio = (arg6 - arg5) / (arg6 - arg7);
        if (ratio > 0.0f) {
            if (ratio < 1.0f) {
                dy = dy * ratio;
                dz = dz * ratio;
            }
        } else {
            dz = (-saved) / 8.0f;
            dy = 0.0f;
            if (arg8[1] > -37.0f) {
                dy = (f32)D_80120BF0 * -22.0f;
            }
            if (actor->unk2FC < 0.0f) {
                if (arg8[1] < -10.0f) {
                    dy = dy - (20.0f * actor->unk2FC) * (f32)D_80120BF0;
                }
            }
        }
    }

    arg8[1] = arg8[1] + dy;
    arg8[2] = saved + dz;
}
