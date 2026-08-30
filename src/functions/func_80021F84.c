/* Recovered from specification specs/func_80021F84.md (podracer select screen tick). */
#include "podcruise/types.h"

typedef struct Owner {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x20];
    s32 unk34;
    u8 pad38[0x37];
    s8 unk6F;
    u8 pad70[2];
    s8 unk72;
} Owner;

typedef struct RacerEntry {
    s8 unk0;
    u8 pad1[0x37];
} RacerEntry;

typedef struct NameEntry {
    u8 pad0[3];
    u8 unk3;
    u8 pad4[8];
    s32 unkC;
} NameEntry;

extern s32 D_800A2550;
extern s32 D_800A4BBC;
extern s32 D_800A254C;
extern s32 D_800A4BE8;
extern s16 D_800A4BC0;
extern s32 D_800A2190;
extern s32 D_800A2194;
extern s32 D_800A2180;
extern s32 D_800A2184;
extern s32 D_800A2548;
extern s32 D_800A2198;
extern s32 D_800A21B0;
extern s32 D_800A4BDC;
extern f32 D_800A4BF0;
extern f32 D_800A9CD0;
extern u8 D_80113E7C;
extern s32 D_800A4BA4[];
extern f32 **D_8011A544;
extern f32 D_800A4C00[];
extern f32 D_800D6DA8[];
extern f32 D_800D6DC0[];
extern f32 D_800A4FE0[];
extern f32 D_800A4FEC[];
extern f32 D_800A5000[];
extern f32 D_800A500C[];
extern f32 D_800A5020[];
extern f32 D_800A502C[];
extern f32 D_800A5040[];
extern f32 D_800A504C[];
extern RacerEntry D_8011A050[];
extern NameEntry D_800A2DE0[];
extern const char D_800A8E80[];
extern const char D_800A8E88[];
extern const char D_800A8EA0[];

extern void func_8004E4F4(void *arg0);
extern void func_800519C0(s32 index, s32 slot, s32 mode, s32 level);
extern void func_800479A4(void);
extern void func_80047920(void);
extern void func_80017C18(const f32 *source, f32 *destination);
extern void func_80015288(f32 *output, f32 *source);
extern void func_800503E8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8002D4C4(s32 arg0);
extern void func_8002AFFC(void *arg0, s32 code, s32 arg2);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, const char *arg6);
extern void func_800469B4(void *arg0, s32 arg1);

void func_80021F84(Owner *owner) {
    f32 vector[5];
    f32 matrix[12];
    char text[52];
    s32 buttons;
    s32 value;
    s32 index;

    if ((D_800A2550 != 0) || (D_800A4BBC != 0)) {
        D_800A254C = 0;
        if (D_800A4BBC == 0) {
            D_800A4BE8 = 0;
        }
        func_8004E4F4(owner);
        func_800519C0(owner->unk72,
                      D_800A2DE0[D_8011A050[D_800A4BE8].unk0].unk3, 0, 0xFF);
        func_800479A4();
        func_80047920();
        D_800A4BC0 = 0;
        D_800A4BBC = 0;
        D_800A2550 = 0;
    }

    value = D_800A254C;
    if (value == 1) {
        D_800A254C = 2;

        func_80017C18(D_8011A544[D_800A2190], matrix);
        func_80015288(D_800A4FEC, vector);
        func_80015288(D_800A4FE0, vector);
        D_800A4C00[251] = 0.0f;
        D_800A4C00[248] = D_800D6DA8[3] + 200.0f;
        D_800A4C00[249] = D_800D6DA8[4] + 300.0f;
        D_800A4C00[250] = D_800A4C00[250] + 200.0f;

        func_80017C18(D_8011A544[5], matrix);
        func_80015288(D_800A500C, vector);
        func_80015288(D_800A5000, vector);
        D_800A4C00[256] = D_800A4C00[256] + 50.0f;
        D_800A4C00[257] = D_800A4C00[257] - 300.0f;
        D_800A4C00[258] = -152.0f;

        func_80017C18(D_8011A544[5], matrix);
        func_80015288(D_800A502C, vector);
        func_80015288(D_800A5020, vector);
        D_800A4C00[264] = D_800A4C00[264] - 100.0f;
        D_800A4C00[265] = D_800A4C00[265] - 500.0f;
        D_800A4C00[266] = D_800A4C00[266] + 100.0f;

        func_80017C18(D_8011A544[D_800A2194], matrix);
        func_80015288(D_800A504C, vector);
        func_80015288(D_800A5040, vector);
        D_800A4C00[272] = D_800D6DC0[0] - 300.0f;
        D_800A4C00[273] = D_800D6DC0[4] + 300.0f;
        D_800A4C00[274] = -152.0f;

        if (D_800A4BE8 < 7) {
            func_800503E8(owner, (D_800A4BE8 % 4) + 0x1F, -1, 0);
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

    buttons = D_800A4BA4[owner->unk6F];
    if (buttons & 2) {
        func_8002D4C4(0x4D);
        D_800A2550 = 1;
        func_800469B4(owner, 3);
        return;
    }
    if (buttons & 0x10000) {
        value = D_800A4BE8;
        if (value > 0) {
            D_800A4BE8 = value - 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            buttons = D_800A4BA4[owner->unk6F];
        }
    }
    if (buttons & 0x20000) {
        value = D_800A4BE8;
        if (value < 7) {
            D_800A4BE8 = value + 1;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            buttons = D_800A4BA4[owner->unk6F];
        }
    }
    if (buttons & 0x4000) {
        value = D_800A4BE8;
        if (value >= 2) {
            D_800A4BE8 = value - 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
            buttons = D_800A4BA4[owner->unk6F];
        }
    }
    if (buttons & 0x8000) {
        value = D_800A4BE8;
        if (value < 6) {
            D_800A4BE8 = value + 2;
            D_800A2180 = 1;
            func_8002D4C4(0x57);
        }
    }

    if ((D_800A2180 != 0) && (D_800A4BE8 != -1)) {
        D_800A2180 = 0;
        func_80047920();
        value = D_800A4BE8;
        if (value < 7) {
            func_800519C0(owner->unk72,
                          D_800A2DE0[D_8011A050[value].unk0].unk3, 0, 0xFF);
            index = (D_800A4BE8 % 4) + 0x1F;
            if (index != owner->unk34) {
                func_800503E8(owner, index, -1, 0);
            }
        } else {
            func_800519C0(owner->unk72, value, 0, 0xFF);
            D_800A4BC0 = 1;
            owner->unk34 = 0x1A;
            func_8002AFFC(owner, 0x1A, 0);
        }
    }

    buttons = D_800A4BA4[owner->unk6F];
    if ((buttons & 1) && !(buttons & 2)) {
        if ((D_800A4BE8 != 7) || (D_80113E7C != 4)) {
            func_8002D4C4(0x55);
            D_800A2198 = 7;
            D_800A21B0 = 1;
            if (D_800A4BE8 == 7) {
                D_800A21B0 = 2;
                owner->unk10 = 1;
            }
            D_800A4BDC = -1;
            D_800A4BF0 = D_800A9CD0;
        }
    }

    if (D_800A254C < 2) {
        D_800A254C = D_800A254C + 1;
    }
}
