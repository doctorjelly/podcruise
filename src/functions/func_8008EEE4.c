/* Independently written from scratchpad spec specs/func_8008EEE4.md. */

#include "podcruise/types.h"

/*
 * Packaging note.  The translation unit that holds this body was built one
 * optimisation level above the rest of the ROM.  At that level the compiler
 * allocates registers across every function of a unit at once, so a file-local
 * routine whose call sites are all visible receives its arguments in whatever
 * registers the allocator chose and is free to destroy callee-saved registers
 * that its caller reloads afterwards.  This routine takes its sample count in
 * an ordinary argument register, its two ratio terms in floating-point
 * registers that are not the first argument pair, and its output pointer in a
 * callee-saved register, and it destroys three callee-saved integer registers
 * and two callee-saved floating-point registers.  Reproducing that needs the
 * routine to stay file-local and to have a caller in the same unit that calls
 * it more than once (a single call site is inlined away and emits no
 * out-of-line body); func_8008EEE4_call_context below is a minimal stand-in.
 * The real caller is func_8008F0B4, and once that function is recovered the
 * two belong in a single translation unit and the stand-in should be deleted.
 */

typedef struct LogTable {
    /* 0x00 */ f64 unk00[8];
} LogTable;

extern LogTable D_800A7E80;
extern f64 D_800ADF30;
extern f64 D_800ADF38;

/* Splits a positive value into a mantissa in [0.5, 1) and a power of two. */
extern f64 func_8008ED18(f64 value, s32 *exponent);

static s32 func_8008EEE4(s32 steps, f64 target, f64 current, u16 *fraction) {
    f64 ratio;
    f64 mantissa;
    f64 logvalue;
    f64 factor;
    f64 accumulator;
    s32 count;
    s32 buckets = 16;
    s32 scale = 0x40000000;
    s32 exponent;
    s32 index;
    s16 whole;
    /*
     * The table is addressed by the top four bits of the mantissa, so it has
     * sixteen entries; the splitting routine never returns a mantissa below
     * one half, so only the upper eight are ever read and only those are
     * loaded.  The lower half is still declared, and the original reserved
     * room for it.
     */
    LogTable upper;
    LogTable lower;

    if (steps == 0) {
        if (current <= target) {
            *fraction = 0xFFFF;
            return 0x7FFF;
        }
        *fraction = 0;
        return 0;
    }
    if (target < 1.0) {
        target = 1.0;
    }
    if (current <= 0.0) {
        current = 1.0f;
    }
    (void)lower;
    upper = D_800A7E80;
    count = (s32)((1.0 / steps) * scale);
    ratio = target / current;
    mantissa = func_8008ED18(ratio, &exponent);
    index = (s32)(mantissa * buckets);
    logvalue = (upper.unk00[index - 8] + exponent) * D_800ADF30
               / ((f64)1.0f * scale);
    accumulator = 1.0;
    factor = 1.0 + logvalue;
    while (count != 0) {
        if ((count & 1) != 0) {
            accumulator *= factor;
        }
        count >>= 1;
        factor *= factor;
    }
    accumulator = accumulator * accumulator;
    accumulator = accumulator * accumulator;
    accumulator = accumulator * accumulator;
    whole = (s16)accumulator;
    *fraction = (s16)((accumulator - (f32)whole) * D_800ADF38);
    return whole;
}

typedef struct Voice {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ u16 unk0E;
} Voice;

void func_8008EEE4_call_context(Voice *voice);

void func_8008EEE4_call_context(Voice *voice) {
    voice->unk06 = (s16)func_8008EEE4(voice->unk00, (f64)voice->unk08,
                                      (f64)voice->unk04, &voice->unk0A);
    voice->unk0C = (s16)func_8008EEE4(voice->unk00, (f64)voice->unk0C,
                                      (f64)voice->unk06, &voice->unk0E);
}
