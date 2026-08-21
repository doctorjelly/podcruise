/* Implements the specification in specs/func_8003E920.md (flush queued draw records). */
#include "podcruise/types.h"

extern s32 D_800A4978;
extern u8 D_80118850[][4];
extern s16 D_80118750[][2];
extern u8 D_80116750[][0x80];

extern void func_80011F04(s32, s32, s32, s32);
extern void func_80011ECC(s32, s32);
extern void func_80013DC0(u8 *);

void func_8003E920(void) {
    s32 i;

    for (i = 0; i < D_800A4978; i++) {
        func_80011F04(D_80118850[i][0], D_80118850[i][1], D_80118850[i][2], D_80118850[i][3]);
        func_80011ECC(D_80118750[i][0], D_80118750[i][1]);
        func_80013DC0(D_80116750[i]);
    }
    D_800A4978 = 0;
}
