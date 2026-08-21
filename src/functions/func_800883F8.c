/* Independently written from the specification for func_800883F8. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x44];
    /* 0x44 */ s32 unk44;
} Stream;

extern f64 D_800ADD80;

s32 func_800883F8(Stream *stream, s32 count) {
    f32 bytes = (f32)count * (f32)stream->unk44 / D_800ADD80 + 0.5;

    return (s32)bytes & ~0xF;
}
