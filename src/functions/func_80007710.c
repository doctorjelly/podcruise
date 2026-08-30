/* Independently written from specs/functions/recovered/func_80007710.md. */

#include "podcruise/types.h"

extern u8 D_800AFAC0[];
extern u32 func_80007594(u32 address, u32 size, s32 unused);

u32 func_80007710(void **destination) {
    *destination = D_800AFAC0;
    return (u32)(unsigned long)&func_80007594;
}
