/* Independently written from specs/functions/recovered/func_80077C94.md. */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x60];
    u32 unk60;
    u8 unk64[0xDC];
    void *unk140;
    u8 unk144[0x5C];
    f32 unk1A0;
    u8 unk1A4[0x44];
    f32 unk1E8;
} Craft80077C94;

typedef struct {
    s16 unk00;
    u8 unk02[0x2A];
    s32 unk2C;
} Item80077C94;

extern s32 D_800A59FC;
extern f32 D_800ADA90;
extern f32 D_800ADA94;
extern f32 D_800ADA98;
extern f32 D_800ADA9C;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern f32 func_800154D0(f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_80017874(f32 *);
extern Item80077C94 *func_800183A8(void *);
extern s32 func_8007B34C(f32 *, s32, s32, s32, s32, f32, s32);

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

void func_80077C94(Craft80077C94 *craft, f32 source[4][4], f32 scaleX, f32 scaleY,
                   f32 scaleZ, f32 angle, s32 arg6) {
    f32 matrix[4][4];
    f32 fade;
    f32 red;
    f32 green;
    f32 blue;
    f32 level;
    f32 alpha;
    s32 mode;
    s32 changed;
    s32 emphasis;
    s32 dim;
    s32 wide;
    s32 tall;
    s32 warm;
    s32 cool;
    s32 lit;
    s32 flags;
    Item80077C94 *item;
    void *node;

    cool = 0;
    warm = 0;
    lit = 0;
    tall = 0;
    wide = 0;
    changed = 0;
    dim = 0;
    emphasis = 0;

    /* The original leaves this stack word unwritten when arg6 is zero. */

    if (craft == 0) {
        return;
    }
    if ((craft->unk60 & 0x2007800) != 0) {
        return;
    }
    if (0.5f < craft->unk1E8) {
        return;
    }
    node = craft->unk140;
    if (node != 0) {
        item = func_800183A8(node);
        if (item != 0) {
            if ((item->unk00 & 0x20) != 0) {
                return;
            }
            flags = item->unk2C;
            if ((flags & 0x2000) != 0) {
                lit = 1;
            }
            if ((flags & 0x4000) != 0) {
                return;
            }
            if ((flags & 0x8000) != 0) {
                warm = 1;
            }
            if ((flags & 0x100) != 0) {
                emphasis = 1;
            }
            if ((flags & 0x200) != 0) {
                cool = 1;
            }
            if ((flags & 0x400) != 0) {
                wide = 1;
            }
            if ((flags & 0x1000) != 0) {
                tall = 1;
            }
            if ((flags & 0x80) != 0) {
                dim = 1;
            }
            if ((flags & 0x40) != 0) {
                changed = 1;
            }
        }
    }

    if (arg6 != 0) {
        mode |= 1;
    }
    func_80017874(matrix[0]);
    matrix[3][0] = source[3][0];
    matrix[3][1] = source[3][1];
    matrix[3][2] = source[3][2];
    matrix[1][0] = source[2][0];
    matrix[1][1] = source[2][1];
    matrix[1][2] = source[2][2];
    matrix[0][0] = source[1][0];
    matrix[0][1] = source[1][1];
    matrix[0][2] = source[1][2];
    matrix[2][0] = source[0][0];
    matrix[2][1] = source[0][1];
    matrix[2][2] = source[0][2];
    func_800154D0(matrix[0]);
    func_800154D0(matrix[1]);
    func_800154D0(matrix[2]);

    fade = (craft->unk1A0 - 200.0f) / 200.0f;
    if (fade <= 0.0f) {
        return;
    }
    if (1.0f < fade) {
        fade = 1.0f;
    }

    level = 0.0f;
    blue = 0.0f;
    green = 0.0f;
    red = 0.0f;

    switch (D_800A59FC) {
    case 0:
        if (changed != 0) {
            blue = 120.0f;
            red = 200.0f;
            green = 170.0f;
            level = 255.0f;
        } else if (cool != 0) {
            green = 120.0f;
            red = 150.0f;
            blue = 100.0f;
            level = 255.0f;
        } else if (wide != 0) {
            blue = 120.0f;
            red = 200.0f;
            green = 170.0f;
            level = 255.0f;
        } else {
            red = 182.0f;
            green = 164.0f;
            blue = 136.0f;
            level = 200.0f;
        }
        break;
    case 1:
        red = 220.0f;
        green = 250.0f;
        blue = 255.0f;
        if (dim != 0) {
            level = 255.0f;
        } else if (changed != 0) {
            level = 150.0f;
        } else if (tall == 0 && warm == 0) {
            level = 50.0f;
        }
        break;
    case 2:
        if (emphasis != 0) {
            blue = 120.0f;
            level = 255.0f;
            green = 100.0f;
            red = blue;
        } else if (changed != 0) {
            blue = 120.0f;
            green = 75.0f;
            level = 64.0f;
            red = green;
        } else {
            blue = 120.0f;
            green = 100.0f;
            level = 16.0f;
            red = blue;
        }
        break;
    case 4:
        if (changed != 0) {
            green = 150.0f;
            red = 190.0f;
            blue = 110.0f;
            level = 255.0f;
        } else if (cool != 0) {
            red = 175.0f;
            green = 135.0f;
            blue = 85.0f;
            level = 255.0f;
        } else if (wide != 0) {
            red = 75.0f;
            green = 70.0f;
            blue = 50.0f;
            level = 255.0f;
        } else if (emphasis != 0) {
            green = 220.0f;
            level = 255.0f;
            blue = 200.0f;
            red = green;
        } else if (lit != 0) {
            level = 255.0f;
            green = 100.0f;
            blue = 30.0f;
            red = level;
        } else {
            red = 110.0f;
            green = 90.0f;
            blue = 80.0f;
            level = 50.0f;
        }
        break;
    case 5:
        if (changed != 0) {
            red = 210.0f;
            green = 130.0f;
            blue = 60.0f;
            level = 200.0f;
        } else if (cool != 0) {
            red = 210.0f;
            green = 130.0f;
            blue = 60.0f;
            level = 255.0f;
        } else {
            red = 210.0f;
            green = 130.0f;
            blue = 60.0f;
            level = 16.0f;
        }
        break;
    case 6:
        if (changed != 0) {
            level = 150.0f;
            red = 186.0f;
            green = 179.0f;
            blue = 170.0f;
        } else if (cool != 0) {
            red = 137.0f;
            green = 122.0f;
            blue = 104.0f;
            level = 255.0f;
        } else {
            green = 203.0f;
            level = 75.0f;
            blue = 204.0f;
            red = green;
        }
        break;
    case 7:
        if (emphasis != 0) {
            level = 255.0f;
            green = level;
        } else if (cool != 0) {
            green = 150.0f;
            blue = 230.0f;
            level = 255.0f;
            red = green;
        } else {
            green = 150.0f;
            blue = 230.0f;
            level = 128.0f;
            red = green;
        }
        break;
    }

    if (D_800ADA90 < matrix[1][2]) {
        if (emphasis != 0) {
            changed = 1;
            angle = 0.0f;
        }
        func_800155EC(matrix[3], matrix[3], -angle, matrix[0]);
        matrix[0][0] *= scaleX;
        matrix[0][1] *= scaleX;
        matrix[0][2] *= scaleX;
        matrix[1][0] *= scaleY;
        matrix[1][1] *= scaleY;
        matrix[1][2] *= scaleY;
        matrix[2][0] *= scaleZ;
        matrix[2][1] *= scaleZ;
        matrix[2][2] *= scaleZ;
        alpha = level * fade;
        if (alpha < 1.0f) {
            alpha = 1.0f;
        } else if (254.0f < alpha) {
            alpha = 254.0f;
        }
        if (wide != 0) {
            changed = 1;
        }
        if (0.0f < alpha) {
            if (func_8007B34C(matrix[0], (s32)red, (s32)green, (s32)blue,
                              (s32)alpha, D_800ADA94, mode) != 0) {
                if (changed != 0) {
                    if (D_800ADA98 < 1.0f) {
                        func_80008B14((s32)69.0f, 7,
                                      fade * D_800ADA9C * 0.25f, 1.0f, 1);
                    }
                }
            }
        }
    }
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
