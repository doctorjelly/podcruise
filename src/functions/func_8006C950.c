/* Independently written from specs/functions/recovered/func_8006C950.md. */
#include "podcruise/types.h"

typedef struct Unk8006C950 {
    /* 0x000 */ u8 pad000[0x2A0];
    /* 0x2A0 */ s32 unk2A0[6];
} Unk8006C950;

extern f32 D_800AD610;
extern f32 D_800AD614;
extern f64 D_80120BF0;

extern void func_80071820(Unk8006C950 *arg0, s32 arg1, f32 arg2);
extern s32 func_80082BE0(void);

void func_8006C950(Unk8006C950 *arg0) {
    s32 index;
    f32 scale;
    f32 bias;

    scale = D_800AD610;
    bias = scale;
    scale = D_800AD614;
    for (index = 0; index != 6; index++) {
        if ((arg0->unk2A0[index] & 8) != 0) {
            func_80071820(arg0, index,
                          ((f32)func_80082BE0() / 2147483648.0f * scale + bias) * (f32)D_80120BF0);
        }
    }
}
