/* Independently written from the specification for func_800883E0. */

#include "podcruise/types.h"

u32 func_800883E0(void) {
    return *(volatile u32 *)0xA4500004;
}
