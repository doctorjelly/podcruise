/* Independently written from specs/func_8000FE1C.md. */

#include "podcruise/types.h"

extern s32 D_8009B814[2];
extern s32 D_8009B82C[2][8];

void func_8000FE1C(void) {
    s32 i;
    s32 j;

    i = 0;
    while (i < 2) {
        D_8009B814[i] = -1;
        j = 0;
        while (j < 8) {
            D_8009B82C[i][j] = -1;
            j++;
        }
        i++;
    }
}
