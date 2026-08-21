/* Independently written from scratchpad spec specs/func_80005CD4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x11C];
    /* 0x11C */ f32 *stops;
    /* 0x120 */ f32 *values;
} PcRampTrack;

extern f32 func_80005CAC(PcRampTrack *track, f32 position, s32 index);

void func_80005CD4(f32 *out, PcRampTrack *track, f32 position, s32 index) {
    f32 blend;
    f32 lower;
    f32 upper;

    if (track->stops[index + 1] < position) {
        *out = track->values[index + 1];
    } else if (position <= track->stops[index]) {
        *out = track->values[index];
    } else {
        blend = func_80005CAC(track, position, index);
        lower = track->values[index];
        upper = track->values[index + 1];
        *out = blend * upper + (1.0f - blend) * lower;
    }
}
