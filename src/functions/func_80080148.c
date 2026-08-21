/* Independently written from scratchpad spec specs/func_80080148.md. */

#include "podcruise/types.h"

extern s32 D_8011DCF8[];
extern f32 D_80120408[][2];

void func_80080148(s32 arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_8011DCF8[i + arg0 * 10] = 0;
    }

    D_80120408[arg0][0] = 0.0f;
    D_80120408[arg0][1] = 0.0f;
}
