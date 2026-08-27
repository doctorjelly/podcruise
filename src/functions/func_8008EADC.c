/* Recovered per specification specs/func_8008EADC.md (audio stream display-list emitter). */
#include "podcruise/types.h"

struct Source;

typedef struct Source {
    s32 unk00;
    u32 *(*unk04)(struct Source *, s16 *, s32, s32, u32 *);
} Source;

typedef struct Stream {
    Source *unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    u32 unk14;
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    s32 unk24;
} Stream;

extern u32 func_80088360(u32);

#define GFX(w0, w1) { u32 *g = dl; dl = g + 2; g[0] = (u32)(w0); g[1] = (u32)(w1); }

u32 *func_8008EADC(Stream *stream, s16 *arg1, s32 arg2, s32 arg3, u32 *list) {
    Source *source;
    u32 *dl;
    s16 count;
    s32 samples;
    f32 value;

    source = stream->unk00;
    count = 320;
    if (arg2 == 0) {
        return list;
    }

    if (stream->unk1C != 0) {
        dl = source->unk04(source, &count, arg2, arg3, list);
        GFX(((u32)count & 0xFFFFFF) | 0x0A000000, ((u32)*arg1 << 16) | ((u32)(arg2 * 2) & 0xFFFF))
        return dl;
    }

    if (stream->unk18 > 1.99996) {
        stream->unk18 = 1.999959945678711f;
    }
    stream->unk18 = (f32)(s32)(stream->unk18 * (f32)32768.0);
    stream->unk18 = stream->unk18 / (f32)32768.0;
    value = stream->unk20 + stream->unk18 * (f32)arg2;
    samples = (s32)value;
    stream->unk20 = value - (f32)samples;

    dl = source->unk04(source, &count, samples, arg3, list);
    GFX(((u32)count & 0xFFFF) | 0x08000000, ((u32)*arg1 << 16) | ((u32)(arg2 * 2) & 0xFFFF))
    GFX((((u32)stream->unk24 & 0xFF) << 16) | 0x05000000 | ((u32)(s32)(stream->unk18 * (f32)32768.0) & 0xFFFF), func_80088360(stream->unk14))
    stream->unk24 = 0;
    return dl;
}
