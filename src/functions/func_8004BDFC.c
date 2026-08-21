/* Spec: $S/specs/func_8004BDFC.md */
#include "podcruise/types.h"

extern s32 func_80030154(s32);
extern void func_8000A44C(s32, s32);
extern void func_8000AC60(s32, s32);
extern void func_8000AC34(s32, s32);
extern void func_80046670(s32, s32, s32, s32);

void func_8004BDFC(void) {
    func_8000A44C(0x4D, func_80030154(0x81));
    func_8000AC60(0x4D, 1);
    func_8000AC34(0x4D, 2);
    func_8000A44C(0x53, func_80030154(0xA8));
    func_8000A44C(0x52, func_80030154(0xA7));
    func_80046670(0x132, -1, 0x54, 0);
    func_8000A44C(0x4F, func_80030154(0xAB));
}
