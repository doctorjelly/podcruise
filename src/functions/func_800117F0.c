/* Independently written from specs/functions/runtime_wrappers.md. */

#include "podcruise/runtime_wrappers.h"

extern u8 D_8009B870;
extern void func_800116E8(void);

void func_800117F0(void) {
    D_8009B870 = 0;
    func_800116E8();
}
