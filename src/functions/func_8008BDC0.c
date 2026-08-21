/* Recovered from specification specs/func_8008BDC0.md (worker batch 12). */
#include "podcruise/types.h"

typedef void (*Callback8008BDC0)(void);

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ void *unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ Callback8008BDC0 unk14;
    /* 0x18 */ Callback8008BDC0 unk18;
} Context8008BDC0;

extern Context8008BDC0 D_800A7B80;
extern s32 D_800A7FB0;
extern u8 D_8014B1E0[];
extern u8 D_8014C390[];
extern u8 D_8014C3A8[];
extern u8 D_8014C4D8[];

extern void func_8008BF3C(void);
extern void func_800880E0(void *, void *, s32);
extern void func_800937D0(void);
extern void func_8008AE30(s32, void *, s32);
extern s32 func_800941B0(s32);
extern void func_8008BFB0(s32, s32);
extern s32 func_8008CA80(void);
extern void func_8008B810(void *, s32, Callback8008BDC0, Context8008BDC0 *, void *, s32);
extern void func_8008B960(void *);
extern void func_8008CAA0(s32);
extern void func_800944E0(void);
extern void func_800945C0(void);
extern void func_800947F0(void);

void func_8008BDC0(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    s32 handle;
    s32 previous;
    s32 count;

    if (D_800A7B80.unk00 == 0) {
        func_8008BF3C();
        func_800880E0(arg1, arg2, arg3);
        func_800880E0(D_8014C390, D_8014C3A8, 1);
        if (D_800A7FB0 == 0) {
            func_800937D0();
        }
        func_8008AE30(8, D_8014C390, 0x22222222);
        previous = -1;
        count = func_800941B0(0);
        if (count < arg0) {
            previous = count;
            func_8008BFB0(0, arg0);
        }
        handle = func_8008CA80();
        D_800A7B80.unk00 = 1;
        D_800A7B80.unk04 = D_8014B1E0;
        D_800A7B80.unk08 = arg1;
        D_800A7B80.unk0C = D_8014C390;
        D_800A7B80.unk10 = D_8014C4D8;
        D_800A7B80.unk14 = func_800944E0;
        D_800A7B80.unk18 = func_800945C0;
        func_8008B810(D_8014B1E0, 0, func_800947F0, &D_800A7B80, D_8014C390, arg0);
        func_8008B960(D_8014B1E0);
        func_8008CAA0(handle);
        if (previous != -1) {
            func_8008BFB0(0, previous);
        }
    }
}
