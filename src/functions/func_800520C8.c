/* Independently written from specs/functions/func_800520C8.md. */

#include "podcruise/types.h"

extern void *D_8011B1BC;
extern void *D_8011B1C0;
extern void *D_8011B1C4;
extern void *D_8011B1C8;

s32 func_800520C8(void *entry) {
    if (entry == D_8011B1BC) {
        return 0;
    }
    if (entry == D_8011B1C0) {
        return 1;
    }
    if (entry == D_8011B1C4) {
        return 2;
    }
    if (entry == D_8011B1C8) {
        return 3;
    }
    return -1;
}
