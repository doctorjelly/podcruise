/* Independently written from the specification in scratchpad specs/func_80093180.md.
   The conversion routine below is the file-local callee of this driver: the unit is
   built one optimisation level up, so the two must be compiled together. */

#include "podcruise/types.h"

typedef union {
    long long li;
    unsigned long long lu;
    f64 d;
    u16 us[4];
} FieldValue;

typedef struct {
    FieldValue v;
    u8 *s;
    s32 n0;
    s32 nz0;
    s32 n1;
    s32 nz1;
    s32 n2;
    s32 nz2;
    s32 prec;
    s32 width;
    u32 nchar;
    u32 flags;
    u8 qual;
} FieldState;

extern u32 func_8008C31C(const u8 *text);
extern void func_80096BF0(FieldState *px, u8 code);
extern void func_80097400(FieldState *px, u8 code);

#define STEP4(pap) (*(pap) = (char *)(((unsigned long)*(pap) + 3) & ~3UL) + 4)
#define STEP8(pap) (*(pap) = (char *)(((unsigned long)*(pap) + 7) & ~7UL) + 8)
#define ARG4(pap, type) (STEP4(pap), ((type *)*(pap))[-1])
#define ARG8(pap, type) (STEP8(pap), ((type *)*(pap))[-1])
#define ARGV(pap, type) (((type *)STEP4(pap))[-1])
/* The eight-byte fetch the original build emits: two of its three arms are
   unreachable, because an argument list is always word aligned. */
#define ARGD(pap)                                                          \
    (*(f64 *)((((unsigned long)*(pap) & 1) != 0                            \
                  ? (*(pap) = (char *)((unsigned long)*(pap) + 7),         \
                     *(pap) - 22)                                          \
                  : ((unsigned long)(&(*(pap))[0]) & 2) != 0               \
                        ? (*(pap) = (char *)((unsigned long)*(pap) + 10),  \
                           *(pap) - 40)                                    \
                        : (*(pap) = (char *)((unsigned long)(*(pap) + 7)   \
                                             & ~7UL) + 8,                  \
                           *(pap)))                                        \
              - 8))

static void func_80092B10(FieldState *px, char **pap, u8 code, u8 *ac) {
    px->n0 = 0;
    px->nz0 = 0;
    px->n1 = 0;
    px->nz1 = 0;
    px->n2 = 0;
    px->nz2 = 0;
    switch (code) {
    case 'c':
        ac[px->n0] = ARG4(pap, s32);
        px->n0 += 1;
        break;
    case 'd':
    case 'i':
        if (px->qual == 'l') {
            px->v.li = ARG4(pap, long);
        } else if (px->qual == 'L') {
            px->v.li = ARG8(pap, long long);
        } else {
            px->v.li = ARG4(pap, s32);
        }
        if (px->qual == 'h') {
            px->v.li = (s16)px->v.li;
        }
        if (px->v.li < 0) {
            ac[px->n0] = '-';
            px->n0 += 1;
        } else if ((px->flags & 0x02) != 0) {
            ac[px->n0] = '+';
            px->n0 += 1;
        } else if ((px->flags & 0x01) != 0) {
            ac[px->n0] = ' ';
            px->n0 += 1;
        }
        px->s = &ac[px->n0];
        func_80096BF0(px, code);
        break;
    case 'X':
    case 'o':
    case 'u':
    case 'x':
        if (px->qual == 'l') {
            px->v.li = ARG4(pap, long);
        } else if (px->qual == 'L') {
            px->v.lu = ARG8(pap, unsigned long long);
        } else {
            px->v.li = ARG4(pap, s32);
        }
        if (px->qual == 'h') {
            px->v.lu = (u16)px->v.li;
        } else if (px->qual == 0) {
            px->v.lu = (u32)px->v.li;
        }
        if ((px->flags & 0x08) != 0) {
            ac[px->n0] = '0';
            px->n0 += 1;
            if (code == 'x' || code == 'X') {
                ac[px->n0] = code;
                px->n0 += 1;
            }
        }
        px->s = &ac[px->n0];
        func_80096BF0(px, code);
        break;
    case 'E':
    case 'G':
    case 'e':
    case 'f':
    case 'g':
        if (px->qual == 'L') {
            px->v.d = ARGD(pap);
        } else {
            px->v.d = ARGD(pap);
        }
        if ((px->v.us[0] & 0x8000) != 0) {
            ac[px->n0] = '-';
            px->n0 += 1;
        } else if ((px->flags & 0x02) != 0) {
            ac[px->n0] = '+';
            px->n0 += 1;
        } else if ((px->flags & 0x01) != 0) {
            ac[px->n0] = ' ';
            px->n0 += 1;
        }
        px->s = &ac[px->n0];
        func_80097400(px, code);
        break;
    case 'n':
        if (px->qual == 'h') {
            *ARG4(pap, s16 *) = px->nchar;
        } else if (px->qual == 'l') {
            *ARG4(pap, s32 *) = px->nchar;
        } else if (px->qual == 'L') {
            *ARGV(pap, long long *) = px->nchar;
        } else {
            *ARG4(pap, s32 *) = px->nchar;
        }
        break;
    case 'p':
        px->v.li = (long)ARG4(pap, char *);
        px->s = &ac[px->n0];
        func_80096BF0(px, 'x');
        break;
    case 's':
        px->s = ARG4(pap, u8 *);
        px->n1 = (s32)func_8008C31C(px->s);
        if (px->prec >= 0 && px->prec < px->n1) {
            px->n1 = px->prec;
        }
        break;
    case '%':
        ac[px->n0] = '%';
        px->n0 += 1;
        break;
    default:
        ac[px->n0] = code;
        px->n0 += 1;
        break;
    }
}


extern u8 D_800A7F60[33];  /* blanks */
extern u8 D_800A7F84[33];  /* zeros */
extern u8 D_800AE010[4];   /* length modifier letters */
extern u8 D_800AE014[8];   /* flag letters */
extern u32 D_800AE01C[8];  /* flag values */
extern u8 *func_8008C344(const u8 *text, s32 code);

typedef u8 *(*PrintEmit)(u8 *state, const u8 *text, s32 length);

#define PUT(text, len) if ((arg = (*prout)(arg, (text), (len))) != 0) { x.nchar += (len); } else { return x.nchar; }
#define PAD(text, count) for (i = (count); 0 < i; i -= j) { if ((u32)i >= sizeof(text)) { j = 32; } else { j = i; } if (0 < j) { PUT(text, j) } }

s32 func_80093180(PrintEmit prout, u8 *arg, const u8 *fmt, char *ap) {
    FieldState x;
    u8 ac[44];
    u8 pad[20];
    const u8 *s;
    u8 c;
    u8 *t;
    s32 i;
    s32 j;

    (void)pad;
    x.nchar = 0;
    for (;;) {
        for (s = fmt; (c = *s) != '\0' && c != '%'; ++s) {
        }
        if (0 < (i = s - fmt)) {
            if ((arg = (*prout)(arg, fmt, s - fmt)) != 0) {
                x.nchar += i;
            } else {
                return x.nchar;
            }
        }
        if (c == '\0') {
            return x.nchar;
        }
        ++s;
        x.flags = 0;
        while ((t = func_8008C344(D_800AE014, *s)) != 0) {
            x.flags |= D_800AE01C[t - D_800AE014];
            ++s;
        }
        if (*s == '*') {
            ++s;
            ap = (char *)(((unsigned long)ap + 3) & ~3UL) + 4;
            x.width = ((s32 *)ap)[-1];
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= 0x04;
            }
        } else {
            for (x.width = 0; *s >= '0' && *s <= '9'; ++s) {
                if (x.width < 999) {
                    x.width = x.width * 10 + *s - '0';
                }
            }
        }
        if (*s != '.') {
            x.prec = -1;
        } else if (*++s == '*') {
            ++s;
            ap = (char *)(((unsigned long)ap + 3) & ~3UL) + 4;
            x.prec = ((s32 *)ap)[-1];
        } else {
            for (x.prec = 0; *s >= '0' && *s <= '9'; ++s) {
                if (x.prec < 999) {
                    x.prec = x.prec * 10 + *s - '0';
                }
            }
        }
        if (func_8008C344(D_800AE010, *s) != 0) {
            x.qual = *s;
            ++s;
        } else {
            x.qual = 0;
        }
        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            ++s;
        }
        func_80092B10(&x, &ap, *s, ac);
        x.width = x.width - x.n0 - x.nz0 - x.n1 - x.nz1 - x.n2 - x.nz2;
        if (!(x.flags & 0x04) && 0 < x.width) {
            PAD(D_800A7F60, x.width)
        }
        if (0 < x.n0) {
            PUT(ac, x.n0)
        }
        if (0 < x.nz0) {
            PAD(D_800A7F84, x.nz0)
        }
        if (0 < x.n1) {
            PUT(x.s, x.n1)
        }
        if (0 < x.nz1) {
            PAD(D_800A7F84, x.nz1)
        }
        if (0 < x.n2) {
            PUT(x.s + x.n1, x.n2)
        }
        if (0 < x.nz2) {
            PAD(D_800A7F84, x.nz2)
        }
        if ((x.flags & 0x04) && 0 < x.width) {
            PAD(D_800A7F60, x.width)
        }
        fmt = s + 1;
    }
}

