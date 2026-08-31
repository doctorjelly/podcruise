/* Independently written from specs/functions/recovered/func_800547EC.md. */

#include "podcruise/types.h"

typedef struct Progress800547EC {
    u8 pad00[8];
    f32 fraction;
} Progress800547EC;

typedef struct Track800547EC {
    u8 pad000[0x50];
    f32 x;
    f32 y;
    u8 pad058[0x54];
    Progress800547EC progress;
} Track800547EC;

typedef struct Racer800547EC {
    u8 pad00[4];
    s32 tag;
    u32 flags;
    u8 pad0C[0xC];
    s32 *kind;
    u8 pad1C[0x40];
    s16 place;
    u8 pad5E[0x26];
    Track800547EC *track;
} Racer800547EC;

typedef struct Session800547EC {
    u8 pad000[0x2C];
    void *graph;
    u8 pad030[0x74];
    f32 craftAxisX;
    f32 craftAxisY;
    u8 pad0AC[0x28];
    f32 craftX;
    f32 craftY;
    u8 pad0DC[0x48];
    s32 displayMode;
    u8 pad128[0x84];
    s32 unk1AC;
    u8 pad1B0[0xC];
    s32 racerCount;
    s32 unk1C0;
} Session800547EC;

typedef struct Camera800547EC {
    u8 pad000[0x1F0];
    f32 directionX;
    f32 directionY;
    u8 pad1F8[0x18];
    f32 originX;
    f32 originY;
    f32 originZ;
} Camera800547EC;

typedef struct Vec800547EC {
    f32 x;
    f32 y;
    f32 z;
} Vec800547EC;

typedef struct Pair800547EC {
    f32 x;
    f32 y;
} Pair800547EC;

extern s32 D_800A52BC;
extern s32 D_800A52C0;
extern f32 D_800A59B0;
extern char D_800ACC38[];
extern char D_800ACC40[];
extern char D_800ACC48[];
extern char D_800ACC50[];
extern char D_800ACC58[];
extern char D_800ACC60[];
extern char D_800ACC68[];
extern f64 D_800ACEB0;
extern f64 D_800ACEB8;
extern f64 D_800ACEC0;
extern f32 D_800ACEC8;
extern f32 D_800ACECC;
extern f32 D_800ACED0;
extern s32 D_800D697C;
extern Racer800547EC *D_8011B1B8;
extern Racer800547EC *D_8011B1BC;
extern Racer800547EC *D_8011B1C0;
extern f64 D_80120BF0;
extern Camera800547EC D_80120DF0;

extern void func_8000A920(s16 index, s32 enable);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern f32 func_800154D0(f32 *vector);
extern void func_8003E54C(u8 kind, s32 x, s32 y);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue, u8 alpha,
                          const char *text);
extern f32 func_80052134(Racer800547EC *racer);
extern f32 func_8007EE40(void);
extern f32 func_8008035C(Progress800547EC *progress);
extern s32 func_80080DB4(void *graph, Vec800547EC *origin, f32 range, s32 limit,
                         Pair800547EC *points, f32 step);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

void func_800547EC(Session800547EC *session) {
    Pair800547EC points[170];
    char text[60];
    Vec800547EC origin;
    f32 direction[3];
    f32 perpendicularX;
    f32 perpendicularY;
    f32 horizontalRange;
    f32 range;
    f32 step;
    f32 referenceProgress;
    f32 scale;
    f32 progress;
    f32 difference;
    f32 screenX;
    f32 screenY;
    f32 relativeX;
    f32 relativeY;
    f32 scaledX;
    f32 scaledY;
    f32 markerOffset;
    Racer800547EC *racer;
    s32 mode;
    s32 icon;
    s32 pointCount;
    s32 i;
    s32 mapVisible;

    mapVisible = 0;
    if (D_800A52BC == 0) {
        return;
    }

    mode = session->displayMode;
    if (D_800A52BC >= 2) {
        if (mode < 4) {
            mode = 5;
            session->displayMode = 5;
        }
    } else if (mode >= 5) {
        mode = 2;
        session->displayMode = 2;
    }

    if (mode == 0) {
        referenceProgress = 0.0f;
        if (session->racerCount >= 2) {
            for (i = 0; i < session->racerCount; i++) {
                racer = &D_8011B1B8[i];
                if ((racer->flags & 1) && !(racer->flags & 2) &&
                    racer->tag == 0x4C6F636C) {
                    referenceProgress = func_8008035C(&racer->track->progress);
                }
            }

            scale = func_8007EE40();
            if (scale > 0.0f) {
                for (i = 0; i < session->racerCount; i++) {
                    racer = &D_8011B1B8[i];
                    if ((racer->flags & 1) && !(racer->flags & 2)) {
                        difference = referenceProgress -
                                     func_8008035C(&racer->track->progress);
                        if (difference > 0.5f) {
                            difference -= 1.0f;
                        }
                        if (difference < -0.5f) {
                            difference += 1.0f;
                        }

                        icon = *racer->kind;
                        screenY = 238.0f * 0.5f +
                                  difference * scale / (90.0f * 0.5f);
                        if (icon != -1 && screenY <= 164.0f &&
                            screenY >= 74.0f) {
                            if (racer == D_8011B1BC) {
                                func_8000A920(0x42, 1);
                                func_8000AA04(0x42, (s16)(276.0f - 2.0f),
                                              (s16)(screenY - 1.0f));
                                func_8000AAC0(0x42, 0.75f, 0.75f);
                                func_8000AB24(0x42, 0xFF, 0xFF, 0xFF, 0xDC);
                            } else {
                                icon += 0x2B;
                                func_8000A920((s16)icon, 1);
                                func_8000AA04((s16)icon, (s16)276,
                                              (s16)screenY);
                                func_8000AAC0((s16)icon, 0.5f, 0.5f);
                                func_8000AB24((s16)icon, 0xFF, 0xFF, 0xFF,
                                              0x80);
                            }

                            if (racer->place > 0) {
                                if (racer == D_8011B1BC) {
                                    func_8008A6B4(text, D_800ACC38,
                                                  racer->place);
                                    func_8003EC40(284, (s16)screenY, 0xFF,
                                                  0xFF, 0, 0xFF, text);
                                } else {
                                    func_8008A6B4(text, D_800ACC40,
                                                  racer->place);
                                    func_8003EC40(284, (s16)screenY, 0xFF,
                                                  0xFF, 0xFF, 0xFF, text);
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if (mode == 1) {
        for (i = 0; i < session->racerCount; i++) {
            racer = &D_8011B1B8[i];
            if ((racer->flags & 1) && !(racer->flags & 2)) {
                progress = func_8008035C(&racer->track->progress) * 920.0f;
                icon = *racer->kind;

                if (progress >= 0.0f && progress <= 260.0f) {
                    screenX = progress + 20.0f;
                    screenY = 15.0f;
                } else if (D_800ACEB0 < (f64)progress && progress <= 460.0f) {
                    screenX = 280.0f;
                    screenY = progress - 260.0f + 15.0f;
                } else if (D_800ACEB8 < (f64)progress && progress <= 720.0f) {
                    screenX = 280.0f - (progress - 460.0f);
                    screenY = 215.0f;
                } else {
                    screenX = 20.0f;
                    if (D_800ACEC0 < (f64)progress && progress <= 920.0f) {
                        screenY = 215.0f - (progress - 720.0f);
                    } else {
                        screenY = 215.0f - (progress - 720.0f);
                    }
                }

                if (icon != -1) {
                    icon += 0x2B;
                    if (racer == D_8011B1BC) {
                        icon = 0x42;
                    }
                    func_8000AB24((s16)icon, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_8000A920((s16)icon, 1);
                    func_8000AA04((s16)icon, (s16)screenX, (s16)screenY);
                    if (racer == D_8011B1BC) {
                        func_8000AAC0((s16)icon, 1.0f, 1.0f);
                    } else {
                        func_8000AAC0((s16)icon, 1.0f, 1.0f);
                    }

                    if (session->racerCount >= 2 && racer->place > 0) {
                        if (racer == D_8011B1BC) {
                            func_8008A6B4(text, D_800ACC48, racer->place);
                            func_8003EC40((s16)(screenX - 1.0f),
                                          (s16)(screenY - 3.0f), 0xFF, 0xFF,
                                          0, 0xFF, text);
                        } else {
                            func_8008A6B4(text, D_800ACC50, racer->place);
                            func_8003EC40((s16)screenX, (s16)screenY, 0xFF,
                                          0xFF, 0xFF, 0xFF, text);
                        }
                    }
                }
            }
        }
    } else if (mode == 2 || mode == 3) {
        origin.x = D_80120DF0.originX;
        origin.y = D_80120DF0.originY;
        origin.z = D_80120DF0.originZ;
        direction[0] = D_80120DF0.directionX;
        direction[1] = D_80120DF0.directionY;
        direction[2] = 0.0f;
        func_800154D0(direction);
        perpendicularX = direction[1];
        perpendicularY = -direction[0];
        mapVisible = 1;

        if (mode == 2) {
            range = D_800ACEC8;
            if (session->unk1AC == 1 && session->unk1C0 == 3) {
                step = 3.0f;
            } else {
                step = 5.0f;
            }
        } else {
            range = 500.0f;
            step = 8.0f;
        }
        horizontalRange = (D_800D697C & 0x4000) ? -range : range;

        pointCount = func_80080DB4(session->graph, &origin, range, 170,
                                   points, step);
        if (pointCount > 0) {
            if (pointCount > 170) {
                pointCount = 170;
            }
            for (i = 0; i < pointCount; i++) {
                scaledX = points[i].x * 25.0f / horizontalRange;
                scaledY = points[i].y * 25.0f / range;
                screenX = perpendicularY * scaledY +
                          scaledX * perpendicularX;
                screenY = direction[1] * scaledY + scaledX * direction[0];
                func_8003E54C(0, (s32)(screenX + 264.0f),
                              (s32)(82.0f - screenY));
            }
        }

        for (i = 0; i < 4; i++) {
            markerOffset = ((f32)i - 1.5f) * range / 20.0f;
            relativeX = session->craftAxisX * markerOffset +
                        session->craftX - origin.x;
            relativeY = session->craftAxisY * markerOffset +
                        session->craftY - origin.y;
            scaledX = relativeX * 25.0f / horizontalRange;
            scaledY = relativeY * 25.0f / range;
            screenX = perpendicularY * scaledY + scaledX * perpendicularX;
            screenY = direction[1] * scaledY + scaledX * direction[0];
            if (screenX < 25.0f && -screenX < 25.0f &&
                screenY < 25.0f && -screenY < 25.0f) {
                func_8003E54C(1, (s32)(screenX + 264.0f),
                              (s32)(82.0f - screenY));
            }
        }

        for (i = 0; i < session->racerCount; i++) {
            racer = &D_8011B1B8[i];
            if (racer != D_8011B1BC && (racer->flags & 1) &&
                !(racer->flags & 2)) {
                relativeX = racer->track->x - origin.x;
                relativeY = racer->track->y - origin.y;
                scaledX = relativeX * 25.0f / horizontalRange;
                scaledY = relativeY * 25.0f / range;
                screenX = perpendicularY * scaledY +
                          scaledX * perpendicularX;
                screenY = direction[1] * scaledY + scaledX * direction[0];
                if (screenX < 25.0f && -screenX < 25.0f &&
                    screenY < 25.0f && -screenY < 25.0f) {
                    if (mode == 2) {
                        func_8003E54C(2, (s32)(screenX + 264.0f),
                                      (s32)(82.0f - screenY));
                    } else {
                        func_8003E54C(3, (s32)(screenX + 264.0f),
                                      (s32)(82.0f - screenY));
                    }
                }
            }
        }

        racer = D_8011B1BC;
        if (racer != 0 && (racer->flags & 1)) {
            relativeX = racer->track->x - origin.x;
            relativeY = racer->track->y - origin.y;
            scaledX = relativeX * 25.0f / horizontalRange;
            scaledY = relativeY * 25.0f / range;
            screenX = perpendicularY * scaledY + scaledX * perpendicularX;
            screenY = direction[1] * scaledY + scaledX * direction[0];
            if (screenX < 25.0f && -screenX < 25.0f &&
                screenY < 25.0f && -screenY < 25.0f) {
                func_8003E54C(4, (s32)(screenX + 264.0f),
                              (s32)(82.0f - screenY));
            }
        }
    } else if (mode != 4 && mode != 6 && (mode == 5 || mode == 7)) {
        for (i = 0; i < session->racerCount; i++) {
            racer = &D_8011B1B8[i];
            if ((racer->flags & 1) && !(racer->flags & 2)) {
                if (func_80052134(racer) > 0.0f) {
                    progress = func_8008035C(&racer->track->progress) * 900.0f;
                } else {
                    progress = 0.0f;
                }

                if (racer == D_8011B1C0) {
                    screenY = 120.0f;
                } else if (racer == D_8011B1BC) {
                    screenY = 108.0f;
                } else {
                    screenY = 114.0f;
                }

                icon = *racer->kind;
                if (icon != -1) {
                    if (racer == D_8011B1BC) {
                        icon = 0x42;
                    } else if (racer == D_8011B1C0) {
                        icon = 0x43;
                        if (D_800A52C0 != 0) {
                            func_8000AB24(0x43, 0xFF, 0x80, 0x80, 0xFF);
                        }
                    } else {
                        icon += 0x2B;
                    }
                    func_8000A920((s16)icon, 1);
                    func_8000AA04((s16)icon,
                                  (s16)(progress / D_800ACECC + 20.0f),
                                  (s16)screenY);
                    func_8000AAC0((s16)icon, 1.0f, 1.0f);
                }

                if (racer->place > 0) {
                    screenX = progress / D_800ACED0 + 20.0f;
                    if (racer == D_8011B1BC) {
                        func_8008A6B4(text, D_800ACC58, racer->place);
                        func_8003EC40((s16)(screenX - 1.0f),
                                      (s16)(screenY - 2.0f), 0xFF, 0xFF, 0,
                                      0xFF, text);
                    } else if (racer == D_8011B1C0) {
                        func_8008A6B4(text, D_800ACC60, racer->place);
                        func_8003EC40((s16)(screenX - 1.0f),
                                      (s16)(screenY - 2.0f), 0, 0xFF, 0xFF,
                                      0xFF, text);
                    } else {
                        func_8008A6B4(text, D_800ACC68, racer->place);
                        func_8003EC40((s16)screenX, (s16)(screenY - 1.0f),
                                      0xBE, 0xBE, 0xBE, 0xFF, text);
                    }
                }
            }
        }
    }

    if (mapVisible != 0) {
        D_800A59B0 = (f32)((f64)D_800A59B0 + D_80120BF0 * 2.0);
        if (D_800A59B0 > 1.0f) {
            D_800A59B0 = 1.0f;
        }
    } else {
        D_800A59B0 = (f32)((f64)D_800A59B0 - D_80120BF0 * 2.0);
        if (D_800A59B0 < 0.0f) {
            D_800A59B0 = 0.0f;
        }
    }
}
