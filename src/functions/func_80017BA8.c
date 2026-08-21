/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/types.h"

void func_80017BA8(void *destination, const void *source) {
    *(f32 *)((u8 *)destination + 0x1C) = *(const f32 *)((const u8 *)source + 0x00);
    *(f32 *)((u8 *)destination + 0x20) = *(const f32 *)((const u8 *)source + 0x04);
    *(f32 *)((u8 *)destination + 0x24) = *(const f32 *)((const u8 *)source + 0x08);
    *(f32 *)((u8 *)destination + 0x28) = *(const f32 *)((const u8 *)source + 0x10);
    *(f32 *)((u8 *)destination + 0x2C) = *(const f32 *)((const u8 *)source + 0x14);
    *(f32 *)((u8 *)destination + 0x30) = *(const f32 *)((const u8 *)source + 0x18);
    *(f32 *)((u8 *)destination + 0x34) = *(const f32 *)((const u8 *)source + 0x20);
    *(f32 *)((u8 *)destination + 0x38) = *(const f32 *)((const u8 *)source + 0x24);
    *(f32 *)((u8 *)destination + 0x3C) = *(const f32 *)((const u8 *)source + 0x28);
    *(f32 *)((u8 *)destination + 0x40) = *(const f32 *)((const u8 *)source + 0x30);
    *(f32 *)((u8 *)destination + 0x44) = *(const f32 *)((const u8 *)source + 0x34);
    *(f32 *)((u8 *)destination + 0x48) = *(const f32 *)((const u8 *)source + 0x38);
    *(u16 *)((u8 *)destination + 0x0C) |= 3;
}
