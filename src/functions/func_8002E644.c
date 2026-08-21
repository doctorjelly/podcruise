#include "podcruise/runtime_leaves.h"

extern s32 D_800A2674;
extern s32 D_800A2678;
extern s32 D_800A2684;
extern s32 D_800A2688;
extern s32 D_800A2680;
extern void func_8008B190(void);
extern void func_8002E2FC(void);

void func_8002E644(void) {
    func_8002DFB0(32, 0);
    D_800A2684 = 0;
    if (D_800A2674 != 0) {
        func_8002DFB0(33, 0);
        func_8008B190();
        D_800A2678 = 1;
        D_800A2688 = 0;
        while (D_800A2688 == 0) {
            func_8002E2FC();
        }
        D_800A2688 = 0;
        func_8002DFB0(34, 0);
    }
    D_800A2680 = 1;
}
