/* Independently written from scratchpad spec specs/func_80005CAC.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x11C];
    /* 0x11C */ f32 *keys;
} PcKeySpanTrack;

f32 func_80005CAC(PcKeySpanTrack *track, f32 position, s32 index) {
    f32 lower = track->keys[index];
    f32 upper = track->keys[index + 1];

    return (position - lower) / (upper - lower);
}
