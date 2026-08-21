/* Implements specification specs/func_80009C0C.md (periodic audio cue sweep). */
#include "podcruise/types.h"

typedef struct {
    f32 unk00;
    f32 unk04;
    s16 unk08;
    s16 unk0A;
} CueEntry;

extern f32 D_8009AF28;
extern f32 D_8009AF2C;
extern CueEntry D_8009B0B8[];
extern CueEntry D_8009B43C[];
extern CueEntry *D_8009B70C[][3];
extern f32 D_800A8230;
extern f64 D_80120BF0;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern s32 func_80082BE0(void);

void func_80009C0C(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    CueEntry *entry;
    f32 start;
    f32 end;
    f32 phase;
    f32 fraction;
    f32 level;
    f32 one;
    f32 quarter;
    f32 zero;
    s32 hit;
    s32 gate;

    (void)arg3;

    gate = 0;
    if (arg0 == 4) {
        if (arg1 < 3) {
            gate = 1;
        }
    }
    one = 1.0f;
    quarter = 0.25f;
    zero = 0.0f;
    if (gate) {
        D_8009AF28 -= D_80120BF0;
        if (D_8009AF28 <= zero) {
            D_8009AF28 = ((f32)func_80082BE0() / (f32)2147483648.0) * 20.0f + 10.0f;
            func_80008B14(0x24, 6, quarter, one, 0);
        }
    }

    if (arg1 == 3) {
        if (arg0 == 1) {
            entry = D_8009B0B8;
        } else if (arg0 == 4) {
            entry = D_8009B43C;
        }
    } else {
        entry = D_8009B70C[arg0][arg1];
    }

    if (entry == 0) {
        return;
    }

    hit = 0;
    while (zero <= entry->unk00 && hit == 0) {
        start = entry->unk00;
        end = entry->unk04;
        phase = arg2;
        if (end < start) {
            if (arg2 < start) {
                phase = arg2 + one;
            }
            end = end + one;
        }
        if (start < end) {
            fraction = (phase - start) / (end - start);
            if (zero < fraction && fraction < one) {
                hit = 1;
                if (entry->unk0A & 1) {
                    D_8009AF2C -= D_80120BF0;
                    if (D_8009AF2C <= zero) {
                        D_8009AF2C = ((f32)func_80082BE0() / (f32)2147483648.0) * 10.0f + 5.0f;
                        func_80008B14(entry->unk08, 6, quarter, one, 0);
                    }
                } else {
                    if (fraction < quarter) {
                        level = (one / quarter) * fraction;
                    } else if (one - quarter < fraction) {
                        level = (one - fraction) * (one / quarter);
                    } else {
                        level = one;
                    }
                    if (entry->unk08 == 5) {
                        level = level * D_800A8230;
                    }
                    if (zero < level) {
                        func_80008B14(entry->unk08, 6, quarter, level, 1);
                    }
                }
            }
        }
        entry++;
    }
}
