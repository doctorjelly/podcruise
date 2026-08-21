/* Specification: specs/func_80096BF0.md (worker spec, batch_04) */
#include "podcruise/types.h"


typedef struct {
    /* 0x00 */ s64 value;
    /* 0x08 */ void *sink;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0xC];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u32 unk30;
} Format80096BF0;

extern u8 D_800A80C0[];
extern u8 D_800A80D4[];
typedef struct {
    s64 quot;
    s64 rem;
} DivResult80096BF0;

extern void *func_8008C2F0(void *, const void *, u32);
extern DivResult80096BF0 func_80097E60(s64, s64);

void func_80096BF0(Format80096BF0 *format, s32 conversion) {
    u8 *digits;
    s64 value;
    DivResult80096BF0 parts;
    s32 kind;
    s32 base;
    s32 index;
    s32 width;
    s32 length;
    s32 extra;
    u8 text[24];
    u8 *out;

    out = text;
    kind = conversion & 0xFF;
    if (kind == 0x58) {
        digits = D_800A80D4;
    } else {
        digits = D_800A80C0;
    }

    index = 24;
    base = (kind == 0x6F) ? 8 : ((kind == 0x78 || kind == 0x58) ? 16 : 10);

    value = format->value;
    if (kind == 0x64 || kind == 0x69) {
        if (format->value < 0) {
            value = -value;
        }
    }

    if (value != 0 || format->unk24 != 0) {
        index = 23;
        out[index] = digits[value % base];
    }

    format->value = value / base;
    while (format->value > 0 && index > 0) {
        parts = func_80097E60(format->value, base);
        format->value = parts.quot;
        index--;
        out[index] = digits[parts.rem];
    }

    length = 24 - index;
    format->unk14 = length;
    func_8008C2F0(format->sink, &out[index], length);

    length = format->unk14;
    width = format->unk24;
    if (length < width) {
        format->unk10 = width - length;
    }
    if (width < 0) {
        if ((format->unk30 & 0x14) == 0x10) {
            extra = format->unk28 - format->unk0C - format->unk10 - length;
            if (extra > 0) {
                format->unk10 += extra;
            }
        }
    }
}
