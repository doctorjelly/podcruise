/* Recovered per specs/func_80038F68.md (worker specification). */
#include "podcruise/types.h"

typedef struct Pair {
    s32 unk0;
    s32 unk4;
} Pair;

typedef struct Quad {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Quad;

typedef struct Entry {
    Pair pair;
    Quad quad;
    u8 pad18[0x10];
} Entry;

extern Pair D_800A3DB0;
extern Quad D_800A3DB8;
extern Entry D_800A3DC8[];
extern s32 D_800A3FA8[];

void func_80038F68(s32 index) {
    if ((index >= 0) && (index < 12)) {
        D_800A3DC8[index].pair = D_800A3DB0;
        D_800A3DC8[index].quad = D_800A3DB8;
        D_800A3FA8[index] = 1;
    }
}
