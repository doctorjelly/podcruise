/* Implements the specification in specs/func_80004704.md (batch viewer-relative vertex setup). */
#include "podcruise/types.h"

extern void func_800059A8(f32 (*)[4]);
extern void func_800160BC(f32 (*)[4], f32 (*)[4]);
extern void func_80016BF4(f32 *, f32 *, f32 (*)[4]);
extern void func_80016CAC(f32 *, f32 *, f32 (*)[4]);

void func_80004704(s32 flags, s32 count, f32 (*out)[7], f32 (*in)[7]) {
    f32 m0[4][4];
    f32 m1[4][4];
    s32 i;

    if (flags & 1) {
        func_800059A8(m0);
        if (flags & 2) {
            func_800160BC(m1, m0);
            for (i = 0; i < count; i++) {
                func_80016CAC(out[i], in[i], m1);
                func_80016BF4(&out[i][3], &in[i][3], m1);
            }
        } else {
            for (i = 0; i < count; i++) {
                out[i][0] = in[i][0] - m0[3][0];
                out[i][1] = in[i][1] - m0[3][1];
                out[i][2] = in[i][2] - m0[3][2];
                out[i][3] = in[i][3];
                out[i][4] = in[i][4];
                out[i][5] = in[i][5];
            }
        }
    } else {
        for (i = 0; i < count; i++) {
            out[i][0] = in[i][0];
            out[i][1] = in[i][1];
            out[i][2] = in[i][2];
            out[i][3] = in[i][3];
            out[i][4] = in[i][4];
            out[i][5] = in[i][5];
        }
    }
}
