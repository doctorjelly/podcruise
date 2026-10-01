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
    Sequence80096158 *seq;
    Channel80096158 *channel;

    seq = sequence;
    field = selector - 2;
    value = *input;
    switch (field % 8) {
        case 0:
            seq->voices[field / 8].start = value & ~7;
            break;
        case 1:
            seq->voices[field / 8].end = value & ~7;
            break;
        case 2:
            seq->voices[field / 8].first = value;
            break;
        case 3:
            seq->voices[field / 8].second = value;
            break;
        case 4:
            seq->voices[field / 8].third = value;
            break;
        case 5:
            seq->voices[field / 8].rate = ((f32)value / 1000.0f) * 2.0 /
                          (f64)D_800A6990->rate;
            break;
        case 6:
            seq->voices[field / 8].position =
                ((f64)(f32)value / 173123.40490667601) *
                (f64)(seq->voices[field / 8].end - seq->voices[field / 8].start);
            break;
        case 7:
            channel = seq->voices[field / 8].channel;
            if (channel != 0) {
                channel->value = value;
                func_8008D7D0(seq->voices[field / 8].channel);
            }
            break;
    }
    return 0;
}
