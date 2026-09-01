/* Implements specs/functions/recovered/func_80007E80.md. */
#include "podcruise/types.h"

extern s32 D_8009A32C[23];
extern s32 D_8009A388[8];
extern s32 D_800B05B0;

extern void func_80007A44(void);
extern void func_80007A80(void);
extern void func_80008F28(void);

void func_80007E80(s32 arg0) {
    s32 released;
    s32 i;
    s32 j;

    (void)arg0;
    released = 0;
    for (i = 0; i != 23; i++) {
        if (D_8009A32C[i] != released * 0) {
            released = 1;
            func_80007A80();
            func_80007A44();
            D_8009A32C[i] = 0;
        }
    }
    for (j = 0; j != 8; j++) {
        if (D_8009A388[j] != 0) {
            released = 1;
            func_80007A80();
            func_80007A44();
            D_8009A388[j] = 0;
        }
    }
    if (released != 0) {
        D_800B05B0 = 0;
        while (D_800B05B0 < 5) {
            func_80008F28();
        }
    }
}
