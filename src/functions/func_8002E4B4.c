/* Implements specs/func_8002E4B4.md (timing baseline setup, recovered specification). */
#include "podcruise/types.h"
u64 D_800A26A0;
extern u8 D_800D7420[];
extern u8 D_800D7438[];
extern u64 func_800811DC(void);
extern void func_800880E0(void *, void *, s32);
extern u64 func_8008AB48(u64, u64);
extern u64 func_8008AC48(u64, u64);
extern void func_8008AE30(s32, void *, s32);

void func_8002E4B4(void) {
    D_800A26A0 = func_8008AB48(func_8008AC48(func_800811DC(), 0x40), 0xBB8);
    func_800880E0(D_800D7420, D_800D7438, 0x14);
    func_8008AE30(4, D_800D7420, 1);
    func_8008AE30(9, D_800D7420, 2);
}
