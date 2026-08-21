/* Independently written from the specification for func_8006C6D0. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ u32 unk60;
} Func8006C6D0Target;

extern u32 D_800D76F0[];

void func_8006C6D0(Func8006C6D0Target *arg0, s32 arg1) {
    if (D_800D76F0[arg1] & 0x2000) {
        if (!(arg0->unk60 & 0x1000)) {
            arg0->unk60 |= 0x1000;
        }
    }
}
