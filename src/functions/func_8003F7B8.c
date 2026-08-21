/* Specification: scratchpad specs/func_8003F7E4.md (corrected boundary: func_8003F7B8) */
#include "podcruise/types.h"

typedef struct Entry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Entry;

extern Entry **D_800A2170;

s32 func_8003F7B8(s32 key) {
    Entry **cursor;
    Entry *entry;
    s32 target;

    cursor = D_800A2170;
    entry = *cursor;
    target = key;
    key = 0;
    for (; entry != 0; cursor++, entry = *cursor) {
        if (entry->unk_00 == target) {
            return entry->unk_08;
        }
    }
    return key;
}
