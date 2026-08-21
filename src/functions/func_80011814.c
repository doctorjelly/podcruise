/* Independently written from the reviewed function specifications. */

#include "podcruise/global_state.h"
#include "podcruise/leaf_state.h"

extern u8 D_8009B870;
extern s32 D_800D6140[];

void func_80011814(void) {
    D_8009B870 = 1;
}

void func_80011824(s32 index, s32 value) {
    D_800D6140[index] = value;
}
