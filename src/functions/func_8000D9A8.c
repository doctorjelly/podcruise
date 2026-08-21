/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */


#include "podcruise/types.h"

extern s32 D_8009B7DC;
extern s32 D_8009B7E4;
extern s32 D_8009B7F4;
extern s32 D_8009B800[];
extern s32 D_800D5718[];
extern s32 D_800D578C;
extern s16 *func_8003F800(s32 tag, s32 index);

void func_8000D9A8(void) {
    s32 i;

    if (D_8009B7F4 == -2) {
        D_8009B800[0] = -1;
        for (i = 0; i != 3; i++) {
        }
    }
    D_8009B7DC = D_8009B7F4;
    D_8009B7E4 = 0;
    D_800D578C = 0;
    if ((func_8003F800(0x4A646765, 0)[3] & 0x1000) == 0) {
        D_8009B800[0] = 2;
        D_8009B7DC = 0;
    } else {
        D_8009B800[0] = 0;
    }
    D_800D5718[D_800D578C] = D_8009B800[0];
}
