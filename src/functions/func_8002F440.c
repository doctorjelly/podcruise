/* Specification: specs/func_8002F440.md (worker-authored) */
#include "podcruise/types.h"

extern u32 D_800AE8B0[];
extern u32 D_80149C60[];

void func_8002F440(void) {
    u32 *p = D_800AE8B0;

    while (p < D_80149C60) {
        *p = 0xDDEEDDEE;
        p++;
    }
}
