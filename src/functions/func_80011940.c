/* Implements specification specs/func_80011940.md (sliding-window decompressor). */
#include "podcruise/types.h"

u8 *func_80011940(u8 *source, u8 *destination) {
    u8 *window;
    s32 ringIndex;
    s32 finished;
    s32 byte;
    u8 control;
    s16 slot;
    s32 high;
    s32 low;
    s32 index;

    window = source - 0x1000;
    ringIndex = 1;
    finished = 0;
    do {
        control = *source++;
        for (slot = 0; slot < 8; slot++) {
            if (control & (1 << slot)) {
                byte = *source++;
                *destination = (u8)byte;
                window[ringIndex] = (u8)byte;
                destination++;
                ringIndex = (ringIndex + 1) & 0xFFF;
            } else {
                high = source[0];
                low = source[1];
                source += 2;
                low += (high & 0xF) << 8;
                high = high >> 4;
                if (low == 0) {
                    finished = 1;
                    break;
                }
                high = high + 1;
                for (index = 0; index <= high; index++) {
                    byte = window[(low + index) & 0xFFF];
                    *destination = (u8)byte;
                    window[ringIndex] = (u8)byte;
                    ringIndex = (ringIndex + 1) & 0xFFF;
                    destination++;
                }
            }
        }
    } while (finished == 0);
    return destination;
}
