/* Recovered from specification specs/func_80028D60.md (worker batch_15). */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 D_80118D60[4][4];
extern Vec3f D_80118D90;
extern Vec3f D_80118E50;

extern void func_80015288(Vec3f *output, Vec3f *source);
extern void func_8001535C(Vec3f *output, Vec3f *left, Vec3f *right);
extern f32 func_800154D0(Vec3f *vector);
extern f32 func_80014F54(f32 first, f32 second);
extern f32 func_80014D4C(f32 value);
extern void func_8001745C(f32 matrix[4][4], f32 first, f32 second, f32 third);

void func_80028D60(void) {
    Vec3f direction;
    Vec3f saved;
    f32 yaw;
    f32 pitch;

    func_80015288(&saved, &D_80118D90);
    func_8001535C(&direction, &D_80118E50, &D_80118D90);
    func_800154D0(&direction);
    yaw = func_80014F54(-direction.x, direction.y);
    pitch = func_80014D4C(direction.z);
    if (yaw < 0.0f) {
        yaw += 360.0f;
    }
    if (yaw > 360.0f) {
        yaw -= 360.0f;
    }
    if (pitch < -90.0f) {
        pitch += 180.0f;
    }
    if (pitch > 90.0f) {
        pitch -= 180.0f;
    }
    func_8001745C(D_80118D60, yaw, pitch, 0.0f);
    func_80015288(&D_80118D90, &saved);
}
