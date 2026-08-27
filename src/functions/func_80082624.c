/* Implements specification $S/specs/func_80082624.md */
#include "podcruise/vector_math.h"

/* Stand-in for the neighbouring function's constants, which in the original
   object precede this function's own literal pool and are what place it at its
   canonical, non-16-aligned address. */
static const f32 poolPadding[2] = {0.95f, -0.95f};

extern f32 func_80014D4C(f32 value);
extern f32 func_80014F54(f32 first, f32 second);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80017580(f32 *matrix, f32 x, f32 y, f32 z);

void func_80082624(f32 *from, f32 *to, f32 *matrix, f32 *out, f32 roll) {
    f32 pitch;
    PcVec3f delta;
    f32 length;
    PcVec3f direction;
    f32 yaw;

    (void)direction; /* declared by the original; reserves frame space only */
    (void)yaw;
    out[0] = from[0];
    out[1] = from[1];
    out[2] = from[2];
    delta.x = to[0] - from[0];
    delta.y = to[1] - from[1];
    delta.z = to[2] - from[2];
    length = func_800153C0(&delta);
    if (1e-4f < length) {
        func_800155C0(&delta, 1.0f / length, &delta);
        pitch = func_80014D4C(delta.z);
        out[4] = pitch;
        out[5] = roll;
        if ((f64)delta.y < 0.0001 && -0.0001 < (f64)delta.y) {
            if ((f64)delta.x < -0.0001) {
                out[3] = 90.0f;
            } else if (0.0001 < (f64)delta.x) {
                out[3] = -90.0f;
            } else {
                out[3] = 0.0f;
            }
        } else {
            out[3] = func_80014F54(-delta.x, delta.y);
        }
        func_800174B8(matrix, out);
    } else {
        func_80017580(matrix, from[0], from[1], from[2]);
    }
}
