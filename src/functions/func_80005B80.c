/* Independently written from specs/functions/selector_state.md. */

#include "podcruise/types.h"

extern s32 D_8009A2A0;
extern s32 D_800AF4C0[75][4];

void func_80005B80(void) {
    s32 record;
    s32 word;

    D_8009A2A0 = 0;
    for (record = 0; record < 75; record++) {
        for (word = 0; word < 4; word++) {
            D_800AF4C0[record][word] = 0;
        }
    }
}
