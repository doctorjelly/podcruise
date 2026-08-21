/* Implements specification specs/func_8003EA84.md (queued draw-record append). */
#include "podcruise/types.h"

extern s32 D_800A4970;
extern s32 D_800A4978;
extern s32 D_800AAB2C;
extern s32 D_800AAB34;
extern s32 D_800AAB38;
extern s32 D_800AAB40;
extern u8 D_80114550[][128];
extern s16 D_80116550[][2];
extern u8 D_80116650[][4];
extern u8 D_80116750[][128];
extern s16 D_80118750[][2];
extern u8 D_80118850[][4];

extern s32 func_8008A6B4();

void func_8003EA84(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
s16 arg0;
s16 arg1;
u8 arg2;
u8 arg3;
u8 arg4;
u8 arg5;
s32 arg6;
s32 arg7;
s32 arg8;
{
    s32 index;

    if (arg8 == 0) {
        index = D_800A4970;
        if (index < 0x40) {
            if (arg7 >= 0) {
                func_8008A6B4(&D_80114550[index], &D_800AAB2C, arg7, arg6);
            } else {
                func_8008A6B4(&D_80114550[index], &D_800AAB34, arg6);
            }
            index = D_800A4970;
            D_80116550[index][0] = arg0;
            D_80116550[index][1] = arg1;
            D_80116650[index][0] = arg2;
            D_80116650[index][1] = arg3;
            D_80116650[index][2] = arg4;
            D_80116650[index][3] = arg5;
            D_800A4970 = index + 1;
        }
    } else {
        index = D_800A4978;
        if (index < 0x20) {
            if (arg7 >= 0) {
                func_8008A6B4(&D_80116750[index], &D_800AAB38, arg7, arg6);
            } else {
                func_8008A6B4(&D_80116750[index], &D_800AAB40, arg6);
            }
            index = D_800A4978;
            D_80118750[index][0] = arg0;
            D_80118750[index][1] = arg1;
            D_80118850[index][0] = arg2;
            D_80118850[index][1] = arg3;
            D_80118850[index][2] = arg4;
            D_80118850[index][3] = arg5;
            D_800A4978 = index + 1;
        }
    }
}
