/* Recovered per specs/functions/func_80039478.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 unk0D;
    /* 0x0E */ u8 unk0E;
    /* 0x0F */ u8 unk0F;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0xC4 - 0x14];
    /* 0xC4 */ f32 unkC4[25][2];
    /* 0x18C */ f32 unk18C[25][2];
    /* 0x254 */ u8 unk254[25][2][3];
    /* 0x2EA */ u8 unk2EA[25][2][3];
    /* 0x380 */ u8 unk380[25][2];
    /* 0x3B2 */ u8 unk3B2[25][2];
    /* 0x3E4 */ u8 pad3E4[0x3F0 - 0x3E4];
} Struct80039478;

typedef struct {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ s8 unk0A;
    /* 0x0B */ u8 pad0B[1];
} Struct800A21B8;

extern Struct800A21B8 D_800A21B8[];
extern s32 D_800A497C;
extern f32 D_800AAAF8;
extern s32 D_80113680;

extern void func_8003140C(void *, s32, s32);
extern void func_80033DC4(void);
extern void func_80029A3C(s32, s32);
extern s32 func_8003931C(void *);

void func_80039478(Struct80039478 *object) {
    s16 i;
    s16 j;
    s16 k;
    f32 value;

    func_8003140C(object, 0, 0x3F0);
    object->unk04 = 1;
    object->unk05 = 0xE1;
    object->unk06 = 0xC8;
    object->unk07 = 0;
    object->unk08 = 0x13;
    D_800A497C = 0;
    func_80033DC4();
    object->unk10 = 0x22E01;
    object->unk0C = 7;
    object->unk0D = 3;
    object->unk0E = 1;
    object->unk0F = 0;

    value = D_800AAAF8;
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 2; j++) {
            object->unkC4[i][j] = value;
            object->unk18C[i][j] = value;
            for (k = 0; k < 3; k++) {
                object->unk254[i][j][k] = 0x41;
                object->unk2EA[i][j][k] = 0x41;
            }
            object->unk380[i][j] = D_800A21B8[i].unk0A;
            object->unk3B2[i][j] = D_800A21B8[i].unk0A;
        }
    }

    for (i = 0; i < 4; i++) {
        func_80029A3C(1, i);
    }

    D_80113680 = func_8003931C(&D_80113680);
}
