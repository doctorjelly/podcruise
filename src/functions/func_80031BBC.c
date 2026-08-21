/* Independently written from scratchpad spec specs/func_80031BBC.md. */

#include "podcruise/types.h"

extern void func_80031640(s32 index);

extern s32 D_800A290C[];

void func_80031BBC(s32 index) {
    D_800A290C[index] = -1;
    func_80031640(index);
}
