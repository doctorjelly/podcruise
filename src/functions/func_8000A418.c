/* Specification: $S/specs/func_8000A418.md */
#include "podcruise/types.h"

extern s32 D_8009B774;
extern void *D_800D3A90[];

void func_8000A418(void *arg0) {
    if (D_8009B774 < 0x40) {
        D_800D3A90[D_8009B774] = arg0;
        D_8009B774 = D_8009B774 + 1;
    }
}
