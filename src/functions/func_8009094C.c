/* Independently written from scratchpad spec specs/func_8009094C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u8 b0;
    /* 0x1 */ u8 b1;
    /* 0x2 */ u8 b2;
    /* 0x3 */ u8 b3;
    /* 0x4 */ u8 b4;
    /* 0x5 */ u8 b5;
} Rec; /* 6 bytes, byte aligned */

extern u8 D_80149CB0;
extern u8 D_8014D720[];

void func_8009094C(s32 arg0) {
    u8 *p;
    Rec rec;
    s32 i;

    D_80149CB0 = 0;
    *(s32 *)&D_8014D720[0x3C] = 1;

    rec.b0 = 1;
    rec.b1 = 3;
    rec.b2 = 0;
    rec.b3 = 0xFF;
    rec.b4 = 0xFF;
    rec.b5 = 0xFF;

    p = D_8014D720;
    for (i = 0; i < arg0; i++) {
        *p = 0;
        p++;
    }

    *(Rec *)p = rec;
    p += 6;
    *p = 0xFE;
}
