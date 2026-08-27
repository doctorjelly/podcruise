/* Specification: scratchpad specs/func_800141EC.md (recovered from assignment func_800141F8). */

#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} PcGfxWords;

typedef struct {
    u8 unk00;
    u8 unk01;
    u8 pad02[2];
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
} PcGlyph;

typedef struct {
    s32 unk00;
    s32 pad04[17];
    u32 unk48;
    s32 pad4C[3];
    u8 pad58[2];
    u8 unk5A;
    u8 unk5B;
    PcGlyph *unk5C;
} PcFont;

extern PcGfxWords *D_801217B0;
extern u8 D_800A1CCC[4];
extern PcFont *D_800A1D8C;
extern u8 D_800A1DD0[];
extern s32 D_800D691C;
extern s32 D_800D6920;
extern s32 D_800D6924;
extern s32 D_800D6928;
extern s32 D_800D692C;
extern s32 D_800D6930;
extern s32 D_800D6934;
extern s32 D_800D6938;

extern void func_800125E4(PcFont *font, s32 index);

#define PC_GFX(a, b) { PcGfxWords *_g = D_801217B0++; _g->w0 = (u32)(a); _g->w1 = (u32)(b); }

void func_800141EC(character)
u8 character;
{
    register PcFont *font;
    PcGlyph *glyph;
    s32 index;
    s32 result;

    PC_GFX(0xFA000000, ((D_800A1CCC[0] & 0xFF) << 24) | ((D_800A1CCC[1] & 0xFF) << 16) | ((D_800A1CCC[2] & 0xFF) << 8) | (D_800A1CCC[3] & 0xFF));
    D_800D6938 = 1;
    PC_GFX(0xFCFF97FF, 0xFF2DFEFF);

    font = D_800A1D8C;
    if (font->unk00 == 0) {
        PC_GFX(0xE3001001, 0xC000);
        PC_GFX(0xFD100000, (u32)(unsigned long)&D_800A1DD0[0]);
        PC_GFX(0xE8000000, 0);
        PC_GFX(0xF5000100, 0x07000000);
        PC_GFX(0xE6000000, 0);
        PC_GFX(0xF0000000, 0x073FC000);
        PC_GFX(0xE7000000, 0);
        font = D_800A1D8C;
    }

    if (font->unk00 == 2) {
        PC_GFX(0xE3001001, 0x8000);
        PC_GFX(0xFD100000, D_800A1D8C->unk48);
        PC_GFX(0xE8000000, 0);
        PC_GFX(0xF5000100, 0x07000000);
        PC_GFX(0xE6000000, 0);
        PC_GFX(0xF0000000, 0x0703C000);
        PC_GFX(0xE7000000, 0);
        PC_GFX(0xE6000000, 0);
        font = D_800A1D8C;
    }

    if ((character >= 0x61) && (character < 0x7B) && (font->unk5B < 0x61)) {
        character -= 0x20;
    }

    result = (s32)(long)font->unk5C;
    if ((result != 0) && (character >= font->unk5A) && (font->unk5B >= character)) {
        index = character - font->unk5A;
        glyph = &((PcGlyph *)(long)result)[index];
        if (glyph->unk08 == -1) {
            result = -2;
        } else {
            result = glyph->unk00;
            D_800D691C = glyph->unk06;
            D_800D6920 = glyph->unk04;
            D_800D6924 = glyph->unk0C;
            D_800D6928 = glyph->unk0E;
            D_800D692C = glyph->unk08;
            D_800D6930 = glyph->unk0A;
            if (font->unk00 == 0) {
                D_800D6934 = glyph->unk01;
            } else {
                D_800D6934 = 0;
            }
        }
    } else {
        result = -2;
    }

    if (result >= 0) {
        func_800125E4(font, result);
    }
}
