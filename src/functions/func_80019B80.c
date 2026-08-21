/* Independently written from scratchpad spec specs/func_80019B80.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x68];
    s32 unk68;
} Struct80019B80;

extern void func_8004A6A4(Struct80019B80 *, s32, s32);

void func_80019B80(Struct80019B80 *arg0) {
    s32 flag;

    flag = 1;
    if (arg0->unk68 == 0) {
        flag = 0;
    }
    func_8004A6A4(arg0, flag, 1);
}
