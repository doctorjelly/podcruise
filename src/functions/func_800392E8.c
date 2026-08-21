/* Implements the specification in specs/func_800392E8.md (module reset entry). */
#include "podcruise/types.h"

extern u8 D_800D9C28[];
extern s32 D_800A26B8;

extern void func_80089BB0(void *arg0);
extern void func_800391F4(s32 arg0);

void func_800392E8(void) {
    func_80089BB0(D_800D9C28);
    D_800A26B8 = 0;
    func_800391F4(5);
}
