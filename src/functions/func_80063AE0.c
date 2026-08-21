/* Independently written from scratchpad spec specs/func_80063AFC.md. */

#include "podcruise/types.h"

extern f32 func_8004E034(f32 arc, f32 radius);

extern f32 D_800A5B30;
extern f32 D_800A5B38;
extern f32 D_800AD424;
extern f32 D_80120BF8;

void func_80063AE0(void) {
    f32 position;
    f32 span;

    position = D_800A5B38;
    span = D_800AD424 + D_800AD424;
    position += D_80120BF8;
    if (span < position) {
        position -= span;
    }
    D_800A5B38 = position;
    D_800A5B30 = (f32)(func_8004E034(position, D_800AD424) / span + 0.5);
}
