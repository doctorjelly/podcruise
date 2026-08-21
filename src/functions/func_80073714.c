/* Implements the specification in specs/func_80073714.md (worker batch 17). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    s32 unk64;
    u8 pad68[0x120];
    f32 unk188;
    u8 pad18C[0x1808];
    void *unk1994;
} Owner80073714;

extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80017B7C(void *, f32, f32, f32);
extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_800D76F0;

void func_80073714(Owner80073714 *owner) {
    void *target;
    s32 flag;
    f32 value;

    target = owner->unk1994;
    if (target == 0) {
        return;
    }
    flag = ((owner->unk64 & 0x40) == 0) || (owner->unk60 & 0x84000);
    if ((D_8009B7D8 & 0x100) && (D_8009B7D0 != 0) && (D_800D76F0 & 0x1000)) {
        flag = 1;
    }
    if (flag) {
        if (target != 0) {
            func_800181BC(target, 2, -4, 0x10, 3);
        }
    } else {
        if (target != 0) {
            func_800181BC(target, 2, 3, 0x10, 2);
            target = owner->unk1994;
        }
        value = owner->unk188 + owner->unk188;
        func_80017B7C(target, 0.0f, 0.0f, value - 3.0f);
    }
}
