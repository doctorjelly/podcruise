/* Specification: scratchpad specs/func_80004FB0.md */
#include "podcruise/types.h"

typedef void (*Callback)(void);

extern f32 D_800AE8B0;
extern f32 D_800AE8B8[3];
extern f32 D_800AE8C8[3];
extern s32 D_800AE8D8;
extern f32 D_800AE8E8[7];
extern s16 D_800AE934;
extern Callback D_800AE93C;
extern Callback D_800AE940;
extern s32 D_800AEC78;
extern s32 D_800AEC7C;
extern s32 D_8009A280;
extern void func_800026BC(void);
extern void func_800020D8(void);
extern void func_8000550C(void);
extern void func_80004DFC(s32, f32 *, s32);

f32 func_80004FB0(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    if (arg0 == 0) {
        D_800AE8B0 = -1.0f;
    } else {
        D_800AE8B0 = arg1[6] + 200.0f;
        D_800AE8D8 = 0;
        D_800AE8E8[6] = arg1[6];
        D_800AE8E8[3] = arg1[3];
        D_800AE8E8[4] = arg1[4];
        D_800AE8E8[5] = arg1[5];
        D_800AE8E8[0] = arg1[0];
        D_800AE8E8[1] = arg1[1];
        D_800AE8E8[2] = arg1[2];
        D_800AE934 = 1;
        D_800AE93C = func_800026BC;
        D_800AE940 = func_800020D8;
        D_800AEC78 = 0;
        D_800AEC7C = 0;
        func_8000550C();
        func_80004DFC(arg0, arg1, 0);
        if (arg1[6] < D_800AE8B0) {
            D_800AE8B0 = -1.0f;
        } else {
            arg2[0] = D_800AE8B8[0];
            arg2[1] = D_800AE8B8[1];
            arg2[2] = D_800AE8B8[2];
            arg3[0] = D_800AE8C8[0];
            arg3[1] = D_800AE8C8[1];
            arg3[2] = D_800AE8C8[2];
        }
    }
    if (D_800AE8D8 != 0) {
        D_8009A280 = D_800AE8D8;
    }
    return D_800AE8B0;
}
