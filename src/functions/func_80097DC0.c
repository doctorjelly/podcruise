/* Specification: scratchpad specs/func_80097DC0.md */
#include "podcruise/types.h"

typedef struct Record80097DC0 {
    struct Record80097DC0 *unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u32 unk_0C;
    s32 unk_10;
} Record80097DC0;

extern Record80097DC0 D_8014D760;
extern u8 D_8014D774[0x60];
extern Record80097DC0 *volatile D_800A7B9C;
extern Record80097DC0 *D_8014D7D4;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern void func_80092850(void *, s32);

Record80097DC0 *func_80097DC0(void) {
    s32 token;

    D_8014D760.unk_04 = 2;
    D_8014D760.unk_0C = 0xA5000000;
    D_8014D760.unk_05 = 3;
    D_8014D760.unk_08 = 6;
    D_8014D760.unk_06 = 6;
    D_8014D760.unk_07 = 2;
    D_8014D760.unk_09 = 1;
    D_8014D760.unk_10 = 0;
    func_80092850(D_8014D774, 0x60);
    token = func_8008CA80();
    D_8014D760.unk_00 = D_800A7B9C;
    D_800A7B9C = &D_8014D760;
    D_8014D7D4 = &D_8014D760;
    func_8008CAA0(token);
    return &D_8014D760;
}
