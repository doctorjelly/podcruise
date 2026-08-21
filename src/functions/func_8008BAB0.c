/* Specification: scratchpad specs/func_8008BAB0.md */
#include "podcruise/types.h"

typedef struct {
    s16 unk0;
    s8 unk2;
    s32 unk4;
} Entry8;

typedef struct {
    s32 unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Context;

extern Context D_800A7B60;
extern s32 D_800A7B7C;
extern u8 D_80149ED0[];
extern u8 D_8014B080[];
extern u8 D_8014B098[];
extern Entry8 D_8014B0B0;
extern Entry8 D_8014B0C8;

extern void func_800880E0();
extern void func_8008AE30();
extern void func_8008B810();
extern void func_8008B960();
extern void func_8008BC30();
extern void func_8008BFB0();
extern s32 func_8008CA80(void);
extern void func_8008CAA0();
extern void func_80092560(void);
extern void func_80093DB0(void);
extern s32 func_800941B0();

void func_8008BAB0(s32 arg0) {
    s32 handle;
    s32 saved;
    s32 current;

    if (D_800A7B60.unk0 == 0) {
        func_80093DB0();
        D_800A7B7C = 0;
        func_800880E0(D_8014B080, D_8014B098, 5);
        D_8014B0B0.unk0 = 13;
        D_8014B0B0.unk2 = 0;
        D_8014B0B0.unk4 = 0;
        D_8014B0C8.unk0 = 14;
        D_8014B0C8.unk2 = 0;
        D_8014B0C8.unk4 = 0;
        func_8008AE30(7, D_8014B080, &D_8014B0B0, &D_8014B0C8);
        func_8008AE30(3, D_8014B080, &D_8014B0C8);
        saved = -1;
        current = func_800941B0(0);
        if (current < arg0) {
            saved = current;
            func_8008BFB0(0, arg0);
        }
        handle = func_8008CA80();
        D_800A7B60.unk0 = 1;
        D_800A7B60.unk4 = D_80149ED0;
        D_800A7B60.unkC = D_800A7B60.unk8 = &D_8014B080[0];
        D_800A7B60.unk10 = 0;
        D_800A7B60.unk14 = 0;
        D_800A7B60.unk18 = 0;
        func_8008B810(D_80149ED0, 0, func_8008BC30, &D_800A7B60, D_8014B080, arg0);
        func_80092560();
        func_8008B960(D_80149ED0);
        func_8008CAA0(handle);
        if (saved != -1) {
            func_8008BFB0(0, saved);
        }
    }
}
