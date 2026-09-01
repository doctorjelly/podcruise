/* Independently written from specs/functions/recovered/medium_control_tranche.md. */
#include "podcruise/types.h"

typedef struct Obj80062EC8 {
    /* 0x00 */ u8 pad00[0x6];
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x4];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20[3];
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ f32 unk38[3];
    /* 0x44 */ f32 unk44[3];
    /* 0x50 */ f32 unk50[3];
    /* 0x5C */ f32 unk5C[3];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ f32 unk84;
    /* 0x88 */ s32 unk88;
    /* 0x8C */ f32 unk8C;
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ s32 unkB8;
} Obj80062EC8;

extern void func_80015268(f32 *, f32, f32, f32);
extern s32 func_80082BE0(void);

void func_80062EC8(Obj80062EC8 *object, s32 arg1, s32 arg2, s32 arg3) {
    if (object != 0) {
        object->unk06 &= 0xFEFF;
        object->unk30 = arg1;
        object->unk34 = arg2;
        func_80015268(object->unk44, 0.0, 0.0, 0.0);
        func_80015268(object->unk50, 0.0, 0.0, 0.0);
        func_80015268(object->unk5C, 0.0, 0.0, 0.0);
        object->unk88 = -1;
        object->unk08 = arg3;
        object->unk14 = 0;
        object->unk10 = 0.0f;
        object->unk18 = 0.0f;
        object->unk1C = ((f32)func_80082BE0() / (f32)2147483648.0) * 5.0f + 3.0f;
        func_80015268(object->unk20, 0.0, 0.0, 0.0);
        object->unk2C = 0.0f;
        func_80015268(object->unk38, 0.0f, 0.0f, 0.0f);
        object->unk74 = 0.0;
        object->unk7C = 0.0f;
        object->unk8C = 0.0f;
        object->unk90 = 0.0f;
        object->unk98 = 0.0f;
        object->unk9C = 0.0f;
        object->unkA0 = 0;
        object->unkA4 = -1;
        object->unkA8 = 0.0f;
        object->unk68 = 90.0f;
        object->unk6C = 90.0f;
        object->unk70 = 90.0f;
        object->unk78 = 1.0f;
        object->unk94 = 1.0f;
        object->unk80 = -1.0f;
        object->unk84 = -1.0f;
        object->unkAC = ((f32)func_80082BE0() / (f32)2147483648.0) * (f32)2.0 + 3.0f;
        object->unkB0 = 0;
        object->unkB4 = 0;
        object->unkB8 = -1;
    }
}
