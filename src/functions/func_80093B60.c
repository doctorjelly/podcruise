/* Independently written from scratchpad spec specs/func_80093B60.md. */

#include "podcruise/types.h"

u8 func_80093B60(u8 *data) {
    u32 remainder;
    u32 count;
    u32 mask;

    remainder = 0;

    for (count = 32; count > 0; count--) {
        for (mask = 0x80; mask != 0; mask >>= 1) {
            remainder <<= 1;
            if (*data & mask) {
                if (remainder & 0x100) {
                    remainder ^= 0x84;
                } else {
                    remainder++;
                }
            } else {
                if (remainder & 0x100) {
                    remainder ^= 0x85;
                }
            }
        }
        data++;
    }

    do {
        remainder <<= 1;
        if (remainder & 0x100) {
            remainder ^= 0x85;
        }
        count++;
    } while (count < 8);

    return remainder;
}
