/* Independently written from $S/specs/func_80027150.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x5E];
    s8 unk5E;
    u8 unk5F[0x13];
    s8 unk72[3];
    u8 unk75[0x57];
    u8 unkCC;
} Show80027150;

typedef struct {
    u8 unk00[0x20];
    f32 unk20;
    u8 unk24[0x10];
} Slot800A31E0;

typedef struct {
    u8 unk00[0x30];
    void *unk30;
    u8 unk34[0x10];
    f32 unk44[3];
} Ent80027150;

extern s32 D_8009B7D0;
extern Slot800A31E0 D_800A31E0[];
extern s32 D_800A2198;
extern s32 D_800A25E4[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern s16 D_800A52DC[];
extern s32 D_800A5998;
extern u8 D_800A9698[];
extern u8 D_80113E60[];
extern f32 D_800D7124;
extern f32 D_800D7128[];
extern f32 D_800D7138[];
extern u8 D_800D7144;
extern f32 D_80118D90[];
extern f32 D_80118DE0[];
extern f32 D_80118E10[];
extern f32 D_80118E50[];
extern f32 D_80118EA0[];
extern f32 D_80118ED0[];
extern void **D_8011A638;
extern void **D_8011A508[];
extern f32 D_80120BF8;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_800092EC(s32, s32, s32);
extern s32 func_80009134(s32, s32);
extern u32 func_80009524(s32, u32);
extern void func_8000953C(s32, u32);
extern void func_8000955C(s32, s32);
extern void func_80009704(s32, s32, s32, s32, s32, s32);
extern void func_80014CC0(f32, f32 *, f32 *);
extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_800174B8(f32 *, f32 *);
extern void func_80017918(f32 *, f32, f32, f32, f32 *);
extern void func_80017BA8(void *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern Ent80027150 *func_8003F800(u32, s32);
extern void func_80033878(void *, f32 *);
extern void func_8005058C(void *, void *, s32, s32, s32);
extern s32 func_8002D968(u8 *, u8 *);
extern s32 func_80082BE0(void);

void func_80027150(Show80027150 *show) {
    f32 offset[3];
    f32 heading[3];
    f32 matrix[16];
    f32 sine;
    f32 cosine;
    f32 fade;
    f32 remaining;
    Ent80027150 *entry;
    void *scene;
    s16 i;
    s16 k;
    s16 j;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800D7124 = 37.0f;
        D_800D7144 = 0;
        for (i = 0; i < 3; i++) {
            D_800D7128[i] = D_800A31E0[show->unk72[i]].unk20;
            D_800D7138[i] = (f32)func_80082BE0() / (f32)2147483648.0 * 360.0f;
        }
        func_80015268(D_80118E50, 0.0f, 0.0f, -100.0f);
        func_80015268(D_80118D90, 300.0f, 0.0f, -100.0f);
        func_80015288(D_80118ED0, D_80118E50);
        func_80015288(D_80118E10, D_80118D90);
        func_8000955C(0, 0x1000000);
        func_80009704(3, 0, D_800A25E4[show->unk5E], 5, 0,
                      D_800A52DC[show->unkCC]);
    }

    if (func_80009134(3, 0) || func_80009134(5, 0)) {
        fade = 0.75f;
    } else {
        fade = 1.0f;
        if (func_80009524(0, 0x1000000) == 0) {
            func_800092EC(1, show->unkCC, 15);
            func_8000953C(0, 0x1000000);
        }
    }
    func_80008B14(5, 6, 0.25f, fade, 1);

    func_80015268(heading, 0.0f, 0.0f, 0.0f);
    func_80015268(offset, 0.0f, 0.0f, 0.0f);

    switch (D_800D7144) {
    case 0:
        if (D_800D7124 < 36.0f) {
            D_800D7144++;
            D_80118EA0[14] += 125.0f;
            D_80118DE0[14] += 150.0f;
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    case 1:
        if (D_800D7124 < 34.0f) {
            D_800D7144++;
            func_80015268(D_80118ED0, 0.0f, 0.0f, 25.0f);
            func_80015268(D_80118E10, -500.0f, 250.0f, 150.0f);
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    case 2:
        if (D_800D7124 < 27.0f) {
            D_800D7144++;
            func_80015268(D_80118E10, -500.0f, -200.0f, 50.0f);
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    case 3:
        if (D_800D7124 < 24.0f) {
            D_800D7144++;
            func_80015268(D_80118ED0, 0.0f, -150.0f, -25.0f);
            func_80015268(D_80118E10, 800.0f, -400.0f, 0.0f);
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    case 4:
        if (D_800D7124 < 18.0f) {
            D_800D7144++;
            func_80015268(D_80118ED0, 0.0f, 150.0f, -50.0f);
            func_80015268(D_80118E10, 100.0f, 300.0f, -25.0f);
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    case 5:
        if (D_800D7124 < 13.0f) {
            D_800D7144++;
            func_80015268(D_80118ED0, 0.0f, 0.0f, 25.0f);
            func_80015268(D_80118E10, -5000.0f, -2000.0f, 1000.0f);
            func_8005058C(D_80118E10, D_80118ED0, 1, 0, 1);
        }
        break;
    }

    if (0.0f <= D_800D7124) {
        remaining = D_800D7124 - D_80120BF8;
        D_800D7124 = remaining;
        if (remaining <= 0.0f) {
            D_800A4BDC = -1;
            if (D_800A5998 == 0) {
                D_800A2198 = 12;
            }
        }
    }

    scene = *D_8011A638;
    if (scene != 0) {
        if (scene != 0) {
            func_800181BC(scene, 2, -4, 0x10, 3);
        }
        func_800174B8(matrix, heading);
        func_80017918(matrix, 0.4f, 0.4f, 0.4f, matrix);
        func_80017BA8(scene, matrix);
        if (scene != 0) {
            func_800181BC(scene, 2, 3, 0x10, 2);
        }
    }

    func_80015268(offset, -75.0f, 0.0f, 0.0f);

    for (k = 0; k < 3; k++) {
        D_800D7138[k] += D_800D7128[k] * D_80120BF8 * 0.5f;
        if (360.0f < D_800D7138[k]) {
            D_800D7138[k] = D_800D7138[k] - 360.0f;
        }
        func_80014CC0(D_800D7138[k], &sine, &cosine);
        entry = func_8003F800(0x456C6D6FU, k + 0x1C);
        entry->unk44[2] = (f32)k * -50.0f + sine * 150.0f * 0.1f;
        func_80033878(entry->unk30, entry->unk44);
        for (j = 0; j < 2; j++) {
            scene = *D_8011A508[j * 3 + k + 0x4D];
            if (scene != 0) {
                if (scene != 0) {
                    func_800181BC(scene, 2, -4, 0x10, 3);
                }
                func_800174B8(matrix, heading);
                func_80017918(matrix, 0.1f, 0.1f, 0.1f, matrix);
                func_80015288(&matrix[12], entry->unk44);
                func_80017BA8(scene, matrix);
                if (scene != 0) {
                    func_800181BC(scene, 2, 3, 0x10, 2);
                }
            }
        }
    }

    if ((D_800A4BA4[0] & 1) || (D_800A4BA4[0] & 2)) {
        if (D_8009B7D0 > 0) {
            if (func_8002D968(D_80113E60, D_800A9698) != 0) {
                D_800D7124 = 0.0f;
            }
        }
    }
}
