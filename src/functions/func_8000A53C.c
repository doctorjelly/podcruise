/* Specification: scratchpad specs/func_8000A53C.md */
#include "podcruise/types.h"

extern s32 D_8009B770;
extern s32 D_8009B778;
extern u8 D_8009B77C[4];
extern u8 D_8009B780[4];
extern f32 D_8009B784;
extern f32 D_8009B788;
extern u8 D_800D2190[];

extern void func_80009FA0(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern void func_8000A330(s32 arg0);
extern void func_8003D370(void);
extern void func_8003D444(void);
extern void func_8003D49C(f32 *arg0, f32 *arg1);
extern void func_8003D4F4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                          s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11,
                          s32 arg12);

void func_8000A53C(s32 arg0) {
    s32 pad[2];
    f32 x;
    f32 y;
    s32 mode;
    s32 i;

    (void) pad;

    func_8003D444();
    func_8003D49C(&x, &y);

    if (arg0 == 2) {
        mode = 1;
    } else if (arg0 == 1) {
        mode = 2;
    } else if (arg0 == 3) {
        mode = 0x800;
    }

    if (arg0 == 3) {
        if (D_8009B780[3] > 0) {
            if (D_8009B780[3] < 255) {
                func_8003D4F4(0, 0, 0, 20.0f * x, 240.0f * y, 0.0f, 0, 0, 2,
                              D_8009B780[0], D_8009B780[1], D_8009B780[2], D_8009B780[3]);
            } else {
                func_8003D4F4(0, 0, 0, 20.0f * x, 240.0f * y, 0.0f, 0, 0, 0,
                              D_8009B780[0], D_8009B780[1], D_8009B780[2], 255);
            }
        }
    }

    for (i = 0; i < D_8009B770; i++) {
        func_80009FA0(&D_800D2190[i * 0x20], mode, x, y);
    }

    func_8000A330(arg0);

    if (arg0 == 3) {
        if (D_8009B77C[3] > 0) {
            if (D_8009B77C[3] < 255) {
                func_8003D4F4(0, 0, 0, 20.0f * x, 240.0f * y, 0.0f, 0, 0, 2,
                              D_8009B77C[0], D_8009B77C[1], D_8009B77C[2], D_8009B77C[3]);
            } else {
                func_8003D4F4(0, 0, 0, 20.0f * x, 240.0f * y, 0.0f, 0, 0, 0,
                              D_8009B77C[0], D_8009B77C[1], D_8009B77C[2], 255);
            }
        }
    }

    if (arg0 == 3) {
        if (D_8009B778 != 0) {
            func_8003D4F4(0, 0, 0, 20.0f * x, D_8009B784 * y, 0.0f, 0, 0, 2, 0, 0, 0, 255);
            func_8003D4F4(0, 0, (s16) (s32) (D_8009B788 * y), 20.0f * x,
                          (240.0f - D_8009B788) * y, 0.0f, 0, 0, 2, 0, 0, 0, 255);
        }
    }

    func_8003D370();
}
