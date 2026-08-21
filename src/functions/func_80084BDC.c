/* Implements the specification in specs/func_80084BDC.md */
#include "podcruise/types.h"

extern void func_80083190(void *, f32 (*)[4]);
extern void func_80016CAC(void *, void *, f32 (*)[4]);
extern void func_80016BF4(void *, void *, f32 (*)[4]);

void func_80084BDC(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    f32 matrix[4][4];

    func_80083190(arg2, matrix);
    func_80016CAC(arg0, arg3, matrix);
    func_80016BF4(arg1, arg4, matrix);
}
