/* Implements the specification in specs/func_8003D444.md */
#include "podcruise/types.h"

extern void func_8003D110(void);
extern void func_8003B300(s32, s32, s32, s32);
extern s16 D_80114470[];

void func_8003D444(void) {
    func_8003D110();
    func_8003B300(0, D_80114470[0] - 1, 0, D_80114470[1] - 1);
}
