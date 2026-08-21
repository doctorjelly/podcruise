/* Independently written from specs/functions/func_80051994.md. */

#include "podcruise/types.h"

extern s32 D_8011A508[];

void func_80051994(s32 first, s32 second) {
    s32 saved;

    saved = D_8011A508[first];
    D_8011A508[first] = D_8011A508[second];
    D_8011A508[second] = saved;
}
