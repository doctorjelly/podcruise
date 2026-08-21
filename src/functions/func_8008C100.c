/* Independently written from scratchpad spec specs/func_8008C100.md. */

#include "podcruise/types.h"

extern void *func_80094C80(void *, u8, void *);

void *func_8008C100(void *arg0, u8 page, u8 *buffer, s32 length) {
    void *result;

    result = 0;
    while (length > 0) {
        result = func_80094C80(arg0, page, buffer);
        if (result != 0) {
            return result;
        }
        length -= 8;
        page++;
        buffer += 8;
    }
    return result;
}
