/* Implements the specification in specs/func_800038E8.md (viewer-relative position setup). */
#include "podcruise/types.h"

extern s16 D_800AE934;
extern f32 D_800AE954;
extern f32 D_800AE958;
extern f32 D_800AE96C;
extern f32 D_800AE970;

extern void func_800059A8(f32 (*)[4]);
extern void func_800160BC(f32 (*)[4], f32 (*)[4]);
extern void func_80016BF4(f32 *, f32 *, f32 (*)[4]);
extern void func_80016CAC(f32 *, f32 *, f32 (*)[4]);

void func_800038E8(s32 flags, f32 *out, f32 *in, f32 *vec, f32 *ref) {
    f32 m0[4][4];
    f32 m1[4][4];

    if (flags & 1) {
        func_800059A8(m0);
        if (flags & 2) {
            func_800160BC(m1, m0);
            func_80016CAC(out, in, m1);
            if (D_800AE934 == 3) {
                func_80016BF4(vec, ref, m1);
                D_800AE954 = vec[0] * m1[3][0] + vec[1] * m1[3][1] + vec[2] * m1[3][2] + D_800AE96C;
                D_800AE958 = vec[0] * m1[3][0] + vec[1] * m1[3][1] + vec[2] * m1[3][2] + D_800AE970;
            }
        } else {
            out[0] = in[0] - m0[3][0];
            out[1] = in[1] - m0[3][1];
            out[2] = in[2] - m0[3][2];
            if (D_800AE934 == 3) {
                vec[0] = ref[0];
                vec[1] = ref[1];
                vec[2] = ref[2];
                D_800AE954 = D_800AE96C - (vec[0] * m0[3][0] + vec[1] * m0[3][1] + vec[2] * m0[3][2]);
                D_800AE958 = D_800AE970 - (vec[0] * m0[3][0] + vec[1] * m0[3][1] + vec[2] * m0[3][2]);
            }
        }
    } else {
        out[0] = in[0];
        out[1] = in[1];
        out[2] = in[2];
        if (D_800AE934 == 3) {
            vec[0] = ref[0];
            vec[1] = ref[1];
            vec[2] = ref[2];
            D_800AE954 = D_800AE96C;
            D_800AE958 = D_800AE970;
        }
    }
}
