/* Independently written from scratchpad spec specs/func_800129E4.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[2];
    s16 unk02;
    u8 unk04[12];
} Glyph;

typedef struct {
    u8 unk00[0x5A];
    u8 unk5A;
    u8 unk5B;
    u8 *unk5C;
    u8 *unk60;
} Font;

extern u8 D_800A1CD8[][2];
extern u8 D_800A1D1C[];

s32 func_800129E4(u8 *arg0, Font *arg1) {
    u8 *p;
    Glyph *glyph;
    u8 *base;
    s32 total;
    s32 done;
    s32 ch;
    s32 c;
    u8 idx;
    u8 next;
    u8 k;
    u8 g;

    p = arg0;
    total = 0;
    done = 0;

    do {
        ch = *p;
        c = ch;
        if (ch == 0) {
            done = 1;
        }
        if (c == 0x7E) {
            next = p[1];
            p++;
            if (next == 0x6E) {
                done = 1;
            } else if (next == 0x7E) {
                ch = 0x7E;
                c = 0x7E;
            } else {
                ch = 0;
                c = 0;
            }
        }
        if (c != 0 && !done) {
            glyph = 0;
            base = arg1->unk5C;
            idx = c;
            if (c >= 0x61 && c < 0x7B && arg1->unk5B < 0x61) {
                idx = c - 0x20;
            }
            if (idx >= 0x97) {
                if (arg1->unk60 != 0) {
                    k = D_800A1D1C[idx - 0x96];
                    if (k != 0xFF) {
                        idx = D_800A1CD8[k][1];
                        g = D_800A1CD8[k][0];
                        if (idx == 0xFF) {
                            glyph = (Glyph *)(arg1->unk60 + g * 16);
                            idx = 0;
                        }
                    }
                }
            }
            if (base != 0 && idx >= arg1->unk5A && idx <= arg1->unk5B) {
                glyph = (Glyph *)(base + (idx - arg1->unk5A) * 16);
            }
            if (glyph != 0) {
                total += glyph->unk02;
            }
        }
        p++;
    } while (!done);

    return total;
}
