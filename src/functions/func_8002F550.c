/* Independently written from specs/functions/recovered/func_8002F550.md. */

#include "podcruise/types.h"

typedef struct {
    u32 words[20];
} Block8002F550;

extern s32 D_80000300;
extern s16 D_800A2830;
extern Block8002F550 D_800A6A60;
extern Block8002F550 D_800A6EC0;
extern Block8002F550 D_800A7320;
extern u8 D_800D7A00[];
extern u8 D_800D9BB0[];
extern u8 D_800D9BD0[];
extern Block8002F550 D_80114488;
extern Block8002F550 D_801144D8;

extern void func_8002F750(void *arg0);
extern void func_8008A2F0(void *regs);
extern void func_8008A3B0(s32 arg0);
extern void func_8008B810(void *object, s32 arg1, void *callback, void *arg3, void *arg4,
                          s32 arg5);
extern void func_8008B960(void *object);
extern void func_8008BAB0(s32 arg0);
extern void func_8008BDC0(s32 arg0, void *arg1, void *arg2, s32 arg3);
extern void func_8008BFB0(void *object, s32 value);

void func_8002F550(void *arg0) {
    Block8002F550 *destination = &D_80114488;

    func_8008BAB0(0xFE);
    switch (D_80000300) {
    case 1:
        D_801144D8 = D_800A6A60;
        break;
    case 2:
        D_801144D8 = D_800A7320;
        break;
    case 0:
        D_801144D8 = D_800A6EC0;
        break;
    }
    *destination = D_801144D8;
    func_8008A2F0(destination);
    func_8008A3B0(1);
    func_8008BDC0(0x96, D_800D9BD0, D_800D9BB0, 8);
    func_8008B810(D_800D7A00, 3, func_8002F750, arg0, D_800D9BB0, 10);
    if (D_800A2830 == 0) {
        func_8008B960(D_800D7A00);
    }
    func_8008BFB0(0, 0);
    while (1) {
    }
}
