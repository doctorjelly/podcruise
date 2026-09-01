/* Recovered from specification specs/func_80021F84.md (uncovered split tranche; entry corrected from func_80021F8C). */

#include "podcruise/types.h"

typedef struct {
    s32 unk_00[4];
    s32 unk_10;
    s32 unk_14[8];
    s32 unk_34;
    s8 unk_38[0x37];
    s8 unk_6F;
    s8 unk_70[2];
    s8 unk_72;
} Struct80021F84;

extern void func_8004E4F4(void *);
extern void func_800519C0(s32, s32, s32, s32);
extern void func_800479A4(void);
extern void func_80047920(void);
extern void func_80017C18(void *, f32 *);
extern void func_80015288(f32 *, f32 *);
extern void func_800503E8(void *, s32, s32, s32);
extern s32 func_8008A6B4(char *, const char *, ...);
extern void func_8003EC40();
extern void func_8002D4C4(s32);
extern void func_800469B4(void *, s32);
extern void func_8002AFFC(void *, s32, s32);

extern s32 D_800A2180;
extern s32 D_800A2184;
extern s32 D_800A2190;
extern s32 D_800A2194;
extern s32 D_800A2198;
extern s32 D_800A21B0;
extern s32 D_800A2548;
extern s32 D_800A254C;
extern s32 D_800A2550;
extern u8 D_800A2DE3[];
extern s32 D_800A2DEC[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern s32 D_800A4BE8;
extern f32 D_800A4BF0;
extern f32 D_800A4C00[];
extern f32 D_800A4FE0[];
extern f32 D_800A4FEC[];
extern f32 D_800A5000[];
extern f32 D_800A500C[];
extern f32 D_800A5020[];
extern f32 D_800A502C[];
extern f32 D_800A5040[];
extern f32 D_800A504C[];
extern char D_800A8E80[];
extern char D_800A8E88[];
extern char D_800A8EA0[];
extern f32 D_800A9CD0;
extern f32 D_800D6DA8[];
extern f32 D_800D6DC0[];
extern u8 D_80113E7C;
extern s8 D_8011A050[];
extern void **D_8011A544;

void func_80021F84(Struct80021F84 *arg0) {
    s32 index;
    f32 matrix[16];
    char buffer[52];
    s32 value;
    s32 flags;

    if (D_800A2550 != 0 || D_800A4BBC != 0) {
        D_800A254C = 0;
        if (D_800A4BBC == 0) {
            D_800A4BE8 = 0;
        }
        func_8004E4F4(arg0);
        func_800519C0(arg0->unk_72, D_800A2DE3[D_8011A050[D_800A4BE8 * 56] * 16], 0, 255);
        func_800479A4();
        func_80047920();
        D_800A4BC0 = 0;
        D_800A4BBC = 0;
        D_800A2550 = 0;
    }

    flags = D_800A254C;
    if (flags == 1) {
        flags = flags + 1;
        D_800A254C = flags;
        func_80017C18(D_8011A544[D_800A2190], matrix);
        func_80015288(D_800A4FEC, &matrix[12]);
        func_80015288(D_800A4FE0, &matrix[12]);
        D_800A4C00[251] = 0.0f;
        D_800A4C00[248] = D_800D6DA8[3] + 200.0f;
        D_800A4C00[249] = D_800D6DA8[4] + 300.0f;
        D_800A4C00[250] = D_800A4C00[250] + 200.0f;
        func_80017C18(D_8011A544[5], matrix);
        func_80015288(D_800A500C, &matrix[12]);
        func_80015288(D_800A5000, &matrix[12]);
        D_800A4C00[256] = D_800A4C00[256] + 50.0f;
        D_800A4C00[257] = D_800A4C00[257] - 300.0f;
        D_800A4C00[258] = -152.0f;
        func_80017C18(D_8011A544[5], matrix);
        func_80015288(D_800A502C, &matrix[12]);
        func_80015288(D_800A5020, &matrix[12]);
        D_800A4C00[264] = D_800A4C00[264] - 100.0f;
        D_800A4C00[265] = D_800A4C00[265] - 500.0f;
        D_800A4C00[266] = D_800A4C00[266] + 100.0f;
        func_80017C18(D_8011A544[D_800A2194], matrix);
        func_80015288(D_800A504C, &matrix[12]);
        func_80015288(D_800A5040, &matrix[12]);
        D_800A4C00[272] = D_800D6DC0[0] - 300.0f;
        D_800A4C00[273] = D_800D6DC0[4] + 300.0f;
        D_800A4C00[274] = -152.0f;
        if (D_800A4BE8 < 7) {
            func_800503E8(arg0, D_800A4BE8 % 4 + 31, -1, 0);
        } else {
            D_800A2180 = 1;
        }
    }

    func_8008A6B4(buffer, D_800A8E80, D_800A2DEC[D_8011A050[D_800A4BE8 * 56] * 4]);
    if (D_800A4BE8 == 7) {
        if (D_80113E7C < 4) {
            func_8008A6B4(buffer, D_800A8E88);
        } else {
            func_8008A6B4(buffer, D_800A8EA0);
        }
    }
    func_8003EC40(30, 44, 255, 255, 255, (u32)(D_800A4BF0 * 2.5f * 255.0f), buffer);

    if (D_800A2184 != 0) {
        D_800A2180 = 1;
        D_800A2548 = 1;
        D_800A2184 = 0;
    }

    flags = D_800A4BA4[arg0->unk_6F];
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
            flags = D_800A4BA4[arg0->unk_6F];
        }
    }
    if (flags & 0x20000) {
        if (D_800A4BE8 < 7) {
            D_800A4BE8 = D_800A4BE8 + 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk_6F];
        }
    }
    if (flags & 0x4000) {
        if (D_800A4BE8 >= 2) {
            D_800A4BE8 = D_800A4BE8 - 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk_6F];
        }
    }
    if (flags & 0x8000) {
        if (D_800A4BE8 < 6) {
            D_800A4BE8 = D_800A4BE8 + 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
        }
    }

    if (D_800A2180 != 0 && D_800A4BE8 != -1) {
        D_800A2180 = 0;
        func_80047920();
        index = D_800A4BE8;
        if (index < 7) {
            func_800519C0(arg0->unk_72, D_800A2DE3[D_8011A050[index * 56] * 16], 0, 255);
            value = D_800A4BE8 % 4 + 31;
            if (value != arg0->unk_34) {
                func_800503E8(arg0, value, -1, 0);
            }
        } else {
            func_800519C0(arg0->unk_72, index, 0, 255);
            D_800A4BC0 = 1;
            arg0->unk_34 = 0x1A;
            func_8002AFFC(arg0, 0x1A, 0);
        }
    }

    flags = D_800A4BA4[arg0->unk_6F];
    if ((flags & 1) && !(flags & 2)) {
        if (D_800A4BE8 != 7 || D_80113E7C != 4) {
            func_8002D4C4(0x55);
            D_800A2198 = 7;
            D_800A21B0 = 1;
            if (D_800A4BE8 == 7) {
                D_800A21B0 = 2;
                arg0->unk_10 = 1;
            }
            D_800A4BDC = -1;
            D_800A4BF0 = D_800A9CD0;
        }
    }

    if (D_800A254C < 2) {
        D_800A254C = D_800A254C + 1;
    }
}
