/* Specification: specs/functions/recovered/func_800928F0.md. */
#include "podcruise/types.h"

extern s32 D_800A7EE0;
extern u8 D_80149CB0;
extern u8 D_8014D720[];

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_800907D0(s32 direction, void *buffer);
extern s32 func_80090880(void *arg0, s32 arg1);
extern void *func_80092250(void *arg0, void *arg1, s32 arg2);
extern s32 func_80093A90(u16 value);
extern u8 func_80093B60(u8 *data);
extern s32 func_80087E80(void *queue, void **out, s32 blocking);

s32 func_800928F0(void *arg0, s32 arg1, u16 arg2, u8 *arg3, s32 arg4) {
    u8 *p;
    s32 status;
    s32 retry;
    s32 check;
    s32 index;

    p = D_8014D720;
    retry = 2;
    if (arg4 != 1 && arg2 < 7 && arg2 != 0) {
        return 0;
    }
    func_800905F0();
    if (D_80149CB0 != 3 || D_800A7EE0 != arg1) {
        D_80149CB0 = 3;
        D_800A7EE0 = arg1;
        index = 0;
        while (index < arg1) {
            index++;
            *p++ = 0;
        }
        p[0] = 0xFF;
        p[1] = 0x23;
        p[2] = *(s32 *)&D_8014D720[0x3C] = 1;
        p[3] = 3;
        p[0x26] = 0xFF;
        p[0x27] = 0xFE;
    } else {
        p = &D_8014D720[arg1];
    }
    p[4] = arg2 >> 3;
    p[5] = func_80093A90(arg2) | (arg2 << 5);
    func_80092250(arg3, &p[6], 0x20);
    func_800907D0(1, D_8014D720);
    check = func_80093B60(arg3) & 0xFF;
    func_80087E80(arg0, 0, 1);
    do {
        func_800907D0(0, D_8014D720);
        func_80087E80(arg0, 0, 1);
        status = (p[2] & 0xC0) >> 4;
        if (status == 0) {
            if (check != p[0x26]) {
                status = func_80090880(arg0, arg1);
                if (status != 0) {
                    break;
                }
                status = 4;
            }
        } else {
            status = 1;
        }
    } while (status == 4 && retry-- >= 0);
    func_80090634();
    return status;
}
