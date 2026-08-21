/* Independently written from specs/functions/func_8000FF54.md. */

#include "podcruise/types.h"

extern u8 D_800D5C38[];
extern f32 D_800D5C60[][3];
extern s32 D_800D60A0[];

void func_8000FF54(s32 index, f32 *source) {
    if (index < 40) {
        D_800D5C60[index][0] = source[0];
        D_800D5C60[index][1] = source[1];
        D_800D5C60[index][2] = source[2];
        D_800D60A0[index] = -1000;
        D_800D5C38[index] = 1;
    }
}
