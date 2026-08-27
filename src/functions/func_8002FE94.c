/* Independently written from the specification for func_8002FE94. */
#include "podcruise/types.h"

/* Rounds a signed value up to a power of two, with a floor of sixteen. */
s32 func_8002FE94(s32 arg0) {
    s32 bit;
    s32 i;
    s32 m;

    bit = 0x40000000;
    i = 31;
    m = bit & arg0;
    while (i != 0) {
        bit >>= 1;
        i--;
        if (m != 0) break;
        m = bit & arg0;
    }
    bit <<= 1;
    if (bit < arg0) bit <<= 1;
    if (bit < 0x10) bit = 0x10;
    return bit;
}
