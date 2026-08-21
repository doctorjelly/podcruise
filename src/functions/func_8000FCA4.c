/* Independently written from specs/functions/func_8000FCA4.md. */

#include "podcruise/types.h"

extern u8 D_8009B827[];

void func_8000FCA4(s32 index, u8 value) {
    D_8009B827[index * 4] = value;
}
