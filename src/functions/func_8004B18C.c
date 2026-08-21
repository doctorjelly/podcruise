/* Implements the specification in specs/func_8004B18C.md */
#include "podcruise/types.h"

extern void func_80046670(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8004B18C(void) {
    s32 index;

    index = 0;
    func_80046670(0x112, -1, 0x62 + index++, 0);
    func_80046670(0x113, -1, 0x62 + index++, 0);
    func_80046670(0xAC, -1, 0x62 + index++, 0);
    func_80046670(0xAD, -1, 0x62 + index++, 0);
    func_80046670(0xAE, -1, 0x62 + index++, 0);
    func_80046670(0x7A, -1, 0x62 + index++, 0);
    func_80046670(0xAF, -1, 0x62 + index++, 0);
    func_80046670(0xB0, -1, 0x62 + index++, 0);
    func_80046670(0xB4, -1, 0x62 + index++, 0);
    func_80046670(0xB5, -1, 0x62 + index++, 0);
    func_80046670(0xB6, -1, 0x62 + index++, 0);
    func_80046670(0xB7, -1, 0x62 + index++, 0);
    func_80046670(0xE7, -1, 0x62 + index++, 0);
    func_80046670(0xF4, -1, 0x62 + index++, 0);
    func_80046670(0xF5, -1, 0x62 + index++, 0);
    func_80046670(0xBA, -1, 0x62 + index++, 0);
    func_80046670(0xB8, -1, 0x62 + index++, 0);
    func_80046670(0xB9, -1, 0x62 + index++, 0);
    func_80046670(0xBB, -1, 0x62 + index++, 0);
    func_80046670(0xBC, -1, 0x62 + index++, 0);
    func_80046670(0xBD, -1, 0x62 + index++, 0);
    func_80046670(0xBE, -1, 0x62 + index++, 0);
    func_80046670(0xB1, -1, 0x62 + index++, 0);
    func_80046670(0xB2, -1, 0x62 + index++, 0);
    func_80046670(0xB3, -1, 0x62 + index++, 0);
}
