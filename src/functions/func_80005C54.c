/* Recovered per specs/func_80005C54.md */
#include "podcruise/types.h"

extern f32 D_800AF970[30];

extern void func_80005B80(void);

void func_80005C54(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        D_800AF970[i] = 0.0f;
    }
    func_80005B80();
}
