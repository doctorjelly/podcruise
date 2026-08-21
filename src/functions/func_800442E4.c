/* Implements the specification in specs/func_800442E4.md */
#include "podcruise/types.h"

extern void func_800862D8(s32, s32, s32, s32, s32);
extern void func_8008635C(s32, s32);
extern void func_80086730(s32, f32, f32, f32, f32, f32);
extern void func_8000A920(s32, s32);

void func_800442E4(void) {
    func_800862D8(0, 8, 8, 0x138, 0xE8);
    func_800862D8(1, 8, 8, 0x138, 0xE8);
    func_8008635C(1, 7);
    func_80086730(1, 85.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    func_8000A920(-201, 0);
}
