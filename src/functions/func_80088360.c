/* Recovered per specs: func_80088360 (see scratchpad specs/func_80088360.md). */
#include "podcruise/types.h"

extern u32 func_8008D450(u32);

u32 func_80088360(u32 address) {
    if ((address >= 0x80000000U) && (address < 0xA0000000U)) {
        return address & 0x1FFFFFFFU;
    }
    if ((address >= 0xA0000000U) && (address < 0xC0000000U)) {
        return address & 0x1FFFFFFFU;
    }
    return func_8008D450(address);
}
