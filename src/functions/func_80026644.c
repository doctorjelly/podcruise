/* Recovered per $S/specs/func_80026644.md (worker specification). */
#include "podcruise/types.h"

typedef struct Unc03Race {
    u8 pad0[0x40];
    s32 unk40;
    f32 unk44[2];
    f32 unk4C;
    u8 pad50[0x20];
    s8 unk70;
} Unc03Race;

typedef struct Unc03Entry {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x44];
    f32 unk50[3];
    u8 pad5C[0x60];
    f32 unkBC;
} Unc03Entry;

extern s32 D_800A4BBC;
extern s32 D_800D6CD0;
extern u8 D_800D6CD4;
extern f32 D_800A2584;
extern s32 D_800A4BA4[];
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern s32 D_800A2198;
extern f32 D_8011A240;
extern f32 D_800A9D7C;
extern f32 D_800A9D80;
extern f32 D_800A9D84;
extern f32 D_80120BF8;
extern void *D_8011A508[];
extern f32 D_800A50CC[];
extern f32 D_800A50EC[];
extern f32 D_800A508C[];
extern f32 D_800A5080[];
extern f32 D_800A510C[];
extern f32 D_800A516C[];
extern f32 D_80118D90[];
extern f32 D_80118E50[];

extern void func_80007A80(void);
extern void func_8005058C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_80082BE0(void);
extern s32 func_8003F800(s32 key, s32 index);
extern f32 func_80064A88(f32 rate);
extern void func_80015288(f32 *output, f32 *source);
extern void func_80033878(void *node, f32 *position);
extern void func_80060DE4(void *entry, s32 code);
extern void func_800494D0(void *arg0, s32 arg1, f32 arg2);
extern void func_800469B4(void *race, s32 mode);
extern void func_80033590(void *node, f32 *out);

void func_80026644(Unc03Race *race) {
    f32 position[3];
    Unc03Entry *entry;
    f32 base;
    f32 temp;
    s32 i;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_80007A80();
        D_800D6CD0 = 0;
        D_800A2584 = 3.0f;
        func_8005058C(D_800A50CC, D_800A50EC, 1, 0, 0);
        D_800D6CD4 = (u8)(s32)((f32)func_80082BE0() / (f32)2147483648.0 * 8.0f);
    }

    entry = (Unc03Entry *)(void *)(long)func_8003F800(0x456C6D6F, race->unk40);
    base = entry->unkBC * D_800A9D7C;
    if (D_800D6CD0 >= 2) {
        func_80064A88(D_800A9D80);
    }
    if (D_800D6CD0 == 3) {
        if (D_800A2584 > 0.0f) {
            race->unk4C = -60.0f + base;
            func_80015288(D_80118E50, race->unk44);
            D_800A2584 = D_800A2584 - D_80120BF8;
        }
    }

    for (i = 0; i < race->unk70; i++) {
        if (D_800A4BA4[i] & 1) {
            func_80033878(D_8011A508[race->unk40], D_800A516C);
            func_80060DE4(entry, 0);
            race->unk40 = -1;
            D_8011A240 = 0.0f;
            D_800A2198 = 9;
        }
    }

    if (D_8011A240 > 0.0f) {
        func_800494D0(race, D_800D6CD4, D_8011A240 * D_800A9D84);
    }

    if (D_800A2198 == 9) {
        func_800469B4(race, D_800A2198);
        return;
    }

    for (i = 0; i < race->unk70; i++) {
        if ((D_800A4BA4[i] & 2) && !(D_800A4BA4[i] & 1)) {
            D_800A2198 = 1;
            D_800A4BDC = -1;
            return;
        }
    }

    if (D_800D6CD0 == 0) {
        if (0.0f < D_800A2584) {
            temp = D_800A2584 - D_80120BF8;
            D_800A2584 = temp;
            if (temp <= 0.0f) {
                func_8005058C(D_800A50CC, D_800A508C, 1, 0, 0);
                D_800D6CD0 = 1;
            }
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 1) {
            temp = -60.0f + base;
            func_80033590(D_8011A508[race->unk40], position);
            position[2] = temp;
            func_8005058C(D_80118D90, position, 1, 0, 0);
            func_80015288(entry->unk50, D_800A510C);
            entry->unk50[1] = -320.0f;
            if (entry->unk8 == 1) {
                func_80060DE4(entry, 6);
            } else {
                func_80060DE4(entry, 0x14);
            }
            D_800D6CD0 = 2;
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 2) {
            D_800D6CD0 = 3;
            D_800A2584 = 5.0f;
        }
    }

    if (D_800A2584 <= 0.0f) {
        if (D_800D6CD0 == 3) {
            func_8005058C(D_80118D90, D_800A508C, 1, 0, 0);
            D_800D6CD0 = 4;
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 4) {
            func_8005058C(D_800A5080, D_80118E50, 1, 0, 0);
            D_800D6CD0 = 5;
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 5) {
            func_800469B4(race, 9);
        }
    }
}
