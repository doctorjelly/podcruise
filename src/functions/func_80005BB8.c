/* Independently written from scratchpad spec specs/func_80005BB8.md. */

#include "podcruise/types.h"

typedef struct PcAttachment {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ u16 unk0C;
} PcAttachment;

typedef struct PcEntity {
    /* 0x000 */ u8 unk000[0xDC];
    /* 0x0DC */ f32 unk0DC;
    /* 0x0E0 */ u8 unk0E0[0x10];
    /* 0x0F0 */ f32 unk0F0;
    /* 0x0F4 */ f32 unk0F4;
    /* 0x0F8 */ f32 unk0F8;
    /* 0x0FC */ f32 unk0FC;
    /* 0x100 */ u32 unk100;
    /* 0x104 */ u8 unk104[4];
    /* 0x108 */ f32 unk108;
    /* 0x10C */ f32 unk10C;
    /* 0x110 */ u8 unk110[0x14];
    /* 0x124 */ PcAttachment *unk124;
} PcEntity;

extern s32 D_8009A2A0;
extern PcEntity *D_800AF4C0[300];

void func_80005BB8(PcEntity *entity) {
    PcAttachment *attachment;

    D_800AF4C0[D_8009A2A0] = entity;
    D_8009A2A0 = D_8009A2A0 + 1;

    entity->unk0F0 = 0.0f;
    if (entity->unk100 & 0x20) {
        entity->unk0F4 = entity->unk10C;
    } else {
        entity->unk0F4 = entity->unk108;
    }
    entity->unk0DC = 0.0f;
    entity->unk0F8 = entity->unk0F4;
    entity->unk0FC = entity->unk0F4;

    if ((entity->unk100 & 0xF) == 8) {
        attachment = entity->unk124;
        if (attachment != 0) {
            attachment->unk0C = attachment->unk0C & 0xFFF7;
        }
    }
    entity->unk100 = entity->unk100 | 0x1000000;
}
