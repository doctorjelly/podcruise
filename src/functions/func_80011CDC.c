/* Specification: $S/specs/func_80011CDC.md */
#include "podcruise/types.h"

extern void func_80008F28(void);
extern void func_80011B18(s32, s32, s32);

void func_80011CDC(s32 arg0, s32 arg1, s32 arg2) {
    s32 chunk;

    func_80008F28();
    while (arg2 > 0) {
        if (arg2 > 0x800) {
            chunk = 0x800;
        } else {
            chunk = arg2;
        }
        func_80011B18(arg0, arg1, chunk);
        arg2 -= chunk;
        arg0 += chunk;
        arg1 += chunk;
        func_80008F28();
    }
}
