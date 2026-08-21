/* Independently written from scratchpad spec specs/func_80033E08.md. */

#include "podcruise/types.h"

typedef struct Slot80033E08 {
    u8 data[0x40];
} Slot80033E08;

extern s32 D_800A3CC4;
extern Slot80033E08 D_800E2C50[];

Slot80033E08 *func_80033E08(void) {
    D_800A3CC4 = D_800A3CC4 + 1;
    if (D_800A3CC4 >= 0xC00) {
        D_800A3CC4 = 0;
    }
    return &D_800E2C50[D_800A3CC4];
}
