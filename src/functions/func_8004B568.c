/* Implements specs/func_8004B568.md (worker specification). */
#include "podcruise/types.h"

extern s32 func_80030154(s32);
extern void func_8000A44C(s16, s32);
extern void func_8000AC34(s16, s32);

void func_8004B568(void) {
    s32 i;
    s16 j;
    s32 t;

    t = func_80030154(0x1A);
    for (i = 0x8D; i < 0x9F; i++) {
        j = i;
        func_8000A44C(j, t);
        func_8000AC34(j, 0x2000);
    }
    t = func_80030154(0x8F);
    for (i = 0x5F; i < 0x66; i++) {
        j = i;
        func_8000A44C(j, t);
    }
    t = func_80030154(0x90);
    for (i = 0x67; i < 0x6E; i++) {
        j = i;
        func_8000A44C(j, t);
    }
    func_8000A44C(0x66, func_80030154(0x8B));
    func_8000A44C(0x6E, func_80030154(0x8D));
    func_8000A44C(0x6F, func_80030154(0x8E));
    func_8000A44C(0x70, func_80030154(0x8C));
    for (i = 0x5F; i != 0x71; i++) {
        j = i;
        func_8000AC34(j, 0x2000);
        func_8000AC34(j, 0x8000);
    }
}
