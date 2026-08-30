/* Independently written from specs/functions/recovered/func_8000803C.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x38];
    u32 *counts;
    u8 pad3C[0x18];
    u32 limit;
} PcCountState8000803C;

typedef struct {
    u8 pad00[8];
    PcCountState8000803C *state;
    u8 pad0C[0x24];
} PcTableEntry8000803C;

typedef struct {
    u8 pad00[0x40];
    PcTableEntry8000803C *table;
} PcObject8000803C;

s32 func_8000803C(PcObject8000803C *object, s32 index) {
    PcTableEntry8000803C *table;
    PcCountState8000803C *state;
    u32 *counts;

    table = object->table;
    state = table[index].state;
    if (state != 0) {
        counts = state->counts;
        if ((counts[1] + counts[0]) < state->limit) {
            return 1;
        }
    }
    return 0;
}
