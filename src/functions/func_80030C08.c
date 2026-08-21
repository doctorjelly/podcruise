/* Implements specs/func_80030C08.md (heap window setup, recovered specification). */
#include "podcruise/types.h"

extern u32 D_80000318;
extern u32 D_800DB894;
extern u32 D_800DB898;
extern void func_8002FAC4(u32);
extern u32 func_8002FAFC(void);

void func_80030C08(void) {
    u32 base;

    base = func_8002FAFC();
    D_800DB894 = base;
    D_800DB894 = (D_800DB894 + 0x3F) & ~0x3F;
    D_800DB898 = (D_80000318 >= 0x800000 ? 0x10000 : 0x4000) + D_800DB894;
    func_8002FAC4((D_80000318 >= 0x800000 ? 0x10000 : 0x4000) + base + 0x40);
}
