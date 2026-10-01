/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

typedef struct Slot {
    s8 owner;
    s8 unk_01;
    s8 unk_02;
} Slot;

typedef struct Entry {
    u8 unk_00[0x20];
} Entry;

extern Entry D_800A4C00[];
extern Entry D_800A4E00[];
extern Slot D_8011A210[];

extern s32 func_80082BE0(void);

void func_8005163C(s32 arg0) {
    s32 placed;
    s32 tries;
    s32 index;

    (void)arg0;
    tries = 0;
    index = 0;
    do {
        D_8011A210[index].owner = -1;
        *(s16 *)((u8 *)&D_800A4C00[index] + 0x98) = -1;
        D_8011A210[index].unk_01 = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 5.0f) + 1;
        D_8011A210[index].unk_02 = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 129.0f) + 0x66;
        index++;
    } while (&D_800A4C00[index] < D_800A4E00);

    for (placed = 0; placed < 7 && tries < 16;) {
        do {
            index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 16.0f);
        } while (D_8011A210[index].owner != -1);
        D_8011A210[index].owner = placed;
        placed++;
        *(s16 *)((u8 *)&D_800A4C00[index] + 0x98) = 4;
        tries++;
    }
}
