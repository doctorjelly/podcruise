/* Specification: specs/func_8008FA94.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

struct Source;

typedef Gfx *(*BuildFunc)(struct Source *, s32, s32, s32, s32);

typedef struct Source {
    s32 unk0;
    BuildFunc unk4;
} Source;

typedef struct {
    Source *unk0;
    s32 unk4[4];
    u32 unk14;
} Owner;

Gfx *func_8008FA94(Owner *owner, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Gfx *gfx;

    gfx = owner->unk0->unk4(owner->unk0, arg1, arg2, arg3, arg4);
    gfx[0].w1 = (u32)(arg2 * 2) & 0xFFFF; gfx[0].w0 = 0x08000000;
    gfx[1].w0 = 0x0D000000; gfx[1].w1 = 0x04400580;
    gfx[2].w1 = (u32)(arg2 * 4) & 0xFFFF; gfx[2].w0 = 0x08000000;
    gfx[3].w0 = 0x06000000; gfx[3].w1 = owner->unk14;
    return gfx + 4;
}
