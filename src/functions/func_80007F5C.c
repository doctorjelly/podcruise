/* Independently written from scratchpad spec specs/func_80007F5C.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} PcSample;

typedef struct {
    s32 unk00[2];
    PcSample *unk08;
} PcSlot;

typedef struct {
    s32 unk00[4];
    PcSlot *unk10[1];
} PcSlotTable;

typedef struct {
    s32 unk00[3];
    PcSlotTable *unk0C;
} PcOwner;

extern PcOwner *func_80007CE4(s32 arg0);
extern f32 D_800A81C8;

f32 func_80007F5C(s32 arg0) {
    PcOwner *owner;
    s32 value;

    owner = func_80007CE4(arg0);
    arg0 &= 0x7FFF;
    if (owner == 0) {
        return 0.0f;
    }
    value = owner->unk0C->unk10[arg0]->unk08->unk04;
    return (f32)value * D_800A81C8;
}
