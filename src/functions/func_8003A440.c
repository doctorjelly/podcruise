/* Implements the specification in specs/func_8003A440.md (subsystem restart sequence). */
#include "podcruise/types.h"

extern s32 D_800A40F0;

extern void func_80039B70(void);
extern void func_80039EC0(s32 arg0);
extern void func_80039CD8(s32 arg0);

void func_8003A440(void) {
    func_80039B70();
    func_80039EC0(0);
    D_800A40F0 = 0;
    func_80039CD8(1);
}
