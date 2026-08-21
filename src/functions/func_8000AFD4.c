/* Recovered from specification specs/func_8000AFD4.md (scratchpad). */
#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x6C];
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    u8 unk_78[0x7C - 0x78];
} Entry8000AFD4;

extern Entry8000AFD4 *D_8009B790;

void func_8000AFD4(s16 index, f32 x, f32 y, f32 z) {
    D_8009B790[index].unk_6C = x;
    D_8009B790[index].unk_70 = y;
    D_8009B790[index].unk_74 = z;
}
