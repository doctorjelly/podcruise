/* Independently written from the specification notes for func_80009704. */

#include "podcruise/types.h"

extern void func_800092EC(s32 owner, s32 handle, s32 detail);

extern s32 D_8009ADE8;
extern s32 D_8009ADEC;
extern s32 D_8009ADF0;

void func_80009704(s32 owner, s32 handle, s32 detail, s32 first, s32 second,
                   s32 third) {
    func_800092EC(owner, handle, detail);
    D_8009ADEC = first;
    D_8009ADF0 = second;
    D_8009ADE8 = third;
}
