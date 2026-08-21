/* Recovered from specification specs/func_800464E8.md (worker batch 12). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x10];
    /* 0x010 */ u8 unk010;
    /* 0x011 */ u8 unk011[0x3F];
    /* 0x050 */ s32 unk050;
    /* 0x054 */ u8 unk054[0x74];
    /* 0x0C8 */ s32 unk0C8;
    /* 0x0CC */ s32 unk0CC;
    /* 0x0D0 */ s32 unk0D0;
    /* 0x0D4 */ u8 unk0D4[0x18];
    /* 0x0EC */ s32 unk0EC[6];
    /* 0x104 */ u8 unk104[0xA64];
    /* 0xB68 */ f32 unkB68;
} Object464E8;

extern void func_8002FA00(s32);
extern void func_80005B80(void);
extern void func_8000A4D8(void);
extern s32 func_80082BE0(void);
extern void func_8004611C(Object464E8 *);
extern void func_80046330(Object464E8 *, s32);
extern void func_800441E0(s32);
extern void func_8002FB90(void);

extern s32 D_800A4B00;
extern s32 D_800A4B04;
extern s32 D_800A4B08;
extern s32 D_800A4B0C;

void func_800464E8(Object464E8 *object, s32 arg1) {
    s32 index;
    s32 scratch[2];
    s32 mode;

    (void)arg1;
    (void)scratch;
    func_8002FA00(2);
    func_80005B80();
    func_8000A4D8();

    object->unk050 = 0;
    object->unk0C8 = 0;
    object->unk0CC = 0;
    object->unk0D0 = 0;
    for (index = 0; index < 6; index++) {
        object->unk0EC[index] = 0;
    }

    if ((f32)func_80082BE0() / 2147483648.0f < 0.5f) {
        mode = 14;
    } else {
        mode = 15;
    }

    D_800A4B00 = 0;
    D_800A4B04 = -1;
    D_800A4B08 = -1;
    D_800A4B0C = -1;
    object->unk010 = 0;

    if (mode == 14) {
        D_800A4B00 = 1;
        D_800A4B08 = 0x114;
        D_800A4B0C = 0x17;
        D_800A4B04 = 1;
    } else if (mode == 15) {
        D_800A4B00 = 1;
        D_800A4B08 = 0x115;
        D_800A4B0C = 0x4E;
        D_800A4B04 = 1;
    }

    func_8004611C(object);
    if (mode == 14) {
        object->unkB68 -= 2.0f;
    }
    func_80046330(object, mode);
    func_800441E0(mode);
    func_8002FB90();
}
