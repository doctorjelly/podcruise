/* Implements specs/func_8006FB00.md (worker specification). */
#include "podcruise/types.h"

typedef struct Unk8006FB00Sub {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
} Unk8006FB00Sub;

typedef struct Unk8006FB00 {
    /* 0x0000 */ u8 pad0[0x60];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad68[0x74 - 0x68];
    /* 0x0074 */ f32 unk74;
    /* 0x0078 */ u8 pad78[0x18C - 0x78];
    /* 0x018C */ f32 unk18C;
    /* 0x0190 */ u8 pad190[0x1AC - 0x190];
    /* 0x01AC */ f32 unk1AC;
    /* 0x01B0 */ u8 pad1B0[0x1F0 - 0x1B0];
    /* 0x01F0 */ f32 unk1F0;
    /* 0x01F4 */ u8 pad1F4[0x22C - 0x1F4];
    /* 0x022C */ f32 unk22C;
    /* 0x0230 */ u8 pad230[0x264 - 0x230];
    /* 0x0264 */ f32 unk264;
    /* 0x0268 */ u8 pad268[0x1E70 - 0x268];
    /* 0x1E70 */ Unk8006FB00Sub *unk1E70;
    /* 0x1E74 */ u8 pad1E74[0x1E88 - 0x1E74];
    /* 0x1E88 */ f32 unk1E88;
} Unk8006FB00;

extern void func_8006CA2C(Unk8006FB00 *);
extern void func_8006D7F0(Unk8006FB00 *);
extern void func_8006E1CC(Unk8006FB00 *);
extern void func_8006E6F8(Unk8006FB00 *);
extern void func_8006FA08(Unk8006FB00 *);

void func_8006FB00(Unk8006FB00 *arg0) {
    f32 scale;
    f32 limit;

    arg0->unk18C = 0.0f;
    arg0->unk1F0 = 0.0f;

    if ((arg0->unk60 & 0x20) && (arg0->unk1E70->unkC != 0)) {
        func_8006E6F8(arg0);
    } else if (arg0->unk60 & 0x40) {
        if ((arg0->unk60 & 0xF) != 2) {
            return;
        }
        arg0->unk1F0 = arg0->unk1E88;
    } else if (arg0->unk60 & 0x80) {
        func_8006E1CC(arg0);
        if (arg0->unk64 & 0x4000000) {
            arg0->unk60 |= 0x400;
            func_8006CA2C(arg0);
        }
        if ((arg0->unk60 & 0xF) == 2) {
            func_8006D7F0(arg0);
        }
    }

    if ((arg0->unk60 & 0xF) == 2) {
        func_8006FA08(arg0);
    }
    if (arg0->unk60 & 0x80) {
        arg0->unk18C = arg0->unk18C * arg0->unk1AC;
    }
    if (0.0f < arg0->unk264) {
        arg0->unk18C = 0.0f;
    }
    scale = arg0->unk22C;
    limit = arg0->unk74 * scale;
    arg0->unk1F0 = arg0->unk1F0 * scale;
    if (limit < arg0->unk1F0) {
        arg0->unk1F0 = limit;
    }
    if (arg0->unk1F0 < -limit) {
        arg0->unk1F0 = -limit;
    }
}
