/* Independently written from the scratchpad specification specs/func_8002B574.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 b[8];
} Unk800A2618;

typedef struct {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C[4];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[0x40];
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 unk5D[0x13];
    /* 0x70 */ s8 unk70;
} Unk8002B574;

extern Unk800A2618 D_800A2618;
extern s16 D_800A2620;
extern f32 D_80120BF8;
extern const char D_800A9820[];
extern const char D_800A9830[];
extern const char D_800A9840[];
extern const char D_800A9850[];
extern const char D_800A9864[];
extern const char D_800A9874[];

extern void func_8008A6B4(char *, const char *, ...);
extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue, u8 alpha, u8 *text);

void func_8002B574(Unk8002B574 *obj) {
    s32 slot[5];
    char line[32];
    char text[36];
    s32 mode;
    s16 x;
    s16 y;
    s32 message;
    Unk800A2618 table;
    s16 i;
    s16 index;
    s32 handle;

    mode = -1;
    table = D_800A2618;

    for (i = 0; i < 5; i++) {
        slot[i] = -1;
    }

    switch (obj->unk08) {
    case 3:
        if (obj->unk10 == 0) {
            slot[0] = 0xA1;
            mode = 0xA2;
            func_8008A6B4(line, D_800A9820);
        }
        break;
    case 8:
        if (obj->unk10 == 0) {
            slot[0] = 0xA1;
            slot[1] = 0xA3;
            slot[2] = 0xA5;
            switch (D_800A2620) {
            case 0:
                func_8008A6B4(line, D_800A9830);
                break;
            case 1:
                mode = 0xA4;
                func_8008A6B4(line, D_800A9840);
                break;
            case 2:
                mode = 0xA6;
                func_8008A6B4(line, D_800A9850);
                break;
            }
        }
        break;
    case 9:
        if (obj->unk10 == 0 && obj->unk70 == 1) {
            slot[0] = 0xA3;
            func_8008A6B4(line, D_800A9864);
        }
        break;
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
    case 12:
    case 13:
    case 15:
    case 16:
    case 17:
        break;
    case 6:
    case 10:
    case 11:
    case 14:
    default:
        break;
    }

    index = D_800A2620;

    obj->unk58 = obj->unk58 + D_80120BF8;
    if (obj->unk58 >= 1.0f && obj->unk5C != 0) {
        obj->unk54 = obj->unk54 + (254.0f * D_80120BF8);
        if (obj->unk54 >= 254.0f) {
            obj->unk54 = 254.0f;
            obj->unk5C = 0;
            obj->unk58 = 0.0f;
        }
    } else if (obj->unk58 >= 3.0f && obj->unk5C == 0) {
        obj->unk54 = obj->unk54 - (254.0f * D_80120BF8);
        if (obj->unk54 <= 0.0f) {
            index++;
            obj->unk54 = 0.0f;
            obj->unk58 = 0.0f;
            obj->unk5C = 1;
            if (index == 5) {
                index = 0;
            }
            if (slot[index] == -1) {
                index = 0;
            }
        }
    }

    message = slot[index];
    D_800A2620 = index;
    if (message == -1) {
        return;
    }

    y = 25;
    x = 25;
    handle = (s16)message;
    func_8000A920(handle, 1);
    func_8000AA04(handle, x, y);
    func_8000AB24(handle, 255, 255, 255, (u32)obj->unk54);
    if (mode != 0xA4) {
        x = table.b[message - 0x9F] + 0x1B;
    }
    if (mode != -1) {
        handle = mode;
        func_8000A920(handle, 1);
        func_8000AA04(handle, x, 25);
        if (mode == 0xA4) {
            func_8000AA04(handle, x, 0x23);
            y = 0x1E;
        }
        if (mode == 0xA2) {
            func_8000AA04(handle, x, y + 5);
        }
        func_8000AB24(handle, 255, 255, 255, (u32)obj->unk54);
        x += table.b[mode - 0x9F];
    }
    x += 5;
    if (message == 0xA1) {
        y += 0xC;
    }
    func_8008A6B4(text, D_800A9874, line);
    func_8003EC40(x, y + 1, 255, 255, 255, (u32)obj->unk54, (u8 *)text);
}
