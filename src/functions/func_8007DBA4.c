/* Recovered from specification specs/func_8007DBA4.md (worker batch 04). */
#include "podcruise/types.h"

typedef struct Node8007DBA4 {
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
} Node8007DBA4;

extern f32 D_8011C858[4];
extern f32 D_8011C868[9];

extern s32 func_800181BC(Node8007DBA4 *node, s32 which, s32 value, s32 flags, s32 mode);

s32 func_8007DBA4(Node8007DBA4 *node) {
    f32 *place;
    s32 red;
    s32 shade;
    s32 blue;
    s32 color;

    place = &node->unk1C;
    if (*(volatile f32 *)&node->unk20 < D_8011C868[1]) {
        shade = 0x00FF0000;
    } else if (node->unk20 < D_8011C868[2]) {
        shade = 0x00FE0000;
    } else if (node->unk20 < D_8011C868[3]) {
        shade = 0x00FC0000;
    } else if (node->unk20 < D_8011C868[4]) {
        shade = 0x00F80000;
    } else if (node->unk20 < D_8011C868[5]) {
        shade = 0x00F00000;
    } else if (node->unk20 < D_8011C868[6]) {
        shade = 0x00E00000;
    } else if (node->unk20 < D_8011C868[7]) {
        shade = 0x00C00000;
    } else if (node->unk20 < D_8011C868[8]) {
        shade = 0x00800000;
    } else {
        shade = 0;
    }
    if (shade != 0) {
        if (node->unk2C < D_8011C868[0]) {
            shade = 0;
        } else if (node->unk2C < D_8011C868[1]) {
            shade &= 0x00010000;
        } else if (node->unk2C < D_8011C868[2]) {
            shade &= 0x00030000;
        } else if (node->unk2C < D_8011C868[3]) {
            shade &= 0x00070000;
        } else if (node->unk2C < D_8011C868[4]) {
            shade &= 0x000F0000;
        } else if (node->unk2C < D_8011C868[5]) {
            shade &= 0x001F0000;
        } else if (node->unk2C < D_8011C868[6]) {
            shade &= 0x003F0000;
        } else if (node->unk2C < D_8011C868[7]) {
            shade &= 0x007F0000;
        }
    }
    red = shade << 8;
    blue = shade >> 8;
    if (red != 0) {
        if (place[3] < D_8011C858[0] || D_8011C858[1] < place[0]) {
            red = 0;
        }
        if (place[3] < D_8011C858[1] || D_8011C858[2] < place[0]) {
            shade = 0;
        }
        if (place[3] < D_8011C858[2] || D_8011C858[3] < place[0]) {
            blue = 0;
        }
    }
    func_800181BC(node, 0, 0xFF, 0x10, 3);
    color = red | shade | blue;
    func_800181BC(node, 0, color, 0x10, 2);
    return color;
}
