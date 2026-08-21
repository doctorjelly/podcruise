/* Recovered from specification specs/functions/func_80013DC0.md (batch_04). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxWord80013DC0;

typedef struct {
    s32 unk00;
    s32 unk04;
    u8 unk08[0x48 - 0x8];
    u32 unk48;
} Page80013DC0;

extern void func_80011E54(s16 argument);
extern void func_80012BF0(u8 *text, Page80013DC0 *page, s16 index);
extern void func_80087814(s32 left, s32 top, s32 right, s32 bottom);

extern u8 D_800A1CCC[4];
extern s16 D_800A1CD0[2];
extern s16 D_800A1CD4[2];
extern Page80013DC0 *D_800A1D8C;
extern u32 D_800A1DD0;
extern s32 D_800D6910;
extern s16 D_800D6914;
extern s16 D_800D6916;
extern s16 D_800D6918;
extern s16 D_800D691A;
extern GfxWord80013DC0 *D_801217B0;

#define EMIT(a, b) { g = D_801217B0; D_801217B0 = g + 1; g->w0 = (a); g->w1 = (b); }

void func_80013DC0(u8 *text) {
    Page80013DC0 *page;
    GfxWord80013DC0 *g;
    u8 *cursor;
    u8 character;
    u8 *body;
    s16 saved[2];
    register s32 index;

    func_80011E54(0);
    D_800D6918 = 0x3E8;
    D_800D691A = -0x3E8;
    D_800D6910 = 0;

    if (text[0] != 0) {
        cursor = text;
        character = text[0];
        do {
            if ((character == 0x7E) && (cursor[1] == 0x62)) {
                D_800D6910 = 1;
            }
            character = cursor[1];
            cursor++;
        } while ((character != 0) && (D_800D6910 == 0));
    }

    index = 0;
    if ((text[0] == 0x7E) && (text[1] == 0x66)) {
        func_80011E54((s16)(text[2] - 0x30));
        index = 3;
    }

    body = text + index;
    index = 0;
    saved[0] = D_800A1CD0[0];
    saved[1] = D_800A1CD0[1];
    EMIT(0xFA000000, (u32)((D_800A1CCC[0] << 24) | (D_800A1CCC[1] << 16) | (D_800A1CCC[2] << 8) | D_800A1CCC[3]))
    EMIT(0xFCFF97FF, 0xFF2DFEFF)

    page = D_800A1D8C;
    if (page->unk00 == 0) {
        EMIT(0xE3001001, 0xC000)
        EMIT(0xFD100000, (u32)(long)&D_800A1DD0)
        EMIT(0xE8000000, 0)
        EMIT(0xF5000100, 0x07000000)
        EMIT(0xE6000000, 0)
        EMIT(0xF0000000, 0x073FC000)
        EMIT(0xE7000000, 0)
        page = D_800A1D8C;
    }
    if (page->unk00 == 2) {
        EMIT(0xE3001001, 0x8000)
        EMIT(0xFD100000, D_800A1D8C->unk48)
        EMIT(0xE8000000, 0)
        EMIT(0xF5000100, 0x07000000)
        EMIT(0xE6000000, 0)
        EMIT(0xF0000000, 0x0703C000)
        EMIT(0xE7000000, 0)
        EMIT(0xE6000000, 0)
        page = D_800A1D8C;
    }

    while (index < page->unk04) {
        D_800A1CD0[0] = saved[0];
        D_800A1CD0[1] = saved[1];
        func_80012BF0(body, page, (s16)index);
        page = D_800A1D8C;
        index++;
    }

    EMIT(0xE7000000, 0)
    if ((D_800D6918 < D_800D691A) && (D_800D6914 < D_800D6916)) {
        func_80087814(D_800D6918, D_800D6914, D_800D691A, D_800D6916);
    }
    D_800A1CD0[0] = D_800A1CD4[0];
    D_800A1CD0[1] = D_800A1CD4[1];
}
