/* Independently written from scratchpad spec specs/func_80022798.md. */

#include "podcruise/types.h"

extern u8 D_800A8EB8[];

extern s32 func_8008A6B4(void *buffer, const void *format, ...);
extern void func_8003EC40(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u8 *arg6);

void func_80022798(f32 arg0, f32 arg1, f32 arg2, u8 *arg3) {
    u8 buf[3];
    u8 obj[16];
    s32 i;

    for (i = 0; i < 3; i++) {
        buf[i] = arg3[i];
    }
    func_8008A6B4(obj, D_800A8EB8, buf[0], buf[1], buf[2]);
    func_8003EC40((s16)(s32)arg0, (s16)(s32)arg1, 0x32, 0xFF, 0xFF, (u32)arg2, obj);
}
