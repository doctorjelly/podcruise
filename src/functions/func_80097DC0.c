/* Specification: scratchpad specs/func_80097DC0.md (device record initialiser). */
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
    u8 unk_14[0x60];
} Record80097DC0;

extern Record80097DC0 D_8014D760;
extern Record80097DC0 *D_800A7B9C;
extern Record80097DC0 *D_8014D7D4;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern void func_80092850(void *, s32);

Record80097DC0 *func_80097DC0(void) {
    register Record80097DC0 *record;
    s32 token;
    Record80097DC0 *previous;

    record = &D_8014D760;
    record->unk_04 = 2;
    record->unk_0C = 0xA5000000;
    record->unk_05 = 3;
    record->unk_08 = 6;
    record->unk_06 = 6;
    record->unk_07 = 2;
    record->unk_09 = 1;
    record->unk_10 = 0;
    func_80092850(record->unk_14, 0x60);
    token = func_8008CA80();
    previous = D_800A7B9C;
    D_800A7B9C = record;
    record->unk_00 = previous;
    D_8014D7D4 = record;
    func_8008CAA0(token);
    return record;
}
