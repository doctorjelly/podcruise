/* Independently written from the specification for func_80065E18. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x190];
    /* 0x190 */ f32 unk190;
    /* 0x194 */ f32 unk194[3];
} Func80065E18Target;

extern f32 D_800A3080;
extern f32 D_800A3084[3];

void func_80065E18(Func80065E18Target *arg0) {
    arg0->unk190 = D_800A3080 * 0.25f;
    arg0->unk194[0] = D_800A3084[0];
    arg0->unk194[1] = D_800A3084[1];
    arg0->unk194[2] = D_800A3084[2];
}
