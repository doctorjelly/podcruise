/* Independently written from specs/functions/recovered/medium_resource_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x10];
    s32 unk10;
    u8 pad14[0x5B];
    s8 unk6F;
} ObjB05;

typedef struct {
    u8 pad00[0x14];
    u8 unk14[0x18];
} RecB05;

extern s32 D_800A23BC;
extern u8 D_800A23C0;
extern s32 D_800A4B94[];
extern s32 D_800A4BA4[];
extern u8 D_800A8B54[];
extern u8 D_800A8B74[];
extern u8 D_800A8B88[];
extern u8 D_800A8BA0[];
extern u8 D_800A8BB8[];
extern u8 D_800A8BD4[];
extern u8 D_800A8BE4[];
extern RecB05 D_80113680[];

extern void func_80029A3C(s32 arg0, s32 arg1);
extern void func_8002BBA4(ObjB05 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern void func_8002D4C4(s32 arg0);
extern void func_8003964C(void);
extern void func_800399F0(void);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 *arg6);
extern s32 func_8008A6B4(u8 *buffer, u8 *format, ...);

s32 func_8001CCC4(ObjB05 *arg0, s32 arg1) {
    u8 letters[3];
    u8 text[0x100];
    s32 i;
    s32 flags;

    if (arg1 == 4) {
        func_8003EC40(0xA0, 0x38, 0xA3, 0xBE, 0x11, 0xFF, D_800A8B54);
    } else {
        for (i = 0; i < 3; i++) {
            letters[i] = D_80113680[arg1].unk14[i];
        }
        func_8008A6B4(text, D_800A8B74, letters[0], letters[1], letters[2]);
        func_8003EC40(0xA0, 0x38, 0xA3, 0xBE, 0x11, 0xFF, text);
    }

    if (D_800A23C0 == 1) {
        func_8003EC40(0xA0, 0x4B, 0xA3, 0xBE, 0x11, 0xFF, D_800A8B88);
        func_8003EC40(0xA0, 0xA0, 0xA3, 0xBE, 0x11, 0xFF, D_800A8BA0);
        func_8003EC40(0xA0, 0xB9, 0xA3, 0xBE, 0x11, 0xFF, D_800A8BB8);
    }

    func_8002BBA4(arg0, 0xA0, 0x64, 0x1E, D_800A23BC == 0, 0, D_800A8BD4);
    func_8002BBA4(arg0, 0xA0, 0x64, 0x1E, D_800A23BC == 0, 1, D_800A8BE4);

    flags = D_800A4BA4[arg0->unk6F];
    if (flags & 1) {
        func_8002D4C4(0x55);
        if (D_800A23C0 != 0) {
            D_800A23C0 = 0;
            arg0->unk10 = 0;
            if (D_800A23BC != 0) {
                D_800A23BC = 0;
                if (arg1 == 4) {
                    func_8003964C();
                } else {
                    func_80029A3C(1, arg1);
                }
                func_80029A3C(0, arg0->unk6F);
                func_800399F0();
                return 1;
            }
            return 0;
        }
        if (D_800A23BC != 0) {
            D_800A23BC = 0;
            D_800A23C0 = 1;
            return 0;
        }
        arg0->unk10 = 0;
        return 0;
    }

    if (flags & 2) {
        func_8002D4C4(0x4D);
        arg0->unk10 = 0;
        D_800A23BC = 0;
        D_800A23C0 = 0;
        return 0;
    }

    if (D_800A23BC == 0) {
        if (D_800A4B94[arg0->unk6F] & 0x4000) {
            func_8002D4C4(0x57);
            D_800A23BC = 1;
        }
    }

    if (D_800A23BC != 0) {
        if (D_800A4B94[arg0->unk6F] & 0x8000) {
            func_8002D4C4(0x57);
            D_800A23BC = 0;
        }
    }
    return 0;
}
