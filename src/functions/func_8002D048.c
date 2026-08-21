/* Independently written from scratchpad spec specs/func_8002D048.md. */

#include "podcruise/types.h"

extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 *arg6);
extern void func_8003EFDC(s16 arg0, s16 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5,
                          u8 arg6, s32 arg7);
extern void func_80022798(f32 arg0, f32 arg1, f32 arg2, u8 *arg3);

extern u8 D_800A9898[];
extern u8 D_800A98AC[];
extern u8 D_800A98BC[];
extern u8 D_800A98D0[];
extern f32 D_800A9EE8;
extern f32 D_800A9EEC;
extern u8 D_80113680[];
extern f32 D_80113744[][2];
extern f32 D_8011380C[][2];

void func_8002D048(s8 *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, u8 arg5) {
    s32 alpha;
    s16 x;

    (void)arg4;
    x = (s16)arg1;
    switch (arg5) {
    case 0:
        alpha = (u8)(u32)arg3;
        func_8003EC40(x, (s16)arg2, 0x32, 0xFF, 0xFF, alpha, D_800A9898);
        break;
    case 3:
        alpha = (u8)(u32)arg3;
        func_8003EC40(x, (s16)arg2, 0x32, 0xFF, 0xFF, alpha, D_800A98AC);
        break;
    default:
        alpha = (u8)(u32)arg3;
        break;
    }

    arg2 += 7;
    if (arg5 == 3) {
        if (D_8011380C[arg0[0x5D]][arg0[0x6E]] < D_800A9EEC) {
            func_8003EFDC(x, (s16)arg2, D_8011380C[arg0[0x5D]][arg0[0x6E]], 0x32, 0xFF, 0xFF, alpha, 1);
            func_80022798((f32)(arg1 + 0x13), (f32)arg2, arg3,
                          &D_80113680[0x2EA + arg0[0x5D] * 6 + arg0[0x6E] * 3]);
        } else {
            func_8003EC40(x, (s16)arg2, 0x32, 0xFF, 0xFF, alpha, D_800A98D0);
        }
    } else {
        if (D_80113744[arg0[0x5D]][arg0[0x6E]] < D_800A9EE8) {
            func_8003EFDC(x, (s16)arg2, D_80113744[arg0[0x5D]][arg0[0x6E]], 0x32, 0xFF, 0xFF, alpha, 1);
            func_80022798((f32)(arg1 + 0x13), (f32)arg2, arg3,
                          &D_80113680[0x254 + arg0[0x5D] * 6 + arg0[0x6E] * 3]);
        } else {
            func_8003EC40(x, (s16)arg2, 0x32, 0xFF, 0xFF, alpha, D_800A98BC);
        }
    }
}
