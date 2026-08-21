/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

extern long long func_800811DC(void);
extern u8 D_800A6770;
extern s32 D_80120C30;

s32 func_80082BE0(void) {
    s32 x;

    if (!D_800A6770) {
        D_80120C30 = (s32)func_800811DC();
        D_800A6770 = 1;
    }
    x = D_80120C30 * 0x41C64E6D + 0x3039;
    if (x == (s32)0x80000000) {
        D_80120C30 = x;
        return 0;
    }
#ifdef PODCRUISE_JP
    if (x < 0) {
        D_80120C30 = x;
        if ((u32)x < 0x80000041U) {
            return 0x7FFFFFBF;
        }
        return -x;
    }
    D_80120C30 = x;
    if (x >= 0x7FFFFFC0) {
        return 0x7FFFFFBF;
    }
    return x;
#else
    if (x < 0) {
        D_80120C30 = x;
        return -x;
    }
    D_80120C30 = x;
    return x;
#endif
}
