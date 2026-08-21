/* Independently written from scratchpad spec specs/func_8000C540.md. */

#include "podcruise/types.h"

extern u8 D_800A26D0;
extern u32 D_800D6960[];
extern u8 D_800D74B0;
extern u8 D_800D74B2;

extern void func_80087E80(void *arg0, s32 *arg1, s32 arg2);
extern void func_80089800(s32 arg0);
extern void func_80089870(void *arg0, u8 *arg1, u8 *arg2);
extern void func_80089BB0(void *arg0);
extern void func_80089C34(void *arg0);

s32 func_8000C540(void *arg0, s32 arg1) {
    s32 status;
    u8 buffer[40];
    u8 scratch[164];

    (void)arg1;
    (void)scratch;
    func_80089800(1);
    func_80089870(arg0, &D_800A26D0, &D_800D74B0);
    if ((D_800A26D0 & 1) == 0) {
        D_800D6960[7] |= 0x1000;
    }
    if ((D_800D74B2 & 1) == 0) {
        return 0;
    }
    func_80089BB0(arg0);
    func_80087E80(arg0, &status, 1);
    func_80089C34(buffer);
    return 2;
}
