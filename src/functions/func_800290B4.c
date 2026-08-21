/* Independently written from the specification for the fade-out step routine. */

#include "podcruise/types.h"

extern f32 D_800A2604;
extern s16 D_800A2608;
extern s32 D_800A260C;
extern s32 D_800A4BD8;
extern s32 D_800A4BDC;
extern f32 D_800A9DEC;
extern f32 D_80120BF8;

extern void func_8000A920(s32, s32);
extern void func_8000AB24(s32, s32, s32, s32, s32);

s32 func_800290A4(void) {
    s32 done;
    s16 count;
    f32 level;

    done = 0;
    if ((D_800A2604 == 255.0f) || (D_800A260C > 0)) {
        func_8000AB24(-0x67, 0, 0, 0, 255);
        D_800A260C = D_800A260C - 1;
        if (D_800A260C > 0) {
            return 0;
        }
    }

    level = D_800A2604;
    if (level <= 0.0f) {
        count = D_800A2608 - 1;
        D_800A2608 = count;
        if (count <= 0) {
            done = 1;
        }
        level = 0.0f;
    } else {
        level -= D_800A9DEC * D_80120BF8;
    }

    if (level < 0.0f) {
        level = 0.0f;
        D_800A2608 = 3;
    }

    D_800A2604 = level;
    func_8000AB24(-0x67, 0, 0, 0, (u32)level);

    if (done != 0) {
        func_8000A920(-0x67, 0);
        D_800A4BD8 = 1;
        D_800A4BDC = 0;
        D_800A260C = 3;
        D_800A2604 = 255.0f;
        return 1;
    }
    return 0;
}
