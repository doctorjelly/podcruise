/* Independently written from scratchpad spec specs/func_8002DA0C.md. */
#include "podcruise/types.h"

extern s32 func_8002D9D0(char slot, unsigned char lane);
extern u8 D_80113E68[];
extern s16 D_80113E6C[];

s32 func_8002DA0C(slot, lane)
char slot;
unsigned char lane;
{
    s16 phase;
    s32 state;

    phase = (s16)((D_80113E6C[(s32)slot] >> (lane * 2)) % 4);
    state = func_8002D9D0(slot, lane);
    state = (state == 3 && phase == 0) ||
            (slot < 3 && ((D_80113E68[(s32)slot] & (1 << (lane + 1))) != 0) == 0);
    return state;
}
