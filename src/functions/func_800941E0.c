/* Implements specs/functions/recovered/remaining_medium_audit_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 origin;
    /* 0x04 */ u32 yScale;
    /* 0x08 */ u32 vStart;
    /* 0x0C */ u32 vBurst;
    /* 0x10 */ u32 vIntr;
} ViFieldRegs;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 width;
    /* 0x0C */ u32 burst;
    /* 0x10 */ u32 vSync;
    /* 0x14 */ u32 hSync;
    /* 0x18 */ u32 leap;
    /* 0x1C */ u32 hStart;
    /* 0x20 */ u32 xScale;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ ViFieldRegs fldRegs[2];
} ViMode;

typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ u32 framep;
    /* 0x08 */ ViMode *modep;
    /* 0x0C */ u32 control;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 xScale;
    /* 0x24 */ f32 yScaleFactor;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ u16 unk2A;
    /* 0x2C */ u32 yScale;
} ViContext;

extern s32 D_800A7B7C;
extern ViContext *D_800A7F50;
extern ViContext *D_800A7F54;
extern u32 func_80088360(u32);

void func_800941E0(void) {
    ViContext *next;
    ViMode *mode;
    u32 field;
    u32 origin;
    u32 hStart;
    u32 vStart;
    u32 physical;
    ViFieldRegs *fld;

    next = D_800A7F54;
    field = *(u32 *)0xA4400010 & 1;
    mode = next->modep;
    physical = func_80088360(next->framep);
    fld = &mode->fldRegs[field];
    origin = fld->origin + physical;

    if (next->state & 2) {
        next->xScale |= mode->xScale & ~0xFFF;
    } else {
        next->xScale = mode->xScale;
    }

    if (next->state & 4) {
        next->yScale = (u32)(next->yScaleFactor * (f32)(mode->fldRegs[field].yScale & 0xFFF));
        next->yScale |= mode->fldRegs[field].yScale & ~0xFFF;
    } else {
        next->yScale = mode->fldRegs[field].yScale;
    }

    vStart = mode->fldRegs[field].vStart - (D_800A7B7C << 16) + D_800A7B7C;

    hStart = mode->hStart;
    if (next->state & 0x20) {
        hStart = 0;
    }
    if (next->state & 0x40) {
        next->yScale = 0;
        origin = func_80088360(next->framep);
    }
    if (next->state & 0x80) {
        next->yScale = ((u32)next->unk28 << 16) & 0x3FF0000;
        origin = func_80088360(next->framep);
    }

    *(u32 *)0xA4400004 = origin;
    *(u32 *)0xA4400008 = mode->width;
    *(u32 *)0xA4400014 = mode->burst;
    *(u32 *)0xA4400018 = mode->vSync;
    *(u32 *)0xA440001C = mode->hSync;
    *(u32 *)0xA4400020 = mode->leap;
    *(u32 *)0xA4400024 = hStart;
    *(u32 *)0xA4400028 = vStart;
    *(u32 *)0xA440002C = mode->fldRegs[field].vBurst;
    *(u32 *)0xA440000C = mode->fldRegs[field].vIntr;
    *(u32 *)0xA4400030 = next->xScale;
    *(u32 *)0xA4400034 = next->yScale;
    *(u32 *)0xA4400000 = next->control;

    D_800A7F54 = D_800A7F50;
    D_800A7F50 = next;
    *D_800A7F54 = *D_800A7F50;
}
