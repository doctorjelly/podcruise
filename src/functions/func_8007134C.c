/* Independently written from specs/functions/recovered/func_8007134C.md. */
#include "podcruise/types.h"

typedef struct Unk8007134CSub {
    /* 0x0000 */ u8 pad0[0x10];
    /* 0x0010 */ u8 unk10;
    /* 0x0011 */ u8 pad11[0x18 - 0x11];
    /* 0x0018 */ s32 *unk18;
} Unk8007134CSub;

typedef struct Unk8007134C {
    /* 0x0000 */ u8 pad0[0x50];
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ f32 unk54;
    /* 0x0058 */ f32 unk58;
    /* 0x005C */ u8 pad5C[0x60 - 0x5C];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u32 unk64;
    /* 0x0068 */ u8 pad68[0xAC - 0x68];
    /* 0x00AC */ f32 unkAC[(0x288 - 0xAC) / 4];
    /* 0x0288 */ f32 unk288[6];
    /* 0x02A0 */ u32 unk2A0[6];
    /* 0x02B8 */ u8 pad2B8[0x30C - 0x2B8];
    /* 0x030C */ f32 unk30C;
    /* 0x0310 */ u8 pad310[0x344 - 0x310];
    /* 0x0344 */ s32 unk344;
    /* 0x0348 */ u8 pad348[0x3C0 - 0x348];
    /* 0x03C0 */ f32 unk3C0[16];
    /* 0x0400 */ f32 unk400[(0x1E70 - 0x400) / 4];
    /* 0x1E70 */ Unk8007134CSub *unk1E70;
} Unk8007134C;

typedef struct Unk8007134CReq {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ Unk8007134C *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ f32 *unk0C;
    /* 0x10 */ f32 *unk10;
    /* 0x14 */ f32 *unk14;
    /* 0x18 */ u8 pad18[0x44 - 0x18];
} Unk8007134CReq;

extern u32 D_80000318;
extern f32 D_800AD884;
extern f32 D_800AD888;
extern f64 D_800AD890;
extern f64 D_800AD898;
extern f32 D_800AD8A0;
extern f32 D_800AD8A4;
extern f64 D_800AD8A8;
extern f64 D_800AD8B0;
extern f32 D_800AD8B8;

extern void func_80008BC4(s32, s32, f32, f32, void *, s32, s32, f32, f32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_8000955C(s32, u32);
extern void func_80031B70(Unk8007134C *, s32);
extern void func_8003B184(void *, void *, f32);
extern void func_8003FA24(s32, void *);
extern void *func_80065810(s32, s32, f32, f32 *, f32);
extern void func_800704A8(Unk8007134C *, f32);
extern void func_80070BBC(Unk8007134C *, void *, s32);
extern void func_80070E98(Unk8007134C *, s32);
extern void func_80075648(Unk8007134C *, s32, f32 *, f32);
extern s32 func_80082BE0(void);

void func_8007134C(Unk8007134C *object, s32 arg1) {
    Unk8007134CReq request;
    f32 position[3];
    f32 matrixB[4][4];
    f32 matrixA[4][4];
    f32 spare[17];
    f32 roll;
    s32 handle;
    f32 limit;
    s32 index;
    s32 sound;
    s32 random;

    (void)spare;

    if ((object->unk60 & 0x80) && !(object->unk64 & 0x04000000)) {
        func_80070E98(object, arg1);
        return;
    }
    if (object->unk60 & 0x4000) {
        return;
    }
    object->unk60 |= 0x4000;
    object->unk60 &= ~0x800000;
    object->unk30C = 10.0f;
    object->unk64 &= ~0x8000;
    object->unk64 &= ~0x10000;
    position[0] = object->unk50;
    position[1] = object->unk54;
    position[2] = object->unk58;
    func_8003B184(object->unkAC, matrixB, 0.0f);
    func_80070BBC(object, matrixB, 1);
    func_800704A8(object, 0.0f);
    func_8003B184(object->unkAC, matrixA, -0.01f);
    request.unk0C = position;
    request.unk10 = matrixB[3];
    request.unk14 = matrixA[3];
    request.unk00 = 0x44657468;
    request.unk04 = object;
    request.unk08 = 0;
    func_8003FA24(0x634D616E, &request);
    func_80065810(3, 0, 3.2f, position, 3.0f);
    if (object->unk344 == 0) {
        func_80075648(object, -1, position, 0.2f);
    } else if (object->unk64 & 0x10000) {
        func_80075648(object, -1, object->unk3C0, 0.2f);
    } else if (object->unk64 & 0x8000) {
        func_80075648(object, -1, object->unk400, 0.2f);
    } else if ((f32)func_80082BE0() / (f32)2147483648.0 < 0.5) {
        func_80075648(object, -1, object->unk3C0, 0.2f);
    } else {
        func_80075648(object, -1, object->unk400, 0.2f);
    }
    roll = (f32)func_80082BE0() / (f32)2147483648.0;
    if (roll < D_800AD884) {
        sound = 0x34;
    } else if (roll < D_800AD888) {
        sound = 0x35;
    } else {
        sound = 0x36;
    }
    random = func_80082BE0();
    func_80008BC4(sound, 7,
                  (f32)((f64)((f32)random / (f32)2147483648.0) * D_800AD890 + D_800AD898),
                  1.0f, position, 0, 0, 10.0f, 500.0f);
    roll = (f32)func_80082BE0() / (f32)2147483648.0;
    if (roll < D_800AD8A0) {
        sound = 0x34;
    } else if (roll < D_800AD8A4) {
        sound = 0x35;
    } else {
        sound = 0x36;
    }
    random = func_80082BE0();
    func_80008BC4(sound, 7,
                  (f32)((f64)((f32)random / (f32)2147483648.0) * D_800AD8A8 + D_800AD8B0),
                  1.0f, position, 0, 0, 10.0f, 500.0f);
    limit = D_800AD8B8;
    for (index = 0; index < 6; index++) {
        object->unk2A0[index] &= ~8;
        if (limit < object->unk288[index]) {
            object->unk288[index] = limit;
        }
    }
    if (object->unk60 & 0x20) {
        func_80031B70(object, 0xC);
        if (D_80000318 >= 0x800000 || (object->unk60 & 0x120) != 0) {
            handle = object->unk1E70->unk18[0];
        } else {
            handle = -1;
        }
        func_800093B0(1, handle, 0xE, 0xE, 0xE, 0xE, 0xE);
        func_8000955C(object->unk1E70->unk10, 0xF0000);
    }
}
