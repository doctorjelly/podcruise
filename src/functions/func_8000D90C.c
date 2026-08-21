/* Specification: specs/func_8000D90C.md (worker-authored) */
#include "podcruise/types.h"

extern s32 D_8009B800;
extern void func_8000D5EC(void *arg0, f32 arg1);
extern void func_8000CC1C(void *arg0, f32 arg1);

void func_8000D90C(void *arg0, f32 arg1) {
    if (D_8009B800 == 0) {
        func_8000D5EC(arg0, arg1);
    } else if (D_8009B800 == 1) {
        func_8000CC1C(arg0, arg1);
    }
}
