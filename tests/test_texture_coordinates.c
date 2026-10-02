#include <assert.h>

#include "../src/functions/func_8003D4F4.c"

Gfx8003D4F4 *D_801217B0;
s32 D_800A4960;
s32 D_800A48D4;
Resource8003D4F4 D_800A4908;
f32 D_800AAB14;
f32 D_800AAB18;
f32 D_800AAB1C;

static f32 geometry[4];
static s32 drawingCalls;

void func_80014CC0(f32 angle, f32 *cosine, f32 *sine) {
    (void)angle;
    *cosine = 1.0f;
    *sine = 0.0f;
}

void func_8003BAB0(
    Gfx8003D4F4 **output, Resource8003D4F4 *resource,
    Strip8003D4F4 *strip, f32 left, f32 top, f32 right, f32 bottom,
    s32 arg6, s32 arg7, s32 xTexture, s32 yTexture, s32 stepX,
    s32 stepY, s32 reverseX, s32 forwardY, f32 cosine, f32 sine,
    s32 flags) {
    (void)output;
    (void)resource;
    (void)strip;
    (void)arg6;
    (void)arg7;
    (void)xTexture;
    (void)yTexture;
    (void)stepX;
    (void)stepY;
    (void)reverseX;
    (void)forwardY;
    (void)cosine;
    (void)sine;
    (void)flags;
    geometry[0] = left;
    geometry[1] = top;
    geometry[2] = right;
    geometry[3] = bottom;
    drawingCalls++;
}

static void check_position(s32 x, s32 y, f32 left, f32 top) {
    static Gfx8003D4F4 commands[32];

    D_801217B0 = commands;
    drawingCalls = 0;
    func_8003D4F4(0, x, y, 1.0f, 1.0f, 0.0f,
                  0, 0, 0, 255, 255, 255, 255);

    assert(drawingCalls == 1);
    assert(geometry[0] == left);
    assert(geometry[1] == top);
    assert(geometry[2] == left + 10.0f);
    assert(geometry[3] == top + 10.0f);
}

int main(void) {
    static Strip8003D4F4 strips[1];
    static u8 stripData;

    D_800A4908.width = 10;
    D_800A4908.height = 10;
    D_800A4908.type = 0;
    D_800A4908.format = 0;
    D_800A4908.stripCount = 1;
    D_800A4908.defaultCrossSpan = 10;
    D_800A4908.strips = strips;
    strips[0].span = 10;
    strips[0].crossSpan = 10;
    strips[0].data = &stripData;

    check_position(2, 4, 2.0f, 4.0f);
    check_position(65537, 65539, 1.0f, 3.0f);
    check_position(65535, 32768, -1.0f, -32768.0f);
    return 0;
}
