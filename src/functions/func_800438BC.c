/* Recovered from specification: func_800438BC (see worker spec). */
#include "podcruise/types.h"

typedef struct Object {
    u8 unk00[0x2C];
    u32 flags;
} Object;

extern char D_800AABA0[];
extern char D_800AABA8[];
extern char D_800AABB0[];
extern char D_800AABB8[];
extern char D_800AABC0[];
extern char D_800AABC8[];
extern char D_800AABD0[];
extern char D_800AABD8[];
extern char D_800AABE0[];
extern char D_800AABE8[];
extern char D_800AABF0[];
extern char D_800AABF8[];
extern char D_800AAC00[];
extern char D_800AAC08[];
extern char D_800AAC10[];
extern char D_800AAC18[];
extern char D_800AAC20[];
extern char D_800AAC28[];
extern char D_800AAC30[];
extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8003ECB0(s16 column, s16 row, const char *text);

void func_800438BC(Object *object) {
    register Object *o;
    u8 text[64];

    o = object;
    if (o != 0) {
        text[0] = 0;
        if (o->flags & 0x1) {
            func_8008A6B4((char *)text, D_800AABA0, (char *)text);
        }
        if (o->flags & 0x2) {
            func_8008A6B4((char *)text, D_800AABA8, (char *)text);
        }
        if (o->flags & 0x4) {
            func_8008A6B4((char *)text, D_800AABB0, (char *)text);
        }
        if (o->flags & 0x8) {
            func_8008A6B4((char *)text, D_800AABB8, (char *)text);
        }
        if (o->flags & 0x10) {
            func_8008A6B4((char *)text, D_800AABC0, (char *)text);
        }
        if (o->flags & 0x20) {
            func_8008A6B4((char *)text, D_800AABC8, (char *)text);
        }
        if (o->flags & 0x40) {
            func_8008A6B4((char *)text, D_800AABD0, (char *)text);
        }
        if (o->flags & 0x80) {
            func_8008A6B4((char *)text, D_800AABD8, (char *)text);
        }
        if (o->flags & 0x100) {
            func_8008A6B4((char *)text, D_800AABE0, (char *)text);
        }
        if (o->flags & 0x200) {
            func_8008A6B4((char *)text, D_800AABE8, (char *)text);
        }
        if (o->flags & 0x400) {
            func_8008A6B4((char *)text, D_800AABF0, (char *)text);
        }
        if (o->flags & 0x800) {
            func_8008A6B4((char *)text, D_800AABF8, (char *)text);
        }
        if (o->flags & 0x1000) {
            func_8008A6B4((char *)text, D_800AAC00, (char *)text);
        }
        if (o->flags & 0x2000) {
            func_8008A6B4((char *)text, D_800AAC08, (char *)text);
        }
        if (o->flags & 0x4000) {
            func_8008A6B4((char *)text, D_800AAC10, (char *)text);
        }
        if (o->flags & 0x8000) {
            func_8008A6B4((char *)text, D_800AAC18, (char *)text);
        }
        if (o->flags & 0x10000) {
            func_8008A6B4((char *)text, D_800AAC20, (char *)text);
        }
        if (o->flags & 0x20000) {
            func_8008A6B4((char *)text, D_800AAC28, (char *)text);
        }
        if (o->flags & 0x20000000) {
            func_8008A6B4((char *)text, D_800AAC30, (char *)text);
        }
        if (text[0] != 0) {
            func_8003ECB0(0x14, 0xC8, (char *)text);
        }
    }
}
