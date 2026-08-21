/* Independently written from specs/func_8008C190.md (worker scratchpad). */

#include "podcruise/types.h"

extern u8 D_80149CB8[];
extern u8 D_80149CD8[];
extern u8 D_80149CF0[];

extern s32 func_80094ED0(void *arg0, u8 arg1, u8 *arg2);
extern s32 func_800906F0(void *arg0, long long arg1, long long arg2, void *arg3,
                         void *arg4);
extern s32 func_80087E80(void *arg0, s32 arg1, s32 arg2);

s32 func_8008C190(arg0, arg1, arg2, arg3)
void *arg0;
u8 arg1;
u8 *arg2;
s32 arg3;
{
    s32 result;

    result = 0;
    while (arg3 > 0) {
        result = func_80094ED0(arg0, arg1, arg2);
        if (result != 0) {
            return result;
        }
        arg3 -= 8;
        arg1 += 1;
        arg2 += 8;
        func_800906F0(D_80149CB8, 0x89544, 0, D_80149CD8, D_80149CF0);
        func_80087E80(D_80149CD8, 0, 1);
    }
    return result;
}
