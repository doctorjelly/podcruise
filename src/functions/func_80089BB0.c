/* Recovered from specification $S/specs/func_80089BB0.md */
#include "podcruise/types.h"

extern u8 D_80149CB0;
extern s32 D_80149C70;

extern void func_800905F0(void);
extern void func_80089CC0(void);
extern s32 func_800907D0(s32, s32 *);
extern void func_80087E80(s32, s32, s32);
extern void func_80090634(void);

s32 func_80089BB0(s32 arg0) {
    s32 result;

    func_800905F0();
    if (D_80149CB0 != 1) {
        func_80089CC0();
        func_800907D0(1, &D_80149C70);
        func_80087E80(arg0, 0, 1);
    }
    result = func_800907D0(0, &D_80149C70);
    D_80149CB0 = 1;
    func_80090634();
    return result;
}
