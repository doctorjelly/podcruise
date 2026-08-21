/* Independently written from the specification notes for func_8008D510. */

#include "podcruise/types.h"

extern void func_80095AA0(void *slot, void *first, void *second, s32 tag);
extern void *func_8008FA94(void *, s32, s32, s32, s32);
extern s32 func_8008FA60(s32 *, s32, s32);

void func_8008D510(u8 *record) {
    func_80095AA0(record, (void *)func_8008FA94, (void *)func_8008FA60, 3);
    *(s32 *)(record + 0x14) = 0;
    *(s32 *)(record + 0x18) = 1;
}
