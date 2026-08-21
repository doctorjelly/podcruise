/* Independently written from scratchpad spec specs/func_8001C404.md. */

#include "podcruise/types.h"

typedef struct Racer {
    char unk_00[0x5E];
    s8 unk_5E;
    char unk_5F[0x0D];
    s8 unk_6C;
} Racer;

typedef struct Str16 {
    s32 unk_00[4];
} Str16;

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern s32 func_8002DA0C(s8 slot, u8 lane);
extern s32 func_8002DAD0(Racer *object, s8 slot, u8 lane);
extern s32 func_8002DB20(Racer *object, s32 rank);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 red, u8 green, u8 blue,
                          u8 alpha, const char *text);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

extern u8 D_800A21B4[];
extern s16 D_80113E6C[];
extern f32 D_8011A240;
extern s32 D_8011A270;

extern Str16 D_800A8AD0;
extern const char D_800A8AE0[];
extern const char D_800A8AE8[];
extern const char D_800A8AF4[];
extern const char D_800A8B00[];
extern const char D_800A8B0C[];
extern const char D_800A8B18[];
extern const char D_800A8B24[];
extern const char D_800A8B30[];
extern const char D_800A8B3C[];
extern const char D_800A8B48[];

void func_8001C404(object, selected)
Racer *object;
unsigned char selected;
{
    f32 alpha;
    s32 first;
    s32 last;
    Str16 buffer;
    s32 i;
    s32 j;
    s16 id;
    s8 slot;
    u8 lane;
    s32 elem;
    s16 state;

    state = 0;
    buffer = D_800A8AD0;
    alpha = 254.0f;
    first = selected;
    if (object->unk_5E != first) {
        alpha = D_8011A240 * 254.0f;
    }
    last = first + 1;
    if (first < last) {
        i = first;
        do {
        slot = i;
        for (j = 0; j < D_800A21B4[i]; j++) {
            elem = 0x37 + j * 0x23;
            lane = j;
            if (object->unk_6C != 0) {
                state = (D_80113E6C[i] >> (j * 2)) % 4;
            }
            id = 0x60 + i * 7 + j;
            func_8000A920(id, 1);
            func_8000AA04(id, elem, 0x5E);
            func_8000AAC0(id, 0.6667f, 0.6667f);
            switch (i) {
            case 0:
                func_8000AB24(id, 0x32, 0xFF, 0xFF, (u8)alpha);
                break;
            case 1:
                func_8000AB24(id, 0x44, 0xFF, 0x3E, (u8)alpha);
                break;
            case 2:
                func_8000AB24(id, 0xA3, 0xBE, 0x11, (u8)alpha);
                break;
            case 3:
                func_8000AB24(id, 0x9D, 0x59, 0x20, (u8)alpha);
                break;
            }
            if (func_8002DAD0(object, slot, lane) == 0) {
                func_8000AB24(id, 0x80, 0x80, 0x80, (u8)alpha);
            } else if (state > 0) {
                func_8000AB24(id, 0xFF, 0xFF, 0xFF, (u8)alpha);
            }
            func_8008A6B4((char *)&buffer, D_800A8AE0, j + 1);
            if (object->unk_6C == 0 || func_8002DA0C(slot, lane) != 0) {
                if (func_8002DAD0(object, slot, lane) == 0) {
                    func_8003EC40(elem + 5, 0x6D, 0x80, 0x80, 0x80, (u8)alpha,
                                  (char *)&buffer);
                    func_8003EC40(elem + 0xC, 0x6F, 0x80, 0x80, 0x80, (u8)alpha,
                                  D_800A8AE8);
                } else {
                    switch (i) {
                    case 0:
                        func_8003EC40(elem + 5, 0x6D, 0x32, 0xFF, 0xFF, (u8)alpha,
                                      (char *)&buffer);
                        func_8003EC40(elem + 0xC, 0x6F, 0x32, 0xFF, 0xFF, (u8)alpha,
                                      D_800A8AF4);
                        break;
                    case 1:
                        func_8003EC40(elem + 5, 0x6D, 0x44, 0xFF, 0x3E, (u8)alpha,
                                      (char *)&buffer);
                        func_8003EC40(elem + 0xC, 0x6F, 0x44, 0xFF, 0x3E, (u8)alpha,
                                      D_800A8B00);
                        break;
                    case 2:
                        func_8003EC40(elem + 5, 0x6D, 0xA3, 0xBE, 0x11, (u8)alpha,
                                      (char *)&buffer);
                        func_8003EC40(elem + 0xC, 0x6F, 0xA3, 0xBE, 0x11, (u8)alpha,
                                      D_800A8B0C);
                        break;
                    case 3:
                        func_8003EC40(elem + 5, 0x6D, 0x9D, 0x59, 0x20, (u8)alpha,
                                      (char *)&buffer);
                        func_8003EC40(elem + 0xC, 0x6F, 0x9D, 0x59, 0x20, (u8)alpha,
                                      D_800A8B18);
                        break;
                    }
                }
            }
            if (object->unk_6C != 0 && state == 0 &&
                func_8002DA0C(slot, lane) == 0) {
                switch (i) {
                case 0:
                    func_8003EC40(elem + 3, 0x6F, 0x32, 0xFF, 0xFF, (u8)alpha,
                                  D_800A8B24);
                    break;
                case 1:
                    func_8003EC40(elem + 3, 0x6F, 0x44, 0xFF, 0x3E, (u8)alpha,
                                  D_800A8B30);
                    break;
                case 2:
                    func_8003EC40(elem + 3, 0x6F, 0xA3, 0xBE, 0x11, (u8)alpha,
                                  D_800A8B3C);
                    break;
                case 3:
                    func_8003EC40(elem + 3, 0x6F, 0x9D, 0x59, 0x20, (u8)alpha,
                                  D_800A8B48);
                    break;
                }
            }
            id = 0x7C + i * 7 + j;
            func_8000A920(id, 1);
            func_8000AA04(id, 0x35 + j * 0x23, 0x5C);
            func_8000AAC0(id, 0.6667f, 0.6667f);
            func_8000AB24(id, 0xA3, 0xBE, 0x11, (u8)alpha);
            if (func_8002DAD0(object, slot, lane) == 0) {
                func_8000AB24(id, 0x80, 0x80, 0x80, (u8)alpha);
            }
            if (object->unk_5E == first) {
                if (func_8002DB20(object, D_8011A270) == j) {
                    func_8000A920(id, 0);
                    func_8000A920(0x5F, 1);
                    func_8000AA04(0x5F, elem - 5, 0x59);
                    func_8000AAC0(0x5F, 0.6667f, 0.6667f);
                    func_8000AB24(0x5F, 0x32, 0xFF, 0xFF, (u8)alpha);
                }
            }
        }
        } while (++i != last);
    }
}
