/* Independently written from scratchpad spec specs/func_80009F6C.md. */

#include "podcruise/types.h"

extern void func_80007A44(void);

extern s32 D_8009ADE8;
extern s32 D_8009AEF0;

void func_80009F6C(void) {
    func_80007A44();
    D_8009AEF0 = -1;
    D_8009ADE8 = -1;
}
