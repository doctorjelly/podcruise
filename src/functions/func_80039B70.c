/* Independently written from scratchpad spec specs/func_80039B70.md. */

#include "podcruise/types.h"

extern u32 D_80000318;
extern u8 *D_80114530[3];

extern void func_80039A30(void);
extern void func_80007A44(void);
extern void *func_8003140C(void *start, s32 mode, u32 length);

#define EXPANDED (D_80000318 >= 0x800000U)
#define SCREEN_WIDTH (EXPANDED ? 640U : 320U)
#define PIXEL_BYTES (EXPANDED ? 4U : 2U)
#define GUARD_ROW (EXPANDED ? SCREEN_WIDTH * PIXEL_BYTES : 0U)

void func_80039B70(void) {
    s32 index;
    u32 g1;
    u32 pb;
    u32 w;
    u32 g2;
    u32 off;

    func_80039A30();
    func_80007A44();
    for (index = 0; index < 3; index++) {
        g1 = GUARD_ROW;
        pb = PIXEL_BYTES;
        w = SCREEN_WIDTH;
        if (EXPANDED) {
            g2 = SCREEN_WIDTH * PIXEL_BYTES;
        } else {
            g2 = 0;
        }
        off = g1 + g1;
        func_8003140C(D_80114530[index] - off, 0, 2U * g2 + w * 240U * pb);
    }
}
