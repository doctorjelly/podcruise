/* Specification: scratchpad specs/func_80030FA0.md */
#include "podcruise/types.h"

extern void func_8000AB24(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_80038DF8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

void func_80030FA0(void) {
    func_8000AB24(-0x67, 0, 0, 0, 0xFF);
    func_80038DF8(0x3E4, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
}
