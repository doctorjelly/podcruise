/* Specification: $S/specs/func_800092EC.md */
#include "podcruise/types.h"

extern s32 func_8003F7B8(u32);
extern s32 func_80051FF4(void);
extern void func_80007D44(s32, s32);
extern s32 func_80009134(s32, s32);
extern s32 func_80008F6C(s32, s32, s32);
extern s32 func_800092B0(s32);
extern void func_80009278(s32);
extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_800091B0(s32, s32, s32, s32);

void func_800092EC(s32 arg0, s32 arg1, s32 arg2) {
    s32 handle;

    if (func_8003F7B8(0x54657374) > 0) {
        if (func_80051FF4() == 0) {
            return;
        }
    }
    func_80007D44(arg0, arg1);
    if (func_80009134(arg0, arg1) != 0) {
        return;
    }
    handle = func_80008F6C(arg0, arg1, arg2);
    if (handle == -1) {
        return;
    }
    if (func_800092B0(handle) != 0) {
        return;
    }
    func_80009278(handle);
    func_80008B14(handle, 7, 0.25f, 1.0f, 0);
    func_800091B0(arg0, arg1, handle, arg2);
}
