/* Specification: specs/func_8003E194.md (entry corrected to 0x8003E18C). */

#include "podcruise/types.h"

extern void func_8003E0A0(void *state, f32 stepU, f32 stepV);

void func_8003E18C(void **holder, s32 arg1, f32 stepU, f32 stepV) {
    (void)arg1;
    func_8003E0A0(*holder, stepU, stepV);
}
