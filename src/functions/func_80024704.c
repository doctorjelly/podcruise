/* Independently written from scratchpad spec specs/func_80024704.md. */

#include "podcruise/types.h"

extern u8 D_800A21B4[];
extern u8 D_80113680[];
extern u8 D_80113E60[];
extern s32 D_8011A240[];

void func_80024704(s8 *arg0) {
    s32 i;

    D_8011A240[10] = 3;
    D_8011A240[11] = 0;

    if (arg0[0x6C] != 0) {
        if (D_80113E60[0xB] == 0) {
            D_8011A240[10] = 2;
        }
        for (i = 0; i < D_800A21B4[arg0[0x5E]]; i++) {
            if (D_80113E60[8 + arg0[0x5E]] & (1 << i)) {
                D_8011A240[11]++;
            }
        }
    } else {
        if (D_80113680[0xF] == 0) {
            D_8011A240[10] = 2;
        }
        for (i = 0; i < D_800A21B4[arg0[0x5E]]; i++) {
            if (D_80113680[0xC + arg0[0x5E]] & (1 << i)) {
                D_8011A240[11]++;
            }
        }
    }

    if (D_8011A240[11] - 1 < D_8011A240[12]) {
        D_8011A240[12] = D_8011A240[11] - 1;
    }

    D_8011A240[8] = D_8011A240[9] = 0;
    if (arg0[0x5E] > 0) {
        D_8011A240[8] = 1;
    }
    if (arg0[0x5E] < D_8011A240[10]) {
        D_8011A240[9] = 1;
    }
}
