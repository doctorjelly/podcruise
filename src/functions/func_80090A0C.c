/* Independently written from scratchpad spec specs/func_80090A0C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u8 b0;
    /* 0x1 */ u8 b1;
    /* 0x2 */ u8 b2;
    /* 0x3 */ u8 b3;
    /* 0x4 */ u8 b4;
    /* 0x5 */ u8 b5;
} Rec; /* 6 bytes, byte aligned */

typedef struct {
    /* 0x0 */ u16 h0;
    /* 0x2 */ u8 b2;
    /* 0x3 */ u8 b3;
} Out;

extern u8 D_8014D720[];

void func_80090A0C(s32 arg0, Out *arg1) {
    u8 *p;
    Rec rec;
    s32 i;

    p = D_8014D720;
    for (i = 0; i < arg0; i++) {
        p++;
    }

    rec = *(Rec *)p;

    arg1->b3 = (rec.b1 & 0xC0) >> 4;
    if (arg1->b3 == 0) {
        arg1->h0 = (rec.b4 << 8) | rec.b3;
        arg1->b2 = rec.b5;
    }
}
