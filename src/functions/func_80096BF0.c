/* Recovered from specs/functions/recovered/medium_pipeline_tranche.md. */
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

void func_80096BF0(Format80096BF0 *format, u8 conversion) {
    u8 text[24];
    u8 *digits;
    s32 base;
    s32 index;
    u64 llval;
    DivResult80096BF0 qr;

    digits = (conversion == 0x58) ? D_800A80D4 : D_800A80C0;
    base = (conversion == 0x6F) ? 8 : ((conversion != 0x78 && conversion != 0x58) ? 10 : 16);
    index = 24;
    llval = format->value;

    if ((conversion == 0x64 || conversion == 0x69) && format->value < 0) {
        llval = -llval;
    }

    if (llval != 0 || format->unk24 != 0) {
        text[--index] = digits[llval % base];
    }

    format->value = llval / base;

    while (format->value > 0 && index > 0) {
        qr = func_80097E60(format->value, base);
        format->value = qr.quot;
        text[--index] = digits[qr.rem];
    }

    format->unk14 = 24 - index;
    func_8008C2F0(format->sink, &text[index], format->unk14);

    if (format->unk14 < format->unk24) {
        format->unk10 = format->unk24 - format->unk14;
    }
    if (format->unk24 < 0 && (format->unk30 & 0x14) == 0x10) {
        index = format->unk28 - format->unk0C - format->unk10 - format->unk14;
        if (index > 0) {
            format->unk10 += index;
        }
    }
}
