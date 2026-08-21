/* Recovered from specification specs/func_8004BAC8.md (worker batch 04). */
#include "podcruise/types.h"

typedef struct Board8004BAC8 {
    /* 0x00 */ u8 unk00[0x6C];
    /* 0x6C */ s8 unk6C;
    /* 0x6D */ u8 unk6D[0x47];
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ s32 unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ s32 unkC0;
    /* 0xC4 */ s32 unkC4;
    /* 0xC8 */ s32 unkC8;
} Board8004BAC8;

extern s16 D_80113E60[];

extern void func_8000A44C(s16 index, s32 value);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_8000AC34(s16 index, u32 flags);
extern s32 func_8002DAD0(Board8004BAC8 *board, s8 group, u8 slot);

void func_8004BAC8(Board8004BAC8 *board, s32 enable) {
    s16 index;
    s16 cell;
    s16 code;
    s32 column;
    s32 row;
    s32 shift;
    s16 *table;
    s32 counter;
    s32 base;

    for (index = 0x7F; index < 0x9F; index++) {
        func_8000A44C(index, board->unkC8);
    }
    if (enable != 0) {
        for (row = 0, table = D_80113E60, base = 0; row < 4; row++) {
            for (column = 0, shift = 0, counter = base + 0x60; column < 7; column++) {
                code = (table[6] >> shift) % 4;
                cell = counter;
                func_8000A44C(cell, board->unkC0);
                func_8000AC34(cell, 0x8000);
                switch (row) {
                    case 0:
                        func_8000AB24(cell, 0x32, 0xFF, 0xFF, 0xFE);
                        break;
                    case 1:
                        func_8000AB24(cell, 0x44, 0xFF, 0x3E, 0xFE);
                        break;
                    case 2:
                        func_8000AB24(cell, 0xA3, 0xBE, 0x11, 0xFE);
                        break;
                    case 3:
                        func_8000AB24(cell, 0x9D, 0x59, 0x20, 0xFE);
                        break;
                }
                if (func_8002DAD0(board, row, column) == 0) {
                    func_8000AB24(cell, 0x80, 0x80, 0x80, 0xFE);
                }
                if (board->unk6C != 0 && code != 0) {
                    switch (code) {
                        case 1:
                            func_8000A44C(cell, board->unkBC);
                            break;
                        case 2:
                            func_8000A44C(cell, board->unkB8);
                            break;
                        case 3:
                            func_8000A44C(cell, board->unkB4);
                            break;
                    }
                }
                index = cell + 0x1C;
                func_8000A44C(index, board->unkC4);
                func_8000AC34(index, 0x8000);
                func_8000AB24(index, 0xA3, 0xBE, 0x11, 0xFE);
                shift += 2;
                counter++;
            }
            table++; base += 7;
        }
    }
}
