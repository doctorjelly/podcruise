/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_8009B810;
extern s32 D_8009B86C;
extern void func_8000FA2C(void *value);
extern void func_800105DC(void *value);
extern void func_80010B34(void *value);
extern void func_80010EA0(void *value);
extern void func_80010080(void *first, void *second);

void func_80011888(void *first, void *second) {
    void *saved = first;
    if (D_8009B810 != 0) {
        func_8000FA2C(saved);
        func_800105DC(saved);
        func_80010B34(saved);
        func_80010EA0(saved);
    } else {
        D_8009B86C = 0;
    }
    func_80010080(saved, second);
}
