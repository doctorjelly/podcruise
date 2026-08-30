/* Independently written from specs/functions/recovered/func_80096158.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 value;
} Channel80096158;

typedef struct {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ s16 first;
    /* 0x0A */ s16 second;
    /* 0x0C */ s16 third;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 rate;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ f32 position;
    /* 0x20 */ Channel80096158 *channel;
    /* 0x24 */ void *unk24;
} Voice80096158;

typedef struct {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ Voice80096158 *voices;
} Sequence80096158;

typedef struct {
    /* 0x00 */ u8 unk00[0x44];
    /* 0x44 */ s32 rate;
} Runtime80096158;

extern Runtime80096158 *D_800A6990;

extern void func_8008D7D0(Channel80096158 *channel);

s32 func_80096158(Sequence80096158 *sequence, s32 selector, const s32 *input) {
    s32 field;
    s32 value;
    Voice80096158 *voice;
    Channel80096158 *channel;

    field = selector - 2;
    value = *input;
    switch (field & 7) {
        case 0:
            voice = &sequence->voices[field / 8];
            voice->start = value & ~7;
            break;
        case 1:
            voice = &sequence->voices[field / 8];
            voice->end = value & ~7;
            break;
        case 2:
            voice = &sequence->voices[field / 8];
            voice->second = value;
            break;
        case 3:
            voice = &sequence->voices[field / 8];
            voice->first = value;
            break;
        case 4:
            voice = &sequence->voices[field / 8];
            voice->third = value;
            break;
        case 5:
            voice = &sequence->voices[field / 8];
            voice->rate = ((f32)value / 1000.0f) * 2.0 /
                          (f64)D_800A6990->rate;
            break;
        case 6:
            voice = &sequence->voices[field / 8];
            voice->position =
                ((f64)(f32)value / 173123.40490667601) *
                (f64)(voice->end - voice->start);
            break;
        case 7:
            voice = &sequence->voices[field / 8];
            channel = voice->channel;
            if (channel != 0) {
                channel->value = value;
                func_8008D7D0(channel);
            }
            break;
    }
    return 0;
}
