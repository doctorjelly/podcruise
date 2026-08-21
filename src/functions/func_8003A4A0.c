/* Independently written from scratchpad spec specs/func_8003A4A0.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x10];
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 unk_1C[0x38];
} Record8003A4A0; /* 0x54 bytes */

typedef struct {
    u8 unk_00[0xC];
    Record8003A4A0 *unk_0C;
} Owner8003A4A0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Triple8003A4A0;

void func_8003A4A0(Owner8003A4A0 *owner, s32 index, Triple8003A4A0 *out) {
    out->x = owner->unk_0C[index].unk_10;
    out->y = owner->unk_0C[index].unk_14;
    out->z = owner->unk_0C[index].unk_18;
}
