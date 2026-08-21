/* Recovered from specification $S/specs/func_800735BC.md */
#include "podcruise/types.h"

extern void func_80006E50(void *, s32);
extern void func_80006E74(void *, f32);
extern void func_80006EB4(void *, f32);

void func_800735BC(void **arg0, f32 arg1) {
    while (*arg0 != 0) {
        func_80006E50(*arg0, 0x10000000);
        func_80006E74(*arg0, 0.0f);
        func_80006EB4(*arg0, arg1);
        arg0++;
    }
}
