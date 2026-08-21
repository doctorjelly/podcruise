/* Independently written from $S/specs/func_80014CD8.md: scaled-angle sine/cosine pair. */
#include "podcruise/types.h"

extern f64 D_800A8780;
extern f64 D_800A8788;
extern f32 func_8008A750(f32 angle);
extern f32 func_8008A8C0(f32 angle);

void func_80014CC0(f32 angle, f32 *outB, f32 *outA) {
    f32 pad;
    f32 scaled;

    scaled = (f32)((f64)angle * D_800A8780 / D_800A8788);
    *outA = func_8008A750(scaled);
    *outB = func_8008A8C0(scaled);
    (void)pad;
}
