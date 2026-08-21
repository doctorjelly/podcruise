/* Recovered from the specification in scratchpad specs/func_80097400.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f64 value;
    /* 0x08 */ u8 *buffer;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 count;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 precision;
} Struct80097400;

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct80097F60;

extern f64 D_800AE170[];
extern u8 D_800AE1B8[];
extern u8 D_800AE1BC[];
extern f64 D_800AE1C8;

extern void *func_8008C2F0(void *destination, const void *source, u32 count);
extern void func_80096E90(Struct80097400 *state, u8 code, u8 *digits,
                          s16 nsig, s16 xexp);
extern Struct80097F60 func_80097F60(s32 numerator, s32 denominator);

void func_80097400(Struct80097400 *state, s32 conversion) {
    u8 digits[32];
    Struct80097F60 split;
    f64 value;
    f64 power;
    u8 *cursor;
    u16 *halves;
    s32 binary;
    s32 kind;
    s32 exponent;
    s32 remaining;
    s32 whole;
    s32 place;
    s32 step;
    s32 shift;
    s32 length;
    s32 keep;
    s32 scan;
    s32 mark;

    value = state->value;
    if (state->precision < 0) {
        state->precision = 6;
    } else if (state->precision == 0) {
        if (conversion == 'g' || conversion == 'G') {
            state->precision = 1;
        }
    }

    halves = (u16 *)state;
    binary = (s16)((halves[0] & 0x7FF0) >> 4);
    exponent = 0;
    kind = 0;
    if (binary == 0x7FF) {
        if ((halves[0] & 0xF) == 0 && halves[1] == 0 && halves[2] == 0 &&
            halves[3] == 0) {
            kind = 1;
        } else {
            kind = 2;
        }
    } else if (binary > 0) {
        halves[0] = (u16)((halves[0] & 0x800F) | 0x3FF0);
        exponent = binary - 0x3FE;
        kind = -1;
    }

    keep = 0;
    cursor = &digits[0];
    if (kind > 0) {
        state->count = 3;
        func_8008C2F0(state->buffer, (kind == 2) ? D_800AE1B8 : D_800AE1BC, 3);
        return;
    }

    if (kind != 0) {
        if (value < 0.0) {
            value = -value;
        }
        cursor = &digits[1];
        exponent = ((exponent * 0x7597) / 0x186A0) - 4;
        step = 0;
        if ((s16)exponent < 0) {
            place = (3 - (s16)exponent) & ~3;
            exponent = -place;
            while (place > 0) {
                if ((place & 1) != 0) {
                    value = value * D_800AE170[step];
                }
                place = place >> 1;
                step++;
            }
        } else if (exponent > 0) {
            exponent = exponent & 0xFFFC;
            place = (s16)exponent;
            power = 1.0;
            while (place > 0) {
                if ((place & 1) != 0) {
                    power = power * D_800AE170[step];
                }
                place = place >> 1;
                step++;
            }
            value = value / power;
        }

        if (conversion == 'f') {
            remaining = (s16)exponent + 10;
        } else {
            remaining = 6;
        }
        remaining = remaining + state->precision;
        if (remaining >= 0x14) {
            remaining = 0x13;
        }
        digits[0] = '0';
        if (remaining > 0) {
            while (value > 0.0) {
                remaining -= 8;
                cursor += 8;
                whole = (s32)value;
                if (remaining > 0) {
                    value = (value - (f64)whole) * D_800AE1C8;
                }
                if (whole > 0) {
                    shift = 7;
                    while (shift >= 0) {
                        split = func_80097F60(whole, 10);
                        cursor--;
                        *cursor = (u8)(split.unk4 + '0');
                        whole = split.unk0;
                        if (whole <= 0) {
                            break;
                        }
                        shift--;
                    }
                } else {
                    shift = 8;
                }
                shift--;
                while (shift >= 0) {
                    cursor--;
                    *cursor = '0';
                    shift--;
                }
                if (remaining <= 0) {
                    break;
                }
                cursor += 8;
            }
        }

        length = (s32)(cursor - &digits[0]) - 1;
        exponent = (s16)exponent + 7;
        if (digits[1] == '0') {
            cursor = &digits[1];
            do {
                cursor++;
                length--;
                exponent = (s16)exponent - 1;
            } while (*cursor == '0');
        }

        if (conversion == 'f') {
            keep = (s16)exponent + 1;
        } else if (conversion == 'e' || conversion == 'E') {
            keep = 1;
        } else {
            keep = 0;
        }
        keep = (s16)(keep + state->precision);
        if (length < keep) {
            keep = (s16)length;
        }
        if (keep > 0) {
            if (keep < length) {
                mark = (cursor[keep] < '5') ? '0' : '9';
            } else {
                mark = '0';
            }
            scan = keep - 1;
            if (mark == cursor[keep - 1]) {
                while (mark == cursor[scan]) {
                    keep = (s16)(keep - 1);
                    scan--;
                }
            }
            if (mark == '9') {
                cursor[scan]++;
            }
            if (scan < 0) {
                keep = (s16)(keep + 1);
                exponent = (s16)exponent + 1;
                cursor--;
            }
        }
    }

    func_80096E90(state, (u8)conversion, cursor, (s16)exponent, (s16)keep);
}
