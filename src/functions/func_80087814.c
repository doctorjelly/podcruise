/* Independently written from scratchpad spec specs/func_80087814.md. */
#include "podcruise/types.h"

extern s16 D_800A6978;
extern s16 D_80114470[2];
extern s16 D_80148B60[][4];

void func_80087814(left, top, right, bottom)
s16 left;
s16 top;
s16 right;
s16 bottom;
{
    s32 index;
    s16 width;
    s16 height;

    index = D_800A6978;
    if (index < 31) {
        left--;
        top--;
        right++;
        bottom++;
        if (left < 0) {
            left = 0;
        }
        if (top < 0) {
            top = 0;
        }
        width = D_80114470[0];
        if (width - 1 < right) {
            right = width - 1;
        }
        height = D_80114470[1];
        if (height - 1 < bottom) {
            bottom = height - 1;
        }
        if (left < right && top < bottom) {
            D_80148B60[index][0] = left * (width / 320.0);
            D_80148B60[index][1] = top * (height / 240.0);
            D_80148B60[index][2] = right * (width / 320.0);
            D_80148B60[index][3] = bottom * (height / 240.0);
            D_800A6978 = index + 1;
        }
    }
}
