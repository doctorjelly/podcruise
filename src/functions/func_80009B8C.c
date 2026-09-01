/* Recovered per specs: func_80009B8C (see scratchpad specs/func_80009B8C.md). */
#include "podcruise/types.h"

extern s32 D_8009AEF0;
extern s16 D_8009AF08[];
extern f32 D_8009AF20;
extern f32 D_8009AF24;
extern f32 D_800A822C;

extern s32 func_8003F7B8(u32);
extern s32 func_80051FF4(void);

void func_80009B8C(u32 selection) {
    if ((func_8003F7B8(0x54657374) <= 0) || (func_80051FF4() != 0)) {
        D_8009AF24 = 0.0f;
        selection = selection % 12;
        D_8009AEF0 = D_8009AF08[selection];
        D_8009AF20 = D_800A822C;
    }
}
