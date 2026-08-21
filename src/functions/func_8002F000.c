/* Independently written from the specification for func_8002F000. */
#include "podcruise/types.h"

extern s32 D_800A26F4;
extern s32 D_800A26F8;
extern f32 D_800D7740;

void func_8002F000(void) {
    D_800A26F4 = 0;
    D_800A26F8 = 1;
    D_800D7740 = 0.0f;
}
