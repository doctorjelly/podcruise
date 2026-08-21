/* Specification: scratchpad specs/func_8003F874.md (corrected boundary: func_8003F800) */
#include "podcruise/types.h"

typedef struct Entry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} Entry;

extern Entry **D_800A2170;
extern Entry *D_800A4AA4[1];
extern s32 D_80118D10;

s32 func_8003F800(s32 key, s32 index) {
    Entry **cursor;
    Entry *entry;
    s32 base;
    s32 target;

    D_800A4AA4[0] = 0;
    cursor = D_800A2170;
    entry = *cursor;
    target = key;
    key = 0;
    for (; entry != 0; cursor++, entry = *cursor) {
        if (entry->unk_00 == target) {
            base = entry->unk_10;
            if (index >= entry->unk_08) {
                return 0;
            }
            D_800A4AA4[0] = entry;
            D_80118D10 = index;
            return base + (entry->unk_0C * index);
        }
    }
    return key;
}
