/* Implements specs/functions/recovered/func_80030B90.md. */
#include "podcruise/types.h"

extern u32 D_80000318;
extern u32 D_80114528;
extern u32 func_8002FAFC(void);
extern void func_8002FAC4(u32);

void func_80030B90(void) {
    u32 base;
    u32 memory_limit;
    s32 width;
    s32 product;

    base = func_8002FAFC();
    D_80114528 = base;
    D_80114528 = (D_80114528 + 0x3F) & ~0x3F;
    memory_limit = 0x800000;
    if (D_80000318 >= memory_limit) {
        width = 640;
    } else {
        width = 320;
        if (D_80000318 == memory_limit) {
        }
    }
    product = width * 15;
    func_8002FAC4(product * 32 + base + 0x40);
}
