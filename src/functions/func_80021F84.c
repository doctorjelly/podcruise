/* Recovered per specs/func_80021F84.md (pause/HUD selection update). */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x10];
    s32 unk10;
    u8 pad14[0x20];
    s32 unk34;
    u8 pad38[0x37];
    s8 unk6F;
    u8 pad70[0x2];
    s8 unk72;
} Object;

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
extern u8 D_800A4FE0[];
extern u8 D_800A4FEC[];
extern u8 D_800A5000[];
extern u8 D_800A500C[];
extern u8 D_800A5020[];
extern u8 D_800A502C[];
extern u8 D_800A5040[];
extern u8 D_800A504C[];
extern u8 D_800A8E80[];
extern u8 D_800A8E88[];
extern u8 D_800A8EA0[];
extern f32 D_800A9CD0;
extern f32 D_800D6DA8[];
extern f32 D_800D6DC0[];
extern u8 D_80113E7C;
extern s8 D_8011A050[];
extern s32 *D_8011A544;

extern void func_80015288(void *, void *);
extern void func_80017C18(s32, void *);
extern void func_8002AFFC(Object *, s32, s32);
extern void func_8002D4C4(s32);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, void *);
extern void func_800469B4(Object *, s32);
extern void func_80047920(void);
extern void func_800479A4(void);
extern void func_8004E4F4(Object *);
extern void func_800503E8(Object *, s32, s32, s32);
extern void func_800519C0(s32, s32, s32, s32);
extern void func_8008A6B4();

void func_80021F84(Object *arg0) {
    f32 sp9C[5];
    f32 sp6C[12];
    u8 sp38[52];
    s32 index;
    s32 flags;
    s32 value;

    if (D_800A2550 != 0 || D_800A4BBC != 0) {
        D_800A254C = 0;
        if (D_800A4BBC == 0) {
            D_800A4BE8 = 0;
        }
        func_8004E4F4(arg0);
        func_800519C0(arg0->unk72, D_800A2DE3[D_8011A050[D_800A4BE8 * 56] * 16], 0, 255);
        func_800479A4();
        func_80047920();
        D_800A4BC0 = 0;
        D_800A4BBC = 0;
        D_800A2550 = 0;
    }

    value = D_800A254C;
    if (value == 1) {
        index = D_8011A544[D_800A2190];
        D_800A254C = 2;
        func_80017C18(index, sp6C);
        func_80015288(D_800A4FEC, sp9C);
        func_80015288(D_800A4FE0, sp9C);
        D_800A4C00[251] = 0.0f;
        D_800A4C00[248] = D_800D6DA8[3] + 200.0f;
        D_800A4C00[249] = D_800D6DA8[4] + 300.0f;
        D_800A4C00[250] = D_800A4C00[250] + 200.0f;
        func_80017C18(D_8011A544[5], sp6C);
        func_80015288(D_800A500C, sp9C);
        func_80015288(D_800A5000, sp9C);
        D_800A4C00[256] = D_800A4C00[256] + 50.0f;
        D_800A4C00[257] = D_800A4C00[257] - 300.0f;
        D_800A4C00[258] = -152.0f;
        func_80017C18(D_8011A544[5], sp6C);
        func_80015288(D_800A502C, sp9C);
        func_80015288(D_800A5020, sp9C);
        D_800A4C00[264] = D_800A4C00[264] - 100.0f;
        D_800A4C00[265] = D_800A4C00[265] - 500.0f;
        D_800A4C00[266] = D_800A4C00[266] + 100.0f;
        func_80017C18(D_8011A544[D_800A2194], sp6C);
        func_80015288(D_800A504C, sp9C);
        func_80015288(D_800A5040, sp9C);
        D_800A4C00[272] = D_800D6DC0[0] - 300.0f;
        D_800A4C00[273] = D_800D6DC0[4] + 300.0f;
        D_800A4C00[274] = -152.0f;
        if (D_800A4BE8 < 7) {
            func_800503E8(arg0, (D_800A4BE8 % 4) + 31, -1, 0);
        } else {
            D_800A2180 = 1;
        }
    }

    func_8008A6B4(sp38, D_800A8E80, D_800A2DEC[D_8011A050[D_800A4BE8 * 56] * 4]);
    if (D_800A4BE8 == 7) {
        if (D_80113E7C < 4) {
            func_8008A6B4(sp38, D_800A8E88);
        } else {
            func_8008A6B4(sp38, D_800A8EA0);
        }
    }
    func_8003EC40(30, 44, 255, 255, 255, (s32)(u32)((D_800A4BF0 * 2.5f) * 255.0f), sp38);

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
        index = D_800A4BE8;
        if (index > 0) {
            D_800A4BE8 = index - 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x20000) {
        index = D_800A4BE8;
        if (index < 7) {
            D_800A4BE8 = index + 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x4000) {
        index = D_800A4BE8;
        if (index >= 2) {
            D_800A4BE8 = index - 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            flags = D_800A4BA4[arg0->unk6F];
        }
    }
    if (flags & 0x8000) {
        index = D_800A4BE8;
        if (index < 6) {
            D_800A4BE8 = index + 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
        }
    }

    if (D_800A2180 != 0 && D_800A4BE8 != -1) {
        D_800A2180 = 0;
        func_80047920();
        index = D_800A4BE8;
        if (index < 7) {
            func_800519C0(arg0->unk72, D_800A2DE3[D_8011A050[index * 56] * 16], 0, 255);
            if (((D_800A4BE8 % 4) + 31) != arg0->unk34) {
                func_800503E8(arg0, (D_800A4BE8 % 4) + 31, -1, 0);
            }
        } else {
            func_800519C0(arg0->unk72, index, 0, 255);
            D_800A4BC0 = 1;
            arg0->unk34 = 0x1A;
            func_8002AFFC(arg0, 0x1A, 0);
        }
    }

    flags = D_800A4BA4[arg0->unk6F];
    if ((flags & 1) && !(flags & 2)) {
        if (!(D_800A4BE8 == 7 && D_80113E7C == 4)) {
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

    flags = D_800A254C;
    if (flags < 2) {
        flags++;
        D_800A254C = flags;
    }
}
