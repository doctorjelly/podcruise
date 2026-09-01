/* Independently written from scratchpad spec specs/func_80028E78.md. */

#include "podcruise/types.h"

extern f32 D_800A25FC;
extern s16 D_800A2600;
extern s32 D_800A2198;
extern s32 D_800A4BD0;
extern s32 D_800A4BD8;
extern s32 D_800A4BDC;
extern f32 D_800A9DE8;
extern f32 D_80120BF8;

extern void func_8000A920(s16, s32);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern s32 func_8003F800(s32, s32);
extern void func_80060DE4(s32, s32);
extern void func_80039CD8(s32);
extern void func_80039B70(void);
extern void func_800399F0(void);
extern void func_800469B4(s32 *, s32);

s32 func_80028E78(s32 *arg0) {
    f32 level;
    s32 done;
    s32 mode;
    s16 count;

    level = D_800A25FC;
    done = 0;
    D_800A4BD8 = 0;
    if (level >= 255.0f) {
        count = D_800A2600 - 1;
        D_800A2600 = count;
        if (count <= 0) {
            done = 1;
        }
        level = 255.0f;
    } else {
        level = D_800A9DE8 * D_80120BF8 + level;
    }
    if (level > 255.0f) {
        level = 255.0f;
        D_800A2600 = 3;
    }
    D_800A25FC = level;
    func_8000AB24(-0x67, 0, 0, 0, (u32)level);
    if (done != 0) {
        D_800A25FC = 0.0f;
        mode = D_800A2198;
        if (mode != -1) {
            if (mode == 1 && arg0[2] == 0x12) {
                mode = func_8003F800(0x456C6D6F, arg0[16]);
                if (mode != 0) {
                    func_80060DE4(mode, 0);
                }
            }
            D_800A4BDC = 1;
            D_800A4BD0 = 0;
            func_80039CD8(1);
            func_80039B70();
            func_800399F0();
            func_800469B4(arg0, D_800A2198);
            return 0;
        } else {
            func_8000A920(-0x67, 0);
            D_800A4BD8 = 1;
            D_800A4BDC = 0;
            func_80039CD8(1);
            func_80039B70();
            func_800399F0();
            return 1;
        }
    }
    return 0;
}
