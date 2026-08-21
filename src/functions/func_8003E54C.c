/* Independently written from specs/functions/func_8003E54C.md. */

#include "podcruise/types.h"

extern s32 D_800A4984;
extern s16 D_80118958[][2];
extern u8 D_80118C50[];

void func_8003E54C(u8 kind, s32 x, s32 y) {
    s32 count;

    count = D_800A4984;
    if (count < 190) {
        D_80118958[count][0] = x;
        D_80118958[count][1] = y;
        D_80118C50[count] = kind;
        D_800A4984 = count + 1;
    }
}
