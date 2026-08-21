/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s32 D_8009B884;
extern void func_800116E8(void);

void func_800117A4(s32 value) {
    if (value >= 0x51) {
        D_8009B884 = 0x50;
    } else {
        D_8009B884 = value;
    }
    func_800116E8();
}
