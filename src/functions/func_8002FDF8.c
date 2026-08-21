/* Recovered per specs/func_8002FDF8.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s16 unk20;
} View8002FDF8;

extern View8002FDF8 D_800D6960;

extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_80038DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_8002FDF8(void) {
    D_800D6960.unk00 = 0.0f;
    D_800D6960.unk04 = 0.0f;
    D_800D6960.unk08 = 0.0f;
    D_800D6960.unk0C = 0.0f;
    D_800D6960.unk10 = 0.0f;
    D_800D6960.unk14 = 0.0f;
    D_800D6960.unk18 = 0;
    D_800D6960.unk20 = 2;
    func_8000AB24(-0x67, 0, 0, 0, 0xFF);
    func_80038DF8(0x3E4, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
}
