/* Independently written from specs/functions/recovered/func_8008DD80.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x14];
    s32 count;
    u8 unk18[4];
    void **entries;
} Context8008DD80;

typedef u32 *(*Emit8008DD80)(void *, s32, s32, s32, u32 *);

u32 *func_8008DD80(void *arg0, s32 arg1, s32 width, s32 arg3, u32 *output) {
    Context8008DD80 *context;
    u32 *cursor;
    void *entry;
    s32 index;
    u32 doubled;
    void **list;

    context = arg0;
    list = context->entries;
    doubled = (u32)width * 2;
    output[0] = 0x02000440;
    output[1] = doubled;
    output[2] = 0x02000580;
    output[3] = doubled;
    cursor = output + 4;

    for (index = 0; index < context->count; index++) {
        entry = list[index];
        cursor = (*(Emit8008DD80 *)((u8 *)entry + 4))(entry, arg1, width, arg3, cursor);
        cursor[0] = 0x08000000;
        cursor[1] = doubled & 0xFFFF;
        cursor[3] = 0x06C00440;
        cursor[2] = 0x0C007FFF;
        cursor[5] = 0x08000580;
        cursor[4] = 0x0C007FFF;
        cursor += 6;
    }
    return cursor;
}
