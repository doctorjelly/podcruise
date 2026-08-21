/* Independently written from specs/functions/func_800305E8.md. */

#include "podcruise/types.h"

extern s32 D_800A2848;
extern s32 D_800A2864;
extern s32 D_800D9DBC;
extern s32 D_800D9DC0;
extern s32 D_800D9DC4;
extern s32 D_800D9DC8;
extern s32 D_800D9DCC;
extern s32 D_800D9DD0;
extern u32 *D_80114528;
extern u8 D_141E200[];

extern u8 *func_80011940(u8 *source, u8 *destination);
extern void func_80011CDC(void *source, void *destination, s32 length);
extern void func_80011D60(u8 *source, u8 *destination, s32 length);
extern void func_8002FAC4(u8 *top);
extern u8 *func_8002FAFC(void);
extern s32 func_8002FC58(void);
extern void func_800304AC(s32 index, s32 *first, s32 *second);
extern void func_800827C0(void *argument);

void *func_800305E8(s32 index) {
    s32 count;
    s32 padA[3];
    s32 header[3];
    void *result;
    u8 *data;
    u8 *scratch;
    u8 *mark;
    s32 size;
    s32 packed;
    s32 started;
    s32 limit;
    s32 i;
    u32 *cursor;
    u32 word;
    s32 padB[5];
    u8 *base[1];
    u32 *bitmap[1];

    (void)padA;
    (void)padB;
    D_800A2848 = 1;
    D_800D9DC8 = 0;
    D_800D9DCC = 0;
    D_800D9DD0 = 0;
    bitmap[0] = D_80114528;
    base[0] = D_141E200;
    func_80011D60(base[0], (u8 *)&count, 4);
    if (index < 0 || index >= count) {
        return 0;
    }
    func_80011D60(base[0] + index * 8 + 4, (u8 *)header, 0xC);
    size = header[2] - header[1];
    func_80011CDC(header[0] + base[0], bitmap[0], header[1] - header[0]);

    mark = func_8002FAFC();
    data = (u8 *)(((unsigned long)mark + 7) & ~7UL);
    func_80011CDC(header[1] + base[0], data, 0xC);

    if (*(u32 *)data == 0x436F6D70) {
        packed = size - 0xC;
        size = ((s32 *)data)[2];
        if (func_8002FC58() < size + 8) {
            D_800A2864 = 1;
            return 0;
        }
        scratch = (u8 *)(unsigned long)((u32)(D_800D9DBC - packed) & ~7U);
        if (scratch < data + size) {
            D_800A2864 = 1;
            return 0;
        }
        func_80011CDC(header[1] + 0xC + base[0], scratch, packed);
        func_80011940(scratch, data);
        func_8002FAC4(data + size);
    } else {
        if (func_8002FC58() < size + 8) {
            D_800A2864 = 1;
            return 0;
        }
        func_80011CDC(header[1] + base[0], data, size);
        func_8002FAC4(data + size);
    }

    D_800D9DC0 = (s32)(unsigned long)mark;
    D_800D9DC4 = (s32)(unsigned long)func_8002FAFC();
    started = (s32)(unsigned long)func_8002FAFC();
    result = data;
    limit = size >> 2;
    cursor = (u32 *)data;
    for (i = 0; i < limit; i++) {
        word = bitmap[0][i >> 5] & (1U << (31 - (i & 31)));
        if (word != 0) {
            if ((*cursor & 0xFF000000) == 0x0A000000) {
                func_800304AC((s32)(*cursor & 0xFFFFFF), (s32 *)cursor,
                              (s32 *)(cursor + 1));
            } else if (*cursor != 0) {
                *cursor = *cursor + (u32)(unsigned long)data;
            }
        }
        cursor++;
    }

    if (*(u32 *)data == 0x4D6F646C || *(u32 *)data == 0x5472616B ||
        *(u32 *)data == 0x506F6464 || *(u32 *)data == 0x50617274 ||
        *(u32 *)data == 0x5363656E || *(u32 *)data == 0x4D416C74 ||
        *(u32 *)data == 0x50757070) {
        result = data + 4;
    } else {
        func_800827C0((void *)(unsigned long)*(u32 *)data);
    }

    D_800D9DCC = (s32)(unsigned long)func_8002FAFC() - started;
    D_800D9DC8 = D_800D9DC4 - D_800D9DC0;
    return result;
}
