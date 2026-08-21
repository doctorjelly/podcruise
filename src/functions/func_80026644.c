/* Recovered per specification specs/func_80026644.md (boundary corrected from func_80026650). */
#include "podcruise/types.h"

typedef struct {
    s32 pad00[16];
    s32 unk40;
    s32 unk44;
    s32 pad48;
    f32 unk4C;
    s32 pad50[8];
    s8 unk70;
} Actor80026644;

typedef struct {
    s32 pad00[2];
    s32 unk08;
    s32 pad0C[17];
    s32 unk50;
    f32 unk54;
    s32 pad58[25];
    f32 unkBC;
} Ent80026644;

typedef struct {
    f32 unk00;
    f32 unk04;
    f32 unk08;
} Vec80026644;

extern s32 D_800A4BBC[];
extern s32 D_800A4BA4[];
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern s32 D_800A2198;
extern f32 D_800A2584;
extern f32 D_800A9D7C;
extern f32 D_800A9D80;
extern f32 D_800A9D84;
extern f32 D_8011A240;
extern f32 D_80120BF8;
extern s32 D_800D6CD0;
extern u8 D_800D6CD4;
extern u8 D_800A5080[];
extern u8 D_800A508C[];
extern u8 D_800A50CC[];
extern u8 D_800A50EC[];
extern u8 D_800A510C[];
extern u8 D_800A516C[];
extern u8 D_80118D90[];
extern u8 D_80118E50[];
extern void *D_8011A508[];

extern void func_80007A80(void);
extern void func_80064A88(f32);
extern void func_80015288(void *, void *);
extern void func_80033590(void *, Vec80026644 *);
extern void func_80033878(void *, void *);
extern void *func_8003F800(u32, s32);
extern void func_800469B4(Actor80026644 *, s32);
extern void func_800494D0(Actor80026644 *, s32, f32);
extern void func_8005058C(void *, void *, s32, s32, s32);
extern void func_80060DE4(void *, s32);
extern s32 func_80082BE0(void);

void func_80026644(Actor80026644 *arg0) {
    s32 i;
    Vec80026644 pos;
    Ent80026644 *ent;
    f32 value;
    f32 depth;

    if (D_800A4BBC[0] != 0) {
        D_800A4BBC[0] = 0;
        func_80007A80();
        D_800D6CD0 = 0;
        D_800A2584 = 3.0f;
        func_8005058C(D_800A50CC, D_800A50EC, 1, 0, 0);
        D_800D6CD4 = (u8)(s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 8.0f);
    }

    ent = func_8003F800(0x456C6D6F, arg0->unk40);
    value = ent->unkBC * D_800A9D7C;
    if (D_800D6CD0 >= 2) {
        func_80064A88(D_800A9D80);
    }
    if (D_800D6CD0 == 3) {
        if (0.0f < D_800A2584) {
            arg0->unk4C = -60.0f + value;
            func_80015288(D_80118E50, &arg0->unk44);
            D_800A2584 = D_800A2584 - D_80120BF8;
        }
    }

    for (i = 0; i < arg0->unk70; i++) {
        if (D_800A4BA4[i] & 1) {
            func_80033878(D_8011A508[arg0->unk40], D_800A516C);
            func_80060DE4(ent, 0);
            arg0->unk40 = -1;
            D_8011A240 = 0.0f;
            D_800A2198 = 9;
        }
    }

    if (0.0f < D_8011A240) {
        func_800494D0(arg0, D_800D6CD4, D_8011A240 * D_800A9D84);
    }

    if (D_800A2198 == 9) {
        func_800469B4(arg0, D_800A2198);
        return;
    }

    for (i = 0; i < arg0->unk70; i++) {
        if ((D_800A4BA4[i] & 2) && !(D_800A4BA4[i] & 1)) {
            D_800A2198 = 1;
            D_800A4BDC = -1;
            return;
        }
    }

    if (D_800D6CD0 == 0) {
        if (0.0f < D_800A2584) {
            depth = D_800A2584 - D_80120BF8;
            D_800A2584 = depth;
            if (depth <= 0.0f) {
                func_8005058C(D_800A50CC, D_800A508C, 1, 0, 0);
                D_800D6CD0 = 1;
            }
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 1) {
            depth = -60.0f + value;
            func_80033590(D_8011A508[arg0->unk40], &pos);
            pos.unk08 = depth;
            func_8005058C(D_80118D90, &pos, 1, 0, 0);
            func_80015288(&ent->unk50, D_800A510C);
            ent->unk54 = -320.0f;
            if (ent->unk08 == 1) {
                func_80060DE4(ent, 6);
            } else {
                func_80060DE4(ent, 20);
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
            func_800469B4(arg0, 9);
        }
    }
}
