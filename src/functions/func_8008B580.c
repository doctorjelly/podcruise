/* Recovered per specs/func_8008B580.md (boot-time exception vector and heap setup). */
#include "podcruise/types.h"

typedef struct {
    u32 words[4];
} Block8008B580;

extern s32 D_80149EC0;
extern s32 D_80000300;
extern s32 D_8000030C;
extern u8 D_8000031C[];
extern u64 D_800A7B40;
extern u32 D_800A7B48;
extern u32 func_8008CB00[];

extern s32 func_80093C10(void);
extern void func_80093C00(u32);
extern void func_80093C20(u32);
extern s32 func_80093C30(u32, u32 *);
extern s32 func_80093C80(u32, u32);
extern void func_80093900(void *, s32);
extern void func_80093CD0(void *, s32);
extern void func_80093D50(void);
extern void func_80093890(s32, u32 *);
extern u64 func_8008AC48(u64, u64);
extern u64 func_8008AB48(u64, u64);
extern void func_80092850(void *, s32);

void func_8008B580(void) {
    u32 status;
    u32 memoryEnd;
    register s32 handle;

    memoryEnd = 0;
    D_80149EC0 = 1;
    handle = func_80093C10();
    func_80093C00(handle | 0x20000000);
    func_80093C20(0x01000800);
    while (func_80093C30(0x1FC007FC, &status) != 0) {
    }
    while (func_80093C80(0x1FC007FC, status | 8) != 0) {
    }

    *(Block8008B580 *)0x80000000UL = *(Block8008B580 *)func_8008CB00;
    *(Block8008B580 *)0x80000080UL = *(Block8008B580 *)func_8008CB00;
    *(Block8008B580 *)0x80000100UL = *(Block8008B580 *)func_8008CB00;
    *(Block8008B580 *)0x80000180UL = *(Block8008B580 *)func_8008CB00;

    func_80093900((void *)0x80000000UL, 0x190);
    func_80093CD0((void *)0x80000000UL, 0x190);
    func_80093D50();
    func_80093890(4, &memoryEnd);
    memoryEnd = memoryEnd & ~0xF;
    if (memoryEnd != 0) {
        D_800A7B40 = memoryEnd;
    }
    D_800A7B40 = func_8008AB48(func_8008AC48(D_800A7B40, 3), 4);
    if (D_8000030C == 0) {
        func_80092850(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        D_800A7B48 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        D_800A7B48 = 0x02E6025C;
    } else {
        D_800A7B48 = 0x02E6D354;
    }
}
