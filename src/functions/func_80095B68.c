#include "podcruise/types.h"
typedef struct { s16 unk00; s16 unk02; s32 unk04; u8 unk08[0x20]; void *unk28; s32 unk2C; } Sprite;
typedef struct { u32 w0; u32 w1; } GfxWord;
extern u32 func_80088360(void *address);
GfxWord *func_80095B68(Sprite *sprite, s32 arg1, s32 arg2, GfxWord *gfx) {
    GfxWord *next;
    /* The original frame reserves four words and writes only the highest and
       lowest, so two further locals were declared between them. Their types
       are not recoverable; these stand in for the reservation. */
    s32 pad0;
    s32 pad1;
    GfxWord *cmd;

    (void)pad0;
    (void)pad1;
    cmd = gfx;
    next = cmd + 2;
    cmd->w0 = (arg1 & 0xFFFF) | 0x08000000; cmd->w1 = ((arg1 & 0xFFFF) << 16) | ((arg2 * 2) & 0xFFFF);
    cmd[1].w0 = 0x0B000020; cmd[1].w1 = func_80088360(sprite->unk08);
    cmd = next;
    next = cmd + 1;
    cmd->w0 = ((sprite->unk2C & 0xFF) << 16) | 0x0E000000 | (sprite->unk02 & 0xFFFF); cmd->w1 = func_80088360(sprite->unk28);
    sprite->unk2C = 0;
    return next;
}
