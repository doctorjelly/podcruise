/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s32 D_8011C840;

void func_80065804(s32 value) {
    D_8011C840 = value;
}
