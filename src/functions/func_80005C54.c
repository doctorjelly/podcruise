/* spec */
#include "podcruise/types.h"

extern f32 D_800AF970[30];

extern void func_80005B80(void);

void func_80005C54(void) {
    s32 i;

    D_800AF970[0] = 0.0f;
    D_800AF970[1] = 0.0f;
    for (i = 2; i < 30; i++) {
        D_800AF970[i] = 0.0f;
    }
    func_80005B80();
}
