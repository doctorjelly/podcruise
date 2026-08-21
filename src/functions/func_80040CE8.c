/* Independently written from specs/functions/func_80040CE8.md. */

#include "podcruise/types.h"

typedef struct Link40CE8 {
    u8 pad00[0x60];
    u32 unk60;
    u32 unk64;
    u8 pad68[0x140 - 0x68];
    void *unk140;
} Link40CE8;

typedef struct Rec40CE8 {
    s16 unk00;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    s16 unk06;
    s16 unk08;
    u8 pad0A[0x2C - 0x0A];
    u32 unk2C;
    s16 unk30;
    u8 pad32[0x34 - 0x32];
    u32 unk34;
    u32 unk38;
} Rec40CE8;

typedef struct Ctx40CE8 {
    u8 pad00[0xF4];
    Link40CE8 *unkF4;
    u8 padF8[0x2A4 - 0xF8];
    Rec40CE8 *unk2A4;
    u32 unk2A8;
    u32 unk2AC;
    u8 pad2B0[0x2C8 - 0x2B0];
    u32 unk2C8;
    u32 unk2CC;
    u32 unk2D0;
    f32 unk2D4;
    f32 unk2D8;
    u8 pad2DC[0x2E0 - 0x2DC];
    f32 unk2E0;
    u32 unk2E4;
} Ctx40CE8;

extern void func_80008750(u8 value);
extern Rec40CE8 *func_800183A8(const void *object);
extern void func_800401FC(Ctx40CE8 *context, Link40CE8 *link);
extern void func_800408D0(Ctx40CE8 *context, Link40CE8 *link, Rec40CE8 *record);
extern s32 func_80051FF4(void);

void func_80040CE8(Ctx40CE8 *context) {
    Link40CE8 *link;
    s32 pad0;
    Rec40CE8 *record;
    s32 pad1;

    (void)pad0;
    (void)pad1;

    link = context->unkF4;
    context->unk2A8 &= ~0x8;
    if (link == 0) {
        return;
    }

    if (link->unk140 != 0 || (link->unk64 & 0x200000)) {
        if (link->unk140 == 0 && (link->unk64 & 0x200000)) {
            record = context->unk2A4;
        } else {
            record = func_800183A8(link->unk140);
        }

        if (record != 0) {
            if (record->unk2C & 0x800) {
                context->unk2A8 |= 0x8;
            }
        }

        if (record != context->unk2A4 || (link->unk64 & 0x200000)) {
            link->unk64 &= ~0x200000;
            context->unk2A4 = record;
            func_800408D0(context, link, record);
            if (func_80051FF4() < 2) {
                if (record != 0 && (record->unk30 & 1)) {
                    func_80008750(0x7F);
                } else {
                    func_80008750(0);
                }
            }
            if (record != 0) {
                if (record->unk00 & 2) {
                    context->unk2A8 |= 0x4;
                }
                if (record->unk00 & 4) {
                    context->unk2A8 &= ~0x4;
                }
                if (record->unk02 & 2) {
                    context->unk2A8 |= 0x1;
                    context->unk2D8 = (f32)record->unk08;
                    if (func_80051FF4() >= 2) {
                        if (record->unk02 & 1) {
                            if (1200.0f < context->unk2D8) {
                                context->unk2D8 = 1200.0f;
                            }
                            if ((link->unk60 & 0xF) != 2) {
                                context->unk2D4 = context->unk2D8;
                            }
                        }
                    }
                }
                if (record->unk02 & 1) {
                    if (record->unk06 > 0) {
                        context->unk2A8 |= 0x2;
                    } else {
                        context->unk2A8 &= ~0x2;
                    }
                    context->unk2E0 = (f32)record->unk06;
                    if (996.0f < context->unk2E0) {
                        context->unk2E0 = 996.0f;
                    }
                    context->unk2C8 = record->unk03;
                    context->unk2CC = record->unk04;
                    context->unk2D0 = record->unk05;
                }
                context->unk2AC &= ~record->unk34;
                context->unk2AC |= record->unk38;
                context->unk2AC &= ~0xFF;
            }
        }
    }

    if (link->unk60 & 0x30000000) {
        context->unk2E4 |= 0x10;
    } else {
        context->unk2E4 &= ~0x10;
    }
    if (link->unk64 & 0x200000) {
        context->unk2E4 |= 0x40;
    }
    if (context->unk2E4 != 0) {
        func_800401FC(context, link);
    }
    link->unk64 &= ~0x200000;
}
