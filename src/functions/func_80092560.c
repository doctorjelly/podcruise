/* Independently written from specs/func_80092560.md. */

#include "podcruise/types.h"

typedef struct Task80092560 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 *unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8 unk10[0x30 - 0x10];
} Task80092560;

extern s32 D_80000300;
extern Task80092560 D_800A7EF0[2];
extern Task80092560 *D_800A7F50;
extern Task80092560 *D_800A7F54;
extern u32 D_800A7FD0[];
extern u32 D_800A8020[];
extern u32 D_800A8070[];

extern void func_80092850(u8 *cursor, s32 length);
extern void func_800941E0(void);

void func_80092560(void) {
    func_80092850((u8 *)D_800A7EF0, 0x60);

    D_800A7F50 = &D_800A7EF0[0];
    D_800A7F54 = &D_800A7EF0[1];
    D_800A7F54->unk02 = 1;
    D_800A7F50->unk02 = 1;
    D_800A7F54->unk04 = 0x80000000;
    D_800A7F50->unk04 = 0x80000000;

    if (D_80000300 == 0) {
        D_800A7F54->unk08 = D_800A7FD0;
    } else if (D_80000300 == 2) {
        D_800A7F54->unk08 = D_800A8020;
    } else {
        D_800A7F54->unk08 = D_800A8070;
    }

    D_800A7F54->unk00 = 0x20;
    D_800A7F54->unk0C = D_800A7F54->unk08[1];

    while (*(u32 *)0xA4400010 >= 0xB) {
    }

    *(u32 *)0xA4400000 = 0;
    func_800941E0();
}
