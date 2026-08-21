/* Implements the specification in specs/func_8000FA2C.md */
#include "podcruise/types.h"

extern void func_8000A920(s32 arg0, s32 arg1);
extern void func_8000AB24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8000EBE8(s32 arg0, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, s32 arg6);
extern void func_8000F0DC(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_8009B814[2];
extern f64 D_800A8698;
extern s32 D_800D5790[2];
extern s32 D_800D5798[2];
extern s32 D_800D57A0[2];
extern s32 D_800D57A8[2];
extern s32 D_800D57B0[2];
extern s32 D_800D57B8[2];
extern s32 D_800D57C8;
extern s32 D_800D57D0[2][3];
extern s32 D_800D76F0;

void func_8000FA2C(s32 arg0) {
    s32 i;
    s32 flag;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;

    func_8000A920(-0x68, 0);
    if (!((D_8009B7D8 & 0x200) && D_8009B7D0 > 0 && (D_800D76F0 & 0x1100) == 0x1100)) {
        D_800D57C8 = 0;
        flag = 0;
        for (i = 0; i < 2; i++) {
            if (D_8009B814[i] >= 0) {
                flag = 1;
                D_800D57B0[i] = D_800D57A0[i];
                D_800D57B8[i] = D_800D57A8[i];
                D_800D57A0[i] = D_800D5790[i]; D_800D57A8[i] = D_800D5798[i];
                func_8000EBE8(arg0, D_800D57D0[i], &sp6C, &sp68, &sp74, &sp70, 1);
                D_800D5790[i] = (s32)sp6C;
                D_800D5798[i] = (s32)sp68;
                func_8000F0DC((s32)sp6C, (s32)sp68, i);
            }
        }
        if (flag != 0) {
            func_8000AB24(-0x68, 0xFF, 0xFF, 0xC8, (u32)(D_800D57C8 * D_800A8698));
        }
    }
}
