/* Independently written from scratchpad spec specs/func_8008A8C0.md. */

#include "podcruise/types.h"

extern f64 D_800ADE20[];
extern f64 D_800ADE48;
extern f64 D_800ADE50;
extern f64 D_800ADE58;
extern f32 D_800ADE60;
extern f32 D_800AE110;

f32 func_8008A8C0(f32 x) {
    f64 wide;
    f64 square;
    f64 series;
    f64 scaled;
    f64 turns;
    s32 bits;
    s32 shape;
    s32 count;

    bits = *(s32 *)&x;
    shape = (bits >> 22) & 0x1FF;

    if (shape < 0xFF) {
        wide = x;
        if (shape >= 0xE6) {
            square = wide * wide;
            series = ((D_800ADE20[4] * square + D_800ADE20[3]) * square + D_800ADE20[2]) *
                         square +
                     D_800ADE20[1];
            return (f32)(wide * square * series + wide);
        }
        return x;
    }

    if (shape < 0x136) {
        wide = x;
        scaled = wide * D_800ADE48;
        if (scaled >= 0.0) {
            count = (s32)(scaled + 0.5);
        } else {
            count = (s32)(scaled - 0.5);
        }
        turns = count;
        wide = wide - turns * D_800ADE50;
        wide = wide - turns * D_800ADE58;
        square = wide * wide;
        series = ((D_800ADE20[4] * square + D_800ADE20[3]) * square + D_800ADE20[2]) *
                     square +
                 D_800ADE20[1];
        if ((count & 1) == 0) {
            return (f32)(wide * square * series + wide);
        }
        return -(f32)(wide * square * series + wide);
    }

    if (x != x) {
        return D_800AE110;
    }
    return D_800ADE60;
}
