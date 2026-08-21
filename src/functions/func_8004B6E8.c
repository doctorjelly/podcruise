/* Implements specs/func_8004B6E8.md (worker specification). */
#include "podcruise/types.h"

extern s32 func_80030154(s32);
extern void func_8000A44C(s16, s32);
extern void func_8000AC34(s16, s32);

void func_8004B6E8(void) {
    s32 i;
    s16 j;
    s32 t;

    t = func_80030154(0x95);
    func_8000A44C(0x71, t);
    func_8000A44C(0x72, t);
    t = func_80030154(0x96);
    func_8000A44C(0x73, t);
    func_8000A44C(0x74, t);
    func_8000A44C(0x75, func_80030154(0x97));
    func_8000A44C(0x76, func_80030154(0x98));
    func_8000A44C(0x77, func_80030154(0x99));
    func_8000A44C(0x78, func_80030154(0x9A));
    func_8000A44C(0x79, func_80030154(0x9B));
    func_8000A44C(0x7A, func_80030154(0x9C));
    func_8000A44C(0x7B, func_80030154(0x9D));
    func_8000A44C(0x7C, func_80030154(0x9E));
    t = func_80030154(0x9F);
    func_8000A44C(0x7D, t);
    func_8000A44C(0x7E, t);
    for (i = 0x71; i != 0x7F; i++) {
        j = i;
        func_8000AC34(j, 0x2000);
        func_8000AC34(j, 0x8000);
    }
}
