/* Specification: $S/specs/func_8000D818.md */
#include "podcruise/types.h"

extern s32 D_8009B7E4;
extern void func_8000C5F0(s32);
extern void func_8002F144(void);

void func_8000D818(s32 arg0) {
    if (arg0 == 0) {
        D_8009B7E4 = 0;
        func_8002F144();
    }
    if (arg0 == 2) {
        D_8009B7E4 = 1;
        func_8002F144();
    }
    if (arg0 == 1) {
        D_8009B7E4 = 2;
        func_8002F144();
    }
    if (arg0 == 3) {
        func_8000C5F0(0);
    }
}
