/* Recovered from specs/func_8007B6CC.md (behavioral specification). */
#include "podcruise/types.h"

extern u32 *D_8011C8F0[];
extern void func_80006E50(u32 item, s32 mask);
extern void func_80006E74(u32 item, f32 value);

void func_8007B6CC(s32 arg0) {
    u32 *list;

    for (list = D_8011C8F0[arg0]; *list != 0; list++) {
        func_80006E50(*list, 0x10000000);
        func_80006E74(*list, 0.0f);
    }
}
