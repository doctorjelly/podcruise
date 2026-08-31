/* Recovered per specs/functions/recovered/func_80058058.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x60];
    /* 0x060 */ u32 unk060;
    /* 0x064 */ u32 unk064;
    /* 0x068 */ u8 unk068[0x1B0];
    /* 0x218 */ f32 unk218;
    /* 0x21C */ u8 unk21C[0x6C];
    /* 0x288 */ f32 unk288[6];
    /* 0x2A0 */ u32 unk2A0[6];
    /* 0x2B8 */ f32 unk2B8;
} Obj80058058;

typedef struct {
    /* 0x00 */ u8 unk00[0x84];
    /* 0x84 */ Obj80058058 *unk84;
} Actor80058058;

extern s32 D_800A26F4;
extern f32 D_800A59B8[2];
extern f32 D_800A59C0[2];
extern f32 D_800A59C8[2];
extern f32 D_800A59D0[2];
extern f32 D_800A59D8[2];
extern f32 D_800A59E0;
extern f32 D_800A59E4;
extern f32 D_800A59E8;
extern f32 D_800A59EC;
extern u8 D_800ACD24[];
extern u8 D_800ACD38[];
extern u8 D_800ACD48[];
extern u8 D_800ACD5C[];
extern u8 D_800ACD68[];
extern u8 D_800ACD74[];
extern f64 D_800ACEF8;
extern f32 D_800ACF00;
extern f32 D_800ACF04;
extern f32 D_800ACF08;
extern f64 D_800ACF10;
extern f64 D_800ACF18;
extern f64 D_800ACF20;
extern f64 D_800ACF28;
extern f32 D_800ACF30;
extern f64 D_800ACF38;
extern f64 D_800ACF40;
extern f64 D_800ACF48;
extern f32 D_800ACF50;
extern f32 D_800ACF54;
extern f32 D_800ACF58;
extern f32 D_800ACF5C;
extern f32 D_800ACF60;
extern f64 D_800ACF68;
extern f64 D_800ACF70;
extern s32 D_800D697C;
extern f64 D_80120BF0;
extern f64 D_80120C00;

extern void func_80008B14(s32 id, s16 channel, f32 volume, f32 pan,
                          s32 repeated);
extern void func_8000A920(s16 id, s32 enabled);
extern void func_8000AA04(s16 id, s16 x, s16 y);
extern void func_8000AAC0(s16 id, f32 xScale, f32 yScale);
extern void func_8000AB24(s16 id, u8 red, u8 green, u8 blue, u8 alpha);
extern s32 func_8002F054(void);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue,
                          u8 alpha, u8 *text);
extern s32 func_80082BE0(void);

#define RANDOM_UNIT() ((f32)func_80082BE0() / 2147483648.0f)

void func_80058058(Actor80058058 *actor, s32 mode) {
    Obj80058058 *obj;
    f32 *phase;
    f32 *visibility;
    f32 *holdTimer;
    f32 *velocity;
    f32 *messageTimer;
    f32 baseY;
    f32 originalY;
    f32 level;
    f32 pulse;
    f32 ratio;
    f32 soundVolume;
    f32 soundParam;
    f32 wobble;
    f32 x;
    f32 y;
    f32 arrowOffset;
    f64 now;
    s32 red[6];
    s32 green[6];
    s32 blue[6];
    s32 alpha[6];
    s32 frontArrowRed;
    s32 frontArrowGreen;
    s32 frontArrowBlue;
    s32 frontArrowAlpha;
    s32 rearArrowRed;
    s32 rearArrowGreen;
    s32 rearArrowBlue;
    s32 rearArrowAlpha;
    s32 frontCritical;
    s32 rearCritical;
    s32 specialCritical;
    s32 fullComponent;
    s32 markedComponent;
    s32 active;
    s32 flags;
    s32 color;
    s32 group;
    s32 row;
    s32 index;
    s16 sprite;

    frontCritical = 0;
    rearCritical = 0;
    specialCritical = 0;
    fullComponent = 0;
    markedComponent = 0;
    soundVolume = 0.0f;
    soundParam = 0.25f;
    obj = actor->unk84;
    baseY = mode == 0 ? 175.0f : 65.0f;
    originalY = baseY;

    phase = &D_800A59B8[mode];
    visibility = &D_800A59C0[mode];
    holdTimer = &D_800A59C8[mode];
    velocity = &D_800A59D0[mode];
    messageTimer = &D_800A59D8[mode];

    if ((obj->unk060 & 0x1000) != 0) {
        *visibility = 1.0f;
        *velocity = 0.0f;
    } else if ((obj->unk060 & 0x4000) != 0) {
        *velocity = -1.0f;
    } else {
        active = 0;
        if ((obj->unk060 & 0x2000) != 0 ||
            (obj->unk064 & 0x4000) != 0 || obj->unk2B8 > 0.0f ||
            obj->unk218 < 50.0f || (obj->unk060 & 0x400) != 0) {
            active = 1;
        }
        for (index = 0; index < 6; index++) {
            if (D_800ACEF8 < (f64)obj->unk288[index] ||
                (obj->unk2A0[index] & 0x1C) != 0) {
                active = 1;
            }
        }
        if (active != 0) {
            *velocity = 4.0f;
            *holdTimer = 5.0f;
        }
    }

    if (func_8002F054() == 0) {
        *phase = (f32)((f64)*phase - (D_80120BF0 * 1.5));
        if (*phase <= 0.0f) {
            *phase += 1.0f;
        }
        obj->unk2B8 = (f32)((f64)obj->unk2B8 - D_80120BF0);
        if (obj->unk2B8 < 0.0f) {
            obj->unk2B8 = 0.0f;
        }
        *visibility =
            (f32)((f64)*visibility + ((f64)*velocity * D_80120BF0));
        if (*visibility > 1.0f) {
            *visibility = 1.0f;
            *velocity = 0.0f;
        }
        if (*visibility > 0.0f) {
            *holdTimer = (f32)((f64)*holdTimer - D_80120BF0);
            if (*holdTimer <= 0.0f) {
                *velocity = -4.0f;
            }
        }
    }

    if (*visibility <= 0.0f) {
        *visibility = 0.0f;
        *velocity = 0.0f;
        if (mode == 0) {
            for (index = 0; index < 6; index++) {
                func_8000A920((s16)(index + 0x1B), 0);
            }
            func_8000A920(0x21, 0);
            func_8000A920(0x22, 0);
        } else {
            for (index = 0; index < 6; index++) {
                func_8000A920((s16)(index + 0x23), 0);
            }
            func_8000A920(0x29, 0);
            func_8000A920(0x2A, 0);
        }
        return;
    }

    if (func_8002F054() == 0) {
        obj->unk2A0[1] ^= 2;
        obj->unk2A0[0] ^= 2;
        obj->unk2A0[5] ^= 2;
        obj->unk2A0[4] ^= 2;
        obj->unk2A0[3] ^= 2;
        obj->unk2A0[2] ^= 2;
    }

    frontArrowRed = 0;
    frontArrowGreen = 0xFF;
    frontArrowBlue = 0xFF;
    if (D_800A26F4 == 0) {
        frontArrowAlpha = (s32)((RANDOM_UNIT() * 64.0f) + 64.0f);
    } else {
        frontArrowAlpha = (s32)112.0f;
    }
    rearArrowRed = 0;
    rearArrowGreen = 0xFF;
    rearArrowBlue = 0xFF;
    if (D_800A26F4 == 0) {
        rearArrowAlpha = (s32)((RANDOM_UNIT() * 64.0f) + 64.0f);
    } else {
        rearArrowAlpha = (s32)112.0f;
    }

    if ((obj->unk060 & 0x2000) != 0) {
        for (index = 0; index < 6; index++) {
            if ((obj->unk2A0[index] & 2) != 0) {
                red[index] = 100;
                green[index] = 100;
                if (D_800A26F4 == 0) {
                    blue[index] =
                        (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
                } else {
                    blue[index] = (s32)D_800ACF00;
                }
            } else {
                red[index] = 200;
                green[index] = 200;
                blue[index] = 200;
            }
            alpha[index] = 0xFF;
        }
    } else if ((obj->unk060 & 0x5000) != 0 ||
               (obj->unk064 & 0x4000) != 0) {
        for (index = 0; index < 6; index++) {
            red[index] = 0xFF;
            if (D_800A26F4 == 0) {
                green[index] = (s32)(RANDOM_UNIT() * 200.0f);
            } else {
                green[index] = (s32)150.0f;
            }
            if (D_800A26F4 == 0) {
                blue[index] = (s32)(RANDOM_UNIT() * 128.0f);
            } else {
                blue[index] = (s32)96.0f;
            }
            if (green[index] < blue[index]) {
                blue[index] = green[index];
            }
            alpha[index] = 0xFF;
        }
    } else {
        for (index = 0; index < 6; index++) {
            flags = obj->unk2A0[index];
            if ((flags & 4) != 0) {
                if (index < 3) {
                    frontCritical = 1;
                } else {
                    rearCritical = 1;
                }
            }
            if ((flags & 0x10) != 0) {
                specialCritical = 1;
            }
            if (obj->unk288[index] >= 1.0f) {
                fullComponent = 1;
            }
            if ((flags & 8) != 0) {
                markedComponent = 1;
            }
        }

        if (frontCritical != 0) {
            frontArrowRed = 0xFF;
            frontArrowBlue = 0;
            if (D_800A26F4 == 0) {
                frontArrowAlpha =
                    (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
            } else {
                frontArrowAlpha = (s32)D_800ACF04;
            }
        }
        if (rearCritical != 0) {
            rearArrowRed = 0xFF;
            rearArrowBlue = 0;
            if (D_800A26F4 == 0) {
                rearArrowAlpha =
                    (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
            } else {
                rearArrowAlpha = (s32)D_800ACF08;
            }
        }

        for (index = 0; index < 6; index++) {
            level = obj->unk288[index];
            if (level < 0.0f) {
                level = 0.0f;
            }
            if (level > 1.0f) {
                level = 1.0f;
            }

            red[index] = (s32)(255.0f * level * 2.0f);
            green[index] =
                (s32)((1.0 - (f64)level) * 2.0 * D_800ACF10);
            blue[index] = 0;
            alpha[index] = 100;
            if (D_800ACF18 < (f64)level) {
                if (RANDOM_UNIT() > 0.5f) {
                    red[index] = 128;
                    green[index] = 0;
                }
            }
            if (level >= 1.0f) {
                color = (s32)(*phase * 127.0f);
                red[index] = color + 128;
                green[index] = color;
                blue[index] = color;
                alpha[index] = color + 128;
            }

            flags = obj->unk2A0[index];
            if ((flags & 8) == 0) {
                if (obj->unk2B8 > 0.0f && (flags & 1) != 0) {
                    if ((flags & 2) != 0) {
                        red[index] = 0xFF;
                        green[index] = 0xFF;
                        blue[index] = 150;
                        alpha[index] = 0xFF;
                    }
                } else {
                    flags &= ~1;
                    obj->unk2A0[index] = flags;
                }
            }
            if ((flags & 4) != 0 && (flags & 2) != 0) {
                red[index] = 128;
                green[index] = 128;
                blue[index] = 0xFF;
                alpha[index] = 200;
            }
            if ((flags & 8) != 0) {
                if ((frontCritical != 0 || rearCritical != 0) &&
                    (flags & 2) != 0) {
                    red[index] = 128;
                    green[index] = 128;
                    blue[index] = 0xFF;
                    alpha[index] = 200;
                } else {
                    pulse = *phase;
                    red[index] =
                        (s32)((pulse * (f32)(0xFF - red[index])) +
                              (f32)red[index]);
                    green[index] =
                        (s32)((pulse * (f32)(128 - green[index])) +
                              (f32)green[index]);
                    blue[index] =
                        (s32)((pulse * (f32)-blue[index]) +
                              (f32)blue[index]);
                    alpha[index] =
                        (s32)((pulse * (f32)(200 - alpha[index])) +
                              (f32)alpha[index]);
                }
            }

            if (red[index] < 0) red[index] = 0;
            if (red[index] >= 0x100) red[index] = 0xFF;
            if (green[index] < 0) green[index] = 0;
            if (green[index] >= 0x100) green[index] = 0xFF;
            if (blue[index] < 0) blue[index] = 0;
            if (blue[index] >= 0x100) blue[index] = 0xFF;
            if (alpha[index] < 0) alpha[index] = 0;
            if (alpha[index] >= 0x100) alpha[index] = 0xFF;
        }

        baseY -= 45.0f;
        if (markedComponent != 0) {
            func_8003EC40(54, (s16)(baseY + 63.0f), 0xFF, 0x80, 0,
                          (u8)(u32)(*phase * 255.0f), D_800ACD24);
        }

        if (obj->unk218 < 20.0f) {
            color = (s32)(*phase * 255.0f);
            if (markedComponent == 0 && (obj->unk060 & 0x800000) != 0) {
                func_8003EC40(54, (s16)(baseY + 63.0f), 0xFF, 0x80, 0,
                              (u8)color, D_800ACD38);
            }
            frontArrowRed = 0xFF;
            frontArrowGreen = 0x80;
            frontArrowBlue = 0;
            frontArrowAlpha = color;
            rearArrowRed = 0xFF;
            rearArrowGreen = 0x80;
            rearArrowBlue = 0;
            rearArrowAlpha = color;
            if ((obj->unk060 & 0x800000) != 0) {
                soundParam = D_800ACF30;
                soundVolume = 0.75f;
            }
        } else if (obj->unk218 < 50.0f) {
            ratio = (obj->unk218 - 50.0f) / -30.0f;
            if (ratio < 0.0f) {
                ratio = 0.0f;
            }
            if (ratio > 1.0f) {
                ratio = 1.0f;
            }
            if ((obj->unk060 & 0x800000) != 0) {
                func_8003EC40(
                    54, (s16)(baseY + 63.0f),
                    (u8)(u32)(255.0f * ratio),
                    (u8)(u32)(((1.0 - (f64)ratio) * D_800ACF38) + 128.0),
                    (u8)(u32)((1.0 - (f64)ratio) * D_800ACF10),
                    (u8)(u32)(*phase * 255.0f), D_800ACD48);
            }
            frontArrowRed = (s32)(255.0f * ratio);
            frontArrowGreen =
                (s32)(((1.0 - (f64)ratio) * D_800ACF40) + 128.0);
            frontArrowBlue =
                (s32)((1.0 - (f64)ratio) * D_800ACF48);
            if (D_800A26F4 == 0) {
                frontArrowAlpha =
                    (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
            } else {
                frontArrowAlpha = (s32)D_800ACF50;
            }
            rearArrowRed = frontArrowRed;
            rearArrowGreen = frontArrowGreen;
            rearArrowBlue = frontArrowBlue;
            rearArrowAlpha = frontArrowAlpha;
            if ((obj->unk060 & 0x800000) != 0) {
                soundParam = D_800ACF54;
                soundVolume = 0.5f;
            }
        }

        if (fullComponent != 0) {
            color = (s32)(*phase * 127.0f);
            func_8003EC40(54, (s16)(baseY + 48.0f), (u8)(color + 128),
                          (u8)color, (u8)color, (u8)(color + 128),
                          D_800ACD5C);
            baseY -= 12.0f;
        }

        if ((obj->unk060 & 0x400) != 0) {
            if (frontCritical != 0 || rearCritical != 0 ||
                specialCritical != 0) {
                *messageTimer = 0.0f;
                if (D_800A26F4 == 0) {
                    color = (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
                } else {
                    color = (s32)D_800ACF58;
                }
                func_8003EC40(54, (s16)(baseY + 48.0f), 0x80, 0x80,
                              0xFF, (u8)color, D_800ACD68);
            } else {
                if (*messageTimer <= 0.0f) {
                    func_80008B14(0x46, 7, 0.25f, 1.0f, 0);
                }
                *messageTimer =
                    (f32)((f64)*messageTimer + D_80120BF0);
                if (*messageTimer < D_800ACF5C) {
                    if (D_800A26F4 == 0) {
                        color =
                            (s32)((RANDOM_UNIT() * 127.0f) + 128.0f);
                    } else {
                        color = (s32)D_800ACF60;
                    }
                    func_8003EC40(54, (s16)(baseY + 48.0f), 0x40,
                                  0x80, 0x40, (u8)color, D_800ACD74);
                }
            }
        } else {
            *messageTimer = 0.0f;
        }

        if (func_8002F054() == 0) {
            if (markedComponent != 0) {
                now = D_80120C00;
                if ((f64)D_800A59E0 < now - 2.0) {
                    D_800A59E4 = (f32)now;
                    func_80008B14(0x87, 7, 0.25f, 1.0f, 0);
                }
                if ((f64)D_800A59E4 < now - D_800ACF68) {
                    func_80008B14(0x86, 6, 0.25f, 1.0f, 1);
                }
                D_800A59E0 = (f32)now;
            }
            if (soundVolume > 0.0f) {
                func_80008B14(0x83, 7, soundParam, soundVolume, 1);
            }
            if ((obj->unk060 & 0x400) != 0 &&
                (frontCritical != 0 || rearCritical != 0 ||
                 specialCritical != 0)) {
                now = D_80120C00;
                if ((f64)D_800A59E8 < now - 2.0) {
                    D_800A59EC = (f32)now;
                    func_80008B14(0x85, 7, 0.25f, 1.0f, 0);
                }
                if ((f64)D_800A59EC < now - D_800ACF70) {
                    func_80008B14(0x75, 6, 0.25f, 1.0f, 1);
                }
                D_800A59E8 = (f32)now;
            }
        }
    }

    for (group = 0; group < 2; group++) {
        for (row = 0; row < 3; row++) {
            index = group * 3 + row;
            sprite = (s16)((mode == 0 ? 0x1B : 0x23) + index);
            wobble = (1.0f - *visibility) * 15.0f;
            x = 34.0f + (f32)(group * 24);
            y = originalY + 2.0f + (f32)(row * 14);
            if (row == 1) {
                x += group == 0 ? -(wobble * 1.5f) : wobble * 1.5f;
            } else {
                x += group == 0 ? -wobble : wobble;
            }
            if (row == 0) {
                y -= wobble;
            } else if (row == 2) {
                y += wobble;
            }
            func_8000A920(sprite, 1);
            if ((D_800D697C & 0x4000) != 0) {
                func_8000AA04(sprite, (s16)(92.0f - x), (s16)y);
            } else {
                func_8000AA04(sprite, (s16)x, (s16)y);
            }
            func_8000AAC0(sprite, 0.75f, 0.75f);
            func_8000AB24(sprite, (u8)red[index], (u8)green[index],
                          (u8)blue[index],
                          (u8)(u32)(*visibility * (f32)alpha[index]));
        }
    }

    arrowOffset = (D_800D697C & 0x4000) != 0 ? 12.0f : -12.0f;
    sprite = mode == 0 ? 0x21 : 0x29;
    func_8000A920(sprite, 1);
    func_8000AA04(sprite, (s16)(42.0f + arrowOffset), (s16)originalY);
    func_8000AAC0(sprite, 0.75f, 0.75f);
    func_8000AB24(
        sprite, (u8)frontArrowRed, (u8)frontArrowGreen,
        (u8)frontArrowBlue,
        (u8)(u32)((f32)frontArrowAlpha * (*visibility * *visibility)));

    sprite = mode == 0 ? 0x22 : 0x2A;
    func_8000A920(sprite, 1);
    func_8000AA04(sprite, (s16)(42.0f - arrowOffset), (s16)originalY);
    func_8000AAC0(sprite, 0.75f, 0.75f);
    func_8000AB24(
        sprite, (u8)rearArrowRed, (u8)rearArrowGreen, (u8)rearArrowBlue,
        (u8)(u32)((f32)rearArrowAlpha * (*visibility * *visibility)));
}

#undef RANDOM_UNIT
