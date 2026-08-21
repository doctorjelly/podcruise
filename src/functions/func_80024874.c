/* Independently written from scratchpad spec specs/func_80024874.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x5D];
    /* 0x5D */ s8 unk5D;
    /* 0x5E */ s8 unk5E;
} Subject;

typedef struct {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ s32 unk30;
} Tally;

extern u8 D_800A21B4[];
extern s32 D_800A22E8[][7];
extern Tally D_8011A240;

extern s32 func_8002DAD0(Subject *subject, s8 group, u8 slot);

void func_80024874(Subject *subject) {
    s32 i;

    D_8011A240.unk30 = 0;
    for (i = 0; i < D_800A21B4[subject->unk5E]; i++) {
        if (subject->unk5D == D_800A22E8[subject->unk5E][i]) {
            return;
        }
        if (func_8002DAD0(subject, subject->unk5E, i) != 0) {
            D_8011A240.unk30++;
        }
    }
}
