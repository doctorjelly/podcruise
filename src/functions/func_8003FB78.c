/* Specification: scratchpad specs/func_8003FBB8.md (corrected boundary: func_8003FB78) */
#include "podcruise/types.h"

typedef struct Entry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} Entry;

extern Entry **D_800A2170;

s32 func_8003FB78(s32 key, s32 arg1, s32 arg2) {
    Entry **cursor;
    Entry *entry;
    s32 target;

    cursor = D_800A2170;
    entry = *cursor;
    target = key;
    key = 0;
    for (; entry != 0; cursor++, entry = *cursor) {
        if (entry->unk_00 == target) {
            entry->unk_10 = arg2;
            entry->unk_08 = arg1;
            return entry->unk_0C * arg1;
        }
    }
    return key;
}
