/* Recovered from specification specs/func_8000A4D8.md (worker tier2_18). */
#include "podcruise/types.h"

extern void func_8000A44C(s16 index, s32 mode);
extern s32 D_8009B770;

void func_8000A4D8(void) {
    s32 index;

    for (index = 0; index < D_8009B770; index++) {
        func_8000A44C(index, 0);
    }
    D_8009B770 = 0;
}
