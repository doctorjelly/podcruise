/* Independently written from scratchpad spec specs/func_80080408.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ f32 unk08;
} Track80080408;

extern s32 func_8003A568(Track80080408 *, s32);
extern f32 D_800ADC60;
extern void *D_8011DCF8[];

void *func_80080408(Track80080408 *track) {
    s32 lane;
    s32 step;
    s32 base;
    s32 index;
    f32 scaled;

    lane = func_8003A568(track, 0);
    scaled = track->unk08 * 10.0f;
    if (scaled < 0.0f) {
        step = (s32)(scaled - D_800ADC60);
    } else {
        step = (s32)scaled;
    }
    base = lane * 10;
    index = step + base;
    return D_8011DCF8[index];
}
