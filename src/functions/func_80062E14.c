/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

extern void func_8003FD7C(void *arg0);
extern s32 D_800A4BE0;

s32 func_80062E14(void *arg0, u32 *arg1, s32 arg2) {
    (void)arg2;
    switch (arg1[0]) {
    case 0x416C6F63:
        if (D_800A4BE0 == 0) {
            return 1;
        }
        return 1;
    case 0x4C6F6164:
    case 0x52536574:
        func_8003FD7C(arg0);
        return 1;
    case 0x4D6F646C:
        if (D_800A4BE0 == 0) {
            return 1;
        } else {
            return 1;
        }
        break;
    case 0x46726565:
        return 1;
    }
    return 0;
}
