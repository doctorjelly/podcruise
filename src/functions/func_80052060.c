/* Recovered from specification $S/specs/func_80052060.md */
#include "podcruise/types.h"

extern s32 func_8003F800(u32, s32);
extern f32 func_8008035C(void *);
extern u8 *D_8011B1BC;

f32 func_80052060(void) {
    if (func_8003F800(0x54657374, 0) == 0) {
        return -1.0f;
    }
    if (D_8011B1BC == 0) {
        return -1.0f;
    }
    return func_8008035C(*(u8 **)(D_8011B1BC + 0x84) + 0xAC);
}
