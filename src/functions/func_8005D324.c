/* Independently written from specs/functions/recovered/func_8005D324.md. */

#include "podcruise/types.h"

extern s32 D_800A52BC;
extern f32 D_800AD010;
extern f32 D_800AD014;
extern f32 D_800AD018;
extern f32 D_800AD01C;
extern f32 D_800AD020;
extern f32 D_800AD024;
extern f32 D_800AD028;
extern f32 D_800AD02C;
extern f32 D_800AD030;
extern f32 D_800AD034;
extern f32 D_800AD038;
extern f32 D_800AD03C;
extern f32 D_800AD040;
extern f32 D_800AD044;
extern f32 D_800AD048;
extern f32 D_800AD04C;
extern f32 D_800AD050;
extern f32 D_800AD054;

extern void func_80011928(void);
extern s32 func_80030154(s32);
extern void func_8000A44C(s16, s32);
extern void func_8000AC34(s16, u32);
extern void func_8000AC60(s16, u32);
extern void func_8000FCBC(s32, s32, f32 *, f32, u8, u8, u8, u8);
extern void func_8005D10C(s32, s32, f32);
extern void func_80011814(void);
extern void func_800117E4(f32);
extern void func_800117A4(s32);
extern void func_80011824(s32, s32);
extern void func_80011778(u8, u8, u8, u8);
extern void func_80011764(f32, f32);
extern void func_8000FCA4(s32, u8);
extern void func_80010014(s32, s32, s32);
extern void func_800117F0(void);

void func_8005D324(s32 arg0, s32 arg1) {
    s16 id;
    s32 paletteB;
    f32 position[3];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    f32 scale;
    s32 palette;
    s32 limit;
    s32 index;

    if (D_800A52BC >= 2) {
        func_80011928();
        return;
    }

    if (arg0 != 7 && arg0 != 5) {
        palette = func_80030154(0x1C);
        func_8000A44C(0x46, palette);
        if (arg0 == 0) {
            func_8000A44C(0x4E, palette);
        }
        palette = func_80030154(0x6D);
        func_8000A44C(0x47, palette);
        func_8000A44C(0x48, palette);
        func_8000A44C(0x49, palette);
        func_8000A44C(0x4A, palette);
        func_8000A44C(0x4B, palette);
        func_8000A44C(0x4C, palette);
        func_8000A44C(0x4D, palette);
        if (arg0 == 0) {
            func_8000A44C(0x4F, palette);
            func_8000A44C(0x50, palette);
            func_8000A44C(0x51, palette);
            func_8000A44C(0x52, palette);
            func_8000A44C(0x53, palette);
            func_8000A44C(0x54, palette);
            func_8000A44C(0x55, palette);
        }
        palette = func_80030154(0x56);
        func_8000A44C(0x44, palette);
        if (arg0 == 0) {
            func_8000A44C(0x45, palette);
        }
        func_8000AC34(0x44, 0x1E00);
        func_8000AC60(0x44, 1);
        for (index = 0x46; index < 0x4E; index++) {
            id = index;
            func_8000AC34(id, 0x1E00);
            func_8000AC60(id, 1);
        }
        if (arg0 == 0) {
            func_8000AC34(0x45, 0x1E00);
            func_8000AC60(0x45, 1);
            for (index = 0x4E; index < 0x56; index++) {
                id = index;
                func_8000AC34(id, 0x1E00);
                func_8000AC60(id, 1);
            }
        }

        alpha = 0xFF;
        if (arg0 == 0) {
            position[0] = -360.0f;
            position[1] = 512.0f;
            position[2] = 200.0f;
            func_8000FCBC(1, 0x45, position, 0.90000004f, 0xFF, 0xDC, 0xBE, 0xFF);
            func_8005D10C(1, 0x4E, 0.90000004f);
            position[0] = -220.0f;
            position[1] = 512.0f;
            position[2] = 260.0f;
            scale = D_800AD010;
            red = 0xFF;
            green = 0xFD;
            blue = 0xE1;
        } else if (arg0 == 1) {
            position[0] = D_800AD014;
            position[1] = D_800AD018;
            position[2] = D_800AD01C;
            scale = D_800AD020;
            red = 0xCD;
            green = 0xF0;
            blue = 0xFF;
        } else if (arg0 == 2) {
            position[0] = 0.0f;
            position[1] = 512.0f;
            position[2] = 230.0f;
            scale = D_800AD024;
            red = 0xFF;
            green = 0xF4;
            blue = 0xBE;
        } else if (arg0 == 3) {
            position[0] = D_800AD028;
            position[1] = D_800AD02C;
            position[2] = D_800AD030;
            scale = D_800AD034;
            red = 0xFF;
            green = 0xDA;
            blue = 0xCC;
        } else if (arg0 == 4) {
            position[0] = D_800AD038;
            position[1] = 84.0f;
            position[2] = 35.0f;
            scale = D_800AD03C;
            red = 0xFF;
            green = 0xE6;
            blue = 0xB4;
            if (arg1 != 3) {
                scale = D_800AD040;
                red = 0x80;
                green = 0x73;
                blue = 0x5A;
                alpha = 0x64;
            }
        } else if (arg0 == 6) {
            position[0] = D_800AD044;
            position[1] = D_800AD048;
            position[2] = D_800AD04C;
            scale = D_800AD050;
            red = 0xF0;
            green = 0xF0;
            blue = 0xFF;
        } else {
            position[0] = 0.0f;
            position[1] = 512.0f;
            position[2] = 230.0f;
            scale = D_800AD054;
            red = 0xFF;
            green = 0xFF;
            blue = 0xFF;
        }
        func_8000FCBC(0, 0x44, position, scale, red, green, blue, alpha);
        func_8005D10C(0, 0x46, scale);
    }

    if (D_800A52BC < 2 && (arg0 == 1 || arg0 == 4) && arg1 != 3) {
        func_80011814();
        func_800117E4(1.0f);
        func_800117A4(0);
        palette = func_80030154(0x6D);
        for (index = 0x56; index < 0x92; index++) {
            id = index;
            func_8000A44C(id, palette);
            func_8000AC34(id, 0x1E00);
            func_8000AC60(id, 1);
            func_80011824(index - 0x56, index);
        }
        if (arg0 == 1 && arg1 != 3) {
            for (index = 0x92; index < 0xA6; index++) {
                id = index;
                func_8000A44C(id, palette);
                func_8000AC34(id, 0x1E00);
                func_8000AC60(id, 1);
                func_80011824(index - 0x56, index);
            }
        }
        if (arg0 == 1) {
            func_80011778(0xE6, 0xE6, 0xFF, 0xC8);
            if (arg1 == 0) {
                func_800117A4(0);
            } else if (arg1 == 1) {
                func_80011764(25.0f, 45.0f);
                func_800117A4(0x14);
            } else if (arg1 == 2) {
                func_80011764(20.0f, 60.0f);
                func_800117A4(0x28);
                func_8000FCA4(0, 0x80);
            }
        } else {
            func_80011778(0xFF, 0xFF, 0xFF, 0x28);
            func_800117E4(7.0f);
            if (arg1 == 0) {
                func_800117A4(0x14);
                func_80011764(10.0f, 300.0f);
            } else {
                func_80011764(50.0f, 1000.0f);
                func_800117A4(0x3C);
            }
        }
    } else {
        func_800117F0();
    }

    if (arg0 != 1 || arg1 == 3) {
        paletteB = func_80030154(0x7F);
        palette = func_80030154(0x80);
        limit = 10;
        for (index = 0; index < limit; index++) {
            id = index + 0x92;
            func_8000A44C(id, palette);
            func_8000AC34(id, 0x1F00);
            func_8000AC60(id, 1);
            id = index + 0x9C;
            func_8000A44C(id, paletteB);
            func_8000AC34(id, 0x1F00);
            func_8000AC60(id, 1);
            func_80010014(index, index + 0x92, index + 0x9C);
        }
    }
}
