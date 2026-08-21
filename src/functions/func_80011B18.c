/* Specification: $S/specs/func_80011B18.md */
#include "podcruise/types.h"

extern s32 D_800A68A0;
extern u8 D_800D9BF8[];

extern void func_80008F28(void);
extern void func_8002E034(void);
extern void func_80087CC0(s32, s32);
extern void func_80087D70(void *, s32, s32, s32, s32, s32, void *);
extern s32 func_80087E80(void *, void *, s32);

void func_80011B18(s32 arg0, s32 arg1, s32 arg2) {
    s32 buffer[6];
    s32 slot;

    if (D_800A68A0 == 0) {
        func_8002E034();
        D_800A68A0 = 1;
    }
    func_80087CC0(arg1, arg2);
    func_80087D70(buffer, 0, 0, arg0, arg1, arg2, D_800D9BF8);
    while (func_80087E80(D_800D9BF8, &slot, 0) != 0) {
        func_80008F28();
    }
}
