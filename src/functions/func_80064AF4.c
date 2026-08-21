/* Independently written from the specification for func_80064AF4. */

#include "podcruise/types.h"

extern f32 D_8011A240[];
extern f32 D_80120BF8;

void func_80064AF4(void) {
    if (D_8011A240[14] > 0.0f) {
        D_8011A240[14] -= D_80120BF8;
        if (D_8011A240[14] < 0.0f) {
            D_8011A240[14] = 0.0f;
        }
    }
}
