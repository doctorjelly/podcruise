/* Implements specification $S/specs/func_8008AFBC.md */
#include "podcruise/types.h"

typedef struct Ctx8008AFBC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20[6];
    s32 unk38;
    s32 unk3C;
} Ctx8008AFBC;

typedef struct Task8008AFBC {
    s32 unk0;
    s32 unk4;
    s32 unk8[12];
    s32 unk38;
} Task8008AFBC;

extern Ctx8008AFBC *func_8008AEA0(Task8008AFBC *task);
extern void func_80093900(Ctx8008AFBC *buffer, s32 length);
extern void func_80093980(u32 value);
extern s32 func_80093990(u32 address);
extern s32 func_800939D0(s32 direction, s32 address, s32 buffer, s32 length);
extern s32 func_80093A60(void);

void func_8008AFBC(Task8008AFBC *task) {
    Ctx8008AFBC *ctx;

    ctx = func_8008AEA0(task);
    if (ctx->unk4 & 1) {
        ctx->unk18 = ctx->unk38;
        ctx->unk1C = ctx->unk3C;
        task->unk4 = task->unk4 & ~1;
        if (ctx->unk4 & 4) {
            ctx->unk10 = *(s32 *)(long)((task->unk38 + 0xBFC) | 0xA0000000);
        }
    }
    func_80093900(ctx, 0x40);
    func_80093980(0x2B00);
    while (func_80093990(0x4001000) == -1) {
    }
    while (func_800939D0(1, 0x4000FC0, (s32)(long)ctx, 0x40) == -1) {
    }
    while (func_80093A60() != 0) {
    }
    while (func_800939D0(1, 0x4001000, ctx->unk8, ctx->unkC) == -1) {
    }
}
