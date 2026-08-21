/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/types.h"

extern void func_80039178(void *argument, s32 size);

/* Declared void: adding a return statement costs four bytes and no longer
   matches. The callee's result nonetheless survives in the return register,
   and func_800396E0 reads it — an unprototyped-C inconsistency in the
   original source, faithful on both sides. */
void func_8003931C(u8 *argument) {
    func_80039178(argument + 4, 0x3EC);
}
