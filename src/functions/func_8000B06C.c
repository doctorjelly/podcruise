/* Specification: $S/specs/func_8000B06C.md */
#include "podcruise/types.h"

extern u8 *D_8009B790;

void func_8000B06C(index, value)
s16 index;
s32 value;
{
    *(s32 *)(D_8009B790 + index * 124 + 0x78) = value;
}
