/* Implements specification specs/func_80057ED4.md (channel 0x17 setup). */
#include "podcruise/types.h"

extern void func_8000A920(s32, s32);
extern void func_8000AA04(s32, s32, s32);
extern void func_8000AAC0(s32, f32, f32);
extern void func_8000AB24(s32, s32, s32, s32, s32);
extern void func_80087814(s32, s32, s32, s32);

void func_80057ED4(void) {
    func_8000A920(0x17, 1);
    func_8000AA04(0x17, 0, 0x76);
    func_8000AAC0(0x17, 320.0f, 4.0f);
    func_8000AB24(0x17, 0, 0, 0, 0xFF);
    func_80087814(0x14, 0x75, 0x12C, 0x7B);
}
