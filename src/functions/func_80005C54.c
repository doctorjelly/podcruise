/* Recovered per specs/func_80005C54.md */
#include "podcruise/types.h"

extern f32 D_800AF970;
extern f32 D_800AF974;
extern f32 D_800AF978[28];

extern void func_80005B80(void);

void func_80005C54(void) {
    s32 i;

    D_800AF970 = 0.0f;
    D_800AF974 = 0.0f;
    for (i = 0; i < 28; i++) {
        D_800AF978[i] = 0.0f;
    }
    func_80005B80();
}
