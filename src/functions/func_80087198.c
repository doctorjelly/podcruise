/* Independently written from specs/functions/recovered/func_80087198.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 w0;
    /* 0x4 */ u32 w1;
} Gfx87198;

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec87198;

typedef struct {
    /* 0x0 */ s16 unk00;
    /* 0x2 */ s16 unk02;
    /* 0x4 */ s16 unk04;
    /* 0x6 */ s16 unk06;
    /* 0x8 */ s16 unk08;
    /* 0xA */ s16 unk0A;
} Band87198;

typedef struct {
    /* 0x000 */ u32 unk00;
    /* 0x004 */ s32 unk04;
    /* 0x008 */ u8 pad008[0x168];
} View87198;

typedef struct {
    /* 0x00 */ u8 pad00[0x44];
    /* 0x44 */ Vec87198 unk44;
    /* 0x50 */ u8 pad50[0x2C];
} Node87198;

extern Node87198 *D_8009B790;
extern s32 D_8009B7D0;
extern u32 D_8009B7D8;
extern s32 D_8009B808;
extern u32 D_800A68AC;
extern u32 D_800A68B0;
extern u8 D_800A68C8[];
extern s32 D_800A694C;
extern s32 D_800A6950;
extern void *D_800A6964;
extern Vec87198 D_800A6968;
extern s32 D_800A6974;
extern s16 D_800D6980;
extern u32 D_800D76F0;
extern u8 D_800D9DB0;
extern u8 D_800D9DB1;
extern u32 D_800D9DB4;
extern u32 D_80114528;
extern u32 D_80114530[];
extern View87198 D_80120DF0[];
extern s32 D_801210D0;
extern Gfx87198 *D_801217B0;
extern Gfx87198 *D_801217B4;
extern Gfx87198 D_801217B8[][10000];
extern s16 D_801488B8[];
extern Vec87198 D_801489C8[];
extern Band87198 D_80148B48[];

extern void func_8000A53C(s32);
extern void func_80011888(void *, s32);
extern void func_80015288(Vec87198 *, Vec87198 *);
extern s32 func_800181BC(void *, s32, u32, s32, s32);
extern void func_80031FA4(void);
extern void func_80035698(s32);
extern void func_800356BC(u32, s32, u32);
extern void func_80038DBC(s32);
extern void func_80038DF8(s32, s32, s32, s32, s32, s32);
extern void func_800390A4(void);
extern void func_8003E9D0(void);
extern void func_8003EA24(void);
extern void func_80084EB8(s32);
extern void func_8008528C();
extern void func_80086CE0(s32);
extern void func_80087080(s32);
extern void func_800870D0(s32, s32);
extern void func_800879B8(void);
extern u32 func_80088360(u32);

#define GFX87198(a, b) { Gfx87198 *g_ = D_801217B0++; g_->w0 = (u32)(a); g_->w1 = (u32)(unsigned long)(b); }

void func_80087198(void) {
    Gfx87198 *cmd;
    Vec87198 spare;
    Vec87198 saved;
    u32 mark;
    s32 first;
    s32 index;
    s32 wants;

    saved = D_800A6968;
    (void)saved;
    (void)spare;
    func_800390A4();
    D_800A6974 = D_800A6974 + 1;

    D_800A68B0 = D_800A68AC;
    D_800A68AC = D_800D9DB4;
    D_800D9DB4 = D_80114530[D_800D9DB0];
    if (D_800A68AC == 0) {
        D_800A68AC = D_800D9DB4;
    }
    if (D_800A68B0 == 0) {
        D_800A68B0 = D_800D9DB4;
    }

    D_801217B0 = D_801217B8[D_800D9DB1];
    D_801217B4 = D_801217B0;
    GFX87198(0xDB060000, 0)

    cmd = D_801217B0++;
    cmd->w0 = 0xFE000000;
    cmd->w1 = func_80088360(D_80114528);

    if ((D_8009B7D8 & 0x200) && D_8009B7D0 > 0 && (D_800D76F0 & 0x1100) == 0x1100) {
        func_80035698(1);
        func_800356BC(0x46756C6C, 2, 0xF5504040);
    } else {
        func_80035698(0);
    }

    GFX87198(0xDB040004, 1)
    GFX87198(0xDB04000C, 1)
    GFX87198(0xDB040014, 0xFFFF)
    GFX87198(0xDB04001C, 0xFFFF)

    D_800A694C = 0;
    func_80087080(0);

    if (D_800A6950 != 0 && (D_801210D0 & 1)) {
        func_8008528C(0, D_80148B48[0].unk0A, D_80148B48[1].unk0A, D_80148B48[0].unk04,
                      D_80148B48[0].unk06, D_80148B48[0].unk08, D_80148B48[1].unk04,
                      D_80148B48[1].unk06, D_80148B48[1].unk08);
    } else {
        wants = 0;
        if (D_800D6980 & 2) {
            wants = 1;
        }
        if (D_8009B808 != 0) {
            wants = 1;
            D_801488B8[0] = 0;
            D_801488B8[1] = 0;
            D_801488B8[2] = 0;
        }
        func_80084EB8(wants == 0);
    }

    func_8000A53C(1);

    mark = (u32)(unsigned long)D_801217B0;
    first = 1;
    for (index = 0; index != 4; index++) {
        if (D_80120DF0[index].unk00 & 1) {
            mark = (u32)(unsigned long)D_801217B0;
            func_80087080(index);
            if (D_800A6950 != 0 && index > 0 && (D_801210D0 & 1)) {
                if (D_80148B48[index - 1].unk00 != 0) {
                    func_80038DBC(1);
                    func_80038DF8(D_80148B48[index - 1].unk02, 1000, D_80148B48[index - 1].unk04,
                                  D_80148B48[index - 1].unk06, D_80148B48[index - 1].unk08, 255);
                } else {
                    func_80038DBC(0);
                }
                if (D_80148B48[index - 1].unk0A != 0) {
                    if (D_800A6964 != 0) {
                        func_800181BC(D_800A6964, 2, 3, 0x10, 2);
                    }
                } else {
                    if (D_800A6964 != 0) {
                        func_800181BC(D_800A6964, 2, -4, 0x10, 3);
                    }
                }
            }
            if (D_8009B808 == 0) {
                if (first) {
                    func_80011888(&D_80120DF0[index], 0);
                } else {
                    func_80011888(&D_80120DF0[index], 1);
                }
                func_80086CE0(index);
            }
            first = 0;
            if (D_800A694C < 31) {
                func_80015288(&D_801489C8[D_800A694C], &D_8009B790[D_80120DF0[index].unk04].unk44);
                D_800A694C = D_800A694C + 1;
            }
        }
    }

    func_80087080(0);
    GFX87198(0xDC38000E, D_800A68C8)
    GFX87198(0xDB0C0000, 0x00010000)

    if (!((D_8009B7D8 & 0x200) && D_8009B7D0 > 0 && (D_800D76F0 & 0x1100) == 0x1100)) {
        func_8000A53C(2);
        func_800870D0(D_8009B7D0, ((u32)(unsigned long)D_801217B0 - mark) / 8);
        func_8003E9D0();
        func_8000A53C(3);
        func_8003EA24();
    }
    func_80031FA4();
    func_800879B8();
    D_8009B808 = 0;
}
