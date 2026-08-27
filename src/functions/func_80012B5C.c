/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[5];
    s16 unkE;
} Glyph;

typedef struct {
    u8 pad0[0x5A];
    u8 first;
    u8 last;
    Glyph *glyphs;
} Font;

void func_80012B5C(c, font, outWidth, outHeight)
u8 c;
Font *font;
s32 *outWidth;
s32 *outHeight;
{
    s32 width;
    s32 height;
    Glyph *glyph;

    if (outWidth != 0) {
        *outWidth = -1;
    }
    if (outHeight != 0) {
        *outHeight = -1;
    }
    if (font->glyphs != 0) {
        if (c >= font->first && c <= font->last) {
            glyph = (Glyph *)((u8 *)&font->glyphs[c] + (font->first * -16));
            width = glyph->unk2;
            height = glyph->unkE;
        }
    }
    if (outWidth != 0) {
        *outWidth = width;
    }
    if (outHeight != 0) {
        *outHeight = height;
    }
}
