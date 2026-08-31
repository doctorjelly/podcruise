/* Implements specs/functions/recovered/func_800704A8.md. */
#include "podcruise/types.h"

extern void func_8003B184(void *request, void *context, f32 offset);
extern void func_80016F0C(const void *matrix, f32 *output);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80015268(void *output, f32 x, f32 y, f32 z);
extern void func_80015288(void *output, void *source);

#define WORD(off) (*(u32 *)((u8 *)object + (off)))
#define HALF(off) (*(s16 *)((u8 *)object + (off)))
#define REAL(off) (*(f32 *)((u8 *)object + (off)))
#define PART(off) ((void *)((u8 *)object + (off)))

void func_800704A8(void *object, f32 offset) {
    f32 matrix[16];
    f32 placement[6];

    func_8003B184(PART(0xAC), matrix, offset);
    func_80016F0C(matrix, placement);
    REAL(0x8) = placement[0];
    REAL(0xC) = placement[1];
    REAL(0x10) = placement[2];
    REAL(0x14) = placement[3];
    REAL(0x18) = placement[4];
    REAL(0x1C) = placement[5];
    func_800174B8((f32 *)PART(0x20), (f32 *)PART(0x8));
    WORD(0x60) &= ~0x10;
    WORD(0x60) &= ~0x200;
    WORD(0x60) &= ~0x800000;
    WORD(0x60) &= ~0x20000;
    WORD(0x60) &= ~0x80000;
    WORD(0x60) &= ~0x100000;
    WORD(0x64) &= ~0x800000;
    WORD(0x64) &= ~0x400000;
    WORD(0x60) &= ~0x4000000;
    WORD(0xEC) = 0;
    WORD(0xF8) = 0;
    WORD(0x100) = 0;
    HALF(0x10C) = 0;
    HALF(0x10E) = 0;
    WORD(0x114) = 0;
    REAL(0xDC) = 0.0f;
    REAL(0x118) = 0.0f;
    REAL(0x11C) = 0.0f;
    REAL(0x110) = 0.0f;
    REAL(0x124) = 1.0f;
    REAL(0x120) = 1.0f;
    if (offset < 0.0f) {
        REAL(0xE8) = REAL(0xE0);
    }
    REAL(0x18C) = 0.0f;
    REAL(0x190) = 32.0f;
    func_80015268(PART(0x194), 0.0f, 0.0f, -1.0f);
    REAL(0x1A0) = 0.0f;
    REAL(0x1B0) = 0.0f;
    REAL(0x1B4) = 0.0f;
    REAL(0x1A4) = 0.0f;
    REAL(0x1A8) = 0.0f;
    REAL(0x218) = 100.0f;
    func_80015268(PART(0x1B8), 0.0f, 0.0f, 0.0f);
    REAL(0x1EC) = 0.0f;
    REAL(0x1F0) = 0.0f;
    REAL(0x228) = 0.0f;
    REAL(0x220) = 0.0f;
    REAL(0x224) = 0.0f;
    REAL(0x1F4) = 0.0f;
    REAL(0x1F8) = 0.0f;
    REAL(0x1FC) = 0.0f;
    REAL(0x200) = 0.0f;
    REAL(0x204) = 0.0f;
    REAL(0x1EBC) = 0.25f;
    func_80015268(PART(0x1C4), 0.0f, 0.0f, 0.0f);
    func_80015268(PART(0x1D0), 0.0f, 0.0f, 0.0f);
    func_80015268(PART(0x1DC), 0.0f, 0.0f, 0.0f);
    func_80015268(PART(0x154), 0.0f, 0.0f, 0.0f);
    func_80015268(PART(0x144), 0.0f, 0.0f, 1.0f);
    func_80015288(PART(0x16C), PART(0x50));
    func_80015288(PART(0x178), PART(0x50));
    REAL(0x150) = 0.0f;
    REAL(0x1ED8) = 0.0f;
    REAL(0x250) = 0.0f;
    REAL(0x338) = 0.0f;
    REAL(0x33C) = 0.0f;
    REAL(0x340) = 0.0f;
    REAL(0x1ED4) = 0.0f;
    REAL(0x208) = 0.0f;
    REAL(0x20C) = 0.0f;
    REAL(0x264) = 0.0f;
    REAL(0x184) = 0.0f;
    REAL(0x188) = 0.0f;
    REAL(0x19AC) = 1.0f;
    REAL(0x19B4) = 1.0f;
    REAL(0x268) = 60.0f;
    REAL(0x19B0) = 0.0f;
}
