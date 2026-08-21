/* Independently written from scratchpad spec specs/func_800091B0.md. */

#include "podcruise/types.h"

extern f32 func_80007F5C(s32 arg0);

extern f32 D_8009AD10[];
extern f32 D_8009AD30[];
extern s32 D_8009AD8C[];
extern f32 D_8009ADFC[];

void func_800091B0(s32 kind, s32 slot, s32 source, s32 preset) {
    f32 level;

    level = func_80007F5C(source);
    switch (kind) {
    case 2:
        D_8009AD10[kind] = D_8009ADFC[preset] + 0.25f;
        break;
    case 0:
    case 1:
        D_8009AD30[slot] = level + 1.0f;
        D_8009AD8C[slot] = kind;
        break;
    default:
        D_8009AD10[kind] = level + 1.0f;
        break;
    }
}
