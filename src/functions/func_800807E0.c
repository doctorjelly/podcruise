/* Independently written from scratchpad spec specs/func_800807E0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
} Flags800807E0;

typedef struct {
    /* 0x00 */ u8 pad00[0x3C];
    /* 0x3C */ s16 unk3C;
} Rider800807E0;

typedef struct {
    /* 0x000 */ u8 pad000[0x64];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad068[0x44];
    /* 0x0AC */ u8 unkAC[0x30];
    /* 0x0DC */ f32 unkDC;
    /* 0x0E0 */ u8 pad0E0[0xC];
    /* 0x0EC */ void *unkEC;
    /* 0x0F0 */ u8 pad0F0[4];
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ s32 unkF8;
    /* 0x0FC */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ u8 pad104[0x3C];
    /* 0x140 */ Rider800807E0 *unk140;
} Craft800807E0;

extern Flags800807E0 *func_800183A8(const void *object);
extern void func_8007EE98(void *track, s32 value);
extern s32 func_8007F22C(void *track, s32 *output);
extern s32 func_8007F23C(void *track, s32 *output);
extern f32 func_80080350(void *track);
extern void *func_80080408(void *track);
extern void func_80080498(Craft800807E0 *craft, s32 *a, s32 *b, s32 *c);

s32 func_800807E0(Craft800807E0 *craft) {
    Flags800807E0 *flags;
    s32 first;
    s32 second;
    s32 result;

    result = 0;
    if (craft->unkEC != (void *)craft->unk140 && craft->unkEC != 0 &&
        craft->unk140 != 0 && (craft->unk64 & 0x20000000) == 0) {
        flags = func_800183A8(craft->unk140);
        if (flags == 0 || (flags->unk00 & 8) == 0) {
            result = 1;
            if (craft->unk140->unk3C != 0) {
                func_8007EE98(craft->unkAC, craft->unk140->unk3C);
                func_80080498(craft, &first, &second, &second);
            }
            craft->unkEC = func_80080408(craft->unkAC);
            craft->unkDC = func_80080350(craft->unkAC);
            craft->unkF8 = func_8007F22C(craft->unkAC, &craft->unkF4);
            craft->unk100 = func_8007F23C(craft->unkAC, &craft->unkFC);
        } else {
            result = (flags == 0) ? -2 : -1;
        }
    }
    return result;
}
