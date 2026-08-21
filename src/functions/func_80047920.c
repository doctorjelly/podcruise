/* Independently written from the specification for the active-entry highlight pass. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0xE];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ u32 unk10;
} HighlightTarget;

typedef struct {
    /* 0x00 */ HighlightTarget *unk00;
} HighlightEntry;

extern s32 D_800A4BE8;
extern s32 D_8011A26C;
extern HighlightEntry *D_8011A508[];

void func_80047920(void) {
    HighlightTarget *target;
    s32 i;

    for (i = 0; i < D_8011A26C; i++) {
        target = D_8011A508[0x8E + i]->unk00;
        if (target == 0) {
            continue;
        }
        if (i == D_800A4BE8) {
            target->unk0E = 0;
            target->unk10 |= 4;
        } else {
            target->unk0E = 1;
            target->unk10 |= 4;
        }
    }
}
