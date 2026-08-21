/* Implements specs/func_8003964C.md (mode entry, recovered specification). */
#include "podcruise/types.h"

extern u8 D_800D9C28[];
extern u8 D_80113680[];
extern void func_800392A4(void);
extern void func_800392E8(void);
extern void func_800393DC(void *, s32, s32);
extern void func_80039478(void *);
extern void func_8003960C(void);
extern s32 func_8008C280(void *);

void func_8003964C(void) {
    s32 result;

    func_800392A4();
    result = func_8008C280(D_800D9C28);
    if (result != 1 && result != 2) {
        func_800392E8();
        return;
    }
    func_800392E8();
    func_80039478(D_80113680);
    func_800393DC(D_80113680, 0, 0x3F0);
    func_800393DC(D_80113680, 0x400, 0x3F0);
    func_8003960C();
}
