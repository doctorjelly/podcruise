/* Independently written from the specification scratchpad specs/func_8008B318.md. */

#include "podcruise/types.h"

typedef struct {
    u8 bytes[39];
} Block8008B318;

extern s32 func_80093A90(u16);

void func_8008B318(s32 offset, u8 *record) {
    u8 *cursor;
    Block8008B318 block;
    s32 i;

    cursor = record;
    block.bytes[0] = 0xFF;
    block.bytes[1] = 0x23;
    block.bytes[2] = 1;
    block.bytes[3] = 3;
    block.bytes[4] = 0xC0;
    block.bytes[5] = func_80093A90(0x600) | 0xC000;
    if (offset != 0) {
        for (i = 0; i < offset; i++) {
            *cursor++ = 0;
        }
    }
    *(Block8008B318 *)cursor = block;
    cursor += 39;
    *cursor = 0xFE;
}
