/* Recovered per specs/func_80031944.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s32 unk18;
} Entry80031944;

extern Entry80031944 D_800DB8A0[];
extern s32 D_800DB910[];
extern void func_80031924(s32);

s32 func_80031944(s32 index, s32 value) {
    D_800DB8A0[index].unk18 = value;
    if (value == 0) {
        D_800DB8A0[index].unk10 = 0;
    } else {
        D_800DB8A0[index].unk10 = 1;
        D_800DB8A0[index].unk00 = 0;
        D_800DB8A0[index].unk04 = 0;
        D_800DB8A0[index].unk06 = 0x8000;
        D_800DB8A0[index].unk08 = 0;
        D_800DB8A0[index].unk0A = 0;
        D_800DB8A0[index].unk0C = 0;
        D_800DB8A0[index].unk14 = 0;
        D_800DB8A0[index].unk16 = 0;
    }
    func_80031924(index);
    D_800DB910[index] = 0;
    return 0;
}
