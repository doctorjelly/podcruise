/* Independently written from scratchpad spec specs/func_80033D30.md. */

#include "podcruise/types.h"

extern s32 D_800A31E0[];
extern f32 D_800A5CA0[];
extern u8 D_800AA650[];
extern u8 D_800AA654[];
extern f32 D_800AAAB4;
extern f32 D_800AAAB8;
extern f32 D_800AAABC;
extern f32 D_800AAAC0;
extern f32 D_800AAAC4;
extern f32 D_800AAAC8;

void func_80033D30(void) {
    D_800A31E0[287] = 0x11D;
    D_800A31E0[288] = 0x11C;
    D_800A31E0[289] = 0x11F;
    D_800A31E0[291] = (s32)(long)D_800AA650;
    D_800A31E0[292] = (s32)(long)D_800AA654;
    D_800A31E0[298] = 0x121;

    D_800A5CA0[609] = D_800AAAB4;
    D_800A5CA0[610] = D_800AAAB8;
    D_800A5CA0[611] = D_800AAABC;
    D_800A5CA0[606] = D_800AAAC0;
    D_800A5CA0[607] = D_800AAAC4;
    D_800A5CA0[608] = D_800AAAC8;
}
