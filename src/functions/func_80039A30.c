/* Independently written from scratchpad spec specs/func_80039A30.md. */

#include "podcruise/types.h"

extern u32 D_80000318;
extern u32 D_80114530[3];

#define EXPANDED (D_80000318 >= 0x800000U)
#define SCREEN_WIDTH (EXPANDED ? 640U : 320U)
#define SCREEN_HEIGHT 240U
#define PIXEL_BYTES (EXPANDED ? 4U : 2U)
#define GUARD_ROW (EXPANDED ? SCREEN_WIDTH * PIXEL_BYTES : 0U)

void func_80039A30(void) {
    s32 index;

    for (index = 0; index < 3; index++) {
        D_80114530[index] = (D_80000318 | 0x80000000U) -
            (SCREEN_WIDTH * SCREEN_HEIGHT * PIXEL_BYTES + 2U * GUARD_ROW) *
            (u32)(index + 1);
        D_80114530[index] += 2U * GUARD_ROW;
    }
}
