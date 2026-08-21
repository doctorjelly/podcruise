/* Independently written from scratchpad spec specs/func_80030A7C.md. */

#include "podcruise/types.h"

void func_80030A7C(u32 *displayList, u32 *patchList) {
    u32 *out;
    u32 *in;
    s32 count;

    out = displayList;
    in = patchList;

    while (*out != 0xFFFFFFFF) {
        if (*in != 0) {
            *out = *in;
        }
        out++;
        in++;
    }
    out++;
    in++;

    if (*out == 0x44617461) {
        out++;
        count = (s32)*out;
        out++;
        while (count > 0) {
            count--;
            out++;
        }
    }

    if (*out == 0x416E696D) {
        while (*out != 0) {
            out++;
        }
        out++;
    }

    if (*out == 0x416C744E && *in == 0x416C744E) {
        out++;
        in++;
        while (*out != 0) {
            *(u32 *)(unsigned long)*out = *in;
            out++;
            in++;
        }
    }
}
