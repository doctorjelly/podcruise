/* Recovered from specification $S/specs/func_800374C4.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 w0;
    /* 0x4 */ u32 w1;
} Gfx800374C4;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u8 unk06[8];
    /* 0x0E */ u8 unk0E[8];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u8 unk20[6];
    /* 0x26 */ u8 unk26[4];
    /* 0x2A */ u8 unk2A[4];
    /* 0x2E */ u8 unk2E[4];
} Mat800374C4;

typedef struct {
    /* 0x00 */ u8 unk00[0x20];
} Light800374C4;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ Mat800374C4 *unk0C;
} Sub800374C4;

typedef struct {
    /* 0x00 */ Sub800374C4 *unk00;
    /* 0x04 */ u8 pad04[4];
    /* 0x08 */ f32 unk08[8];
    /* 0x28 */ void *unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8 pad38[6];
    /* 0x3E */ s16 unk3E;
} Item800374C4;

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ Item800374C4 **unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x10];
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u32 unk38;
} Ctx800374C4;

extern s32 D_800A3D3C;
extern s32 D_800A3D60;
extern s32 D_800A3D64;
extern Mat800374C4 D_800A3D68;
extern s32 D_800A3FE8;
extern s32 D_800A3FF4;
extern s32 D_800A3FF8;
extern u32 D_800D697C;
extern Gfx800374C4 *D_80112C90;
extern Light800374C4 D_80112C98[];
extern u32 D_80112DD8;
extern Mat800374C4 D_80112DE0;
extern s32 D_80112E18;
extern s16 D_80112E1C;
extern s16 D_80112E1E;
extern s32 D_801134D0;
extern s32 D_801134D4;

extern void func_800349C4(void);
extern Light800374C4 *func_80033DD0(void);
extern void func_80034DA8(void);
extern void func_80034E20(void);
extern void func_8003527C(void *);
extern void func_800352E4(void);
extern s32 func_800358A0(s32);
extern void func_8003594C(Mat800374C4 *, Sub800374C4 *);
extern void func_80035BF0(Mat800374C4 *, s32);
extern void func_80036314(s32, s16, s16);
extern void func_800366DC(Light800374C4 *);
extern s32 func_80036A1C(f32 *, s32);
extern void func_80036F98(Ctx800374C4 *);

void func_800374C4(Ctx800374C4 *context) {
    s16 count;
    Item800374C4 *item;
    s32 index;
    u32 mode;
    u32 flags;
    u32 chunk;
    Mat800374C4 material;

    if (D_800A3FE8 != 0 && D_800A3FF4 != 0) {
        func_800349C4();
    }

    if (D_800A3D3C == 0) {
        context->unk34 = D_801134D0;
        context->unk38 = D_801134D4;
    }

    if (D_800A3D3C == 0 && D_800A3D64 != 0) {
        count = func_80036A1C((f32 *)&context->unk1C, 1);
    } else {
        count = 2;
    }

    if (count == 0) {
        return;
    }

    if (D_800A3FE8 != 0 && D_800A3FF8 != 0) {
        func_80034DA8();
    }

    if (D_800A3D3C != 0) {
        if (D_800A3D60 != 0) {
            if (!(context->unk10 & 0x40)) {
                func_80036F98(context);
                context->unk10 = context->unk10 | 0x40;
            }
        } else {
            if (!(context->unk10 & 0x20)) {
                func_80036F98(context);
                context->unk10 = context->unk10 | 0x20;
            }
        }
        if (context->unk10 & 0x80) {
            if (D_800A3D60 != 0) {
                func_800366DC(&D_80112C98[context->unk20]);
            } else {
                func_800366DC(&D_80112C98[context->unk1C]);
            }
        }
        if (D_800A3D60 != 0) {
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w0 = 0xDE000000;
                g->w1 = context->unk38;
            }
        } else {
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w0 = 0xDE000000;
                g->w1 = context->unk34;
            }
        }
        return;
    }

    for (index = 0; index < context->unk14; index++) {
        item = context->unk18[index];
        if (count != 2) {
            if (func_80036A1C(&item->unk08[0], 0) == 0) {
                continue;
            }
        }
        {
            Gfx800374C4 *g;
            g = D_80112C90++;
            g->w1 = 0;
            g->w0 = 0xE7000000;
        }
        chunk = item->unk30;
        mode = D_80112DD8;
        if (item->unk00 != 0) {
            flags = item->unk00->unk00;
            if (flags & 2) {
                mode = mode | 0x10000;
            } else {
                mode = mode & ~0x10000;
            }
            if (flags & 1) {
                mode = mode | 0x20000;
            } else {
                mode = mode & ~0x20000;
            }
            if (flags & 4) {
                mode = mode | 0x200000;
            } else {
                mode = mode & ~0x200000;
            }
            if (flags & 8) {
                mode = mode | 0x400;
            } else {
                mode = mode & ~0x400;
            }
            if (flags & 0x40) {
                mode = mode | 0x200;
            } else {
                mode = mode & ~0x200;
            }
            if (flags & 0x10) {
                mode = mode | 0x40000;
            } else {
                mode = mode & ~0x40000;
            }
            if (flags & 0x20) {
                mode = mode | 0x80000;
            } else {
                mode = mode & ~0x80000;
            }
        }
        mode = func_800358A0(mode);
        if (mode != D_80112DD8) {
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w1 = mode & 0x2F0605;
                g->w0 = 0xD9FFFFFF;
            }
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w0 = (~(~mode & 0x2F0605) & 0xFFFFFF) | 0xD9000000;
                g->w1 = 0;
            }
        }
        if (mode & 0xC0000) {
            func_80034DA8();
            func_800366DC(func_80033DD0());
        }
        D_80112DD8 = mode;
        if (item->unk00 != 0 && item->unk00->unk0C != 0) {
            material = *item->unk00->unk0C;
        } else {
            material = D_800A3D68;
        }
        func_8003594C(&material, item->unk00);
        func_80035BF0(&material, 0);
        D_80112DE0 = material;
        if ((D_800D697C & 0x10) || item->unk00 == 0 || item->unk00->unk08 == 0) {
            D_80112E18 = -1;
            D_80112E1C = 0;
            D_80112E1E = 0;
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w1 = 0;
                g->w0 = 0xD7000000;
            }
        } else if (D_80112E18 == item->unk00->unk08 && (item->unk00->unk00 & 0x4000) == 0 &&
                   item->unk00->unk04 == D_80112E1C &&
                   ((D_80112E1E = item->unk00->unk06), D_80112E1E) == 0) {
            Gfx800374C4 *g;
            g = D_80112C90++;
            g->w1 = 0;
            g->w0 = 0xE7000000;
        } else {
            D_80112E18 = item->unk00->unk08;
            D_80112E1C = item->unk00->unk04;
            D_80112E1E = item->unk00->unk06;
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w1 = 0;
                g->w0 = 0xE7000000;
            }
            func_80036314(D_80112E18, item->unk00->unk04, item->unk00->unk06);
        }
        if (chunk != 0) {
            if (item->unk3E != 0) {
                if (item->unk28 != 0) {
                    func_8003527C(item->unk28);
                } else {
                    func_80034E20();
                }
                {
                    Gfx800374C4 *g;
                    g = D_80112C90++;
                    g->w0 = (((u32)(item->unk3E & 0xFF) << 12) | 0x1000000) |
                            ((u32)(item->unk3E & 0x7F) << 1);
                    g->w1 = item->unk34;
                }
                func_800352E4();
            }
            {
                Gfx800374C4 *g;
                g = D_80112C90++;
                g->w1 = chunk;
                g->w0 = 0xDE000000;
            }
        }
    }
}
