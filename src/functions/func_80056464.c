/* Specification: scratchpad specs/func_80056464.md */
#include "podcruise/types.h"

extern f32 func_8002F060(void);
extern void func_8000A920(s32 arg0, s32 arg1);
extern void func_8000AA04(s32 arg0, s32 arg1, s32 arg2);
extern void func_8000AAC0(s32 arg0, f32 arg1, f32 arg2);
extern void func_8000AB24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4);
extern void func_80087814(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_80056464(void) {
    f32 c160 = 160.0f;
    f32 c12 = 12.5f;
    f32 c20 = 20.0f;
    f32 c30 = 30.0f;
    s32 red = 0;
    s32 green = 110;
    s32 blue = 143;
    f32 level;
    f32 mark;
    s32 alpha = 254;

    level = func_8002F060();
    if (level <= 0.0f) {
        func_8000A920(0x1A, 0);
        return;
    }

    func_8000A920(0x1A, 1);

    mark = 90.0f - (1.0f - level) * 80.0f;
    func_8000AA04(0x1A, (s16) c160, (s16) mark);
    func_8000AAC0(0x1A, c12 + c20, 3.90625f);
    func_8000AB24(0x1A, (u8) (red * 0.5), (u8) (green * 0.5), (u8) (blue * 0.5),
                  (u32) (alpha * level));
    func_80087814((s16) (c160 - 65.0f), (s16) (mark - c30), (s16) (c160 + 60.0f),
                  (s16) (mark + c30));
}
