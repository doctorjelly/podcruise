/* Independently written from scratchpad spec specs/func_80039184.md. */

#include "podcruise/types.h"

extern void func_800390C0(void);

extern u32 D_80114070[256];

u32 func_80039178(u8 *data, s32 length) {
    u8 *cursor;
    u32 accumulator;

    if (D_80114070[1] == 0) {
        func_800390C0();
    }
    accumulator = -1;
    cursor = data;
    while (length > 0) {
        length--;
        accumulator = D_80114070[*cursor ^ (accumulator >> 24)] ^ (accumulator << 8);
        cursor++;
    }
    return ~accumulator;
}
