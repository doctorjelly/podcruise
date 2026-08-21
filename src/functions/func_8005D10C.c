/* Recovered per specs/func_8005D10C.md (podcruise worker specification). */
#include "podcruise/types.h"

extern f32 D_800AD008;
extern f32 D_800AD00C;

extern void func_8000FD74(s32, s32, s32, f32, f32, s32, s32, s32);

void func_8005D10C(s32 arg0, s32 arg1, f32 arg2) {
    func_8000FD74(arg0, 0, arg1, 1.0f, arg2 * D_800AD008, 0xFF, 0xFF, 0xC8);
    func_8000FD74(arg0, 1, arg1 + 1, 0.75f, arg2, 0xFF, 0xFF, 0xC8);
    func_8000FD74(arg0, 2, arg1 + 2, 0.63f, arg2 * 0.75f, 0xB4, 0xFF, 0xB4);
    func_8000FD74(arg0, 3, arg1 + 3, 0.43f, arg2 * 2.0f, 0xFF, 0xFF, 0xC8);
    func_8000FD74(arg0, 4, arg1 + 4, 0.25f, arg2 * D_800AD00C, 0xFF, 0xC8, 0xC8);
    func_8000FD74(arg0, 4, arg1 + 5, -0.18f, arg2 * 0.75f, 0xFF, 0xC8, 0xC8);
    func_8000FD74(arg0, 5, arg1 + 6, -0.43f, arg2, 0xB4, 0xFF, 0xB4);
    func_8000FD74(arg0, 6, arg1 + 7, -1.35f, arg2 * 0.5f, 0xFF, 0xB4, 0xB4);
}
