/* Independently written from specs/functions/recovered/func_8003609C.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx *D_80112C90;

#define EMIT(cmd, value) { Gfx *g = D_80112C90++; g->w0 = (cmd); g->w1 = (value); }

void func_8003609C(u32 arg0, u32 *arg1) {
    u32 field;

    if (arg0 == *arg1) {
        return;
    }

    field = arg0 & 3;
    if (field != (*arg1 & 3)) {
        *arg1 &= ~3;
        *arg1 |= field;
        if (field == 0) {
            EMIT(0xE3001001, 0)
        } else if (field == 1) {
            EMIT(0xE3001001, 0x8000)
        } else if (field == 2) {
            EMIT(0xE3001001, 0xC000)
        }
    }

    field = arg0 & 0xC;
    if (field != (*arg1 & 0xC)) {
        *arg1 &= ~0xC;
        *arg1 |= field;
        if (field == 0) {
            EMIT(0xE3000D01, 0)
        } else if (field == 4) {
            EMIT(0xE3000D01, 0x20000)
        } else if (field == 8) {
            EMIT(0xE3000D01, 0x40000)
        }
    }

    field = arg0 & 0x30;
    if (field != (*arg1 & 0x30)) {
        *arg1 &= ~0x30;
        *arg1 |= field;
        if (field == 0) {
            EMIT(0xE3001201, 0x2000)
        } else if (field == 0x10) {
            EMIT(0xE3001201, 0)
        } else if (field == 0x20) {
            EMIT(0xE3001201, 0x3000)
        }
    }

    field = arg0 & 0xC0;
    if (field != (*arg1 & 0xC0)) {
        *arg1 &= ~0xC0;
        *arg1 |= field;
        if (field == 0) {
            EMIT(0xE3000F00, 0)
        } else if (field == 0x40) {
            EMIT(0xE3000F00, 0x10000)
        }
    }
}
