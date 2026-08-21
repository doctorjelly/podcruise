/* Recovered from specification specs/func_800398B8.md (scratchpad). */
#include "podcruise/types.h"
extern s32 D_800A26B8;
extern s32 D_80113680;
extern s32 D_80113A70;
extern s32 func_8003931C(void *);
extern void func_80039890(void);
extern void func_8003960C(void);
void func_800398B8(void) {
    if (D_800A26B8 == 0) {
        D_80113680 = func_8003931C(&D_80113680);
        if (D_80113680 != D_80113A70) { func_80039890(); func_8003960C(); }
    }
}
