/* Recovered per $S/specs/func_8004B868.md */
#include "podcruise/types.h"

extern s32 func_80030154(s32 arg0);
extern void func_8000A44C(s32 arg0, s32 arg1);
extern void func_8000AC34(s16 arg0, s32 arg1);

void func_8004B868(void) {
    s32 i;
    s32 handle;

    func_8000A44C(0x9F, func_80030154(0x4A));
    func_8000A44C(0xA0, func_80030154(0x4C));
    func_8000A44C(0xA3, func_80030154(0x50));
    func_8000A44C(0xA4, func_80030154(0x4D));
    func_8000A44C(0xA5, func_80030154(0x4E));
    func_8000A44C(0xA6, func_80030154(0x4F));
    func_8000A44C(0xA2, func_80030154(0xAC));
    func_8000A44C(0xA1, func_80030154(0x51));

    handle = func_80030154(0x53);
    func_8000A44C(0xA7, handle);
    func_8000A44C(0xAA, handle);

    handle = func_80030154(0x52);
    func_8000A44C(0xA9, handle);
    func_8000A44C(0xAC, handle);

    handle = func_80030154(0x55);
    func_8000A44C(0xA8, handle);
    func_8000A44C(0xAB, handle);

    func_8000A44C(0xAD, func_80030154(0x54));

    for (i = 0xAA; i < 0xAD; i++) {
        func_8000AC34(i, 4);
    }
    for (i = 0xA7; i < 0xAE; i++) {
        func_8000AC34(i, 0x8000);
    }

    handle = func_80030154(0x59);
    func_8000A44C(0xAE, handle);
    func_8000A44C(0xB1, handle);

    handle = func_80030154(0x58);
    func_8000A44C(0xB0, handle);
    func_8000A44C(0xB3, handle);

    handle = func_80030154(0x5B);
    func_8000A44C(0xAF, handle);
    func_8000A44C(0xB2, handle);

    func_8000A44C(0xB4, func_80030154(0x5A));

    for (i = 0xB1; i < 0xB4; i++) {
        func_8000AC34(i, 8);
    }
    for (i = 0xAE; i != 0xB5; i++) {
        func_8000AC34(i, 0x8000);
    }
}
