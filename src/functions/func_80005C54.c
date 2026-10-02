/* Recovered per specs/func_80005C54.md */
#include "podcruise/types.h"

f32 D_800AF970[30];

extern void func_80005B80(void);

void func_80005C54(void) {
    s32 i;

    i = 0;
    do {
        D_800AF970[i++] = 0.0f;
    } while (i < 30);
    func_80005B80();
}
