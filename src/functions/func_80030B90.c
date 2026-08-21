/* Implements the specification in specs/func_80030B90.md */
#include "podcruise/types.h"

extern u32 D_80000318;
extern u32 D_80114528;
extern u32 func_8002FAFC(void);
extern void func_8002FAC4(u32);

void func_80030B90(void) {
    u32 base;
    s32 width;

    base = func_8002FAFC();
    D_80114528 = base;
    D_80114528 = (D_80114528 + 0x3F) & ~0x3F;
    if (D_80000318 >= 0x800000) {
        width = 640;
    } else {
        width = 320;
    }
    func_8002FAC4(width * 480 + base + 0x40);
}
