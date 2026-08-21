/* Recovered per specs/func_80081A2C.md (closest point on a segment). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f64 D_800ADCC0;

void func_80081A2C(Vec3f *point, Vec3f *segmentStart, Vec3f *segmentEnd, Vec3f *out) {
    f32 lengthSquared;
    f32 delta[3];
    f32 projected;
    f32 base;
    f32 t;

    delta[0] = segmentEnd->x - segmentStart->x;
    delta[1] = segmentEnd->y - segmentStart->y;
    delta[2] = segmentEnd->z - segmentStart->z;

    projected = point->x * delta[0] + point->y * delta[1] + delta[2] * point->z;
    base = segmentStart->x * delta[0] + segmentStart->y * delta[1] + delta[2] * segmentStart->z;
    lengthSquared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];

    if ((f64)lengthSquared <= D_800ADCC0) {
        out->x = segmentStart->x;
        out->y = segmentStart->y;
        out->z = segmentStart->z;
    } else {
        t = (projected - base) / lengthSquared;
        if (t <= 0.0f) {
            out->x = segmentStart->x;
            out->y = segmentStart->y;
            out->z = segmentStart->z;
        } else if (1.0f <= t) {
            out->x = segmentEnd->x;
            out->y = segmentEnd->y;
            out->z = segmentEnd->z;
        } else {
            out->x = delta[0] * t;
            out->y = delta[1] * t;
            out->z = delta[2] * t;
            out->x = segmentStart->x + out->x;
            out->y = segmentStart->y + out->y;
            out->z = segmentStart->z + out->z;
        }
    }
}
