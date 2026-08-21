/* Recovered per specs/func_8002F06C.md (worker specification). */
#include "podcruise/types.h"

extern s32 D_800A26F4;
extern s32 D_800A26F8;

extern void func_80007A80(void);
extern void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_8000D9A8(void);
extern void func_8003FA24(u32 arg0, void *arg1);

void func_8002F06C(void) {
    u32 message[4];
    u32 extra[2];
    (void)extra;

    if (D_800A26F8 == 0) {
        func_80007A80();
        func_80008B14(0x4E, 6, 0.25f, 1.0f, 0);
        D_800A26F4 = 2;
        message[0] = 0x50617773;
        message[1] = 1;
        func_8003FA24(0x416C6C21, message);
        func_8000D9A8();
    }
}
