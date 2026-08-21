/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/types.h"

extern void func_800174B8(f32 *matrix, const void *source);
extern void func_80017BA8(void *destination, const void *source);

void func_80017D18(void *object, const void *source) {
    f32 matrix[16];

    func_800174B8(matrix, source);
    func_80017BA8(object, matrix);
}
