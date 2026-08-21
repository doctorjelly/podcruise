/* Independently written from scratchpad spec specs/func_8004F358.md. */

#include "podcruise/types.h"

typedef struct Entry8004F358 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0A */ u8 unk0A[2];
} Entry8004F358;

typedef struct Table8004F358 {
    /* 0x000 */ u8 unk000[8];
    /* 0x008 */ s32 unk008;
    /* 0x00C */ u8 unk00C[0xC4 - 0xC];
    /* 0x0C4 */ f32 unk0C4[25][2];
    /* 0x18C */ f32 unk18C[25][2];
    /* 0x254 */ u8 unk254[0x380 - 0x254];
    /* 0x380 */ u8 unk380[25][2];
} Table8004F358;

typedef struct Owner8004F358 {
    /* 0x00 */ u8 unk00[0x5D];
    /* 0x5D */ s8 unk5D;
    /* 0x5E */ u8 unk5E[0x64 - 0x5E];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s8 unk6C;
    /* 0x6D */ s8 unk6D;
    /* 0x6E */ s8 unk6E;
    /* 0x6F */ s8 unk6F;
    /* 0x70 */ s8 unk70;
    /* 0x71 */ s8 unk71;
    /* 0x72 */ u8 unk72[0x8E - 0x72];
    /* 0x8E */ s8 unk8E;
    /* 0x8F */ s8 unk8F;
} Owner8004F358;

typedef struct Message8004F358 {
    /* 0x00 */ u32 tag;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
} Message8004F358;

extern Entry8004F358 D_800A21B8[];
extern u8 D_800A4BFC;
extern s32 D_800A5998;
extern Table8004F358 D_80113680;
extern s8 D_80119668[];

extern void func_8002FA00(s32 arg0);
extern void func_80030298(u32 arg0, s32 arg1);
extern void func_80039EC0(s32 arg0);
extern void func_8003FA24(u32 arg0, u32 *arg1);
extern void func_8004F254(Owner8004F358 *arg0);
extern void func_8004F6E8(Owner8004F358 *arg0);
extern s32 func_8004F790(Owner8004F358 *arg0, s32 arg1);
extern void func_8004FF7C(void);
extern s32 func_80082BE0(void);

void func_8004F358(Owner8004F358 *arg0, s32 arg1, s32 arg2) {
    Message8004F358 message;

    (void)arg2;
    func_8004FF7C();
    func_8004F6E8(arg0);

    if (arg0->unk64 == 2) {
        arg0->unk70 = 1;
        arg0->unk71 = 3;
        do {
            arg0->unk5D = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 25.0f);
        } while ((arg0->unk5D == 19) || (D_800A21B8[arg0->unk5D].unk00 == -1) ||
                 (D_800A21B8[arg0->unk5D].unk08 != 0));
    }

    if (D_800A5998 != 0) {
        arg0->unk64 = 1;
        arg0->unk5D = D_80119668[D_800A4BFC];
        D_80113680.unk008 |= 0x40;
    }

    message.unk04 = func_8004F790(arg0, arg1);
    message.unk08 = arg0->unk71;
    if (arg0->unk64 == 2) {
        message.unk08 = 3;
    } else if (D_800A5998 != 0) {
        message.unk08 = 2;
    }
    message.unk0C = D_800A21B8[arg0->unk5D].unk09;
    message.unk10 = D_800A21B8[arg0->unk5D].unk00;
    message.unk14 = D_800A21B8[arg0->unk5D].unk04;
    message.unk18 = -1;
    message.unk1C = D_800A21B8[arg0->unk5D].unk08;
    message.unk20 = 0;
    if (arg0->unk64 == 2) {
        message.unk20 = 30;
    } else if (D_800A5998 != 0) {
        message.unk20 = 1000000;
    }
    message.unk24 = arg0->unk8E;
    if (arg0->unk6C != 0) {
        message.unk24 = 3;
    }
    message.unk28 = D_80113680.unk18C[arg0->unk5D][arg0->unk6E];
    message.unk2C = D_80113680.unk0C4[arg0->unk5D][arg0->unk6E];
    message.unk30 = arg0->unk8F - 2;
    if (arg0->unk6C != 0) {
        message.unk30 = 0;
    }
    message.unk34 = arg0->unk6E;
    message.unk38 = D_80113680.unk380[arg0->unk5D][arg0->unk6E];
    if ((D_800A21B8[arg0->unk5D].unk00 == -1) || (D_800A21B8[arg0->unk5D].unk04 == -1)) {
        message.unk0C = D_800A21B8[16].unk09;
        message.unk10 = D_800A21B8[16].unk00;
        message.unk14 = D_800A21B8[16].unk04;
        message.unk1C = D_800A21B8[16].unk08;
    }
    message.tag = 0x4265676E;

    if (arg0->unk68 < 0) {
        func_80039EC0(D_800A21B8[arg0->unk5D].unk09 + 8);
        func_8003FA24(0x4A646765, &message.tag);
        func_8004F254(arg0);
    } else {
        func_8002FA00(1);
        func_80030298(0x5363656E, 1);
        message.unk04 = arg0->unk68;
        func_8003FA24(0x5363656E, &message.tag);
    }
}
