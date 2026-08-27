/* Independently written from scratchpad spec specs/func_80029C24.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ signed char unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 pad02[0x36];
} Slot; /* 0x38 */

typedef struct {
    /* 0x00 */ u8 pad00[3];
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 pad08[8];
} Entry; /* 0x10 */

typedef struct {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[8];
    /* 0x24 */ u8 unk24[0x40];
} Settings;

extern s32 D_8011A270;
extern Slot D_801198A8[];
extern Slot D_8011A050[];
extern Entry D_800A2DE0[];
extern Settings D_80113E60;
extern f32 D_800A9E08;
extern s32 D_800D6CC8;
extern s32 D_800D6CCC;
extern s16 D_800D6CC4;

void func_80029C24(void) {
    Entry *entry;
    Entry *other;
    u8 kind;
    s32 productA;
    s32 productB;

    entry = &D_800A2DE0[D_801198A8[D_8011A270].unk00];
    kind = entry->unk03;
    other = &D_800A2DE0[D_8011A050[kind].unk00];

    productA = D_80113E60.unk24[kind] * other->unk04;
    productB = D_801198A8[D_8011A270].unk01 * entry->unk04;

    D_800D6CC8 = (s32)((f32)productA * D_800A9E08) + 1;
    D_800D6CCC = (s32)((f32)productB * D_800A9E08) + 1;

    if (D_80113E60.unk18 + D_800D6CC8 < D_800D6CCC) {
        D_800D6CC4 = 1;
    } else {
        D_800D6CC4 = 0;
    }
}
