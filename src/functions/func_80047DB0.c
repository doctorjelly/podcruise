/* Independently written from specs/functions/recovered/func_80047DB0.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 unk04[0x8];
    /* 0x0C */ void *unk0C;
} Holder;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ u8 unk10[0x28];
} Record;

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
} Triple;

extern Triple D_800A51C4;
extern f32 D_800A4BF0;
extern s32 D_800A4BE8;
extern f32 D_800A4B50;
extern f32 D_800AAF9C;
extern f64 D_800AAFA0;
extern u8 D_80113E60[];
extern Record D_8011A050[];
extern s32 D_8011A240[];
extern Holder *D_8011A508[];
extern f32 D_80118D60[4][4];
extern f32 D_80118D70[4];
extern f32 D_80118D80[4];
extern f32 D_80118D90[4];

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_80015288(f32 *destination, f32 *source);
extern void func_800155EC(f32 *out, f32 *base, f32 scale, f32 *offset);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_800178C4(void *output, void *source, f32 angle, f32 x, f32 y, f32 z);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_80028D60(void);
extern void func_80046DC4(void *object, f32 x, f32 y);
extern void func_80047A78(void *object, s32 arg1, s32 arg2, f32 arg3, f32 arg4,
                          f32 arg5, f32 arg6);

void func_80047DB0(void *object) {
    f32 point[3];
    f32 second[4][4];
    f32 first[4][4];
    Triple vector;
    f32 level;
    f32 columnBase;
    f32 rowBase;
    f32 scale;
    void *entry;
    void *other;
    Record *record;
    s16 identifier;
    s16 column;
    u8 alpha;
    s32 index;

    vector = D_800A51C4;

    level = D_800A4BF0 * 2.5f * 255.0f;
    if (254.0f < level) {
        level = 254.0f;
    }
    func_80046DC4(object, 20.0f, 135.0f);

    alpha = (u8)(u32)level;
    for (index = 0; index <= D_8011A240[11]; index++) {
        identifier = (s16)(index + 0x5F);
        func_8000A920(identifier, 1);
        columnBase = (f32)((index % 2) * 40 + 210);
        rowBase = (f32)((index / 2) * 35 + 20);
        column = (s16)(s32)(columnBase + 2.0f);
        func_8000AA04(identifier, column, (s16)(s32)(rowBase + 1.0f));
        if (index == D_8011A240[11]) {
            func_8000AA04(identifier, column, (s16)(s32)(rowBase + 2.0f));
        }
        func_8000AB24(identifier, 0x32, 0xFF, 0xFF, alpha);

        identifier = (s16)(index + 0x67);
        func_8000A920(identifier, 1);
        func_8000AA04(identifier, (s16)(s32)columnBase, (s16)(s32)rowBase);
        func_8000AB24(identifier, 0xA3, 0xBE, 0x11, alpha);

        if (index == D_800A4BE8) {
            identifier = 0x70;
            if (index < D_8011A240[11]) {
                identifier = 0x6F;
            }
            func_8000A920(identifier, 1);
            column = (s16)(s32)(columnBase - 5.0f);
            func_8000AA04(identifier, column, (s16)(s32)(rowBase - 7.0f));
            if (index == D_8011A240[11]) {
                func_8000AA04(identifier, column, (s16)(s32)(rowBase - 4.0f));
            }
            func_8000AB24(identifier, 0x32, 0xFF, 0xFF, alpha);
        }
        if (index < D_8011A240[11]) {
            func_80047A78(object, (s32)(columnBase + 36.0f), (s32)(rowBase + 2.0f),
                          (f32)(u32)D_80113E60[index + 0x24] * D_800AAF9C,
                          level, 3.0f, 30.0f);
        }
    }

    for (index = 0; index < D_8011A240[11] + 1; index++) {
        entry = D_8011A508[0x8E + index]->unk00;
        if (entry == 0) {
            continue;
        }
        record = &D_8011A050[index];
        if (entry != 0) {
            func_800181BC(entry, 2, -4, 0x10, 3);
        }
        if (index == D_8011A240[11]) {
            other = D_8011A508[0x8E + index]->unk0C;
            if (other != 0) {
                if (other != 0) {
                    func_800181BC(other, 2, -4, 0x10, 3);
                }
            }
        }
        func_80028D60();
        func_800156DC(first, D_80118D60);
        func_80015288(point, D_80118D90);
        func_800155EC(point, point, record->unk04, D_80118D60[0]);
        func_800155EC(point, point, record->unk08, D_80118D70);
        func_800155EC(point, point, record->unk0C, D_80118D80);
        func_80015288(first[3], point);
        func_800156DC(second, first);
        if (index == D_800A4BE8) {
            if (index != D_8011A240[11]) {
                func_800178C4(second, second, D_800A4B50 * 4.0f,
                              first[2][0], first[2][1], first[2][2]);
                func_800178C4(second, second, 45.0f,
                              first[1][0], first[1][1], first[1][2]);
                func_800178C4(second, second, D_800A4B50 * -1.0f,
                              first[2][0], first[2][1], first[2][2]);
            }
        }
        scale = (f32)((f64)(D_800A4BF0 * 2.5f) * D_800AAFA0);
        if (index == D_8011A240[11]) {
            scale = (f32)((f64)scale * 5.5);
        }
        func_80017918(second, scale, scale, scale, second);
        func_80015288(second[3], point);
        func_80017BA8(entry, second);
        if (entry != 0) {
            func_800181BC(entry, 2, 3, 0x10, 2);
        }
    }
    (void)vector;
}
