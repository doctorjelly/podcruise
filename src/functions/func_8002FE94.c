/* Independently written from specs/functions/recovered/func_8002FE94.md. */
#include "podcruise/types.h"

/* The incoming counter value is overwritten before use; see the arity note in
 * the specification. */
s32 func_8002FE94(s32 value, s32 counter) {
    s32 power;
    s32 hit;

    power = 0x40000000;
    for (counter = 31; counter != 0;) {
        hit = power & value;
        power >>= 1;
        counter--;
        if (hit != 0) break;
    }
    power <<= 1;
    if (power < value) power <<= 1;
    if (power < 0x10) power = 0x10;
    return power;
}
