/* Independently written from the specification for func_80003B44. */

#include "podcruise/types.h"

extern f32 D_800AE8B8[3];
extern f32 D_800AE8C8[3];
extern s16 D_800AE934;

extern void func_800059A8(f32 *matrix);
extern void func_80016BF4(f32 *destination, f32 *source, f32 (*transform)[4]);
extern void func_80016CAC(f32 *destination, f32 *source, f32 (*transform)[4]);

void func_80003B44(s32 flags) {
    f32 matrix[4][4];
    f64 unused;

    (void)unused;
    if (flags & 1) {
        func_800059A8(&matrix[0][0]);
        if (flags & 2) {
            func_80016CAC(D_800AE8B8, D_800AE8B8, matrix);
            if (D_800AE934 != 2) {
                func_80016BF4(D_800AE8C8, D_800AE8C8, matrix);
            }
        } else {
            D_800AE8B8[0] += matrix[3][0];
            D_800AE8B8[1] += matrix[3][1];
            D_800AE8B8[2] += matrix[3][2];
        }
    }
}
