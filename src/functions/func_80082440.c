/* Recovered per specification scratchpad/specs/func_80082440.md */
#include "podcruise/types.h"

extern f32 D_800ADCD0;
extern f32 D_800ADCD4;

extern void func_800154D0(f32 *v);
extern void func_80015538(f32 *dst, f32 *a, f32 *b);

void func_80082440(f32 *m, f32 *origin, f32 *dir, f32 *up, f32 t) {
    f32 dot;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;

    m[12] = origin[0] + dir[0] * t;
    m[13] = origin[1] + dir[1] * t;
    m[14] = origin[2] + dir[2] * t;

    dot = dir[0] * up[0] + dir[1] * up[1] + dir[2] * up[2];

    if (dot >= D_800ADCD0 || dot <= D_800ADCD4) {
        m[4] = dir[0] * -1.0f;
        m[5] = dir[1] * -1.0f;
        m[6] = dir[2] * -1.0f;
        m[2] = 1.0f;
        m[1] = 0.0f;
        m[0] = 0.0f;

        func_80015538(&m[8], &m[0], &m[4]);
        func_80015538(&m[0], &m[4], &m[8]);
        func_800154D0(&m[0]);
        func_800154D0(&m[8]);
    } else {
        m[4] = dir[0] * -1.0f;
        m[5] = dir[1] * -1.0f;
        m[6] = dir[2] * -1.0f;
        m[0] = up[0];
        m[1] = up[1];
        m[2] = up[2];

        func_80015538(&m[8], &m[0], &m[4]);
        func_80015538(&m[0], &m[4], &m[8]);
        func_800154D0(&m[0]);
        func_800154D0(&m[8]);
    }
}
