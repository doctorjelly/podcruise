/* Independently written from specs/functions/func_80051FF4.md. */

#include "podcruise/types.h"

extern void *D_8011B1BC;
extern void *D_8011B1C0;
extern void *D_8011B1C4;
extern void *D_8011B1C8;

s32 func_80051FF4(void) {
    if (D_8011B1BC == 0) {
        return 0;
    }
    if (D_8011B1C0 == 0) {
        return 1;
    }
    if (D_8011B1C4 == 0) {
        return 2;
    }
    if (D_8011B1C8 == 0) {
        return 3;
    }
    return 4;
}
