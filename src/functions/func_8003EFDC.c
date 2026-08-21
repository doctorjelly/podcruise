/* Independently written from the specification for func_8003EFDC. */

#include "podcruise/types.h"

extern u8 D_800AAB44[];
extern u8 D_800AAB4C[];

extern void func_8003F1C0(s16 arg0, s16 arg1, f32 arg2, u8 arg3, u8 arg4,
                          u8 arg5, u8 arg6, u8 *arg7);

void func_8003EFDC(s16 arg0, s16 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5,
                   u8 arg6, s32 arg7) {
    if (arg7 != 0) {
        func_8003F1C0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, D_800AAB44);
    } else {
        func_8003F1C0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, D_800AAB4C);
    }
}
