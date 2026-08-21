/* Recovered from specs/func_8005C210.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s16 unk04;
    /* 0x06 */ u8 pad06[0x50 - 0x06];
    /* 0x50 */ u8 unk50[0x10];
    /* 0x60 */ u32 unk60;
    /* 0x64 */ u32 unk64;
} Sub;

typedef struct {
    /* 0x00 */ u8 pad00[0x5C];
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 pad5E[0x84 - 0x5E];
    /* 0x84 */ Sub *unk84;
    /* 0x88 */
} Entry;

typedef struct {
    /* 0x000 */ u8 pad00[8];
    /* 0x008 */ u32 unk08;
    /* 0x00C */ u8 pad0C[0x1BC - 0x0C];
    /* 0x1BC */ s32 unk1BC;
} Owner;

extern void func_8000FEAC(s32 arg0, void *arg1, s32 arg2);
extern s32 D_800A52BC;
extern Entry *D_8011B1B8;
extern Entry *D_8011B1BC;
extern Entry *D_8011B1C0;

void func_8005C210(Owner *owner) {
    Entry *entry;
    Sub *sub;
    s16 value;
    s32 i;

    if ((owner->unk08 & 0xF) == 1 && !(owner->unk08 & 0x20)) {
        for (i = 0; i < owner->unk1BC; i++) {
            entry = &D_8011B1B8[i];
            sub = entry->unk84;
            func_8000FEAC(sub->unk04, sub->unk50, -9999);
            if (!(sub->unk60 & 0x5000) && !(sub->unk64 & 0x2000000)) {
                value = entry->unk5C;
                if (value > 0) {
                    if (entry == D_8011B1BC || entry == D_8011B1C0) {
                        if (D_800A52BC >= 2) {
                            func_8000FEAC(sub->unk04, sub->unk50, -value);
                        }
                    } else {
                        func_8000FEAC(sub->unk04, sub->unk50, value);
                    }
                }
            }
        }
    }
}
