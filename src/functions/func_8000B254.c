/* Specification: $S/specs/func_8000B254.md */
#include "podcruise/types.h"

extern void func_80017874(s32);
extern void func_80017C18(s32, s32);
extern void func_80017C98(s32, s32);
extern s32 func_80017DA4(s32);

void func_8000B254(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == 3) {
        func_80017C98(arg1, arg2);
        return;
    }
    if (arg0 == 2) {
        func_80017C18(arg1, arg2);
        return;
    }
    if (func_80017DA4(arg1) == 0xD065) {
        func_80017C98(arg1, arg2);
        return;
    }
    if (func_80017DA4(arg1) == 0xD065) {
        func_80017C18(arg1, arg2);
        return;
    }
    func_80017874(arg2);
}
