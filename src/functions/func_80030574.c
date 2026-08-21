/* Independently written from scratchpad spec specs/func_80030574.md. */

#include "podcruise/types.h"
extern u32 D_800D9E00[1700];
void func_80030574(u32 limit) {
    s32 i;
    for (i = 0; i < 1700; i++) {
        if (limit < D_800D9E00[i]) {
            D_800D9E00[i] = 0;
        }
    }
}
