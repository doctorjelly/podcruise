/* Recovered from specification $S/specs/func_80053AD4.md */
#include "podcruise/types.h"

extern f32 D_800ACE94;
extern f32 D_800ACE98;
extern f32 D_800ACE9C;
extern void func_8003B184(void *, f32 *, f32);
extern void func_80017BA8(void *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_8000EA4C(void *, s32, s32, s32, s32, s32, s32);
void func_80053AD4(void *arg0, void *arg1);

void func_80053AD4(void *arg0, void *arg1) {
    f32 matrices[7][16];
    f32 pad[18];
    register f32 angle;
    register f32 stepRest;
    register f32 stepFirst;
    s32 index;

    (void)pad;
    angle = D_800ACE94;
    stepRest = D_800ACE9C;
    stepFirst = D_800ACE98;
    for (index = 0; index < 7; index++) {
        func_8003B184((void *)(*(u8 **)((u8 *)arg1 + 0x84) + 0xAC), matrices[index], angle);
        if (index >= 2) {
            angle += stepRest;
        } else {
            angle += stepFirst;
        }
    }

    for (index = 0; index < 6; index++) {
        func_80017BA8(((void **)arg0)[index + 4], matrices[index]);
        if (((void **)arg0)[index + 4] != 0) {
            func_800181BC(((void **)arg0)[index + 4], 2, 3, 0x10, 2);
        }
        func_8000EA4C(((void **)arg0)[index + 4], -1, -1, 0, 0xFF, 0, -1);
    }
}
