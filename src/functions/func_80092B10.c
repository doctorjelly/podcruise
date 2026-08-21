/* Independently written from the specification in specs/func_80092B10.md. */

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

/* The original translation unit emits four bytes of read-only data ahead of
   this function's switch table; this stand-in reproduces that offset so the
   table lands at its canonical address. */
const char *func_80092B10_pool_head(void);
const char *func_80092B10_pool_head(void) {
    return "pad";
}

#define STEP4(pap) (*(pap) = (char *)(((unsigned long)*(pap) + 3) & ~3UL) + 4)
#define STEP8(pap) (*(pap) = (char *)(((unsigned long)*(pap) + 7) & ~7UL) + 8)
#define ARG4(pap, type) (STEP4(pap), ((type *)*(pap))[-1])
#define ARG8(pap, type) (STEP8(pap), ((type *)*(pap))[-1])
/* A pointer argument that is immediately written through: the cursor advance
   and the re-read of the cursor form the operand of the cast, so the target
   address is produced before the stored value is fetched. */
#define ARGN(pap, type) ((type *)(STEP4(pap), *(pap)))[-1]
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
            *ARGN(pap, s16 *) = px->nchar;
        } else if (px->qual == 'l') {
            *ARGN(pap, s32 *) = px->nchar;
        } else if (px->qual == 'L') {
            *ARGN(pap, long long *) = px->nchar;
        } else {
            *ARGN(pap, s32 *) = px->nchar;
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

void func_80092B10_call_context(FieldState *px, char **pap, const char *fmt, u8 *ac);

void func_80092B10_call_context(FieldState *px, char **pap, const char *fmt, u8 *ac) {
    while (*fmt != '\0') {
        if (*fmt == '%') {
            func_80092B10(px, pap, (u8)fmt[1], ac);
            fmt += 2;
        } else if (*fmt == '#') {
            func_80092B10(px, pap, (u8)'d', ac);
            fmt += 1;
        } else if (*fmt == '@') {
            func_80092B10(px, pap, (u8)'s', ac);
            fmt += 1;
        } else {
            func_80092B10(px, pap, (u8)'c', ac);
            fmt += 1;
        }
    }
}
