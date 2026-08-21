/* Recovered from specification $S/specs/func_8005F948.md */
#include "podcruise/types.h"

extern f32 D_800AD090;
extern void func_8003B184(void *, void *, f32);
extern void func_8003B250(void *, s32);

void func_8005F948(u8 *arg0) {
    f32 *temp;

    *(s32 *)(arg0 + 0x54) = 0;
    *(s32 *)(arg0 + 0x58) = 0;
    *(s32 *)(arg0 + 0x5C) = 0;
    *(s32 *)(arg0 + 0x60) = 0;
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x2C);
    *(f32 *)(arg0 + 0x38) = 0.0f;
    *(f32 *)(arg0 + 0x3C) = 0.0f;
    *(f32 *)(arg0 + 0x40) = 0.0f;
    if (*(s32 *)(arg0 + 0x2C) != 0) {
        func_8003B250(arg0 + 0x34, 0);
    }
    temp = (f32 *)(arg0 + 0x34);
    func_8003B184(temp, arg0 + 0x64, 0.0f);
    temp[1] = D_800AD090;
}
