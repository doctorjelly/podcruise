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
    s16 *end;
    s16 *stop;
    Buffer *buf;
    s32 off;
    s32 len;
    s32 head;
    s32 tail;

    gfx = list;
    buf = buffer;
    off = offset;
    len = length;
    end = buf->base + buf->count;
    if (start < buf->base) {
        start += buf->count;
    }
    stop = start + len;
    if (end < stop) {
        gfx->w0 = 0x08000000;
        head = (end - start) * 2;
        gfx->w1 = ((u32)off << 16) | ((u32)head & 0xFFFF);
        gfx++;
        EMIT(0x06000000, func_80088360(start))
        tail = (stop - end) * 2;
        EMIT(0x08000000, ((u32)(off + head) << 16) | ((u32)tail & 0xFFFF))
        EMIT(0x06000000, func_80088360(buf->base))
        EMIT(0x08000000, (u32)(len * 2) & 0xFFFF)
    } else {
        gfx->w0 = 0x08000000;
        gfx->w1 = ((u32)off << 16) | ((u32)(len * 2) & 0xFFFF);
        gfx++;
        EMIT(0x06000000, func_80088360(start))
    }
    return gfx;
}
