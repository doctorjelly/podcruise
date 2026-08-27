/* Independently written from scratchpad spec specs/func_8004110C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x20];
    /* 0x020 */ f32 unk020[16];
    /* 0x060 */ u8 pad060[0x1C];
    /* 0x07C */ s32 unk07C;
    /* 0x080 */ u8 pad080[0x88];
    /* 0x108 */ f32 unk108[16];
    /* 0x148 */ u8 pad148[0xDC];
    /* 0x224 */ f32 unk224[16];
    /* 0x264 */ f32 unk264[16];
} Frame;

void func_8004110C(Frame *frame, s32 value) {
    frame->unk224[0] = frame->unk020[0]; frame->unk224[1] = frame->unk020[1]; frame->unk224[2] = frame->unk020[2]; frame->unk224[3] = frame->unk020[3]; frame->unk224[4] = frame->unk020[4]; frame->unk224[5] = frame->unk020[5]; frame->unk224[6] = frame->unk020[6]; frame->unk224[7] = frame->unk020[7]; frame->unk224[8] = frame->unk020[8]; frame->unk224[9] = frame->unk020[9]; frame->unk224[10] = frame->unk020[10]; frame->unk224[11] = frame->unk020[11]; frame->unk224[12] = frame->unk020[12]; frame->unk224[13] = frame->unk020[13]; frame->unk224[14] = frame->unk020[14]; frame->unk224[15] = frame->unk020[15];
    frame->unk264[0] = frame->unk108[0]; frame->unk264[1] = frame->unk108[1]; frame->unk264[2] = frame->unk108[2]; frame->unk264[3] = frame->unk108[3]; frame->unk264[4] = frame->unk108[4]; frame->unk264[5] = frame->unk108[5]; frame->unk264[6] = frame->unk108[6]; frame->unk264[7] = frame->unk108[7]; frame->unk264[8] = frame->unk108[8]; frame->unk264[9] = frame->unk108[9]; frame->unk264[10] = frame->unk108[10]; frame->unk264[11] = frame->unk108[11]; frame->unk264[12] = frame->unk108[12]; frame->unk264[13] = frame->unk108[13]; frame->unk264[14] = frame->unk108[14]; frame->unk264[15] = frame->unk108[15];
    frame->unk07C = value;
}
