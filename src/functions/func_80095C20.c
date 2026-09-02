/* Implements specification $S/specs/func_80095C20.md */
#include "podcruise/types.h"

typedef struct Gfx {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct Buffer {
    u8 unk00[0x14];
    s16 *base;
    s32 unk18;
    s32 count;
} Buffer;

extern u32 func_80088360(void *address);

#define EMIT(first, second) { Gfx *cmd = gfx++; cmd->w0 = (first); cmd->w1 = (second); }

Gfx *func_80095C20(Buffer *buffer, s16 *start, s32 offset, s32 length, Gfx *list) {
    Gfx *gfx;
    s16 *stop;
    s32 head;
    s32 tail;
    s16 *end;

    gfx = list;
    end = buffer->base + buffer->count;
    if (start < buffer->base) {
        start += buffer->count;
    }
    stop = start + length;
    if (end < stop) {
        head = (end - start) * 2;
        EMIT(0x08000000, (((u32)offset & 0xFFFF) << 16) | ((u32)head & 0xFFFF))
        EMIT(0x06000000, func_80088360(start))
        tail = (stop - end) * 2;
        EMIT(0x08000000, ((((u32)(head + offset)) & 0xFFFF) << 16) | ((u32)tail & 0xFFFF))
        EMIT(0x06000000, func_80088360(buffer->base))
        EMIT(0x08000000, (u32)(length << 1) & 0xFFFF)
    } else {
        EMIT(0x08000000, (((u32)offset & 0xFFFF) << 16) | ((u32)(length << 1) & 0xFFFF))
        EMIT(0x06000000, func_80088360(start))
    }
    return gfx;
}
