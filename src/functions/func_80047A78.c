/* Independently written from specs/func_80047A78.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
} Obj;

#define ID_BASE_US 0x8D
#define ID_BASE_JP 0x8F

#ifndef ID_BASE
#define ID_BASE ID_BASE_US
#endif

extern s32 D_800A4BB8;

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);

void func_80047A78(Obj *object, s32 arg1, s32 arg2, f32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s16 id;
    f32 scaleX;
    f32 scaleY;

    (void)arg4;

    if (object->unk08 == 8) {
        scaleX = 0.375f;
        scaleY = 3.75f;
    } else {
        arg1 += 3;
        arg2 += 1;
        arg5 -= 2.0f;
        scaleX = arg5 * 0.125f;
        scaleY = arg6 * 0.125f;
    }

    id = (s16)(D_800A4BB8 + ID_BASE);
    D_800A4BB8 += 1;
    func_8000A920(id, 1);
    func_8000AA04(id, (s16)arg1, (s16)arg2);
    func_8000AAC0(id, scaleX, (1.0f - arg3) * scaleY);
    func_8000AB24(id, 0, 0, 0, 0xFF);

    id = (s16)(D_800A4BB8 + ID_BASE);
    D_800A4BB8 += 1;
    func_8000A920(id, 1);
    func_8000AA04(id, (s16)arg1, (s16)(s32)((f32)arg2 + (1.0f - arg3) * arg6));
    func_8000AAC0(id, scaleX, scaleY * arg3);
    func_8000AB24(id, (u8)(u32)((1.0f - arg3) * 255.0f), (u8)(u32)(255.0f * arg3), 0, 0xFF);
}
