/* Recovered per specs/func_800950F4.md */
#include "podcruise/types.h"

typedef struct {
    u8 b[8];
} Blk8;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Out;

extern s32 D_8014C530[];
extern u8 D_8014C531[];
extern s32 D_8014C570[];
extern u8 D_80149CB0;

extern s32 func_800907D0(s32, void *);
extern s32 func_80087E80(void *, s32, s32);

s32 func_800950F4(void *arg0, Out *arg1) {
    Blk8 blk;
    s32 status[1];
    s32 result;
    s32 i;
    s32 *word;
    s32 n;
    u8 *p;

    word = D_8014C530;
    do {
        *word = 0;
        word++;
    } while (word < D_8014C570);
    D_8014C530[15] = 1;

    p = (u8 *)D_8014C530;
    n = 4;
    for (i = 0; i < n; i++) {
        *p++ = 0;
    }

    blk.b[0] = 0xFF;
    blk.b[1] = 1;
    blk.b[2] = 3;
    blk.b[3] = 0;
    blk.b[4] = 0xFF;
    blk.b[5] = 0xFF;
    blk.b[6] = 0xFF;
    blk.b[7] = 0xFF;

    *(Blk8 *)p = blk;
    p += 8;
    *p = 0xFE;

    func_800907D0(1, D_8014C530);
    func_80087E80(arg0, 0, 1);

    D_80149CB0 = 0xFE;
    status[0] = func_800907D0(0, D_8014C530);
    func_80087E80(arg0, 0, 1);
    p = D_8014C531;
    if (status[0] != 0) {
        return status[0];
    }

    *(u8 *)D_8014C530 = 0;
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    blk = *(Blk8 *)(p + 3);

    arg1->unk3 = (blk.b[2] & 0xC0) >> 4;
    result = arg1->unk3;
    arg1->unk0 = (blk.b[5] << 8) | blk.b[4];
    arg1->unk2 = blk.b[6];
    if (result != 0) {
        return result;
    }
    return 0;
}
