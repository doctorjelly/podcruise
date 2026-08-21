/* Specification: $S/specs/func_80097D70.md */
#include "podcruise/types.h"

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern void func_8008D12C(void *);
extern u8 D_800A7BB8[];
extern u8 *D_800A7BC0;

void func_80097D70(void) {
    register s32 handle;

    handle = func_8008CA80();
    *(s16 *)(D_800A7BC0 + 0x10) = 2;
    func_8008D12C(D_800A7BB8);
    func_8008CAA0(handle);
}
