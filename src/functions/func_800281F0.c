/* Independently written from specs/functions/func_800281F0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} EntryF0;

extern EntryF0 D_800D6CD8[23];
extern s32 D_80113E74[][11];
extern s32 D_8011A26C;

void func_800281F0(signed char *arg0) {
    s32 count;
    s32 mask;
    s32 index;

    count = 0;
    mask = D_80113E74[arg0[0x6F]][0] | 0x22E01;

    for (index = 0; index < 23; index++) {
        if ((1 << index) & mask) {
            D_800D6CD8[count].unk0 = index;
            D_800D6CD8[count].unk4 = 0xFF;
            D_800D6CD8[count].unk5 = 0;
            count++;
        }
    }

    for (index = count; index < 23; index++) {
        D_800D6CD8[index].unk0 = -1;
        D_800D6CD8[index].unk4 = 0xFF;
        D_800D6CD8[index].unk5 = 0;
    }

    D_8011A26C = count;
}
