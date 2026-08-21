/* Independently written from specs/functions/func_80010014.md. */

#include "podcruise/types.h"

extern s32 D_800D5F80[];
extern s32 D_800D5FA8[];

void func_80010014(s32 index, s32 first, s32 second) {
    if (index < 10) {
        D_800D5F80[index] = first;
        D_800D5FA8[index] = second;
    }
}
