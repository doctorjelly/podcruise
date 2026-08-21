/* Recovered from specification $S/specs/func_80092050.md */
#include "podcruise/types.h"

typedef struct Ctx80092050 {
    u8 buffer[0x3C];
    s32 unk3C;
} Ctx80092050;

extern s32 D_800A7EE0;
extern u8 D_80149CB0;
extern Ctx80092050 D_8014D720;

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_80093A90(u16);
extern void func_800907D0(s32, Ctx80092050 *);
extern void func_80087E80(void *, s32, s32);
extern s32 func_80093B60(u8 *);
extern void func_80092250(u8 *, void *, s32);
extern s32 func_80090880(void *, s32);

s32 func_80092050(void *arg0, s32 arg1, u16 arg2, void *arg3);

s32 func_80092050(void *arg0, s32 arg1, u16 arg2, void *arg3) {
    u8 *p;
    s32 retry;
    s32 status;
    s32 i;

    p = D_8014D720.buffer;
    retry = 2;
    func_800905F0();
    if ((D_80149CB0 != 2) || (arg1 != D_800A7EE0)) {
        D_80149CB0 = 2;
        D_800A7EE0 = arg1;
        for (i = 0; i < arg1; i++) {
            *p = 0; p++;
        }
        D_8014D720.unk3C = 1;
        p[0] = 0xFF;
        p[1] = 3;
        p[2] = 0x21;
        p[3] = 2;
        p[0x26] = 0xFF;
        p[0x27] = 0xFE;
    } else {
        p = &D_8014D720.buffer[arg1];
    }
    p[4] = arg2 >> 3;
    p[5] = func_80093A90(arg2) | (arg2 << 5);
    func_800907D0(1, &D_8014D720);
    func_80087E80(arg0, 0, 1);
    for (;;) {
        func_800907D0(0, &D_8014D720);
        func_80087E80(arg0, 0, 1);
        status = (p[2] & 0xC0) >> 4;
        if (status == 0) {
            if (func_80093B60(&p[6]) != p[0x26]) {
                status = func_80090880(arg0, arg1);
                if (status != 0) {
                    break;
                }
                status = 4;
            } else {
                func_80092250(&p[6], arg3, 0x20);
            }
        } else {
            status = 1;
        }
        if (status != 4) {
            break;
        }
        if (retry-- < 0) {
            break;
        }
    }
    func_80090634();
    return status;
}
