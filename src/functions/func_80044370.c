/* Independently written from scratchpad spec specs/func_80044370.md. */

#include "podcruise/types.h"

extern void func_80005B80(void);
extern void func_80008750(s32 arg0);
extern void func_8000A4D8(void);
extern void func_8000AB24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80030304(u32 arg0);
extern void func_80039B70(void);
extern void func_80039CD8(s32 arg0);
extern void func_8003FA24(u32 arg0, s32 *arg1);
extern void func_800442E4(void);
extern void func_80087754(s32 arg0);

void func_80044370(s16 *arg0, s32 arg1) {
    s32 params[16];

    func_800442E4();
    func_80008750(0);
    func_8000AB24(-0x67, 0, 0, 0, 0xFF);
    func_8000A4D8();
    func_80005B80();
    func_80087754(0);
    arg0[3] |= 0x1000;
    func_80039CD8(1);
    func_80039B70();
    params[0] = arg1;
    func_8003FA24(0x416C6C21, params);
    func_80030304(0x5363656E);
}
