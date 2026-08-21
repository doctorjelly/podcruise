#include "podcruise/runtime_leaves.h"

extern s32 D_8009A310;
extern s32 D_800A2684;
extern s32 D_800A2694;
extern void func_8008AFBC(s32 value);
extern void func_8008B14C(s32 value);
extern void func_8002E2FC(void);

void func_8002E5D4(void) {
    func_8008AFBC(D_8009A310);
    func_8008B14C(D_8009A310);
    func_8002DFB0(35, 0);
    while (D_800A2684 == 0) {
        func_8002E2FC();
    }
    D_800A2694 = 0;
}
