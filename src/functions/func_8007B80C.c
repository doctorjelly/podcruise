/* Recovered per specs/func_8007B80C.md (boundary corrected: real entry is func_8007B7BC). */
#include "podcruise/types.h"

typedef struct {
    u8 unk000[0x100];
    s32 flags;
    u8 unk104[4];
    f32 unk108;
    u8 unk10C[8];
    f32 unk114;
} Entry8007B7BC;

extern Entry8007B7BC **D_8011C8F0[];

s32 func_8007B7BC(s32 index) {
    Entry8007B7BC **list = D_8011C8F0[index];
    Entry8007B7BC *entry = list[0];

    while (entry != 0) {
        if (!(entry->flags & 0x10000000) || entry->unk108 <= entry->unk114) {
            return 1;
        }
        list++;
        entry = list[0];
    }
    return 0;
}
