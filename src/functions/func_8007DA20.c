/* Independently written from scratchpad spec specs/func_8007DA20.md. */

#include "podcruise/types.h"

extern s32 D_800A5B5C;
extern f32 D_800ADC10;
extern f32 D_800ADC14;
extern f32 D_800ADC18;
extern f32 D_800ADC1C;
extern f32 D_800ADC20;
extern f32 D_800ADC24;
extern f32 D_800ADC28;
extern f32 D_800ADC2C;
extern f32 D_8011C858[4];
extern f32 D_8011C868[9];
extern f32 D_8011C88C;
extern f32 D_8011C890;

void func_8007DA20(void) {
    f32 xstep;
    f32 ystep;
    f32 ylo;
    f32 yhi;
    f32 xlo;
    f32 xhi;

    if (D_800A5B5C == 1) {
        ylo = D_800ADC10;
        yhi = D_800ADC14;
        xhi = D_800ADC18;
        xlo = D_800ADC1C;
    } else if (D_800A5B5C == 2) {
        ylo = D_800ADC20;
        yhi = D_800ADC24;
        xhi = D_800ADC28;
        xlo = D_800ADC2C;
    }

    xstep = (xhi - xlo) / 3;
    ystep = (yhi - ylo) / 8;

    D_8011C858[0] = xlo;
    D_8011C858[1] = xlo + xstep;
    D_8011C858[2] = xhi - xstep;
    D_8011C858[3] = xhi;

    D_8011C868[0] = ylo;
    D_8011C868[1] = ylo + ystep;
    D_8011C868[2] = 2 * ystep + ylo;
    D_8011C868[3] = 3 * ystep + ylo;
    D_8011C868[4] = 4 * ystep + ylo;
    D_8011C868[5] = 5 * ystep + ylo;
    D_8011C868[6] = 6 * ystep + ylo;
    D_8011C868[7] = yhi - ystep;
    D_8011C868[8] = yhi;

    D_8011C88C = xstep / 4;
    D_8011C890 = ystep / 4;
}
