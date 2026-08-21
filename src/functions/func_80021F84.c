/* Independently written from scratchpad spec specs/func_80021F84.md. */

#include "podcruise/types.h"

typedef struct Unk800A2DE0 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0xC - 0x4];
    /* 0x0C */ u8 *unkC;
} Unk800A2DE0;

typedef struct Unk8011A050 {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ u8 pad1[0x38 - 0x1];
} Unk8011A050;

typedef struct Slot80021F84 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 pad10[0x20 - 0x10];
} Slot80021F84;

typedef struct Unk80024070 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x34 - 0x14];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x6F - 0x38];
    /* 0x6F */ s8 unk6F;
    /* 0x70 */ u8 pad70[0x2];
    /* 0x72 */ s8 unk72;
} Unk80024070;

extern s32 D_800A2180;
extern s32 D_800A2184;
extern s32 D_800A2190;
extern s32 D_800A2194;
extern s32 D_800A2198;
extern s32 D_800A21B0;
extern s32 D_800A2548;
extern s32 D_800A254C;
extern s32 D_800A2550;
extern Unk800A2DE0 D_800A2DE0[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern s32 D_800A4BE8;
extern f32 D_800A4BF0;
extern Slot80021F84 D_800A4C00[];
extern f32 D_800A4FE0[];
extern f32 D_800A4FEC[];
extern f32 D_800A5000[];
extern f32 D_800A500C[];
extern f32 D_800A5020[];
extern f32 D_800A502C[];
extern f32 D_800A5040[];
extern f32 D_800A504C[];
extern u8 D_800A8E80[];
extern u8 D_800A8E88[];
extern u8 D_800A8EA0[];
extern f32 D_800A9CD0;
extern f32 D_800D6DA8[];
extern f32 D_800D6DC0[];
extern u8 D_80113E7C;
extern Unk8011A050 D_8011A050[];
extern f32 **D_8011A544;

extern void func_80015288(f32 *, f32 *);
extern void func_80017C18(const f32 *, f32 *);
extern void func_8002AFFC(Unk80024070 *, s32, s32);
extern void func_8002D4C4(s32);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, u8 *);
extern void func_800469B4(Unk80024070 *, s32);
extern void func_80047920(void);
extern void func_800479A4(void);
extern void func_8004E4F4(Unk80024070 *);
extern void func_800503E8(Unk80024070 *, s32, s32, s32);
extern void func_800519C0(s32, s32, s32, s32);
extern s32 func_8008A6B4(u8 *, u8 *, ...);

void func_80021F84(Unk80024070 *arg0) {
    s32 state;
    f32 matrix[4][4];
    u8 text[0x34];
    f32 *entry;
    s32 flags;
    s32 saved;

    if (D_800A2550 != 0 || D_800A4BBC != 0) {
        D_800A254C = 0;
        if (D_800A4BBC == 0) {
            D_800A4BE8 = 0;
        }
        func_8004E4F4(arg0);
        func_800519C0(arg0->unk72,
                      D_800A2DE0[D_8011A050[D_800A4BE8].unk0].unk3, 0, 0xFF);
        func_800479A4();
        func_80047920();
        D_800A4BC0 = 0;
        D_800A4BBC = 0;
        D_800A2550 = 0;
    }

    state = D_800A254C;
    if (state == 1) {
        entry = D_8011A544[D_800A2190];
        state = 2;
        D_800A254C = state;
        func_80017C18(entry, &matrix[0][0]);
        func_80015288(D_800A4FEC, &matrix[3][0]);
        func_80015288(D_800A4FE0, &matrix[3][0]);
        D_800A4C00[31].unkC = 0.0f;
        D_800A4C00[31].unk0 = D_800D6DA8[3] + 200.0f;
        D_800A4C00[31].unk4 = D_800D6DA8[4] + 300.0f;
        D_800A4C00[31].unk8 = D_800A4C00[31].unk8 + 200.0f;

        func_80017C18(D_8011A544[5], &matrix[0][0]);
        func_80015288(D_800A500C, &matrix[3][0]);
        func_80015288(D_800A5000, &matrix[3][0]);
        D_800A4C00[32].unk0 = D_800A4C00[32].unk0 + 50.0f;
        D_800A4C00[32].unk4 = D_800A4C00[32].unk4 - 300.0f;
        D_800A4C00[32].unk8 = -152.0f;

        func_80017C18(D_8011A544[5], &matrix[0][0]);
        func_80015288(D_800A502C, &matrix[3][0]);
        func_80015288(D_800A5020, &matrix[3][0]);
        D_800A4C00[33].unk0 = D_800A4C00[33].unk0 - 100.0f;
        D_800A4C00[33].unk4 = D_800A4C00[33].unk4 - 500.0f;
        D_800A4C00[33].unk8 = D_800A4C00[33].unk8 + 100.0f;

        func_80017C18(D_8011A544[D_800A2194], &matrix[0][0]);
        func_80015288(D_800A504C, &matrix[3][0]);
        func_80015288(D_800A5040, &matrix[3][0]);
        D_800A4C00[34].unk0 = D_800D6DC0[0] - 300.0f;
        D_800A4C00[34].unk4 = D_800D6DC0[4] + 300.0f;
        D_800A4C00[34].unk8 = -152.0f;

        if (D_800A4BE8 < 7) {
            func_800503E8(arg0, D_800A4BE8 % 4 + 31, -1, 0);
        } else {
            D_800A2180 = 1;
        }
    }

    func_8008A6B4(text, D_800A8E80,
                  D_800A2DE0[D_8011A050[D_800A4BE8].unk0].unkC);
    if (D_800A4BE8 == 7) {
        if (D_80113E7C < 4) {
            func_8008A6B4(text, D_800A8E88);
        } else {
            func_8008A6B4(text, D_800A8EA0);
        }
    }
    func_8003EC40(0x1E, 0x2C, 0xFF, 0xFF, 0xFF,
                  (u32)(D_800A4BF0 * 2.5f * 255.0f), text);

    if (D_800A2184 != 0) {
        D_800A2180 = 1;
        D_800A2548 = 1;
        D_800A2184 = 0;
    }

    flags = D_800A4BA4[arg0->unk6F];
    if (flags & 2) {
        func_8002D4C4(0x4D);
        D_800A2550 = 1;
        func_800469B4(arg0, 3);
        return;
    }

    if (flags & 0x10000) {
        if (D_800A4BE8 > 0) {
            D_800A4BE8 = D_800A4BE8 - 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x20000) {
        if (D_800A4BE8 < 7) {
            D_800A4BE8 = D_800A4BE8 + 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x4000) {
        if (D_800A4BE8 >= 2) {
            D_800A4BE8 = D_800A4BE8 - 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x8000) {
        if (D_800A4BE8 < 6) {
            D_800A4BE8 = D_800A4BE8 + 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
        }
    }

    if (D_800A2180 != 0) {
        if (D_800A4BE8 != -1) {
            D_800A2180 = 0;
            func_80047920();
            saved = D_800A4BE8;
            if (saved < 7) {
                func_800519C0(arg0->unk72,
                              D_800A2DE0[D_8011A050[saved].unk0].unk3, 0, 0xFF);
                flags = D_800A4BE8 % 4 + 31;
                if (flags != arg0->unk34) {
                    func_800503E8(arg0, flags, -1, 0);
                }
            } else {
                func_800519C0(arg0->unk72, saved, 0, 0xFF);
                D_800A4BC0 = 1;
                arg0->unk34 = 0x1A;
                func_8002AFFC(arg0, 0x1A, 0);
            }
        }
    }

    flags = D_800A4BA4[arg0->unk6F];
    if ((flags & 1) && !(flags & 2)) {
        if (D_800A4BE8 != 7 || D_80113E7C != 4) {
            func_8002D4C4(0x55);
            D_800A2198 = 7;
            D_800A21B0 = 1;
            if (D_800A4BE8 == 7) {
                D_800A21B0 = 2;
                arg0->unk10 = 1;
            }
            D_800A4BDC = -1;
            D_800A4BF0 = D_800A9CD0;
        }
    }

    state = D_800A254C;
    if (state < 2) {
        state = state + 1;
        D_800A254C = state;
    }
}
