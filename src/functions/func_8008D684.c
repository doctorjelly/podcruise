/* Implements the specification in specs/func_8008D684.md */
#include "podcruise/types.h"

extern void func_80095AA0(void *a, void *b, void *c, s32 d);
extern s32 func_80087FC0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void *func_8008E54C(void *object, s16 *state, s32 count, s32 unused, void *out);
extern void func_8008DEA0(void);

void func_8008D684(u32 *object, s32 (*setup)(void *), s32 arg2) {
    func_80095AA0(object, func_8008E54C, func_8008DEA0, 0);
    object[5] = (u32)(s32)func_80087FC0(0, 0, arg2, 1, 0x20);
    object[6] = (u32)(s32)func_80087FC0(0, 0, arg2, 1, 0x20);
    object[12] = setup(&object[13]);
    object[15] = 0;
    object[16] = 1;
    object[17] = 0;
}
