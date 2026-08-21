/* See specs/func_80036314.md (worker specification) for behavior. */
#include "podcruise/types.h"

typedef struct {
    u32 hi;
    u32 lo;
} CommandWord;

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
} Layer;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[8];
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 unk0D;
    /* 0x0E */ u8 unk0E;
    /* 0x0F */ u8 unk0F;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ Layer *unk1C[7];
    /* 0x38 */ u32 unk38;
    /* 0x3C */ u32 unk3C;
} Sprite;

extern CommandWord *D_80112C90;
extern u32 D_80112E14;
extern void func_8003609C(u32, u32 *);

void func_80036314(Sprite *sprite, s16 dx, s16 dy) {
    s32 i;
    Layer **slot;
    CommandWord *cmd;
    Layer *layer;
    s32 mode;
    s32 lod;

    func_8003609C(sprite->unk00, &D_80112E14);
    cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = (0xD7000000 | ((sprite->unk0F & 7) << 11) | ((sprite->unk0E & 7) << 8)) | 2; cmd->lo = ((u32)sprite->unk14 << 16) | ((u32)sprite->unk16 & 0xFFFF);
    if ((sprite->unk00 & 0x100) == 0) {
        mode = (sprite->unk0D == 3) ? 3 : 2;
        lod = (sprite->unk1A < 0x7FF) ? sprite->unk1A : 0x7FF;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xFD000000 | ((sprite->unk0C & 7) << 21) | ((mode & 3) << 19); cmd->lo = sprite->unk38;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF5000000 | ((sprite->unk0C & 7) << 21) | ((mode & 3) << 19); cmd->lo = 0x07000000;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xE6000000; cmd->lo = 0;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF3000000; cmd->lo = 0x07000000 | ((lod & 0xFFF) << 12) | (sprite->unk18 & 0xFFF);
    }
    if (sprite->unk3C != 0) {
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xFD100000; cmd->lo = sprite->unk3C;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xE8000000; cmd->lo = 0;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF5000100; cmd->lo = 0x07000000;
        cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xE6000000; cmd->lo = 0;
        if (sprite->unk0D == 1) {
            cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF0000000; cmd->lo = 0x073FC000;
        } else {
            cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF0000000; cmd->lo = 0x0703C000;
        }
    }
    slot = sprite->unk1C;
    if (slot != 0) {
        for (i = 0; i != 7; i++) {
            layer = *slot;
            if (layer != 0) {
                cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF5000000 | ((sprite->unk0C & 7) << 21) | ((sprite->unk0D & 3) << 19) | ((u32)layer->unk02 << 9) | (layer->unk00 & 0x1FF); cmd->lo = (u32)((i & 7) << 24) | ((layer->unk03 & 3) << 18) | ((layer->unk05 & 0xF) << 14) | ((layer->unk07 & 0xF) << 10) | ((((layer->unk03 & 0xF0) >> 4) & 3) << 8) | ((layer->unk04 & 0xF) << 4) | (layer->unk06 & 0xF);
                cmd = D_80112C90; D_80112C90 = cmd + 1; cmd->hi = 0xF2000000 | (((layer->unk08 + dx) & 0xFFF) << 12) | ((layer->unk0A + dy) & 0xFFF); cmd->lo = (u32)((i & 7) << 24) | (((layer->unk0C + dx) & 0xFFF) << 12) | ((layer->unk0E + dy) & 0xFFF);
            }
            slot++;
        }
    }
}
