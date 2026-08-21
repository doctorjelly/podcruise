/* Implements specs/func_8004A6A4.md (scene teardown and next-state message). */
#include "podcruise/types.h"

typedef struct Unk8004A6A4 {
    /* 0x00 */ u8 pad00[0x38];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 pad3C[0x2C];
    /* 0x68 */ s32 unk68;
} Unk8004A6A4;

extern void func_8000A4D8(void);
extern void func_8000A920(s32 arg0, s32 arg1);
extern void func_80030304(u32 arg0);
extern void func_8003E1D0(void);
extern void func_8003FA24(u32 arg0, u32 *arg1);
extern void func_8003FC94(u32 arg0);
extern void func_80046764(void);
extern void func_8004F358(Unk8004A6A4 *arg0, s32 arg1, s32 arg2);
extern void func_80087754(s32 arg0);

void func_8004A6A4(Unk8004A6A4 *arg0, s32 arg1, s32 arg2) {
    s32 unusedHigh[7];
    u32 message;
    s32 unusedLow[2];

    (void)unusedHigh;
    (void)unusedLow;
    func_8003FC94(0x456C6D6F);
    func_80030304(0x456C6D6F);
    func_8003E1D0();
    func_8000A920(-0x67, 0);
    arg0->unk38 = -1;
    func_8000A4D8();
    func_80046764();
    func_80087754(0);
    func_8004F358(arg0, arg1, arg2);
    message = 0x53746F70;
    func_8003FA24(0x48616E67, &message);
    message = 0x57616B65;
    if (arg0->unk68 < 0) {
        func_8003FA24(0x4A646765, &message);
    } else {
        func_8003FA24(0x5363656E, &message);
    }
}
