/* Independently written from scratchpad spec specs/func_80006EC0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0xE0];
    /* 0x0E0 */ f32 unk0E0;
    /* 0x0E4 */ f32 unk0E4;
    /* 0x0E8 */ s32 unk0E8;
    /* 0x0EC */ s32 unk0EC;
    /* 0x0F0 */ u8 unk0F0[0x10];
    /* 0x100 */ s32 unk100;
    /* 0x104 */ u8 unk104[0x10];
    /* 0x114 */ f32 unk114;
    /* 0x118 */ s32 unk118;
} PcTrackHolder;

extern s32 func_80006704(PcTrackHolder *holder);

void func_80006EC0(PcTrackHolder *holder, f32 position, f32 blend) {
    holder->unk100 |= 0x20000000;
    holder->unk0E0 = blend;
    holder->unk0E4 = 0.0f;
    holder->unk0E8 = holder->unk118;
    holder->unk0EC = (s32)holder->unk114;
    holder->unk114 = position;
    holder->unk118 = func_80006704(holder);
}
