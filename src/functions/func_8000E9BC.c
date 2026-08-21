/* Independently written from specs/functions/func_8000E9BC.md. */

#include "podcruise/types.h"

void func_8000E9BC(u8 **owner, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f) {
    u8 *slot;

    if (owner == 0) {
        return;
    }
    slot = owner[3];
    if (slot == 0) {
        return;
    }
    if (a >= 0) {
        slot[0x20] = a;
    }
    if (b >= 0) {
        slot[0x21] = b;
    }
    if (c >= 0) {
        slot[0x22] = c;
    }
    if (d >= 0) {
        slot[0x23] = d;
    }
    if (e >= 0) {
        slot[0x24] = e;
    }
    if (f >= 0) {
        slot[0x25] = f;
    }
}
