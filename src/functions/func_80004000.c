/* Specification: scratchpad specs/func_80004000.md (camera/view parameter setup) */
#include "podcruise/types.h"

extern f32 D_800A8138;
extern f32 D_800AE8B0;
extern s32 D_800AE8D8;
extern f32 D_800AE8DC;
extern f32 D_800AE8E0;
extern f32 D_800AE908[3];
extern s16 D_800AE934;
extern void (*D_800AE93C)();
extern void (*D_800AE940)();
extern f32 D_800AE948[3];
extern f32 D_800AE954;
extern f32 D_800AE958;
extern f32 D_800AE960[3];
extern f32 D_800AE96C;
extern f32 D_800AE970;
extern s32 D_800AEC78;
extern s32 D_800AEC7C;

extern void func_80003348();
extern void func_80002FFC();
extern void func_8000550C(void);

void func_80004000(f32 *arg0, f32 arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 dot;

    D_800AE8E0 = arg1;
    D_800AE8DC = arg1 * arg1;
    D_800AE908[0] = arg0[0];
    D_800AE908[1] = arg0[1];
    D_800AE908[2] = arg0[2];
    D_800AE948[0] = arg2[0];
    D_800AE948[1] = arg2[1];
    D_800AE948[2] = arg2[2];
    D_800AE960[0] = arg2[0];
    D_800AE960[1] = arg2[1];
    D_800AE960[2] = arg2[2];
    dot = (arg0[0] * arg2[0] + arg0[1] * arg2[1]) + arg0[2] * arg2[2];
    D_800AE954 = dot + arg3;
    D_800AE958 = dot + arg4;
    D_800AE96C = D_800AE954;
    D_800AE970 = D_800AE958;
    D_800AE8D8 = 0;
    D_800AE8B0 = D_800AE8DC * D_800A8138;
    D_800AE934 = 3;
    D_800AE93C = func_80003348;
    D_800AE940 = func_80002FFC;
    D_800AEC78 = 0;
    D_800AEC7C = 0;
    func_8000550C();
}
