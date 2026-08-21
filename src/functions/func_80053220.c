/* Implements the specification in specs/func_80053220.md (input-mask gate). */
#include "podcruise/types.h"
extern s32 D_800A5998;
extern s32 D_800A59A0;
extern s32 D_800A52BC;
extern s32 D_800A59A8;
extern s32 D_800D7700[];
extern s32 func_8002F054(void);
s32 func_80053220(s32 mask) {
    if ((D_800A5998 != 0) && (D_800A59A0 == 0)) {
        return 0;
    }
    if (D_800A52BC >= 2) {
        if (func_8002F054() != 0) {
            return D_800D7700[D_800A59A8] & mask;
        }
        if ((D_800D7700[0] & mask) != 0) {
            D_800A59A8 = 0;
            return 1;
        }
        if ((D_800D7700[1] & mask) != 0) {
            D_800A59A8 = 1;
            return 1;
        }
    } else {
        return D_800D7700[0] & mask;
    }
}
