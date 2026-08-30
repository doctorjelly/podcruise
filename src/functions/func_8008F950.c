/* Independently written from specs/functions/recovered/func_8008F950.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x14];
    s32 index;
    u8 pad18[4];
    void **entries;
} PcDispatch8008F950;

s32 func_8008F950(PcDispatch8008F950 *dispatch, s32 kind, void *value) {
    void **entries;

    entries = dispatch->entries;
    if (kind == 2) {
        entries[dispatch->index] = value;
        dispatch->index++;
    }
    return 0;
}
