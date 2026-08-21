/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef struct Blk80045F60 {
    /* 0x0 */ u8 data[0x30];
} Blk80045F60;

typedef struct Obj80045F60 {
    /* 0x000 */ u8 pad000[0xC8];
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ u8 pad0CC[0x20];
    /* 0x0EC */ void **unkEC[6];
    /* 0x104 */ Blk80045F60 unk104[9][6];
} Obj80045F60;

extern void func_80083134(void *, s32, void *, s32);

void func_80045F60(Obj80045F60 *object) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_80083134(object->unkEC[i][0], object->unkC8, &object->unk104[0][i], 12);
        func_80083134(object->unkEC[i][4], object->unkC8, &object->unk104[1][i], 12);
        func_80083134(object->unkEC[i][8], object->unkC8, &object->unk104[2][i], 12);
        func_80083134(object->unkEC[i][2], object->unkC8, &object->unk104[3][i], 12);
        func_80083134(object->unkEC[i][6], object->unkC8, &object->unk104[4][i], 12);
        func_80083134(object->unkEC[i][3], object->unkC8, &object->unk104[5][i], 12);
        func_80083134(object->unkEC[i][7], object->unkC8, &object->unk104[6][i], 12);
        func_80083134(object->unkEC[i][10], object->unkC8, &object->unk104[7][i], 12);
        func_80083134(object->unkEC[i][11], object->unkC8, &object->unk104[8][i], 12);
    }
}
