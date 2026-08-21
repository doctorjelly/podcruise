/* Independently written from scratchpad spec specs/func_80073470.md. */

#include "podcruise/types.h"

typedef struct Owner {
    char unk_000[0x344];
    void **entries;
} Owner;

extern void func_800181BC(void *entry, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 D_800A6668;

void func_80073470(Owner *owner) {
    void **entries;
    s32 i;

    entries = owner->entries;
    if (entries != 0) {
        D_800A6668 = 0;
        for (i = 0; i < 75; i++) {
            if (entries[i] != 0) {
                func_800181BC(entries[i], 2, 3, 0x10, 2);
                entries = owner->entries;
            }
        }
        if (entries[61] != 0) {
            func_800181BC(entries[61], 2, -4, 0x10, 3);
            entries = owner->entries;
        }
        for (i = 62; i < 65; i++) {
            if (entries[i] != 0) {
                func_800181BC(entries[i], 2, 3, 0x10, 2);
                entries = owner->entries;
            }
        }
        if (entries[16] != 0) {
            func_800181BC(entries[16], 2, -4, 0x10, 3);
            entries = owner->entries;
        }
        if (entries[14] != 0) {
            func_800181BC(entries[14], 2, -4, 0x10, 3);
            entries = owner->entries;
        }
        if (entries[15] != 0) {
            func_800181BC(entries[15], 2, -4, 0x10, 3);
        }
    }
}
