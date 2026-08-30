/* Independently written from specs/functions/recovered/func_8008F980.md. */

#include "podcruise/types.h"

typedef u32 *(*PcEmit8008F980)(void *, s32, s32, s32, u32 *);

typedef struct {
    /* 0x00 */ void *unk00;
    /* 0x04 */ PcEmit8008F980 emit;
} PcEntry8008F980;

typedef struct {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 count;
    /* 0x18 */ void *unk18;
    /* 0x1C */ PcEntry8008F980 **entries;
} PcHandler8008F980;

u32 *func_8008F980(void *handler_arg, s32 arg1, s32 arg2, s32 arg3,
                   u32 *output) {
    PcHandler8008F980 *handler = handler_arg;
    s32 i;
    u32 *cursor;

    output[0] = 0x020006C0;
    output[1] = arg2 << 1;
    output[2] = 0x02000800;
    output[3] = arg2 << 1;
    cursor = output + 4;

    for (i = 0; i < handler->count; i++) {
        PcEntry8008F980 *entry = handler->entries[i];

        cursor = entry->emit(entry, arg1, arg2, arg3, cursor);
    }
    return cursor;
}
