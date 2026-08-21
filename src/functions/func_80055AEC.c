/* Recovered from specification: specs/func_80055AEC.md (worker scratchpad) */
#include "podcruise/types.h"
extern u16 *func_8000ABD4(s32);
void func_80055AEC(s32 arg0, f32 value) {
    u16 *entry; s32 index; s32 lo = -242; s32 hi = 492; s32 word;
    if (value < 0.0f) { value = 0.0f; } else if (value > 1.0f) { value = 1.0f; }
    entry = func_8000ABD4((s16)arg0);
    if (entry != 0) {
        for (index = 0; index < 256; index++) {
            word = *entry;
            if (((word & 0xF800) >> 8) <= 0 ||
                ((word & ~1) - ((word & 0x3E) << 2)) >= (s32)((f32)lo + value * (f32)hi)) {
                *entry = word & ~1;
            } else {
                *entry = word | 1;
            }
            entry++;
        }
    }
}
