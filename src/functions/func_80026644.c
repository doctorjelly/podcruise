/* Recovered per specification specs/func_80026644.md (podcruise). */
#include "podcruise/types.h"

typedef struct Obj {
    u8 pad00[0x40];
    s32 unk40;
    f32 unk44[3];
    u8 pad50[0x20];
    s8 unk70;
} Obj;

typedef struct Ent {
    u8 pad00[8];
    s32 unk08;
    u8 pad0C[0x44];
    f32 unk50[3];
    u8 pad5C[0x60];
    f32 unkBC;
} Ent;

extern s32 D_800A4BBC;
extern s32 D_800D6CD0;
extern f32 D_800A2584;
extern u8 D_800D6CD4;
extern f32 D_800A9D7C;
extern f32 D_800A9D80;
extern f32 D_800A9D84;
extern f32 D_8011A240;
extern f32 D_80120BF8;
extern s32 D_800A2198;
extern s32 D_800A4BA4[];
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern u8 D_800A50CC[];
extern u8 D_800A50EC[];
extern u8 D_800A516C[];
extern u8 D_800A510C[];
extern u8 D_800A508C[];
extern u8 D_800A5080[];
extern u8 D_80118E50[];
extern u8 D_80118D90[];
extern void *D_8011A508[];

extern void func_80007A80(void);
extern void func_8005058C(void *, void *, s32, s32, s32);
extern s32 func_80082BE0(void);
extern Ent *func_8003F800(u32, s32);
extern void func_80064A88(f32);
extern void func_80015288(void *, void *);
extern void func_80033878(void *, void *);
extern void func_80060DE4(void *, s32);
extern void func_800494D0(Obj *, s32, f32);
extern void func_800469B4(Obj *, s32);
extern void func_80033590(void *, f32 *);

void func_80026644(Obj *obj) {
    register s32 i;
    f32 point[3];
    Ent *ent;
    f32 base;
    f32 height;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_80007A80();
        D_800D6CD0 = 0;
        D_800A2584 = 3.0f;
        func_8005058C(D_800A50CC, D_800A50EC, 1, 0, 0);
        D_800D6CD4 = (u8)(s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 8.0f);
    }

    ent = func_8003F800(0x456C6D6FU, obj->unk40);
    base = ent->unkBC * D_800A9D7C;
    if (D_800D6CD0 >= 2) {
        func_80064A88(D_800A9D80);
    }
    if (D_800D6CD0 == 3) {
        if (0.0f < D_800A2584) {
            obj->unk44[2] = -60.0f + base;
            func_80015288(D_80118E50, obj->unk44);
            D_800A2584 = D_800A2584 - D_80120BF8;
        }
    }

    for (i = 0; i < obj->unk70; i++) {
        if (D_800A4BA4[i] & 1) {
            func_80033878(D_8011A508[obj->unk40], D_800A516C);
            func_80060DE4(ent, 0);
            obj->unk40 = -1;
            D_8011A240 = 0.0f;
            D_800A2198 = 9;
        }
    }

    if (0.0f < D_8011A240) {
        func_800494D0(obj, D_800D6CD4, D_8011A240 * D_800A9D84);
    }

    if (D_800A2198 == 9) {
        func_800469B4(obj, D_800A2198);
        return;
    }

    for (i = 0; i < obj->unk70; i++) {
        if ((D_800A4BA4[i] & 2) && !(D_800A4BA4[i] & 1)) {
            D_800A2198 = 1;
            D_800A4BDC = -1;
            return;
        }
    }

    if (D_800D6CD0 == 0) {
        if (0.0f < D_800A2584) {
            height = D_800A2584 - D_80120BF8;
            D_800A2584 = height;
            if (height <= 0.0f) {
                func_8005058C(D_800A50CC, D_800A508C, 1, 0, 0);
                D_800D6CD0 = 1;
            }
        }
    }

    if (D_800A4BC0 == 0) {
        if (D_800D6CD0 == 1) {
            height = -60.0f + base;
            func_80033590(D_8011A508[obj->unk40], point);
            point[2] = height;
            func_8005058C(D_80118D90, point, 1, 0, 0);
            func_80015288(ent->unk50, D_800A510C);
            ent->unk50[1] = -320.0f;
            if (1 == ent->unk08) {
                func_80060DE4(ent, 6);
            } else {
                func_80060DE4(ent, 0x14);
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
            func_800469B4(obj, 9);
        }
    }
}
