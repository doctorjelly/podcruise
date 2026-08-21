/* Independently written from scratchpad spec specs/func_80093A90.md. */

#include "podcruise/types.h"

s32 func_80093A90(u16 value) {
    s32 remainder;
    u32 mask;
    s32 index;
    u16 result;
    u32 data;

    data = value;

    remainder = 0;
    for (mask = 0x400; mask != 0; mask >>= 1) {
        remainder <<= 1;
        if (data & mask) {
            if (remainder & 0x20) {
                remainder ^= 0x14;
            } else {
                remainder += 1;
            }
        } else {
            if (remainder & 0x20) {
                remainder ^= 0x15;
            }
        }
    }

    for (index = 0; index < 5; index++) {
        remainder <<= 1;
        if (remainder & 0x20) {
            remainder ^= 0x15;
        }
    }

    result = remainder & 0x1F;
    return result;
}
