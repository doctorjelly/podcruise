/* Specification: scratchpad specs/func_80068410.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ u32 flags;
} Track;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x60];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u32 unk64;
    /* 0x0068 */ u8 pad0068[0x10];
    /* 0x0078 */ f32 unk78;
    /* 0x007C */ f32 unk7C;
    /* 0x0080 */ f32 unk80;
    /* 0x0084 */ f32 unk84;
    /* 0x0088 */ u8 pad0088[0xFC];
    /* 0x0184 */ f32 unk184;
    /* 0x0188 */ u8 pad0188[0x4];
    /* 0x018C */ f32 unk18C;
    /* 0x0190 */ u8 pad0190[0x14];
    /* 0x01A4 */ f32 unk1A4;
    /* 0x01A8 */ u8 pad01A8[0x4];
    /* 0x01AC */ f32 unk1AC;
    /* 0x01B0 */ u8 pad01B0[0x90];
    /* 0x0240 */ f32 unk240;
    /* 0x0244 */ f32 unk244;
    /* 0x0248 */ u8 pad0248[0xB4];
    /* 0x02FC */ f32 unk2FC;
    /* 0x0300 */ u8 pad0300[0x1B70];
    /* 0x1E70 */ Track *unk1E70;
} Racer;

extern f32 D_800AD4EC;
extern f32 D_800AD4F0;
extern f32 D_800AD4F4;
extern f32 D_800AD4F8;
extern f32 D_800AD4FC;
extern f32 D_800AD500;
extern f32 D_800AD504;
extern f32 D_800AD508;
extern f32 D_800AD50C;
extern f32 D_800AD510;
extern f32 D_800AD514;
extern f32 D_800AD518;
extern f32 D_800AD51C;
extern f64 D_80120BF0;

extern f32 func_80081700(f32, f32);

f32 func_80068410(Racer *racer) {
    f32 scale;
    f32 limit;
    f32 amount;
    f32 negated;
    f32 result;

    if ((racer->unk60 & 0x800000) || (racer->unk64 & 0x2000)) {
        scale = 4.0f;
    } else {
        scale = 1.5f;
    }

    if (racer->unk1E70->flags & 8) {
        if (D_800AD4EC < racer->unk18C) {
            racer->unk1A4 = racer->unk1A4 + (f32)D_80120BF0 * racer->unk18C * scale;
            if (D_800AD4F0 <= racer->unk18C) {
                limit = D_800AD4F4;
            } else {
                limit = racer->unk18C / (1.0f - racer->unk18C);
            }
            if (limit < racer->unk1A4) {
                racer->unk1A4 *= func_80081700(racer->unk84, (f32)D_80120BF0);
            }
        } else if (racer->unk18C < D_800AD4F8) {
            racer->unk1A4 = racer->unk1A4 + (f32)D_80120BF0 * racer->unk18C * scale;
            if (D_800AD4FC < racer->unk18C) {
                if (racer->unk1A4 < 0.5f * racer->unk18C) {
                    racer->unk1A4 *= func_80081700(20.0f, (f32)D_80120BF0);
                }
            }
        } else {
            racer->unk1A4 *= func_80081700(racer->unk84, (f32)D_80120BF0);
        }
        if (racer->unk60 & 0x200) {
            racer->unk1A4 *= func_80081700(racer->unk80, (f32)D_80120BF0);
        }
    } else {
        if (D_800AD500 < racer->unk18C) {
            racer->unk1A4 = racer->unk1A4 + (f32)D_80120BF0 * racer->unk18C * scale;
            if (D_800AD504 <= racer->unk18C) {
                limit = D_800AD508;
            } else {
                limit = racer->unk18C / (1.0f - racer->unk18C);
            }
            if (limit < racer->unk1A4) {
                racer->unk1A4 *= func_80081700(racer->unk84, (f32)D_80120BF0);
            }
        } else if (racer->unk18C < D_800AD50C) {
            racer->unk1A4 = racer->unk1A4 + (f32)D_80120BF0 * racer->unk18C * scale;
            if (D_800AD510 < racer->unk18C) {
                if (racer->unk1A4 < 0.5f * racer->unk18C) {
                    racer->unk1A4 *= func_80081700(20.0f, (f32)D_80120BF0);
                }
            }
        } else if (racer->unk1A4 < D_800AD514) {
            racer->unk1A4 *= func_80081700(10.0f, (f32)D_80120BF0);
        } else {
            racer->unk1A4 *= func_80081700(racer->unk84, (f32)D_80120BF0);
        }
        if (racer->unk60 & 0x200) {
            racer->unk1A4 *= func_80081700(racer->unk80, (f32)D_80120BF0);
        }
    }

    amount = racer->unk1A4;
    if (0.0f < amount) {
        result = (racer->unk7C * amount) / (amount + racer->unk78);
    } else {
        negated = -amount;
        result = (-racer->unk7C * negated) / (negated + racer->unk78);
    }

    result *= racer->unk1AC;

    if (racer->unk184 < 15.0f) {
        if (!(racer->unk64 & 0x8000000)) {
            racer->unk64 = racer->unk64 | 0x8000000;
            if (racer->unk244 < 1.0f) {
                racer->unk64 = racer->unk64 | 0x10000000;
            }
        }
        result *= racer->unk244;
    } else {
        racer->unk64 = racer->unk64 & 0xF7FFFFFF;
    }

    result += racer->unk240;

    if (racer->unk60 & 0x4000000) {
        if (result < 75.0f) {
            result = 75.0f;
        }
    }
    if (racer->unk60 & 0x80) {
        if (racer->unk2FC < -0.5f) {
            if (racer->unk64 & 0x2000000) {
                result = result * D_800AD518;
            } else {
                result = result * D_800AD51C;
            }
        }
    }
    return result;
}
