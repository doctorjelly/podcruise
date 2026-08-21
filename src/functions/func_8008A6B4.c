/* Independently written from specs/functions/func_8008A6B4.md. */

#include "podcruise/types.h"

extern void *func_8008A690(void *state, const char *text, s32 length);
extern s32 func_80093180(void *emit, void *state, const char *format,
                         void *arguments);

s32 func_8008A6B4(char *buffer, const char *format, ...) {
    s32 count;

    count = func_80093180((void *)func_8008A690, buffer, format,
                          (void *)((char **)&format + 1));
    if (count >= 0) {
        buffer[count] = 0;
    }
    return count;
}
