/* Recovered per specs/func_800865E8.md (worker specification). */
#include "podcruise/types.h"

extern void func_80005B1C(s32, s32);
extern void func_8000FE1C(void);
extern void func_8000FE78(void);
extern void func_8000FEF0(void);
extern void func_80010040(void);
extern void func_80011838(void);
extern void func_8003E1D0(void);
extern void func_800862D8(s32, s32, s32, s32, s32);
extern void func_8008635C(s32, s32);
extern void func_800863C8(s32);

extern u32 *D_800A68B4;
extern u32 D_800A6908;
extern u32 D_800D697C;
extern u8 D_800D9DB0;
extern u8 D_800D9DB1;
extern u32 D_80120DF0;
extern u32 *D_801488C0;

void func_800865E8(void) {
    s32 i;

    func_80011838();
    func_8000FE1C();
    func_8000FE78();
    func_8000FEF0();
    func_80010040();

    for (i = 0; i < 4; i++) {
        func_800863C8(i);
    }

    func_8008635C(0, 1);
    func_800862D8(0, 0, 0, 0x140, 0xF0);
    func_800862D8(1, 8, 8, 0x138, 0xE8);

    D_800A68B4 = &D_80120DF0;

    if (D_800D697C & 0x400) {
        func_8008635C(1, 0);
        func_800862D8(1, 8, 8, 0x138, 0xE8);
    }

    *D_800A68B4 &= ~1;

    func_8003E1D0();

    D_801488C0 = &D_800A6908;
    D_800D9DB0 = 0;
    D_800D9DB1 = 0;

    func_80005B1C(3, 2);
    func_80005B1C(5, 0);
}
