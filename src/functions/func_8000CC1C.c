/* Independently written from specs/func_8000CC1C.md. */

#include "podcruise/types.h"

typedef struct Target {
    s8 pad00[0x1C];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
} Target;

typedef struct Entry {
    s8 pad00[6];
    s16 unk06;
    s8 pad08[0x64];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    s8 padAC[0x5C];
    f32 unk108;
    s8 pad10C[0x1D64];
    Target *unk1E70;
} Entry;

static const u32 D_800A85A0[3] = { 0, 0, 0 };

extern s32 D_8009B7E0;
extern s32 D_8009B804;

extern Entry *func_8003F714(s32 id, s32 key);
extern void func_8000C6C8(f32 *value, f32 rate, f32 scale, f32 lower, f32 upper);
extern f32 sqrtf(f32 value);

#ifdef __sgi
#pragma intrinsic (sqrtf)
#endif

void func_8000CC1C(s32 selector, f32 value) {
    Entry *entry;
    f32 pad0;
    f32 temp;
    f32 pad2;
    f32 pad3;

    (void)D_800A85A0;
    D_8009B804 = 1;
    entry = func_8003F714(0x54657374, D_8009B7E0);
    if (entry == 0) {
        return;
    }

    switch (selector) {
    case 0:
        value = (0.0f < value) ? 1.0f : -1.0f;
        D_8009B7E0 = (s32)((f32)D_8009B7E0 + value);
        entry = func_8003F714(0x54657374, D_8009B7E0);
        if ((entry == 0) || (entry->unk06 & 0x100)) {
            if (value < 0.0f) {
                while (value < 0.0f) {
                    D_8009B7E0 = D_8009B7E0 + 1;
                    entry = func_8003F714(0x54657374, D_8009B7E0);
                    if ((entry == 0) || (entry->unk06 & 0x100)) {
                        value = 0.0f;
                        D_8009B7E0 = D_8009B7E0 - 1;
                    }
                }
            } else {
                D_8009B7E0 = 0;
            }
        }
        break;
    case 1:
        if (entry != 0) {
            func_8000C6C8(&entry->unk6C, value, 0.01f, 0.05f, 1.0f);
            entry->unk1E70->unk1C = entry->unk6C;
        }
        break;
    case 2:
        if (entry != 0) {
            func_8000C6C8(&entry->unk70, value, 1.0f, 10.0f, 1000.0f);
            entry->unk1E70->unk20 = entry->unk70;
        }
        break;
    case 3:
        if (entry != 0) {
            func_8000C6C8(&entry->unk74, value, 1.0f, 10.0f, 1000.0f);
            entry->unk1E70->unk24 = entry->unk74;
        }
        break;
    case 4:
        if (entry != 0) {
            func_8000C6C8(&entry->unk78, value, 0.01f, 0.02f, 10.0f);
            entry->unk1E70->unk28 = entry->unk78;
        }
        break;
    case 5:
        if (entry != 0) {
            func_8000C6C8(&entry->unk7C, value, 1.0f, 100.0f, 2000.0f);
            entry->unk1E70->unk2C = entry->unk7C;
        }
        break;
    case 6:
        if (entry != 0) {
            func_8000C6C8(&entry->unk80, value, 0.5f, 2.0f, 1000.0f);
            entry->unk1E70->unk30 = entry->unk80;
        }
        break;
    case 7:
        if (entry != 0) {
            func_8000C6C8(&entry->unk84, value, 0.5f, 2.0f, 1000.0f);
            entry->unk1E70->unk34 = entry->unk84;
        }
        break;
    case 8:
        if (entry != 0) {
            func_8000C6C8(&entry->unk88, value, 1.0f, 10.0f, 1000.0f);
            entry->unk1E70->unk38 = entry->unk88;
        }
        break;
    case 9:
        if (entry != 0) {
            func_8000C6C8(&entry->unk8C, value, 0.1f, 0.1f, 30.0f);
            entry->unk1E70->unk3C = entry->unk8C;
        }
        break;
    case 10:
        if (entry != 0) {
            func_8000C6C8(&entry->unk90, value, 0.1f, 0.1f, 20.0f);
            entry->unk1E70->unk40 = entry->unk90;
        }
        break;
    case 11:
        if (entry != 0) {
            func_8000C6C8(&entry->unk94, value, 0.05f, 3.0f, 30.0f);
            entry->unk1E70->unk44 = entry->unk94;
        }
        break;
    case 12:
        if (entry != 0) {
            func_8000C6C8(&entry->unk98, value, 0.01f, 0, 1.0f);
            entry->unk1E70->unk48 = entry->unk98;
        }
        break;
    case 13:
        if (entry != 0) {
            func_8000C6C8(&entry->unk9C, value, 0.1f, 1.0f, 100.0f);
            entry->unk1E70->unk4C = entry->unk9C;
        }
        break;
    case 14:
        if (entry != 0) {
            func_8000C6C8(&entry->unkA0, value, 0.01f, 0, 1.0f);
            entry->unk1E70->unk50 = entry->unkA0;
        }
        break;
    case 15:
        if (entry != 0) {
            func_8000C6C8(&entry->unkA8, value, 0.05f, 0.05f, 20.0f);
            entry->unk1E70->unk54 = entry->unkA8;
        }
        break;
    case 16:
        if (entry != 0) {
            temp = sqrtf(entry->unk108);
            func_8000C6C8(&temp, value, 1.0f, 10.0f, 500.0f);
            entry->unk108 = temp * temp;
        }
        break;
    }
}
