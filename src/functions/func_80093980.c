/* Independently written from scratchpad spec specs/func_80093980.md. */

#include "podcruise/types.h"

void func_80093980(u32 arg0) {
    *(volatile u32 *)(unsigned long)0xA4040010U = arg0;
}
