/* Specification: scratchpad specs/func_80030FF8.md (display/framebuffer state reset) */
#include "podcruise/types.h"

extern u32 D_80000318;
extern u8 D_8014D7E0[];
extern u8 *D_800D9DB8;
extern u8 *D_80114538;
extern u8 *D_800D9DBC;
extern s16 D_800A2844;
extern s16 D_800D6996;
extern u8 *D_800D9DB4;
extern u8 *D_800D9DD8;
extern s32 D_800D9DDC;
extern s32 D_800D9DE0;
extern s32 D_800D9DE4[8];

extern void func_8008A360(u8 *);
extern void func_80088AD0(void);
extern void func_80030EA0(void);
extern void func_80030FA0(void);
extern void func_8002FB90(void);

void func_80030FF8(s32 arg0, s32 arg1) {
    u8 *base;
    s32 amount;
    s32 i;

    D_800D9DB8 = D_8014D7E0;
    amount = (D_80000318 >= 0x800000) ? ((D_80000318 >= 0x800000 ? 640 : 320) * (D_80000318 >= 0x800000 ? 4 : 2)) : 0;
    base = D_80114538;
    D_800D9DBC = base - ((amount & ~0x3F) * 2);
    if (D_800A2844 != 0) {
        D_800D6996 = 2;
    } else {
        D_800D9DB4 = base;
        func_8008A360(D_800D9DB4);
    }
    D_800A2844 = 1;
    func_80088AD0();
    D_800D9DDC = 0; D_800D9DD8 = D_800D9DB8;
    D_800D9DE0 = 0;
    for (i = 0; i < 8; i++) {
        D_800D9DE4[i] = 0;
    }
    func_80030EA0();
    func_80030FA0();
    func_8002FB90();
    (void)arg0;
    (void)arg1;
}
