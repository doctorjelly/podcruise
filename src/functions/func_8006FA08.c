/* Recovered from specification $S/specs/func_8006FA08.md */
#include "podcruise/types.h"

typedef struct Unk8006FA08Sub {
    /* 0x0000 */ u8 pad00[0xC];
    /* 0x000C */ s32 unk0C;
} Unk8006FA08Sub;

typedef struct Unk8006FA08 {
    /* 0x0000 */ u8 pad00[0x60];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ u8 pad64[0x130 - 0x64];
    /* 0x0130 */ f32 unk130;
    /* 0x0134 */ u8 pad134[0x1AC - 0x134];
    /* 0x01AC */ f32 unk1AC;
    /* 0x01B0 */ u8 pad1B0[0x22C - 0x1B0];
    /* 0x022C */ f32 unk22C;
    /* 0x0230 */ u8 pad230[0x1E70 - 0x230];
    /* 0x1E70 */ Unk8006FA08Sub *unk1E70;
} Unk8006FA08;

extern f32 D_800AD7F0;

extern s32 func_80051FF4(void);
extern void func_8006DB1C(Unk8006FA08 *);
extern f32 func_8007EE40(void);

void func_8006FA08(Unk8006FA08 *arg0) {
    f32 value;

    if ((arg0->unk60 & 0x20) && arg0->unk1E70->unk0C != 0) {
        arg0->unk22C = 1.0f;
        if (func_80051FF4() >= 2) {
            if (arg0->unk130 > 0.0f) {
                value = (arg0->unk130 * 100.0f) / (D_800AD7F0 / func_8007EE40()) + 1.0f;
                arg0->unk22C = value;
                if (value > 1.25f) {
                    arg0->unk22C = 1.25f;
                }
            }
        }
    } else if (arg0->unk60 & 0x80) {
        func_8006DB1C(arg0);
    } else {
        arg0->unk22C = 1.0f;
    }
    arg0->unk1AC = arg0->unk22C;
}
