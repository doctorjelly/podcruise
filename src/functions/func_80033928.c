/* Independently written from scratchpad spec specs/func_80033928.md. */

#include "podcruise/types.h"

extern void func_80006EB4(s32, f32);

void func_80033928(s32 *list, f32 amount) {
    s32 *entry;

    if (list != 0) {
        entry = list;
        while (*entry != 0) {
            func_80006EB4(*entry, amount);
            entry++;
        }
    }
}
