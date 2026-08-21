/* Independently written from scratchpad spec specs/func_80079714.md. */

#include "podcruise/types.h"

typedef struct PcAxis {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} PcAxis;

typedef struct PcCraft {
    u8 unk0000[0x60];
    u32 unk0060;
    u32 unk0064;
    u8 unk0068[0x1614 - 0x68];
    PcAxis unk1614[1];
} PcCraft;

extern f64 D_80120BF0;
extern f32 func_80073C58(f32, f32, f32, f32, f32, f32);

f32 func_80079714(PcCraft *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                  f32 arg6, f32 arg7) {
    f32 prev;
    f32 value;

    arg4 = arg4 * D_80120BF0;
    arg5 = arg5 * D_80120BF0;
    prev = arg0->unk1614[arg1].unk0;
    value = arg2;
    if (arg0->unk0060 & 0x00800000) {
        value = arg2 / (f32)2.0;
    }
    if (arg0->unk0060 & 0x200) {
        value = arg3;
        arg5 = arg5 * (f32)2.0;
    }
    value = func_80073C58(value, prev, arg6, arg7, arg5, arg4);
    if (arg0->unk0064 & 0x02000000) {
        value = (value + prev) * 0.5f;
    }
    arg0->unk1614[arg1].unk0 = value;
    return value;
}
