/* Independently written from scratchpad spec specs/func_80030EA0.md. */

#include "podcruise/types.h"

extern void func_80008F58(f32 first, f32 second);
extern void func_80030B90(void);
extern void func_80030C08(void);
extern void func_8002FDF8(void);
extern void func_80030298(s32 arg0, s32 arg1);
extern void func_80030C98(void);
extern void func_80086CC8(s32 first, s32 second, s32 third);
extern void func_80038DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern s32 D_800A284C;
extern s32 D_800A6758;
extern s32 D_800D6960[];

void func_80030EA0(void) {
    func_80008F58(50.0f, 300.0f);
    func_80030B90();
    func_80030C08();
    func_8002FDF8();
    if (D_800A284C == -1) {
        func_80030298(0x634D616E, 6);
        func_80030298(0x4A646765, 1);
        func_80030298(0x48616E67, 1);
    } else {
        func_80030C98();
    }
    D_800D6960[7] &= ~0x800;
    func_80086CC8(0, 0, 0);
    func_80038DF8(0x3E4, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    D_800D6960[7] |= 1;
    D_800A6758 = 1;
}
