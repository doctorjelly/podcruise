/* Independently written from scratchpad spec specs/func_80001D34.md. */

#include "podcruise/types.h"

extern f64 D_800A8128;
extern f64 D_800A8130;

f32 func_80001D34(f32 *plane, f32 *ray, f32 *hit) {
    f32 originDot;
    f32 directionDot;
    f32 distance;

    originDot = ray[0] * plane[0] + ray[1] * plane[1] + ray[2] * plane[2];
    directionDot = ray[3] * plane[0] + ray[4] * plane[1] + ray[5] * plane[2];

    if (D_800A8128 <= directionDot && directionDot <= D_800A8130) {
        return -1.0f;
    }

    distance = (plane[3] - originDot) / directionDot;
    if (distance < 0.0f) {
        return -1.0f;
    }
    if (ray[6] < distance) {
        return -1.0f;
    }

    hit[0] = ray[3] * distance;
    hit[1] = ray[4] * distance;
    hit[2] = ray[5] * distance;
    hit[0] += ray[0];
    hit[1] += ray[1];
    hit[2] += ray[2];
    return distance;
}
