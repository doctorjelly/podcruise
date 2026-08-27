/* Recovered from the specification in specs/func_8002FB90.md (worker notes). */
#include "podcruise/types.h"
extern s32 func_8008A6B4(u8 *destination, u8 *format, s32 value);
extern s32 D_800A285C;
extern u8 D_800A9FD0[];
extern u32 D_800D9DBC;
extern u32 D_800D9DD8[];
void func_8002FB90(void) {
    u8 buffer[76];
    s32 index;
    s32 flag;
    flag = D_800A285C;
    for (index = 1; D_800D9DD8[index] != 0; index++) {
        if (flag != 0) {
            func_8008A6B4(buffer, D_800A9FD0, index);
            flag = D_800A285C;
        }
    }
    if (D_800D9DD8[index - 1] < D_800D9DBC) {
        if (flag != 0) {
            return;
        }
        return;
    }
    while (1) {
    }
}
