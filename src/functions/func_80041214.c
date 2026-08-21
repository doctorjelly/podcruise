/* Independently written from the specification notes for func_80041214. */

#include "podcruise/types.h"

extern void func_8004110C(u8 *record, s32 mode);

void func_80041214(u8 *record) {
    s32 mode = *(s32 *)(record + 0x80);

    if (mode == 2 || mode == 1) {
        func_8004110C(record, mode);
    } else {
        *(s32 *)(record + 0x7C) = mode;
    }
}
