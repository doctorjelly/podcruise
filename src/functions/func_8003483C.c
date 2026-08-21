/* Recovered per specification specs/func_8003483C.md (worker batch_03). */
#include "podcruise/types.h"

typedef struct Entry8003483C {
    /* 0x00 */ f32 unk00[3];
    /* 0x0C */ f32 unk0C[3];
    /* 0x18 */ f32 unk18[3];
    /* 0x24 */ f32 unk24[3];
} Entry8003483C;

extern s32 D_800A3FF0;
extern s32 D_800A3FF4;
extern s32 D_800A3FF8;
extern Entry8003483C D_80112EA0[];

extern void func_80015268(f32 *, f32, f32, f32);

void func_8003483C(void) {
    D_800A3FF0 = 0;
    D_800A3FF4 = 1;
    D_800A3FF8 = 0;
    func_80015268(D_80112EA0[D_800A3FF0].unk00, 1.0f, 0.0f, 0.0f);
    func_80015268(D_80112EA0[D_800A3FF0].unk0C, 0.0f, 1.0f, 0.0f);
    func_80015268(D_80112EA0[D_800A3FF0].unk18, 0.0f, 0.0f, 1.0f);
    func_80015268(D_80112EA0[D_800A3FF0].unk24, 0.0f, 0.0f, 0.0f);
}
