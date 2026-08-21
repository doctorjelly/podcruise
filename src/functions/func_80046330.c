/* Recovered from specification specs/func_80046330.md */
#include "podcruise/types.h"

extern void func_80015268(f32 *out, f32 x, f32 y, f32 z);
extern void func_80038DBC(s32 mode);
extern void func_80038DF8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_80086A20(s32 index, f32 *a, f32 *b, f32 *c);

void func_80046330(s32 arg0, s32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    (void)arg0;

    if (arg1 == 0x11 || arg1 == 0x10 || (arg1 >= 9 && arg1 <= 0xF)) {
        func_80038DBC(1);
        func_80038DF8(0x3E4, 0x3E8, 0xC8, 0xEA, 0xE5, 0xFF);
        func_80015268(sp30, 225.0f, 250.0f, 247.0f);
        func_80015268(sp24, 140.0f, -420.0f, -300.0f);
        func_80015268(sp3C, 88.0f, 77.0f, 58.0f);
        func_80086A20(-1, sp3C, sp30, sp24);
    } else if (arg1 == 0x13) {
        func_80038DBC(0);
        func_80015268(sp30, 225.0f, 250.0f, 247.0f);
        func_80015268(sp24, 140.0f, -420.0f, -300.0f);
        func_80015268(sp3C, 88.0f, 77.0f, 58.0f);
        func_80086A20(-1, sp3C, sp30, sp24);
    } else if (arg1 == 0x12) {
        func_80038DBC(1);
        func_80038DF8(0x3E4, 0x3E8, 0xC8, 0xEA, 0xE5, 0xFF);
        func_80015268(sp30, 225.0f, 250.0f, 247.0f);
        func_80015268(sp24, 140.0f, -420.0f, -300.0f);
        func_80015268(sp3C, 88.0f, 77.0f, 58.0f);
        func_80086A20(-1, sp3C, sp30, sp24);
    }
}
