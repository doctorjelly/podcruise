/* Recovered per scratchpad spec specs/func_8006B304.md */
#include "podcruise/types.h"

typedef struct PcGridUser {
    /* 0x000 */ u8 pad000[0x50];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ u8 pad058[0x214];
    /* 0x26C */ s32 unk26C;
} PcGridUser;

extern f32 D_8011C858[];
extern f32 D_8011C868[];
extern f32 D_8011C88C;
extern f32 D_8011C890;

void func_8006B304(PcGridUser *user) {
    f32 v[3];
    s32 rows;
    s32 result;

    v[0] = user->unk50;
    v[1] = user->unk54;
    rows = 0;

    if (D_8011C868[7] - D_8011C890 < v[1]) {
        rows = 0x800000;
    }
    if (v[1] < D_8011C868[7] + D_8011C890 && D_8011C868[6] - D_8011C890 < v[1]) {
        rows |= 0x400000;
    }
    if (v[1] < D_8011C868[6] + D_8011C890 && D_8011C868[5] - D_8011C890 < v[1]) {
        rows |= 0x200000;
    }
    if (v[1] < D_8011C868[5] + D_8011C890 && D_8011C868[4] - D_8011C890 < v[1]) {
        rows |= 0x100000;
    }
    if (v[1] < D_8011C868[4] + D_8011C890 && D_8011C868[3] - D_8011C890 < v[1]) {
        rows |= 0x80000;
    }
    if (v[1] < D_8011C868[3] + D_8011C890 && D_8011C868[2] - D_8011C890 < v[1]) {
        rows |= 0x40000;
    }
    if (v[1] < D_8011C868[2] + D_8011C890 && D_8011C868[1] - D_8011C890 < v[1]) {
        rows |= 0x20000;
    }
    if (v[1] < D_8011C868[1] + D_8011C890) {
        rows |= 0x10000;
    }

    result = 0;
    if (D_8011C858[2] - D_8011C88C < v[0]) {
        result = rows >> 8;
    }
    if (v[0] < D_8011C858[2] + D_8011C88C && D_8011C858[1] - D_8011C88C < v[0]) {
        result |= rows;
    }
    if (v[0] < D_8011C858[1] + D_8011C88C) {
        result |= rows << 8;
    }
    user->unk26C = result;
}
