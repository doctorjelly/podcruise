/* Recovered from specification specs/functions/recovered/func_80094C80.md */
#include "podcruise/types.h"

typedef struct Info80094C80 {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Info80094C80;

typedef struct Block80094C80 {
    u8 unk0[12];
} Block80094C80;

extern u8 D_80149CB0;
extern u8 D_8014C530[];

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_800950F4(void *, Info80094C80 *);
extern void func_80094E44(u8);
extern s32 func_800907D0(s32, u8 *);
extern void func_80087E80(void *, void *, s32);

s32 func_80094C80(arg0, arg1, arg2)
void *arg0;
u8 arg1;
u8 *arg2;
{
    s32 status;
    s32 unused;
    u8 *source;
    s32 index;
    Info80094C80 info[1];
    Block80094C80 block;

    (void)unused;
    source = D_8014C530;
    func_800905F0();
    status = func_800950F4(arg0, info);
    if (status == 0) {
        switch (info->unk0 & 0xC000) {
        case 0x8000:
            if (arg1 >= 0x40) {
                status = -1;
            }
            break;
        case 0xC000:
            if ((arg1 + 0) >= 0x100) {
                status = -1;
            }
            break;
        default:
            status = 8;
            break;
        }
    }
    if (status != 0) {
        func_80090634();
        return status;
    }
    {
        while (info->unk2 & 0x80) {
            func_800950F4(arg0, info);
        }
        func_80094E44(arg1);
        func_800907D0(1, D_8014C530);
        func_80087E80(arg0, 0, 1);
        func_800907D0(0, D_8014C530);
        D_80149CB0 = 4;
        func_80087E80(arg0, 0, 1);
        for (index = 0; index < 4; index++) {
            source++;
        }
        block = *(Block80094C80 *)source;
        status = (block.unk0[1] & 0xC0) >> 4;
        if (status == 0) {
            for (index = 0; index < 8; index++) {
                *arg2++ = block.unk0[index + 4];
            }
        }
    }
    func_80090634();
    return status;
}
