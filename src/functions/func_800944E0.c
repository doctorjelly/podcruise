/* Independently written from specs/functions/recovered/func_800944E0.md. */

#include "podcruise/types.h"

#define PI_DRAM_ADDR_REG (*(volatile u32 *)0xA4600000)
#define PI_CART_ADDR_REG (*(volatile u32 *)0xA4600004)
#define PI_RD_LEN_REG (*(volatile u32 *)0xA4600008)
#define PI_WR_LEN_REG (*(volatile u32 *)0xA460000C)
#define PI_STATUS_REG (*(volatile u32 *)0xA4600010)

extern u32 D_80000308;

extern u32 func_80088360(u32 address);

s32 func_800944E0(s32 direction, u32 cartridge_offset, u32 dram_address, u32 size) {
    register u32 stat;

    stat = PI_STATUS_REG;
    while (stat & 3) {
        stat = PI_STATUS_REG;
    }

    PI_DRAM_ADDR_REG = func_80088360(dram_address);
    PI_CART_ADDR_REG = (D_80000308 | cartridge_offset) & 0x1FFFFFFF;
    switch (direction) {
    case 0:
        PI_WR_LEN_REG = size - 1;
        break;
    case 1:
        PI_RD_LEN_REG = size - 1;
        break;
    default:
        return -1;
    }
    return 0;
}
