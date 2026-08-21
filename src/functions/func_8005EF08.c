/* Independently written from specification $S/specs/func_8005EF08.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ void **unk18;
} ObjEF08;

typedef struct {
    /* 0x00 */ ObjEF08 *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ void *unk08;
} ResEF08;

typedef struct {
    /* 0x000 */ u8 unk000[0x10];
    /* 0x010 */ void *slots[6];
    /* 0x028 */ void *unk028;
    /* 0x02C */ s32 unk02C;
    /* 0x030 */ void *unk030;
    /* 0x034 */ u8 unk034[0x178];
    /* 0x1AC */ s32 unk1AC;
    /* 0x1B0 */ s32 unk1B0;
    /* 0x1B4 */ u8 unk1B4[0xC];
    /* 0x1C0 */ s32 unk1C0;
} CtxEF08;

extern void *D_8011AC80[];
extern s32 D_8011ACBC;
extern s32 D_8011AC60;
extern s32 D_8011AC74;
extern void *D_8011AC78;
extern s32 D_8011ACC0;
extern s32 D_8011ACD4;
extern void *D_8011ACD8;
extern s32 D_8011ACE0;
extern s32 D_8011AD10;
extern s32 D_8011AD24;
extern void *D_8011AD28;
extern s32 D_8011AD30;
extern s32 D_8011B1D4;
extern s32 D_8011B1D8;
extern s32 D_8011B1DC;
extern s32 D_8011B1E0;
extern s32 D_800A6950;
extern void *D_800A6964;

extern void func_80005B1C(s32 selector, s32 value);
extern void func_80008F28(void);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern void func_80018324(void *object, u32 flags);
extern s32 func_8002FAFC(void);
extern void *func_800305E8(s32 index);
extern void *func_80030964(void *stream);
extern void func_80030B68(s32 *arg0, s32 *arg1, s32 *arg2);
extern void func_8005E1A4(CtxEF08 *ctx, void *arg1, void *arg2);
extern void func_8005EA0C(void);
extern void func_8005EA70(CtxEF08 *ctx);
extern void func_8005EAC0(CtxEF08 *ctx);
extern void func_8005EC18(CtxEF08 *ctx);
extern void func_8005ED70(CtxEF08 *ctx);
extern void func_8005EE18(void *stream);
extern void func_800834DC(void *first, s32 second, s32 third, s32 fourth);
extern void func_80087754(void *arg);
extern void func_800877AC(s32 selector, s32 value);

void func_8005EF08(CtxEF08 *ctx) {
    void **cursor;
    s32 j;
    void *temp;
    ResEF08 *first;
    ResEF08 *second;
    ResEF08 *third;
    ResEF08 *fourth;
    void *entity;
    void **end;
    s32 style;
    s32 flags;
    void *player;

    cursor = D_8011AC80;
    end = (void **)&D_8011ACBC;
    do {
        *cursor = 0;
        cursor++;
    } while (cursor < end);
    func_80018324(&D_8011AC60, 0x5064);
    D_8011AC74 = 0xF;
    D_8011AC78 = &D_8011AC80[0];
    D_8011B1E0 = func_8002FAFC();
    func_80008F28();
    first = func_800305E8(ctx->unk1B0);
    player = func_80030964(first);
    temp = first->unk08;
    D_8011AC80[0] = temp;
    D_8011AC80[3] = first->unk00;
    if (D_800A6950 != 0) {
        D_800A6964 = temp;
    }
    func_80030B68(&D_8011B1D4, &D_8011B1D8, &D_8011B1DC);
    D_8011B1E0 = func_8002FAFC() - D_8011B1E0;
    func_8005EAC0(ctx);
    func_8005EC18(ctx);
    func_8005ED70(ctx);
    func_8005E1A4(ctx, player, first);
    func_8005EE18(first);
    if (ctx->unk1AC == 4 && ctx->unk1C0 == 0) {
        first = func_800305E8(0x119);
        func_80030964(first);
        D_8011AC80[2] = first->unk00;
        if (first->unk00 != 0) {
            func_800181BC(first->unk00, 2, 3, 0x10, 2);
        }
    } else {
        D_8011AC80[2] = 0;
    }
    func_8005EA0C();
    second = func_800305E8(0x72);
    D_8011AC80[9] = second->unk00;
    for (j = 0; j < 6; j++) {
        entity = second->unk00->unk18[j];
        ctx->slots[j] = entity;
        if (entity != 0) {
            func_800181BC(entity, 2, -4, 0x10, 3);
        }
    }
    third = func_800305E8(0x126);
    func_80030964(third);
    entity = third->unk00;
    D_8011AC80[8] = entity;
    if (entity != 0) {
        func_800181BC(entity, 2, -4, 0x10, 3);
    }
    ctx->unk028 = third->unk00;
    fourth = func_800305E8(0x47);
    D_8011AC80[13] = fourth->unk00;
    if (D_8011AC80[13] != 0) {
        func_800181BC(D_8011AC80[13], 2, -4, 0x10, 3);
    }
    fourth = func_800305E8(0x47);
    D_8011AC80[14] = fourth->unk00;
    if (D_8011AC80[14] != 0) {
        func_800181BC(D_8011AC80[14], 2, -4, 0x10, 3);
    }
    ctx->unk030 = D_8011AC80[3];
    func_80018324(&D_8011ACC0, 0x5064);
    D_8011ACD4 = 0;
    D_8011ACD8 = &D_8011ACE0;
    D_8011AC80[10] = &D_8011ACC0;
    func_80018324(&D_8011AD10, 0x5064);
    D_8011AD24 = 0;
    D_8011AD28 = &D_8011AD30;
    D_8011AC80[1] = &D_8011AD10;
    func_8005EA70(ctx);
    func_80087754(&D_8011AC60);
    style = 0x16;
    flags = 0x10;
    if (ctx->unk1C0 == 1) {
        style = 0x26;
        flags = 0x20;
    }
    if (ctx->unk1C0 == 2) {
        style = 0x46;
        flags = 0x40;
    }
    if (ctx->unk1C0 == 3) {
        style = 0x16;
        flags = 0x10;
    }
    func_800877AC(4, -0x100);
    func_800877AC(3, -0x100);
    func_800877AC(6, style);
    func_80005B1C(5, flags | 2);
    func_800834DC(D_8011AC80[3], -1, style, 0);
}
