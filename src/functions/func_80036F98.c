/* Specification: scratchpad specs/func_80036F98.md (batch_06 worker spec) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 hi;
    /* 0x04 */ u32 lo;
} CommandWord;

typedef struct {
    /* 0x00 */ u32 words[13];
} Params;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ void *unk08;
    /* 0x0C */ Params *unk0C;
} Item;

typedef struct {
    /* 0x00 */ Item *unk00;
    /* 0x04 */ u8 pad04[0x2C];
    /* 0x30 */ u32 unk30;
} Node;

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ Node **unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x10];
    /* 0x34 */ CommandWord *unk34;
    /* 0x38 */ CommandWord *unk38;
} Scene;

typedef struct {
    /* 0x00 */ u8 unk00[0x20];
} Slot;

extern CommandWord *D_800A3D30;
extern s32 D_800A3D38;
extern s32 D_800A3D40;
extern s32 D_800A3D60;
extern Params D_800A3D68;
extern u32 D_800D697C;
extern CommandWord *D_80112C90;
extern Slot D_80112C98[];
extern u32 D_80112DD8;
extern Params D_80112DE0;
extern u32 D_80112E14;
extern void *D_80112E18;

extern s32 func_800358A0(s32);
extern void func_8003594C(Params *, Item *);
extern void func_80035BF0(Params *, s32);
extern void func_80036314(void *, s16, s16);
extern void func_800366DC(Slot *);

#define GFX_PIPESYNC(pkt) { CommandWord *_g = (pkt)++; _g->lo = 0; _g->hi = 0xE7000000; }
#define GFX_SETGEOM(pkt, w) { CommandWord *_g = (pkt)++; _g->lo = (u32)(w); _g->hi = 0xD9FFFFFF; }
#define GFX_CLEARGEOM(pkt, w) { CommandWord *_g = (pkt)++; _g->hi = 0xD9000000 | (~(u32)(w) & 0xFFFFFF); _g->lo = 0; }
#define GFX_NOTEX(pkt) { CommandWord *_g = (pkt)++; _g->lo = 0; _g->hi = 0xD7000000; }
#define GFX_CALLDL(pkt, dl) { CommandWord *_g = (pkt)++; _g->hi = 0xDE000000; _g->lo = (u32)(dl); }
#define GFX_ENDDL(pkt) { CommandWord *_g = (pkt)++; _g->lo = 0; _g->hi = 0xDF000000; }

void func_80036F98(Scene *scene) {
    Node *node;
    Item *item;
    void *tex;
    u32 dl;
    s32 mode;
    u32 flags;
    Params params;
    s32 index;
    CommandWord *saved;

    saved = D_80112C90;
    D_80112C90 = D_800A3D30;
    if (D_800A3D60 != 0) {
        scene->unk38 = D_800A3D30;
    } else {
        scene->unk34 = D_800A3D30;
    }

    for (index = 0; index < scene->unk14; index++) {
        node = scene->unk18[index];
        dl = node->unk30;
        GFX_PIPESYNC(D_80112C90);
        item = node->unk00;
        mode = D_80112DD8;
        if (item != 0) {
            flags = item->unk00;
            if (flags & 2) { mode |= 0x10000; } else { mode &= ~0x10000; }
            if (flags & 1) { mode |= 0x20000; } else { mode &= ~0x20000; }
            if (flags & 4) { mode |= 0x200000; } else { mode &= ~0x200000; }
            if (flags & 8) { mode |= 0x400; } else { mode &= ~0x400; }
            if (flags & 0x40) { mode |= 0x200; } else { mode &= ~0x200; }
            if (flags & 0x10) { mode |= 0x40000; } else { mode &= ~0x40000; }
            if (flags & 0x20) { mode |= 0x80000; } else { mode &= ~0x80000; }
        }
        mode = func_800358A0(mode);
        if (D_800A3D40 != 0 || mode != (s32)D_80112DD8) {
            GFX_SETGEOM(D_80112C90, mode & 0x2F0605);
            GFX_CLEARGEOM(D_80112C90, ~mode & 0x2F0605);
        }
        if (mode & 0xC0000) {
            if (D_800A3D38 < 10) {
                if (D_800A3D60 != 0) {
                    scene->unk20 = D_800A3D38;
                } else {
                    scene->unk1C = D_800A3D38;
                }
                func_800366DC(&D_80112C98[D_800A3D38]);
                scene->unk10 |= 0x80;
                D_800A3D38 = D_800A3D38 + 1;
            }
        }
        D_80112DD8 = mode;
        item = node->unk00;
        if (item == 0 || item->unk0C == 0) {
            params = D_800A3D68;
        } else {
            params = *item->unk0C;
        }
        func_8003594C(&params, node->unk00);
        func_80035BF0(&params, D_800A3D40);
        D_80112DE0 = params;
        if (D_800A3D40 != 0) {
            D_80112E18 = (void *)-1; D_80112E14 = 0xFF;
        }
        if ((D_800D697C & 0x10) == 0 && (item = node->unk00) != 0 && (tex = item->unk08) != 0) {
            if (tex != D_80112E18 || (item->unk00 & 0x4000)) {
                D_80112E18 = tex;
                GFX_PIPESYNC(D_80112C90);
                item = node->unk00;
                func_80036314(D_80112E18, item->unk04, item->unk06);
            } else {
                GFX_PIPESYNC(D_80112C90);
            }
        } else {
            D_80112E18 = (void *)-1;
            GFX_NOTEX(D_80112C90);
        }
        if (dl != 0) {
            GFX_CALLDL(D_80112C90, dl);
        }
    }

    D_800A3D30 = D_80112C90;
    GFX_ENDDL(D_800A3D30);
    D_80112C90 = saved;
    D_800A3D40 = 0;
}
