/* Independently written from specs/functions/recovered/medium_control_tranche.md. */
#include "podcruise/types.h"

extern u32 D_80000318;
extern u8 *D_80114530[];
extern u8 *D_8011453C;

extern void func_80039A30(void);
extern void func_80007A44(void);
extern void *func_8003140C(void *start, s32 mode, u32 length);

#define LARGE_MEMORY (D_80000318 >= 0x800000)
#define LINE_PIXELS (LARGE_MEMORY ? 0x280 : 0x140)
#define PIXEL_BYTES (LARGE_MEMORY ? 4 : 2)
#define GUARD_PIXELS (LARGE_MEMORY ? LINE_PIXELS * PIXEL_BYTES : 0)

void func_80039B70(void) {
    u8 **buffer;

    func_80039A30();
    func_80007A44();
    buffer = D_80114530;
    do {
        func_8003140C(*buffer - GUARD_PIXELS * 2, 0, LINE_PIXELS * 0xF0 * PIXEL_BYTES + GUARD_PIXELS * 2);
        buffer++;
    } while (buffer != &D_8011453C);
}
