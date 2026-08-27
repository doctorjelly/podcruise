/* Recovered per specification specs/func_80026644.md (assigned as func_80026650;
   boundary corrected to the real entry at 0x80026644). */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x40];
    s32 unk40;
    f32 unk44[2];
    f32 unk4C;
    u8 pad50[0x20];
    s8 unk70;
} Obj;

typedef struct {
    u8 pad00[0x8];
    s32 unk08;
    u8 pad0C[0x44];
    f32 unk50;
    f32 unk54;
    u8 pad58[0x64];
    f32 unkBC;
} Obj2;

extern s32 D_800A4BBC;
extern s32 D_800D6CD0;
extern u8 D_800D6CD4;
extern f32 D_800A2584;
extern f32 D_800A9D7C;
extern f32 D_800A9D80;
extern f32 D_800A9D84;
extern f32 D_8011A240;
extern f32 D_80120BF8;
extern s32 D_800A2198;
extern s32 D_800A4BDC;
extern s16 D_800A4BC0;
extern u32 D_800A4BA4[];
extern void *D_8011A508[];
extern u8 D_800A50CC[];
extern u8 D_800A50EC[];
extern u8 D_800A516C[];
extern u8 D_800A508C[];
extern u8 D_800A5080[];
extern u8 D_800A510C[];
extern u8 D_80118E50[];
extern u8 D_80118D90[];

extern void func_80007A80(void);
extern s32 func_80082BE0(void);
extern void func_8005058C(void *, void *, s32, s32, s32);
extern Obj2 *func_8003F800(s32, s32);
extern void func_80064A88(f32);
extern void func_80015288(void *, void *);
extern void func_80033878(void *, void *);
extern void func_80060DE4(void *, s32);
extern void func_80033590(void *, void *);
extern void func_800469B4(Obj *, s32);
extern void func_800494D0(Obj *, s32, f32);

void func_80026644(Obj *p) {
    s32 i;
    f32 v[3];
    Obj2 *o;
    f32 base;
    f32 z;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_80007A80();
        D_800D6CD0 = 0;
        D_800A2584 = 3.0f;
        func_8005058C(D_800A50CC, D_800A50EC, 1, 0, 0);
        D_800D6CD4 = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 8.0f);
    }

    o = func_8003F800(0x456C6D6F, p->unk40);
    base = o->unkBC * D_800A9D7C;
    if (D_800D6CD0 >= 2) {
        func_80064A88(D_800A9D80);
    }
    if (D_800D6CD0 == 3) {
        if (0.0f < D_800A2584) {
            p->unk4C = -60.0f + base;
            func_80015288(D_80118E50, p->unk44);
            D_800A2584 = D_800A2584 - D_80120BF8;
        }
    }

    for (i = 0; i < p->unk70; i++) {
        if (D_800A4BA4[i] & 1) {
            func_80033878(D_8011A508[p->unk40], D_800A516C);
            func_80060DE4(o, 0);
            p->unk40 = -1;
            D_8011A240 = 0.0f;
            D_800A2198 = 9;
        }
    }

    if (0.0f < D_8011A240) {
        func_800494D0(p, D_800D6CD4, D_8011A240 * D_800A9D84);
    }

    i = D_800A2198;
    if (i == 9) {
        func_800469B4(p, i);
        return;
    }

    for (i = 0; i < p->unk70; i++) {
        if ((D_800A4BA4[i] & 2) && !(D_800A4BA4[i] & 1)) {
            D_800A2198 = 1;
            D_800A4BDC = -1;
            return;
        }
    }

    if (D_800D6CD0 == 0) {
        if (0.0f < D_800A2584) {
            z = D_800A2584 - D_80120BF8;
            D_800A2584 = z;
            if (z <= 0.0f) {
                func_8005058C(D_800A50CC, D_800A508C, 1, 0, 0);
                D_800D6CD0 = 1;
            }
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 1) {
            z = -60.0f + base;
            func_80033590(D_8011A508[p->unk40], v);
            v[2] = z;
            func_8005058C(D_80118D90, v, 1, 0, 0);
            func_80015288(&o->unk50, D_800A510C);
            o->unk54 = -320.0f;
            if (o->unk08 == 1) {
                func_80060DE4(o, 6);
            } else {
                func_80060DE4(o, 20);
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
            func_800469B4(p, 9);
        }
    }
}
