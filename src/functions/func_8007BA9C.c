/* Independently written from scratchpad spec specs/func_8007BA9C.md. */

#include "podcruise/types.h"

extern void *D_8011CA58[];
extern u8 D_8011CB20[][88];

void *func_8007BA9C(void *arg0) {
    s32 i;

    i = 0;
    while (i < 50 && D_8011CA58[i] != (void *)0 && D_8011CA58[i] != arg0) {
        i++;
    }

    if (D_8011CA58[i] != (void *)0) {
        return D_8011CB20[i];
    }
    return (void *)0;
}
