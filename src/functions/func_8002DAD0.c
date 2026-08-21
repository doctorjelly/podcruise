/* Independently written from scratchpad spec specs/func_8002DAD0.md. */

#include "podcruise/types.h"

extern u8 D_8011368C[];
extern u8 D_80113E68[];

s32 func_8002DAD0(signed char *arg0, signed char arg1, u8 arg2) {
    u8 bits;

    bits = D_80113E68[arg1];
    if (arg0[0x6C] == 0) {
        bits = D_8011368C[arg1];
    }
    return (bits & (1 << arg2)) != 0;
}
