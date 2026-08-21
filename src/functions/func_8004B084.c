/* Implements the specification in specs/func_8004B084.md */
#include "podcruise/types.h"

extern void func_80046670(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8004B084(void) {
    func_80046670(0x4F, -1, 0x3D, 0);
    func_80046670(0x75, -1, 0x3E, 0);
    func_80046670(0x76, -1, 0x3F, 0);
    func_80046670(0xF8, -1, 0x40, 0);
    func_80046670(0x77, -1, 0x41, 0);
    func_80046670(0x74, -1, 0x42, 0);
    func_80046670(0x52, -1, 0x43, 0);
    func_80046670(0x79, -1, 0x44, 0);
    func_80046670(0x4D, -1, 0x45, 0);
    func_80046670(0x51, -1, 0x46, 0);
    func_80046670(0x51, -1, 0x47, 0);
    func_80046670(0x51, -1, 0x48, 0);
}
