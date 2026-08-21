/* Independently written from the specification for func_8002DCF4. */

#include "podcruise/types.h"

extern u8 D_800A9ABC[];
extern u8 D_800A9AC0[];
extern u8 D_800A9AC4[];
extern u8 D_800A9AC8[];
extern u8 D_80113694[];
extern u8 D_801136C0[];
extern u8 D_801136EC[];
extern u8 D_80113718[];

extern s32 func_8002D968(u8 *arg0, u8 *arg1);

s32 func_8002DCF4(void) {
    if (func_8002D968(D_80113694, D_800A9ABC) &&
        func_8002D968(D_801136C0, D_800A9AC0) &&
        func_8002D968(D_801136EC, D_800A9AC4) &&
        func_8002D968(D_80113718, D_800A9AC8)) {
        return 1;
    }
    return 0;
}
