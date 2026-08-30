#include "podcruise/types.h"
extern u16 *func_8000ABD4(s16);
void func_80055AEC(s32 arg0, f32 arg1) {
    u16 *entry;
    s32 index;
    s32 level;
    if (arg1 < 0.0f) { arg1 = 0.0f; } else if (arg1 > 1.0f) { arg1 = 1.0f; }
    entry = func_8000ABD4((s16) arg0);
    if (entry != 0) {
        for (index = 0; index < 256; index++) {
            level = (*entry & 0xF800) >> 8;
            if ((level > 0) && ((level - ((*entry & 0x3E) << 2)) < (s32) ((f32) -242 + arg1 * (f32) 492))) {
                *entry = *entry | 1;
            } else {
                *entry = *entry & ~1;
            }
            entry++;
        }
    }
}
