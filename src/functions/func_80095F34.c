/* Recovered from specification specs/func_80095F34.md (shape rework, worker shape_04). */
#include "podcruise/types.h"

typedef struct Cmd80095F34 {
    /* 0x00 */ u32 w0;
    /* 0x04 */ u32 w1;
} Cmd80095F34;

typedef struct Step80095F34 {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 unk18[0x8];
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
} Step80095F34;

typedef struct Wave80095F34 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 unk08[0x10];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C[0x8];
    /* 0x24 */ Step80095F34 *unk24;
} Wave80095F34;

typedef struct Port80095F34 {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ s32 unk18;
} Port80095F34;

extern f32 func_80095AC0(Wave80095F34 *wave, s32 steps);
extern Cmd80095F34 *func_80095DA8(Port80095F34 *port, u32 pos, u32 arg2, u32 count, Cmd80095F34 *cmd);
extern u32 func_80088360(u32 address);

Cmd80095F34 *func_80095F34(Port80095F34 *port, Wave80095F34 *wave, u32 arg2, s32 arg3, Cmd80095F34 *cmd) {
    Cmd80095F34 *result;
    f32 pos;
    f32 value;
    s32 offset;
    s32 aligned;
    s32 whole;
    f32 frac;
    s32 padA[2];
    s32 length;
    Cmd80095F34 *out;
    Cmd80095F34 *next;

    (void)padA;
    if (wave->unk24 != 0) {
        length = wave->unk04 - wave->unk00;
        value = func_80095AC0(wave, arg3) / (f32)length;
        value = (f32)(s32)(value * 32768.0f) / 32768.0f;
        frac = 1.0 - value;
        pos = wave->unk24->unk20 + frac * (f32)arg3;
        whole = (s32)pos;
        wave->unk24->unk20 = pos - (f32)whole;
        offset = port->unk18 + ((-(wave->unk04 - wave->unk18)) * 2);
        aligned = (offset & 7) >> 1;
        out = func_80095DA8(port, offset - (aligned * 2), 0x280, whole + aligned, cmd);
        result = out + 2;
        out->w0 = 0x08000000 | (((aligned * 2) + 0x280) & 0xFFFF);
        next = out + 1; out->w1 = (arg2 << 16) | ((arg3 * 2) & 0xFFFF);
        next->w0 = (0x05000000 | ((wave->unk24->unk24 & 0xFF) << 16)) |
                        ((s32)(frac * 32768.0f) & 0xFFFF);
        next->w1 = func_80088360(wave->unk24->unk14);
        wave->unk24->unk24 = 0;
        wave->unk18 = wave->unk18 + whole - arg3;
    } else {
        result = func_80095DA8(port, port->unk18 + ((-wave->unk04) * 2), arg2, arg3, cmd);
    }
    return result;
}
