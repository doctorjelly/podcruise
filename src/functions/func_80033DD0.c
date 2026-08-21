/* Independently written from scratchpad spec specs/func_80033DD0.md. */

#include "podcruise/types.h"

typedef struct Slot80033DD0 {
    u8 data[0x20];
} Slot80033DD0;

extern s32 D_800A3CC0;
extern Slot80033DD0 D_800E0C50[];

Slot80033DD0 *func_80033DD0(void) {
    D_800A3CC0 = D_800A3CC0 + 1;
    if (D_800A3CC0 >= 0x100) {
        D_800A3CC0 = 0;
    }
    return &D_800E0C50[D_800A3CC0];
}
