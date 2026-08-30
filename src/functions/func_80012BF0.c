/* Independently written from specs/functions/recovered/func_80012BF0.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} DisplayWord80012BF0;

typedef struct {
    u8 texture;
    u8 tile;
    s16 advance;
    s16 y_offset;
    s16 x_offset;
    s16 texture_s;
    s16 texture_t;
    s16 width;
    s16 height;
} Glyph80012BF0;

typedef struct {
    s32 mode;
    s32 texture_count;
    u32 textures[17];
    s16 line_advance;
    u8 pad4E[0xC];
    u8 first_character;
    u8 last_character;
    Glyph80012BF0 *glyphs;
    Glyph80012BF0 *extended_glyphs;
} Font80012BF0;

typedef struct {
    s16 x_offset;
    s16 y_offset;
    s16 width;
    s16 height;
    s16 texture_s;
    s16 texture_t;
    s16 tile;
} GlyphMetrics80012BF0;

extern void func_80011F04(u8 red, u8 green, u8 blue, u8 alpha);
extern void func_80011F38(s16 x, s16 y, s16 x_offset, s16 y_offset,
                         s16 width, s16 height, s16 texture_s,
                         s16 texture_t, s16 tile);
extern void func_800125E4(Font80012BF0 *font, s32 texture_index);
extern s32 func_800129E4(u8 *text, Font80012BF0 *font);

extern s32 D_800A1CA4;
extern u8 D_800A1CA8[];
extern u8 D_800A1CCC[4];
extern s16 D_800A1CD0[2];
extern s16 D_800A1CD4[2];
extern u8 D_800A1CD8[][2];
extern u8 D_800A1D1C[];
extern Font80012BF0 *D_800A1D8C;
extern s32 D_800D6910;
extern DisplayWord80012BF0 *D_801217B0;

#define CURRENT_COLOR \
    (((u32)D_800A1CCC[0] << 24) | ((u32)D_800A1CCC[1] << 16) | \
     ((u32)D_800A1CCC[2] << 8) | (u32)D_800A1CCC[3])

#define EMIT_PRIMITIVE_COLOR(value)                                      \
    do {                                                                 \
        DisplayWord80012BF0 *command = D_801217B0++;                     \
        command->w0 = 0xFA000000;                                        \
        command->w1 = (u32)(value);                                      \
    } while (0)

#define DRAW_GLYPH_AT(px, py, glyph_metrics)                             \
    func_80011F38((s16)(px), (s16)(py), (glyph_metrics).x_offset,        \
                  (glyph_metrics).y_offset, (glyph_metrics).width,       \
                  (glyph_metrics).height, (glyph_metrics).texture_s,     \
                  (glyph_metrics).texture_t, (glyph_metrics).tile)

#define DRAW_EFFECTS_AT(px, py, glyph_metrics)                           \
    do {                                                                 \
        if (outline_enabled != 0) {                                      \
            EMIT_PRIMITIVE_COLOR(D_800A1CCC[3]);                         \
            DRAW_GLYPH_AT((px) - 1, (py) - 1, glyph_metrics);            \
            DRAW_GLYPH_AT((px) + 1, (py) + 1, glyph_metrics);            \
            DRAW_GLYPH_AT((px) + 1, (py) - 1, glyph_metrics);            \
            DRAW_GLYPH_AT((px) - 1, (py) + 1, glyph_metrics);            \
            DRAW_GLYPH_AT((px) - 1, (py), glyph_metrics);                \
            DRAW_GLYPH_AT((px) + 1, (py), glyph_metrics);                \
            DRAW_GLYPH_AT((px), (py) - 1, glyph_metrics);                \
            DRAW_GLYPH_AT((px), (py) + 1, glyph_metrics);                \
            EMIT_PRIMITIVE_COLOR(CURRENT_COLOR);                         \
        } else if (shadow_enabled != 0) {                                \
            EMIT_PRIMITIVE_COLOR(D_800A1CCC[3]);                         \
            DRAW_GLYPH_AT((px) + 1, (py) + 1, glyph_metrics);            \
            EMIT_PRIMITIVE_COLOR(CURRENT_COLOR);                         \
        } else if (cross_enabled != 0) {                                 \
            EMIT_PRIMITIVE_COLOR(D_800A1CCC[3]);                         \
            DRAW_GLYPH_AT((px) - 1, (py), glyph_metrics);                \
            DRAW_GLYPH_AT((px) + 1, (py), glyph_metrics);                \
            DRAW_GLYPH_AT((px), (py) - 1, glyph_metrics);                \
            DRAW_GLYPH_AT((px), (py) + 1, glyph_metrics);                \
            EMIT_PRIMITIVE_COLOR(CURRENT_COLOR);                         \
        }                                                                \
    } while (0)

#define DRAW_DECORATED_AT(px, py, glyph_metrics)                         \
    do {                                                                 \
        DRAW_EFFECTS_AT(px, py, glyph_metrics);                          \
        DRAW_GLYPH_AT(px, py, glyph_metrics);                            \
    } while (0)

#define LOAD_GLYPH_METRICS(destination, source, font)                    \
    do {                                                                 \
        (destination).x_offset = (source)->x_offset;                     \
        (destination).y_offset = (source)->y_offset;                     \
        (destination).width = (source)->width;                           \
        (destination).height = (source)->height;                         \
        (destination).texture_s = (source)->texture_s;                   \
        (destination).texture_t = (source)->texture_t;                   \
        if ((font)->mode == 0) {                                         \
            (destination).tile = (source)->tile;                         \
        } else {                                                         \
            (destination).tile = 0;                                      \
        }                                                                \
    } while (0)

void func_80012BF0(u8 *text, Font80012BF0 *font, s16 texture_index) {
    GlyphMetrics80012BF0 metrics;
    GlyphMetrics80012BF0 deferred_metrics;
    Glyph80012BF0 *glyph;
    u8 *mapping;
    u8 *cursor;
    u8 character;
    u8 control;
    u8 mapped_index;
    u8 *color;
    s16 start_x;
    s16 x;
    s16 y;
    s16 deferred_x;
    s16 deferred_y;
    s16 deferred_texture;
    s16 selected_texture;
    s16 advance;
    s32 cross_enabled;
    s32 outline_enabled;
    s32 shadow_enabled;
    s32 block_index;

    cross_enabled = 0;
    outline_enabled = 0;
    shadow_enabled = 0;
    x = D_800A1CD0[0];
    start_x = x;
    y = D_800A1CD0[1];
    func_800125E4(font, texture_index);
    block_index = 0;
    cursor = text;

    while ((*cursor != 0) && (D_800A1CA4 >= block_index)) {
        character = *cursor;
        if (character == 0x7E) {
            control = cursor[1];
            cursor++;
            switch (control) {
            case 0x63:
                x = start_x - func_800129E4(cursor + 1, D_800A1D8C) / 2;
                D_800A1CD0[0] = x;
                character = 0;
                break;
            case 0x72:
                x = start_x - func_800129E4(cursor + 1, D_800A1D8C);
                D_800A1CD0[0] = x;
                character = 0;
                break;
            case 0x6E:
                x = start_x;
                D_800A1CD0[0] = start_x;
                y += font->line_advance;
                character = 0;
                break;
            case 0x6B:
                cross_enabled = (cross_enabled == 0);
                character = 0;
                break;
            case 0x6F:
                outline_enabled = (outline_enabled == 0);
                character = 0;
                break;
            case 0x70:
                cross_enabled = 0;
                outline_enabled = 0;
                shadow_enabled = 0;
                character = 0;
                break;
            case 0x73:
                shadow_enabled = (shadow_enabled == 0);
                character = 0;
                break;
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
                color = &D_800A1CA8[(control - 0x30) * 3];
                func_80011F04(color[0], color[1], color[2], D_800A1CCC[3]);
                EMIT_PRIMITIVE_COLOR(CURRENT_COLOR);
                character = 0;
                break;
            case 0x62:
                block_index++;
                character = 0;
                break;
            case 0x74:
                character = 0x7E;
                break;
            case 0x7E:
                character = 0;
                break;
            default:
                character = control;
                break;
            }
        }

        if ((D_800D6910 == 0) || (block_index == D_800A1CA4)) {
            advance = 0;
            deferred_texture = -5;

            if ((character >= 0x97) && (font->extended_glyphs != 0)) {
                mapped_index = D_800A1D1C[character - 0x96];
                if (mapped_index != 0xFF) {
                    mapping = D_800A1CD8[mapped_index];
                    if (mapping[0] != 0xFF) {
                        glyph = &font->extended_glyphs[mapping[0]];
                        deferred_y = y;
                        if (glyph->texture_s == -1) {
                            selected_texture = -2;
                            deferred_metrics = metrics;
                        } else {
                            selected_texture = glyph->texture;
                            LOAD_GLYPH_METRICS(metrics, glyph, font);
                            deferred_metrics = metrics;
                        }
                        deferred_texture = selected_texture;
                        deferred_x = x;
                        DRAW_EFFECTS_AT(x, y, metrics);
                        character = mapping[1];
                        if (character == 0xFF) {
                            advance = glyph->advance;
                        }
                    } else {
                        character = mapping[1];
                    }
                    if (character == 0xFF) {
                        character = 0;
                    }
                }
            }

            if (character == 0) {
                selected_texture = -2;
            } else {
                if ((character >= 0x61) && (character < 0x7B) &&
                    (font->last_character < 0x61)) {
                    character -= 0x20;
                }
                if ((font->glyphs != 0) &&
                    (character >= font->first_character) &&
                    (character <= font->last_character)) {
                    glyph = &font->glyphs[character - font->first_character];
                    if (glyph->texture_s == -1) {
                        selected_texture = -2;
                    } else {
                        selected_texture = glyph->texture;
                        LOAD_GLYPH_METRICS(metrics, glyph, font);
                    }
                    advance = glyph->advance;
                } else {
                    selected_texture = -2;
                    advance = 0;
                }
            }

            if ((character != 0) && (selected_texture == texture_index)) {
                DRAW_DECORATED_AT(x, y, metrics);
            }
            if (deferred_texture == texture_index) {
                DRAW_GLYPH_AT(deferred_x, deferred_y, deferred_metrics);
            }
            x += advance;
        }
        cursor++;
    }

    D_800A1CD4[0] = x;
    D_800A1CD4[1] = y;
    D_801217B0->w0 = 0xE7000000;
    D_801217B0->w1 = 0;
    D_801217B0++;
}

#undef LOAD_GLYPH_METRICS
#undef DRAW_DECORATED_AT
#undef DRAW_EFFECTS_AT
#undef DRAW_GLYPH_AT
#undef EMIT_PRIMITIVE_COLOR
#undef CURRENT_COLOR
