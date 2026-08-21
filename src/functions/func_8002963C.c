/* Recovered from specification $S/specs/func_8002963C.md */
#include "podcruise/types.h"

typedef struct Rec8002963C {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[5];
    s32 unk8;
    u8 padC[4];
} Rec8002963C;

typedef struct Slot8002963C {
    u8 unk0;
    u8 unk1;
    u8 pad2[0x36];
} Slot8002963C;

typedef struct Group8002963C {
    s8 unk0;
    u8 unk1;
    u8 pad2[0x36];
} Group8002963C;

typedef struct Triple8002963C {
    u8 unk0;
    s8 unk1;
    u8 unk2;
} Triple8002963C;

typedef struct Owner8002963C {
    u8 pad0[8];
    s32 unk8;
} Owner8002963C;

extern u8 D_800A21B4[4];
extern u8 D_80113E60[];
extern u8 D_80113E68[4];
extern Rec8002963C D_800A2DE0[];
extern Slot8002963C D_801198A8[];
extern Group8002963C D_8011A050[7];
extern Triple8002963C D_8011A210[7];
extern s32 D_8011A240[];

extern void func_80046670(s32 arg0, s32 arg1, s32 slot, s32 arg3);

void func_8002963C(Owner8002963C *owner) {
    s32 i;
    s32 bit;
    s32 g;
    s32 k;
    s32 n;
    s32 c;
    u8 total;

    total = 0;
    D_8011A240[11] = 0;
    for (i = 0; i < 4; i++) {
        for (bit = 0; bit < D_800A21B4[i]; bit++) {
            if ((D_80113E68[i] & (1 << bit)) != 0) {
                total = total + 1;
            }
        }
    }

    for (g = 0; g < 7; g++) {
        D_8011A050[g].unk0 = D_80113E60[0x1D + g] + g * 6;
        D_8011A050[g].unk1 = D_80113E60[0x24 + g];
    }

    if (owner->unk8 == 7) {
        for (g = 0; g < 7; g++) {
            n = D_8011A050[g].unk0;
            for (k = 0; k < 6; k += 2) {
                if (g * 6 + k != n) {
                    if (total >= D_800A2DE0[g * 6 + k].unk2 + 3) {
                        c = D_8011A240[11];
                        D_8011A240[11] = c + 1;
                        D_801198A8[c].unk0 = g * 6 + k;
                        D_801198A8[c].unk1 = 0xFF;
                    }
                }
                if (g * 6 + k != n - 1) {
                    if (total >= D_800A2DE0[g * 6 + k + 1].unk2 + 3) {
                        c = D_8011A240[11];
                        D_8011A240[11] = c + 1;
                        D_801198A8[c].unk0 = g * 6 + k + 1;
                        D_801198A8[c].unk1 = 0xFF;
                    }
                }
            }
        }
    } else if (owner->unk8 == 4) {
        for (g = 0; g < 7; g++) {
            c = D_8011A240[11];
            D_8011A240[11] = c + 1;
            D_801198A8[c].unk0 = D_8011A210[g].unk1 + g * 6;
            D_801198A8[c].unk1 = D_8011A210[g].unk2;
        }
    }

    for (i = 0; i < D_8011A240[11]; i++) {
        func_80046670(D_800A2DE0[D_801198A8[i].unk0].unk8, -1, i + 0x62, 0);
    }

    for (i = 0; i < 7; i++) {
        func_80046670(D_800A2DE0[D_8011A050[i].unk0].unk8, -1, i + 0x8E, 0);
    }
}
