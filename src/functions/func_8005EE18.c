/* Independently written from scratchpad spec specs/func_8005EE18.md. */

#include "podcruise/types.h"

typedef union {
    s32 word;
    f32 value;
} Token;

extern void func_8000FF54(s32 index, f32 *source);

void func_8005EE18(Token *stream) {
    Token *cursor;
    Token *next;
    s32 count;
    s32 i;
    f32 vector[3];

    cursor = stream;
    while (cursor->word != -1) {
        cursor++;
    }
    cursor++;
    if (cursor->word == 0x44617461) {
        count = cursor[1].word;
        cursor += 2;
        for (i = 0; i < count; i++) {
            if (cursor->word == 0x4C537472) {
                next = cursor + 4;
                vector[0] = cursor[1].value;
                vector[1] = cursor[2].value;
                vector[2] = cursor[3].value;
                func_8000FF54(i, vector);
                cursor = next;
            } else {
                cursor++;
            }
        }
    }
}
