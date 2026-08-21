/* Implements the specification in specs/func_80053C08.md (per-entry rank change announcements). */
#include "podcruise/types.h"

typedef struct Big {
    u8 pad00[0x60];
    s32 unk60;
    s32 unk64_lo : 5;
    s32 unk64_flag : 1;
    s32 unk64_hi : 26;
    u8 pad68[0x1998 - 0x68];
    s32 unk1998;
} Big;

typedef struct Record {
    u8 pad00[0x18];
    s32 *unk18;
    u8 pad1C[0x5C - 0x1C];
    s16 unk5C;
    u8 pad5E[0x84 - 0x5E];
    Big *unk84;
} Record;

typedef struct Owner {
    u8 pad000[0x1BC];
    s32 unk1BC;
} Owner;

extern Record *D_8011B1B8;
extern s16 D_8011C7E8[];

extern s32 func_80082BE0(void);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);

void func_80053C08(Owner *owner) {
    s32 spareA[4];
    Record *other;
    Record *rec;
    s32 spareB[1];
    Big *big;
    s32 i;
    s32 j;
    s32 id;
    s32 cur;
    s32 prev;
    s32 n;

    (void)spareA;
    (void)spareB;
    for (i = 0; i < owner->unk1BC; i++) {
        rec = &D_8011B1B8[i];
        if ((rec->unk84->unk60 & 0x20) != 0) {
            cur = rec->unk5C;
            if (cur > 0) {
                prev = D_8011C7E8[i];
                if (prev < cur) {
                    if (cur == 2 || (f32)func_80082BE0() / (f32)2147483648.0 < 0.25f) {
                        id = -1;
                        for (j = 0; j < owner->unk1BC; j++) {
                            other = &D_8011B1B8[j];
                            n = other->unk5C;
                            if (n > 0 && rec != other && rec->unk5C == n + 1) {
                                id = *other->unk18;
                                j = owner->unk1BC;
                            }
                        }
                        if (id != -1) {
                            big = other->unk84;
                            if ((big->unk60 & 0x20) == 0 && !big->unk64_flag && (f64)big->unk1998 < 500.0) {
                                if (id == 0xE) {
                                    if ((f32)func_80082BE0() / (f32)2147483648.0 < 0.5f) {
                                        func_800093B0(1, id, 0x12, 0x12, 0x13, 0x14, 0x15);
                                    } else {
                                        func_800093B0(1, id, 0x17, 0x17, 0x18, 0x19, 0x3);
                                    }
                                } else {
                                    if ((f32)func_80082BE0() / (f32)2147483648.0 < 0.5f) {
                                        func_800093B0(1, id, 0x11, 0x12, 0x13, 0x14, 0x15);
                                    } else {
                                        func_800093B0(1, id, 0x17, 0x17, 0x18, 0x19, 0x3);
                                    }
                                }
                            }
                        }
                    }
                } else if (cur < prev) {
                    if (cur == 1 || (f32)func_80082BE0() / (f32)2147483648.0 < 0.25f) {
                        id = -1;
                        for (j = 0; j < owner->unk1BC; j++) {
                            other = &D_8011B1B8[j];
                            n = other->unk5C;
                            if (n > 0 && rec != other && rec->unk5C + 1 == n) {
                                id = *other->unk18;
                                j = owner->unk1BC;
                            }
                        }
                        if (id != -1) {
                            big = other->unk84;
                            if ((big->unk60 & 0x20) == 0 && !big->unk64_flag && (f64)big->unk1998 < 500.0) {
                                func_800093B0(1, id, 0x15, 0x1, 0x17, 0x3, 0x14);
                            }
                        }
                    }
                }
            }
        }
        D_8011C7E8[i] = rec->unk5C;
    }
}
