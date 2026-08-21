/* Independently written from the specification for func_8008C31C. */

#include "podcruise/types.h"

u32 func_8008C31C(const u8 *text) {
    const u8 *cursor = text;

    while (*cursor != 0) {
        cursor++;
    }
    return (u32)(cursor - text);
}
