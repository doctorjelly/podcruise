/* Independently written from $S/specs/func_80090F70.md. */

#include "podcruise/types.h"

extern s32 func_80090B24(void *context, u16 *first, u16 *second);
extern s32 func_80091FD0(void *owner, s32 mode);
extern s32 func_80092050(s32 handleA, s32 handleB, u16 selector, void *context);
extern s32 func_800928F0(s32 handleA, s32 handleB, u16 selector, void *context, s32 flag);

s32 func_80090F70(u8 *owner, u8 *context) {
    u16 table[4];
    s32 result;
    u16 first;
    u16 second;
    s32 index;
    s32 other;

    if (owner[0x65] != 0) {
        result = func_80091FD0(owner, 0);
        if (result != 0) {
            return result;
        }
    }

    table[0] = 1;
    table[1] = 3;
    table[2] = 4;
    table[3] = 6;

    for (index = 1; index != 4; index++) {
        result = func_80092050(*(s32 *)(owner + 4), *(s32 *)(owner + 8), table[index], context);
        if (result != 0) {
            return result;
        }
        func_80090B24(context, &first, &second);
        if (first == *(u16 *)(context + 0x1C) && second == *(u16 *)(context + 0x1E)) {
            break;
        }
    }

    if (index == 4) {
        return 10;
    }

    for (other = 0; other != 4; other++) {
        if (other != index) {
            result = func_800928F0(*(s32 *)(owner + 4), *(s32 *)(owner + 8), table[other], context, 1);
            if (result != 0) {
                return result;
            }
        }
    }

    return 0;
}
