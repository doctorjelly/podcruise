/* Independently written from specs/functions/func_800441E0.md. */

#include "podcruise/types.h"

extern void func_800862D8(s32, s32, s32, s32, s32);
extern void func_8008635C(s32, s32);
extern void func_80086730(s32, f32, f32, f32, f32, f32);

extern f32 D_800AAD00;
extern f32 D_800AAD04;

void func_800441E0(s32 mode) {
    s32 top;
    s32 bottom;
    /* Three further words of frame the original reserves and never reads. */
    s32 spare0;
    s32 spare1;
    s32 spare2;

    (void)spare0;
    (void)spare1;
    (void)spare2;
    top = 8;
    bottom = 232;
    func_8008635C(1, 5);
    func_800862D8(1, 8, (s32)(top + 40.0f), 0x138, (s32)(bottom - 40.0f));
    func_800862D8(0, 8, (s32)(top + 40.0f), 0x138, (s32)(bottom - 40.0f));
    if (mode == 14) {
        func_80086730(1, 75.0f, -1.0f, 5.0f, D_800AAD00, 100.0f);
    } else {
        func_80086730(1, 45.0f, -1.0f, 5.0f, D_800AAD04, 100.0f);
    }
}
