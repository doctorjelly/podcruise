#include "podcruise/types.h"
extern s32 func_8002D9D0();
extern u8 D_80113E68[];
extern s16 D_80113E6C[];

s32 func_8002DA0C(slot, lane)
char slot;
unsigned char lane;
{
    s16 phase;
    s32 state;
    s32 index;

    index = lane;
    phase = (s16)((D_80113E6C[(s32)slot] >> (index * 2)) % 4);
    state = func_8002D9D0(slot, lane);
    if (state == 3 && phase == 0) {
        return phase == 0;
    }
    return slot < 3 && ((D_80113E68[(s32)slot] & (1 << (index + 1))) != 0) == 0;
}
