/* Recovered from specification $S/specs/func_80089800.md */
#include "podcruise/types.h"

extern void func_800905F0(void);
extern void func_80090634(void);
extern u8 D_80149CB0;
extern u8 D_80149CB1;

s32 func_80089800(mode)
u8 mode;
{
    s32 status;

    status = 0;
    func_800905F0();
    if (mode >= 5) {
        D_80149CB1 = 4;
    } else {
        D_80149CB1 = mode;
    }
    D_80149CB0 = 0xFE;
    func_80090634();
    return status;
}
