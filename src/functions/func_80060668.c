/* Implements the specification in specs/func_80060668.md (per-selection gauge setup). */
#include "podcruise/types.h"

typedef struct {
    f32 a;
    f32 b;
} Pair80060668;

typedef struct {
    Pair80060668 pair[4];
} Row80060668;

typedef struct {
    Row80060668 row[8];
} Table80060668;

typedef struct {
    u8 unk00[0x8];
    s32 unk08;
    u8 unk0C[0x1A0];
    s32 unk1AC;
    u8 unk1B0[0x10];
    s32 unk1C0;
    s32 unk1C4;
} Obj80060668;

extern Table80060668 D_800A5A2C;
extern f32 D_800A5B64;
extern f32 D_800A5B68;
extern s32 D_800A5B6C;
extern s32 D_800A6748;
extern f32 D_800AD094;
extern f32 D_800AD098;
extern f32 D_800AD09C;
extern f32 D_800AD0A0;

void func_80060668(Obj80060668 *obj) {
    Table80060668 table;

    table = D_800A5A2C;
    D_800A5B64 = D_800AD094;
    D_800A5B68 = 20.0f;
    D_800A5B6C = -1;
    D_800A6748 = 0;

    D_800A5B64 = table.row[obj->unk1AC].pair[obj->unk1C0].a * D_800AD098;
    D_800A5B68 = table.row[obj->unk1AC].pair[obj->unk1C0].b;

    if (obj->unk1AC == 1) {
        if (obj->unk1C0 != 3) {
            D_800A5B6C = 1;
            if (obj->unk1C0 == 0) {
                D_800A6748 = 1;
            }
            if (obj->unk1C0 == 1) {
                D_800A6748 = 2;
            }
            if (obj->unk1C0 == 2) {
                D_800A6748 = 3;
            }
        }
    }
    if (obj->unk1AC == 3) {
        if (obj->unk1C0 == 1) {
            D_800A5B6C = 6;
        }
        if (obj->unk1C0 == 2) {
            D_800A5B6C = 5;
        }
    }
    if (obj->unk1AC == 4) {
        if (obj->unk1C0 != 3) {
            if (obj->unk1C0 == 0) {
                D_800A5B6C = 2;
            }
            if (obj->unk1C0 == 1) {
                D_800A5B6C = 3;
            }
            if (obj->unk1C0 == 2) {
                D_800A5B6C = 4;
            }
        }
    }
    if (obj->unk1C4 == -1) {
        D_800A5B64 = D_800A5B64 * D_800AD09C;
    } else if (obj->unk1C4 == 1) {
        D_800A5B64 = D_800A5B64 * D_800AD0A0;
    }
    if ((obj->unk08 & 0x20) != 0) {
        D_800A5B68 = 2.0f;
    }
}
