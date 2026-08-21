/* Implements the specification in specs/func_80093FB4.md */
#include "podcruise/types.h"
extern u32 D_8014C520;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern u32 func_8008C550(void);
extern void func_80097980(u32);

void func_80093FB4(u64 value) {
    u64 adjusted;
    s32 token;

    token = func_8008CA80();
    D_8014C520 = func_8008C550();
    adjusted = value + D_8014C520;
    func_80097980((u32)adjusted);
    func_8008CAA0(token);
}
