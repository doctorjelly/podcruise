/* Independently written from scratchpad spec specs/func_80006704.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x104];
    /* 0x104 */ s32 count;
    /* 0x108 */ u8 unk108[0x0C];
    /* 0x114 */ f32 position;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ f32 *keys;
} PcKeyTrack;

s32 func_80006704(PcKeyTrack *track) {
    s32 index;

    if (track->keys[track->count - 1] < track->position) {
        return track->count - 2;
    }
    if (track->position < track->keys[0]) {
        return 0;
    }
    index = track->count - 2;
    while (track->position < track->keys[index]) {
        index--;
    }
    return index;
}
