/* Recovered per specs/func_80091B68.md (worker specification). */
#include "podcruise/types.h"

typedef struct Object80091B68 {
    u8 pad0[0x60];
    s32 unk60;
    u8 unk64;
} Object80091B68;

typedef struct Out80091B68 {
    u8 pad0[0x100];
    u8 unk100;
    u8 flags[0x100];
} Out80091B68;

typedef union Entry80091B68 {
    u16 half;
    struct {
        u8 hi;
        u8 lo;
    } b;
} Entry80091B68;

extern s32 func_80091354(Object80091B68 *object, Entry80091B68 *entries, s32 arg2, u8 arg3);

s32 func_80091B68(Object80091B68 *object, Out80091B68 *out) {
    s32 index;
    s32 counter;
    s32 offset;
    u8 iteration;
    Entry80091B68 entry;
    Entry80091B68 entries[128];
    s32 spare[1];

    (void)spare;
    for (counter = 0; counter < 0x100; counter++) {
        out->flags[counter] = 0;
    }
    out->unk100 = 0xFF;
    for (iteration = 0; iteration < object->unk64; iteration++) {
        if (iteration > 0) {
            index = 1;
        } else {
            index = object->unk60;
        }
        offset = func_80091354(object, entries, 0, iteration);
        if (offset != 0 && offset != 3) {
            return offset;
        }
        for (counter = index; counter < 0x80; counter++) {
            entry = entries[counter];
            if (entry.half >= object->unk60 && entry.b.hi != iteration) {
                offset = entry.b.lo / 4 + (entry.b.hi % 8) * 32;
                out->flags[offset] |= 1 << (iteration % 8);
            }
        }
    }
    return 0;
}
