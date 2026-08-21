/* Implements specs/func_80007E80.md (release two slot tables, then drain). */
#include "podcruise/types.h"

extern s32 D_8009A32C[23];
extern s32 D_8009A388[8];
extern s32 D_800B05B0;

extern void func_80007A44(void);
extern void func_80007A80(void);
extern void func_80008F28(void);

void func_80007E80(s32 arg0) {
    s32 index;
    s32 released;

    (void)arg0;
    released = 0;
    for (index = 0; index != 23; index++) {
        if (D_8009A32C[index] != 0) {
            released = 1;
            func_80007A80();
            func_80007A44();
            D_8009A32C[index] = 0;
        }
    }
    for (index = 0; index != 8; index++) {
        if (D_8009A388[index] != 0) {
            released = 1;
            func_80007A80();
            func_80007A44();
            D_8009A388[index] = 0;
        }
    }
    if (released != 0) {
        D_800B05B0 = 0;
        while (D_800B05B0 < 5) {
            func_80008F28();
        }
    }
}
