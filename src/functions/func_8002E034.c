/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_800A2690;
extern s32 D_800A2698;
extern void func_8002E2FC(void);
extern void func_8002E124(void);

void func_8002E034(void) {
    func_8002DFB0(0x3F, 0);
    if (D_800A2690 != 0) {
        do {
            func_8002E2FC();
            func_8002E124();
        } while (D_800A2690 != 0);
    }
    D_800A2698 = 0;
    func_8002DFB0(0x40, 0);
    D_800A2690 = 1;
}
