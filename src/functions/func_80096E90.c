/* Independently written from scratchpad spec specs/func_80096E90.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ u8 *buf;
    /* 0x0C */ s32 n0;
    /* 0x10 */ s32 nz0;
    /* 0x14 */ s32 n1;
    /* 0x18 */ s32 nz1;
    /* 0x1C */ s32 n2;
    /* 0x20 */ s32 nz2;
    /* 0x24 */ s32 prec;
    /* 0x28 */ s32 width;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u32 flags;
} FmtState;

extern u8 D_800AE1C0[];
extern void *func_8008C2F0(void *destination, const void *source, u32 count);

static void func_80096E90(FmtState *px, u8 code, u8 *p, s16 nsig, s16 xexp);

static void func_80096E90(FmtState *px, u8 code, u8 *p, s16 nsig, s16 xexp) {
    s32 total;

    if (nsig <= 0) {
        p = D_800AE1C0;
        nsig = 1;
    }
    if (code == 'f' ||
        ((code == 'g' || code == 'G') && -4 <= xexp && xexp < px->prec)) {
        xexp++;
        if (code != 'f') {
            if (!(px->flags & 8) && nsig < px->prec) {
                px->prec = nsig;
            }
            px->prec -= xexp;
            if (px->prec < 0) {
                px->prec = 0;
            }
        }
        if (xexp <= 0) {
            px->buf[px->n1] = '0';
            px->n1++;
            if (px->prec > 0 || (px->flags & 8)) {
                px->buf[px->n1] = '.';
                px->n1++;
            }
            if (px->prec < -xexp) {
                xexp = -px->prec;
            }
            px->nz1 = -xexp;
            px->prec += xexp;
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            px->n2 = nsig;
            func_8008C2F0(px->buf + px->n1, p, nsig);
            px->nz2 = px->prec - nsig;
        } else if (nsig < xexp) {
            func_8008C2F0(px->buf + px->n1, p, nsig);
            px->n1 += nsig;
            px->nz1 = xexp - nsig;
            if (px->prec > 0 || (px->flags & 8)) {
                px->buf[px->n1] = '.';
                px->n2++;
            }
            px->nz2 = px->prec;
        } else {
            func_8008C2F0(px->buf + px->n1, p, xexp);
            px->n1 += xexp;
            nsig -= xexp;
            if (px->prec > 0 || (px->flags & 8)) {
                px->buf[px->n1] = '.';
                px->n1++;
            }
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            func_8008C2F0(px->buf + px->n1, p + xexp, nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }
    } else {
        if (code == 'g' || code == 'G') {
            if (nsig < px->prec) {
                px->prec = nsig;
            }
            px->prec--;
            if (px->prec < 0) {
                px->prec = 0;
            }
            if (code == 'g') {
                code = 'e';
            } else {
                code = 'E';
            }
        }
        px->buf[px->n1] = *p;
        p++;
        px->n1++;
        if (px->prec > 0 || (px->flags & 8)) {
            px->buf[px->n1] = '.';
            px->n1++;
        }
        if (px->prec > 0) {
            nsig--;
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            func_8008C2F0(px->buf + px->n1, p, nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }
        p = px->buf + px->n1;
        *p++ = code;
        if (xexp >= 0) {
            *p++ = '+';
        } else {
            *p++ = '-';
            xexp = -xexp;
        }
        if (xexp >= 100) {
            if (xexp >= 1000) {
                *p++ = (u8)(xexp / 1000 + '0'); xexp %= 1000;
            }
            *p++ = (u8)(xexp / 100 + '0'); xexp %= 100;
        }
        *p++ = (u8)(xexp / 10 + '0'); xexp %= 10;
        *p++ = (u8)(xexp + '0');
        px->n2 = (s32)(p - px->buf) - px->n1;
    }
    if ((px->flags & 0x14) == 0x10) {
        total = px->n0 + px->n1 + px->nz1 + px->n2 + px->nz2;
        if (total < px->width) {
            px->nz0 = px->width - total;
        }
    }
}

/*
 * Stand-in caller. This body is file-local in the original translation unit,
 * which was built one optimisation level above the rest of the ROM; its
 * parameter registers only appear when the compiler can see a call site in the
 * same unit. Delete this and place the real caller (func_80097400) in this
 * unit once that function is recovered.
 */
void func_80096E90_call_context(FmtState *px, u8 code, u8 *p, s16 nsig,
                                s16 xexp);

void func_80096E90_call_context(FmtState *px, u8 code, u8 *p, s16 nsig,
                                s16 xexp) {
    func_80096E90(px, code, p, nsig, xexp);
    func_80096E90(px, code, p, nsig, xexp);
    func_80096E90(px, code, p, nsig, xexp);
}
