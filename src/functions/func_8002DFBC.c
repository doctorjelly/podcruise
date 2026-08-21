/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_800A268C;
extern void func_8002E2FC(void);
extern void func_8002E124(void);

void func_8002DFBC(void) {
    func_8002DFB0(0x3D, 0);
    while (D_800A268C != 0) {
        func_8002E2FC();
        func_8002E124();
    }
    func_8002DFB0(0x3E, 0);
    D_800A268C = 1;
}
