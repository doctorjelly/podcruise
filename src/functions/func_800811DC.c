/* Recovered from specification $S/specs/func_800811DC.md */
#include "podcruise/types.h"
extern u32 D_800A675C;
extern u32 D_800A6760;

extern u32 func_8008C550(void);

u64 func_800811DC(void) {
    u32 temp;
    u32 count;

    temp = func_8008C550();
    if (temp < D_800A6760) {
        D_800A675C++;
    }
    D_800A6760 = temp;
    count = D_800A675C;
    return (u64)count * 0x20 + (u64)temp;
}
