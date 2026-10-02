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
static f32 rotation[2];
static s32 drawingCalls;
static s32 trigCalls;

void func_80014CC0(f32 angle, f32 *sine, f32 *cosine) {
    (void)angle;
    *sine = 0.25f;
    *cosine = 0.75f;
    trigCalls++;
}

void func_8003BAB0(
    Gfx8003D4F4 **output, Resource8003D4F4 *resource,
    Strip8003D4F4 *strip, f32 left, f32 top, f32 right, f32 bottom,
    s32 arg6, s32 arg7, s32 xTexture, s32 yTexture, s32 stepX,
    s32 stepY, s32 reverseX, s32 forwardY, f32 sine, f32 cosine,
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
    (void)flags;
    geometry[0] = left;
    geometry[1] = top;
    geometry[2] = right;
    geometry[3] = bottom;
    rotation[0] = sine;
    rotation[1] = cosine;
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

static void check_render_flags(void) {
    static Gfx8003D4F4 commands[32];
    static const s32 flags[] = { 0, 0x800, 0x800000, 0x20000, 0x2000 };
    s32 i;

    for (i = 0; i < 5; i++) {
        D_801217B0 = commands;
        D_800A4960 = 0;
        drawingCalls = 0;
        trigCalls = 0;
        func_8003D4F4(0, 20, 30, 1.0f, 1.0f, 0.0f,
                      0, 0, flags[i], 255, 255, 255, 255);
        assert(drawingCalls == 1);
        if (i == 2) {
            assert(trigCalls == 1);
            assert(rotation[0] == 0.25f);
            assert(rotation[1] == 0.75f);
        } else {
            assert(trigCalls == 0);
            assert(rotation[0] == 0.0f);
            assert(rotation[1] == 1.0f);
        }
        if (i == 3) {
            assert(geometry[0] == 15.0f);
            assert(geometry[1] == 25.0f);
            assert(geometry[2] == 25.0f);
            assert(geometry[3] == 35.0f);
        } else {
            assert(geometry[0] == 20.0f);
            assert(geometry[1] == 30.0f);
        }
    }
}

static void check_mode_commands(void) {
    /* Canonical branches at 8003D68C-8003D6FC, including the unusual
     * transition from old mode 1 to requested mode 0 without a command. */
    static const s32 expected[4][4] = {
        { 1, 0, 1, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 }
    };
    static const u32 payloads[4] = {
        0x0F0A7008, 0x00504240, 0x00504340, 0x00504340
    };
    static Gfx8003D4F4 commands[32];
    Gfx8003D4F4 *command;
    s32 oldMode;
    s32 newMode;
    s32 count;

    for (newMode = 0; newMode < 4; newMode++) {
        for (oldMode = 0; oldMode < 4; oldMode++) {
            D_801217B0 = commands;
            D_800A4960 = 0x20 | oldMode;
            func_8003D4F4(0, 0, 0, 1.0f, 1.0f, 0.0f,
                          0, 0, 0x10000 | newMode, 255, 255, 255, 255);
            count = 0;
            for (command = commands; command < D_801217B0; command++) {
                if (command->w0 == 0xE200001C) {
                    assert(command->w1 == payloads[newMode]);
                    count++;
                }
            }
            assert(count == expected[newMode][oldMode]);
            assert(D_800A4960 == (0x10020 | newMode));
        }
    }
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
    check_render_flags();
    check_mode_commands();
    return 0;
}
