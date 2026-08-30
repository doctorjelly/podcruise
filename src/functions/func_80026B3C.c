/* Independently written from specs/functions/recovered/func_80026B3C.md. */
#include "podcruise/types.h"

/* Stand-in for the two single-precision pool entries that precede this
   function's double-precision literals in the original translation unit. */
const f32 PcPoolPad80026B3C[2] = { -3.3f, 0.4f };

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_26B3C;

typedef struct {
    u8 pad00[0x20];
    f32 unk20;
    u8 pad24[0x10];
} Rec52_26B3C;

typedef struct {
    f32 unk00;
    f32 unk04;
    f32 unk08;
    u8 pad0C[0x1C];
} Rec40_26B3C;

typedef struct {
    s8 unk00;
    u8 pad01[0xB];
} Rec12_26B3C;

typedef struct {
    u8 pad00[0x5D];
    s8 unk5D;
    u8 pad5E[0x14];
    s8 unk72;
} Ctx26B3C;

extern void func_80008B14(s32, s16, f32, f32, s32);
extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_8001745C(f32 *, f32, f32, f32);
extern void func_80018480(void *, f32 *, s32, f32, f32, f32, f32, s32, f32, f32);
extern void func_80033590(void *, f32 *);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, s32);
extern void func_80063AA0(s32, s32);

extern Rec12_26B3C D_800A21C2[];
extern s32 D_800A2588[];
extern Rec52_26B3C D_800A31E0[];
extern s32 D_800A4BA4;
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern Rec40_26B3C D_800D6C20[];
extern f32 D_800D70D0;
extern s32 D_800D70D4;
extern s32 D_800D70D8;
extern Vec3_26B3C D_800D70E0;
extern Vec3_26B3C D_800D70F0;
extern Vec3_26B3C D_800D7100;
extern Vec3_26B3C D_800D7110;
extern s8 D_80113E67;
extern Vec3_26B3C D_80118D90;
extern Vec3_26B3C D_80118E50;
extern void *D_8011A508[];
extern f32 D_80120BF8;

void func_80026B3C(Ctx26B3C *arg0) {
    f32 matrix[16];
    Rec40_26B3C *entry;
    s32 i;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800D70D0 = 5.0f;
        D_800D70D4 = 0;
        D_800D70D8 = 0;
        func_80033590(D_8011A508[28], &D_800D70F0.x);
        func_80015288(&D_800D70E0.x, &D_800D70F0.x);
        D_800D70F0.z = (f32)((f64)D_800A31E0[arg0->unk72].unk20 * 0.6667 + -157.0);
        D_800D70E0.x = D_800D70E0.x + 60.0f;
        D_800D70E0.y = D_800D70E0.y + 70.0f;
        D_800D70E0.z = (f32)((f64)D_800A31E0[2].unk20 * 0.6667 + -157.0);
        func_80033590(D_8011A508[29], &D_800D7110.x);
        func_80015288(&D_800D7100.x, &D_800D7110.x);
        D_800D7110.z = (f32)((f64)D_800A31E0[2].unk20 * 0.6667 + -157.0);
        D_800D7100.x = D_800D7100.x + 60.0f;
        D_800D7100.y = D_800D7100.y - 70.0f;
        D_800D7100.z = (f32)((f64)D_800A31E0[arg0->unk72].unk20 * 0.6667 + -157.0);
        func_80015268(&D_800D70E0.x, 296.0f, -206.0f, -68.0f);
        func_80015268(&D_800D70F0.x, -315.0f, 365.0f, -82.0f);
        func_80015268(&D_800D7100.x, 315.0f, -566.0f, -70.0f);
        func_80015268(&D_800D7110.x, 0.0f, -680.0f, -68.0f);
        func_80015288(&D_80118D90.x, &D_800D70E0.x);
        func_80015288(&D_80118E50.x, &D_800D7110.x);
    }

    func_80008B14(0x1B, 7, 0.05f, 0.8f, 1);

    if (D_800D70D0 >= 0.0f) {
        D_800D70D0 = D_800D70D0 - D_80120BF8 * 0.5f;
        if (D_800D70D0 <= 0.0f) {
            D_800A4BDC = -1;
        }
    }

    for (i = 0; i != 2; i++) {
        if (D_8011A508[15 + i] != 0) {
            entry = &D_800D6C20[i];
            entry->unk00 = 0.0f;
            entry->unk04 = (f32)(0.0 - (f64)((f32)i * 2500.0));
            entry->unk08 = 50.0f;
            if (arg0->unk72 == 7) {
                D_800D6C20[0].unk04 = 200.0f;
            }
            if (arg0->unk72 == 0x11) {
                D_800D6C20[0].unk04 = 400.0f;
            }
            func_8001745C(matrix, 0.0f, 0.0f, 0.0f);
            func_80015268(&matrix[12], entry->unk00, entry->unk04, entry->unk08);
            func_80018480(D_8011A508[15 + i], matrix, 0, 70.0f, 70.0f, 70.0f, -157.0f, 1, 1.0f, 1.0f);
        }
    }

    if ((D_800A4BA4 & 1) || (D_800A4BA4 & 2)) {
        D_800D70D0 = 0.0f;
        D_800A4BDC = -1;
    }

    if (D_800D70D0 < 4.5f && 2.75f < D_800D70D0) {
        if (D_800D70D4 == 0) {
            D_800D70D4 = 1;
            func_80063AA0(0x1D, 0x18);
            func_80008B14(D_800A21C2[arg0->unk5D].unk00 + 0xAF, 7, 0.25f, 1.0f, 0);
        }
        func_8003EC40(0xA0, 0xC8, 0x78, 0xAA, 0xAA, 0xFF,
                      D_800A2588[D_800A21C2[arg0->unk5D].unk00]);
    }

    if (D_800D70D0 < 2.5f && 0.25f < D_800D70D0) {
        if (D_800D70D8 == 0) {
            D_800D70D8 = 1;
            func_80063AA0(0x1C, 0x18);
            func_80015288(&D_80118D90.x, &D_800D7100.x);
            func_80015288(&D_80118E50.x, &D_800D70F0.x);
            func_80008B14(D_80113E67 + 0xAF, 7, 0.25f, 1.0f, 0);
        }
        func_8003EC40(0xA0, 0xC8, 0xAA, 0xAA, 0, 0xFF, D_800A2588[D_80113E67]);
    }
}
