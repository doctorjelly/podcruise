/* Independently written from scratchpad spec specs/func_8000F5A0.md. */

#include "podcruise/types.h"

extern s16 D_80114470[];
extern u16 *D_80114528;
extern s32 D_8009B814[];
extern s32 D_8009B86C;
extern s32 D_800D57A0[];
extern s32 D_800D57A8[];
extern s32 D_800D57C0[];
extern s32 D_800D5958[];
extern s32 D_800D5988[];
extern s32 D_800D5AF8[];
extern s32 D_800D5B48[];
extern s32 D_800D5B98[];
extern s32 D_800D5BE8[];
extern u8 D_800D5C38[];
extern s32 D_800D5E40[];
extern s32 D_800D5EE0[];
extern s32 D_800D5FD0[];
extern s32 D_800D6020[];
extern s32 D_800D6070[];
extern s32 D_800D60A0[];

void func_8000F5A0(void) {
    u16 *buffer;
    u16 *end[1]; /* held out of a register: the original keeps this bound live */
    u16 *sample;
    s32 width;
    s32 height;
    s32 index;
    s32 row;
    s32 column;
    s32 count;
    s32 x;
    s32 y;
    register s32 columnMax;
    register s32 rowMax;

    width = D_80114470[0];
    height = D_80114470[1];
    buffer = D_80114528;
    end[0] = buffer + width * height;

    for (index = 0; index < 2; index++) {
        if (D_8009B814[index] < 0) {
            continue;
        }
        x = D_800D57A0[index];
        y = D_800D57A8[index];
        if (x < -500) {
            D_800D57C0[index] = 50;
            continue;
        }
        count = 0;
        columnMax = width - x - 8;
        rowMax = height - y - 8;
        sample = buffer + (y - 4) * width + (x - 4);
        for (row = 0; row < 8; row++) {
            for (column = 0; column < 8; column++) {
                if (column < 12 - x || column >= columnMax || row < 12 - y ||
                    row >= rowMax) {
                    count++;
                } else if (sample >= buffer && sample < end[0] && (s32)*sample < 65500) {
                    count++;
                }
                sample++;
            }
            sample += width - 8;
        }
        D_800D57C0[index] = count;
    }

    for (index = 0; index < 20; index++) {
        D_800D5FD0[index] = -1000;
        if (D_800D5AF8[index] >= 0) {
            D_800D5FD0[index] = buffer[D_800D5B48[index] * width + D_800D5AF8[index]];
        }
        D_800D6020[index] = -1000;
        if (D_800D5B98[index] >= 0) {
            D_800D6020[index] = buffer[D_800D5BE8[index] * width + D_800D5B98[index]];
        }
    }

    for (index = 0; index < 40; index++) {
        if (D_800D5C38[index] != 0) {
            D_800D60A0[index] = -1000;
            if (D_800D5E40[index] >= 0) {
                D_800D60A0[index] = buffer[D_800D5EE0[index] * width + D_800D5E40[index]];
            }
        }
    }

    for (index = 0; index < D_8009B86C; index++) {
        D_800D6070[index] = -1000;
        if (D_800D5958[index] >= 0) {
            D_800D6070[index] = buffer[D_800D5988[index] * width + D_800D5958[index]];
        }
    }
}
