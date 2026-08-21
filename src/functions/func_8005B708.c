/* Implements the specification in specs/func_8005B708.md */
#include "podcruise/types.h"

extern s32 func_8003F800(s32, s32);
extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_80053300(s32);
extern void func_8005C36C(s32);

void func_8005B708(void) {
    s32 pad[4];
    s32 handle;

    handle = func_8003F800(0x4A646765, 0);
    func_80008B14(0x8F, 6, 0.25f, 0.2f, 1);
    func_80053300(handle);
    func_8005C36C(handle);
    (void)pad;
}
