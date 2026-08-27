#include "podcruise/types.h"
s32 func_8002FE94(s32 arg0) {
    s32 bit;
    s32 i;
    s32 m;
    bit = 0x40000000;
    m = bit & arg0;
    for (i = 31; i != 0; i--) {
        bit >>= 1;
        if (m != 0) break;
        m = bit & arg0;
    }
    bit <<= 1;
    if (bit < arg0) bit <<= 1;
    if (bit < 0x10) bit = 0x10;
    return bit;
}
