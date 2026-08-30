/* Independently written from specs/functions/recovered/func_8008A750.md. */

#include "podcruise/types.h"

extern f64 D_800ADDD0[];
extern f64 D_800ADDF8;
extern f64 D_800ADE00;
extern f64 D_800ADE08;
extern f32 D_800ADE10;
extern f32 D_800AE110;

f32 func_8008A750(f32 x) {
    f64 wide;
    f64 square;
    f64 series;
    f64 scaled;
    f64 turns;
    f32 magnitude;
    s32 bits;
    s32 shape;
    s32 count;

    bits = *(s32 *)&x;
    shape = (bits >> 22) & 0x1FF;

    if (shape < 0x136) {
        if (x > 0.0f) {
            magnitude = x;
        } else {
            magnitude = -x;
        }
        wide = magnitude;
        scaled = wide * D_800ADDF8 + 0.5;
        if (scaled >= 0.0) {
            count = (s32)(scaled + 0.5);
        } else {
            count = (s32)(scaled - 0.5);
        }
        turns = count - 0.5;
        wide = wide - turns * D_800ADE00;
        wide = wide - turns * D_800ADE08;
        square = wide * wide;
        series = ((D_800ADDD0[4] * square + D_800ADDD0[3]) * square + D_800ADDD0[2]) *
                     square +
                 D_800ADDD0[1];
        if ((count & 1) == 0) {
            return (f32)(wide * square * series + wide);
        }
        return -(f32)(wide * square * series + wide);
    }

    if (x != x) {
        return D_800AE110;
    }
    return D_800ADE10;
}
