/* Independently written from scratchpad spec specs/func_8008ADA0.md. */

#include "podcruise/types.h"

u32 func_8008ADA0(void) {
    return *(volatile u32 *)(unsigned long)0xA450000CU;
}
