/* Recovered from specification specs/func_8002F480.md (scratchpad). */
#include "podcruise/types.h"
extern u32 D_80000318;
extern u32 D_8014D7E0[];
void func_8002F480(void) {
    u32 *p;
    for (p = D_8014D7E0; (u32)(unsigned long)p < (0x80000000 | D_80000318); p++) {
        *p = 0xBBCCBBCC;
    }
}
