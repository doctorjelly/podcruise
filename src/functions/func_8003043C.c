/* Independently written from scratchpad spec specs/func_8003043C.md. */

#include "podcruise/types.h"

extern void func_80011D60(void *source, void *destination, s32 length);
extern u8 D_102ABB0[];
extern s32 D_800D9E00[1700];
extern s32 D_800DB890;

void func_8003043C(void) {
    s32 index;

    func_80011D60(D_102ABB0, &D_800DB890, 4);
    if (D_800DB890 > 1700) {
        while (1) {
        }
    }
    for (index = 0; index < 1700; index++) {
        D_800D9E00[index] = 0;
    }
}
