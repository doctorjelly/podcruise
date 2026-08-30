/* Independently written from specs/functions/recovered/func_80080D08.md. */

#include "podcruise/types.h"

typedef struct {
    f32 element[16];
} PcMatrix80080D08;

extern s32 D_800A6704;
extern PcMatrix80080D08 D_8011DCB8;

s32 func_80080D08(void *output_arg) {
    PcMatrix80080D08 *output = output_arg;

    if (D_800A6704 >= 0) {
        output->element[0] = D_8011DCB8.element[0];
        output->element[1] = D_8011DCB8.element[1];
        output->element[2] = D_8011DCB8.element[2];
        output->element[3] = D_8011DCB8.element[3];
        output->element[4] = D_8011DCB8.element[4];
        output->element[5] = D_8011DCB8.element[5];
        output->element[6] = D_8011DCB8.element[6];
        output->element[7] = D_8011DCB8.element[7];
        output->element[8] = D_8011DCB8.element[8];
        output->element[9] = D_8011DCB8.element[9];
        output->element[10] = D_8011DCB8.element[10];
        output->element[11] = D_8011DCB8.element[11];
        output->element[12] = D_8011DCB8.element[12];
        output->element[13] = D_8011DCB8.element[13];
        output->element[14] = D_8011DCB8.element[14];
        output->element[15] = D_8011DCB8.element[15];
        return 1;
    }
    return 0;
}
