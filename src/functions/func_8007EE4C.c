/* Independently written from scratchpad spec specs/func_8007EE4C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *source;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ u8 unk10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} PcAnimPlayer;

extern void func_8003B250(PcAnimPlayer *player, s32 index);

PcAnimPlayer *func_8007EE4C(PcAnimPlayer *player, void *source) {
    player->source = source;
    player->unk20 = 0;
    player->unk24 = 0;
    player->unk28 = 0;
    player->unk2C = 0;
    player->unk04 = 0.0f;
    player->unk0C = 0.0f;
    player->unk08 = 0.0f;
    func_8003B250(player, 0);
    return player;
}
