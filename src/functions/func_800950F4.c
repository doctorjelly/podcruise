/* Recovery evidence: specs/functions/recovered/medium_runtime_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    u8 b[8];
} Blk8;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Out;

typedef struct {
    s32 ram[15];
    s32 status;
} Pif;

extern Pif D_8014C530;
extern u8 D_80149CB0;

extern s32 func_800907D0(s32, void *);
extern s32 func_80087E80(void *, s32, s32);

s32 func_800950F4(void *arg0, Out *arg1) {
    s32 status[1];
    s32 i;
    u8 *p;
    Blk8 blk;

    for (i = 0; i < 16; i++) {
        D_8014C530.ram[i] = 0;
    }
    D_8014C530.status = 1;

    p = (u8 *)D_8014C530.ram;
    for (i = 0; i < 4; i++) {
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

    func_800907D0(1, &D_8014C530);
    func_80087E80(arg0, 0, 1);

    D_80149CB0 = 0xFE;
    status[0] = func_800907D0(0, &D_8014C530);
    func_80087E80(arg0, 0, 1);
    if (status[0] != 0) {
        return status[0];
    }

    p = (u8 *)D_8014C530.ram;
    for (i = 0; i < 4; i++) {
        *p++ = 0;
    }
    blk = *(Blk8 *)p;

    arg1->unk3 = (blk.b[2] & 0xC0) >> 4;
    arg1->unk0 = blk.b[4] | (blk.b[5] << 8);
    arg1->unk2 = blk.b[6];
    if (arg1->unk3 != 0) {
        return arg1->unk3;
    }
    return 0;
}
