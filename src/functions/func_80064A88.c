/* Independently written from the specification for func_80064A88. */

#include "podcruise/types.h"

extern f32 D_8011A240[];
extern f32 D_80120BF8;

f32 func_80064A88(f32 rate) {
    D_8011A240[0] += rate * D_80120BF8;
    if (D_8011A240[0] > 1.0f) {
        D_8011A240[0] = 1.0f;
    }
    if (D_8011A240[0] < 0.0f) {
        D_8011A240[0] = 0.0f;
    }
    return D_8011A240[0];
}
