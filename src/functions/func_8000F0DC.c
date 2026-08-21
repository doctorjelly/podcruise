/* Recovered per scratchpad specification specs/func_8000F0DC.md. */
#include "podcruise/types.h"

typedef struct Emitter8000F0DC {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
} Emitter8000F0DC;

typedef struct Colour8000F0DC {
    /* 0x0 */ u8 red;
    /* 0x1 */ u8 green;
    /* 0x2 */ u8 blue;
    /* 0x3 */ u8 alpha;
} Colour8000F0DC;

extern Emitter8000F0DC D_8009B814[];
extern Colour8000F0DC D_8009B824[];
extern f32 D_8009B81C[];
extern s32 D_8009B82C[][8];
extern f32 D_800A8690;
extern s32 D_800D57C0[];
extern s32 D_800D57C8;
extern s32 D_800D57E8[][8];
extern f32 D_800D5828[][8];
extern u8 D_800D5868[][8][3];
extern s16 D_80114470[];

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AAC0(s16 index, f32 left, f32 right);
extern void func_8000AB24(s16 index, s32 red, s32 green, s32 blue, s32 alpha);
extern void func_8000E680(s16 index, s16 x, s16 y);
extern void func_8000EEE0(s32, s32, s32, s32, f32, f32, s32, s32, s32);
extern s32 func_8001F464(void);
extern s32 func_8002F054(void);
extern f32 func_8002F060(void);

void func_8000F0DC(s32 x, s32 y, s32 index) {
    Emitter8000F0DC *emitter;
    Colour8000F0DC *colour;
    f32 fade;
    f32 volume;
    f32 distance;
    s32 dx;
    s32 dy;
    s32 level;
    s32 shade;
    s32 slot;
    f32 intensity;

    if (D_800D57C0[index] >= 50) {
        func_8000A920(D_8009B814[index].unk2, 0);
        for (slot = 0; slot < 8; slot++) {
            if (D_8009B82C[index][slot] != -1) {
                func_8000A920((s16)D_8009B82C[index][slot], 0);
            }
        }
        return;
    }
    fade = 1.0f - (f32)D_800D57C0[index] / 50.0f;
    volume = D_8009B81C[index] * fade;
    dx = x - D_80114470[0] / 2;
    dy = y - D_80114470[1] / 2;
    distance = sqrtf((f32)(dx * dx + dy * dy)) / 80.0f;
    emitter = &D_8009B814[index];
    if (1.0f < distance) {
        level = 0;
    } else {
        level = (s32)(255.0f - distance * 255.0f);
    }
    colour = &D_8009B824[index];
    level = (s32)(volume / D_8009B81C[index]) * level;
    level = (s32)((f32)level * ((f32)(u32)colour->alpha / 255.0f));
    if (D_800D57C8 < level) {
        D_800D57C8 = level;
    }
    func_8000A920(emitter->unk2, 1);
    func_8000E680(emitter->unk2, (s16)x, (s16)y);
    func_8000AAC0(emitter->unk2, volume, volume);
    if (func_8002F054() != 0) {
        shade = (s32)(255.0f - func_8002F060() * 150.0f);
    } else {
        shade = 255;
    }
    func_8000AB24(emitter->unk2, colour->red, colour->green, colour->blue,
                  colour->alpha * shade / 255);
    if (2.0f < distance || func_8001F464() == 0) {
        for (slot = 0; slot < 8; slot++) {
            if (D_8009B82C[index][slot] != -1) {
                func_8000A920((s16)D_8009B82C[index][slot], 0);
            }
        }
        return;
    }
    intensity = (1.0f - func_8002F060() * D_800A8690) *
                (fade * ((2.0f - distance) * 0.5f)) *
                ((f32)(u32)colour->alpha / 255.0f);
    for (slot = 0; slot < 8; slot++) {
        if (D_8009B82C[index][slot] != -1) {
            func_8000A920((s16)D_8009B82C[index][slot], 1);
            func_8000EEE0(D_8009B82C[index][slot], x, y, D_800D57E8[index][slot],
                          D_800D5828[index][slot], intensity,
                          D_800D5868[index][slot][0], D_800D5868[index][slot][1],
                          D_800D5868[index][slot][2]);
        }
    }
}
