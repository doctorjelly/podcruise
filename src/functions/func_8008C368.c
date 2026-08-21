/* Recovered per specs/func_8008C368.md (boundary corrected: real entry is func_8008C344). */
#include "podcruise/types.h"

u8 *func_8008C344(u8 *text, s32 target) {
    register u8 wanted;

    wanted = (u8)target;
    while (*text != wanted) {
        if (*text == 0) {
            return (u8 *)0;
        }
        text++;
    }
    return text;
}
