/* Independently written from specs/functions/recovered/func_8003D4F4.md. */

#include "podcruise/types.h"

typedef struct Gfx8003D4F4 {
    u32 w0;
    u32 w1;
} Gfx8003D4F4;

typedef struct Strip8003D4F4 {
    /* 0x00 */ s16 span;
    /* 0x02 */ s16 crossSpan;
    /* 0x04 */ void *data;
} Strip8003D4F4;

typedef struct Resource8003D4F4 {
    /* 0x00 */ s16 width;
    /* 0x02 */ s16 height;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 format;
    /* 0x06 */ u8 pad06[2];
    /* 0x08 */ void *palette;
    /* 0x0C */ s16 stripCount;
    /* 0x0E */ s16 defaultCrossSpan;
    /* 0x10 */ Strip8003D4F4 *strips;
} Resource8003D4F4;

extern Gfx8003D4F4 *D_801217B0;
extern s32 D_800A4960;
extern s32 D_800A48D4;
extern Resource8003D4F4 D_800A4908;
extern f32 D_800AAB14;
extern f32 D_800AAB18;
extern f32 D_800AAB1C;

extern void func_80014CC0(f32, f32 *, f32 *);
extern void func_8003BAB0(
    Gfx8003D4F4 **, Resource8003D4F4 *, Strip8003D4F4 *, f32,
    f32, f32, f32, s16, s16, s32, s32, s32, s32, s32, s32,
    f32, f32, s32);

#define EMIT_COMMAND(first, second)             \
    do {                                        \
        Gfx8003D4F4 *command = output++;        \
        command->w0 = (u32)(first);             \
        command->w1 = (u32)(unsigned long)(second); \
    } while (0)

void func_8003D4F4(
    s32 resourceAddress, s32 x, s32 y, f32 scaleX, f32 scaleY,
    f32 angle, s32 arg6, s32 arg7, s32 flags, s32 red, s32 green,
    s32 blue, s32 alpha) {
    Resource8003D4F4 *resource;
    Strip8003D4F4 *strip;
    Gfx8003D4F4 *output;
    s32 oldFlags;
    s32 modeChanged;
    s32 modeFirst;
    s32 modeSecond;
    s32 fixedX;
    s32 fixedY;
    s32 stepX;
    s32 stepY;
    s32 reverseX;
    s32 reverseY;
    s32 stripIndex;
    s32 span;
    s32 crossSpan;
    s32 xStart;
    s32 xEnd;
    s32 yStart;
    s32 yEnd;
    s32 xTexture;
    s32 yTexture;
    s32 rounded;
    f32 halfWidth;
    f32 halfHeight;
    f32 sine;
    f32 cosine;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;
    f32 bias;

    if (flags & 8) {
        return;
    }
    if ((scaleX <= D_800AAB14) || (scaleY <= D_800AAB14)) {
        return;
    }

    if ((scaleX == 1.0f) && (scaleY == 1.0f)) {
        flags |= 0x20;
    } else {
        flags &= ~0x20;
    }

    if (resourceAddress == 0) {
        resource = &D_800A4908;
    } else {
        resource = (Resource8003D4F4 *)(unsigned long)resourceAddress;
    }
    strip = resource->strips;

    if (flags & 0x800) {
        func_80014CC0(angle, &cosine, &sine);
    } else {
        sine = 0.0f;
        cosine = 0.0f;
    }

    if (flags & 0x2000) {
        halfWidth = (f32)resource->width * 0.5f * scaleX;
        halfHeight = (f32)resource->height * 0.5f * scaleY;
    } else {
        halfWidth = 0.0f;
        halfHeight = 0.0f;
    }

    output = D_801217B0;
    EMIT_COMMAND(0xE7000000, 0);

    oldFlags = D_800A4960;
    if (flags != oldFlags) {
        modeChanged = 0;
        if (flags & 2) {
            modeFirst = 0x00404340;
            modeSecond = 0x00104340;
            if ((oldFlags & 2) == 0) {
                modeChanged = 1;
            }
        } else if (flags & 1) {
            modeFirst = 0x00404240;
            modeSecond = 0x00104240;
            if ((oldFlags & 3) != 1) {
                modeChanged = 1;
            }
        } else {
            modeFirst = 0x0C087008;
            modeSecond = 0x03027008;
            if (oldFlags & 3) {
                modeChanged = 1;
            }
        }

        if (flags & 0x10) {
            modeFirst |= 0x10;
            modeSecond |= 0x10;
            if ((oldFlags & 0x10) == 0) {
                EMIT_COMMAND(0xEE000000, D_800A48D4 << 16);
                EMIT_COMMAND(0xE2001D00, 4);
                modeChanged = 1;
            }
        } else if (oldFlags & 0x10) {
            EMIT_COMMAND(0xEE000000, 0);
            EMIT_COMMAND(0xE2001D00, 0);
            modeChanged = 1;
        }

        if (modeChanged != 0) {
            EMIT_COMMAND(0xE200001C, modeFirst | modeSecond);
        }

        if (flags & 4) {
            if ((oldFlags & 4) == 0) {
                EMIT_COMMAND(0xF9000000, 0xFFFFFF01);
                EMIT_COMMAND(0xE2001E01, 1);
            }
        } else if (oldFlags & 4) {
            EMIT_COMMAND(0xE2001E01, 0);
        }

        if ((flags & 0x100) && ((oldFlags & 0x100) == 0)) {
            EMIT_COMMAND(0xE3001201, 0x3000);
        } else if ((flags & 0x20) && ((oldFlags & 0x20) == 0)) {
            EMIT_COMMAND(0xE3001201, 0x3000);
        } else if (((flags & 0x120) == 0) && (oldFlags & 0x120)) {
            EMIT_COMMAND(0xE3001201, 0);
        }
        D_800A4960 = flags;
    }

    EMIT_COMMAND(
        0xFA000000,
        ((u32)(u8)red << 24) | ((u32)(u8)green << 16) |
            ((u32)(u8)blue << 8) | (u32)(u8)alpha);

    if (flags & 0x10000) {
        EMIT_COMMAND(0xFC11FE23, 0xFFFFF7FB);
    } else if (flags & 0x10000000) {
        EMIT_COMMAND(0xFCFF97FF, 0xFF2DFEFF);
    } else {
        EMIT_COMMAND(0xFC119623, 0xFF2FFFFF);
    }

    if (resource->type == 2) {
        EMIT_COMMAND(0xE3001001, 0x8000);
        EMIT_COMMAND(0xFD100000, resource->palette);
        EMIT_COMMAND(0xE8000000, 0);
        EMIT_COMMAND(0xF5000100, 0x07000000);
        EMIT_COMMAND(0xE6000000, 0);
        if (resource->format == 0) {
            EMIT_COMMAND(0xF0000000, 0x0703C000);
        } else {
            EMIT_COMMAND(0xF0000000, 0x073FC000);
        }
        EMIT_COMMAND(0xE7000000, 0);
        EMIT_COMMAND(0xE6000000, 0);
    }

    fixedX = flags & 0x05000000;
    if (fixedX != 0) {
        stepX = 0x400;
    } else {
        stepX = (s32)(1024.0f / scaleX + 0.5f);
    }
    fixedY = flags & 0x0A000000;
    if (fixedY != 0) {
        stepY = 0x400;
    } else {
        stepY = (s32)(1024.0f / scaleY + 0.5f);
    }

    if ((strip != 0) && (resource->stripCount > 0) && (strip->span > 0)) {
        xStart = -1;
        yStart = -1;
        xEnd = 0x2328;
        yEnd = 0x2328;
        stripIndex = 0;
        reverseX = flags & 0x2000;
        reverseY = flags & 0x4000;
        bias = D_800AAB18;

        for (;;) {
            span = strip->span;
            if (reverseX != 0) {
                xStart = xEnd - span;
            } else {
                xEnd = xStart + span;
            }

            if ((xStart < 0) || (resource->width < xEnd)) {
                crossSpan = strip->crossSpan;
                if (yStart == -1) {
                    if (reverseY != 0) {
                        yEnd = resource->height;
                        if (crossSpan != 0) {
                            yStart = yEnd - crossSpan;
                        } else {
                            yStart = yEnd - resource->defaultCrossSpan;
                        }
                    } else {
                        yStart = 0;
                        if (crossSpan != 0) {
                            yEnd = crossSpan;
                        } else {
                            yEnd = resource->defaultCrossSpan;
                        }
                    }
                } else if (reverseY != 0) {
                    yEnd = yStart;
                    if (crossSpan != 0) {
                        yStart -= crossSpan;
                    } else {
                        yStart -= resource->defaultCrossSpan;
                    }
                } else {
                    yStart = yEnd;
                    if (crossSpan != 0) {
                        yEnd += crossSpan;
                    } else {
                        yEnd += resource->defaultCrossSpan;
                    }
                }

                if ((yStart < 0) || (resource->height < yEnd)) {
                    break;
                }

                top = (f32)y - halfHeight + (f32)yStart * scaleY;
                bottom = (f32)y - halfHeight + (f32)yEnd * scaleY;
                yTexture = (yEnd - yStart - 1) << 5;
                if (reverseY != 0) {
                    rounded = (s32)(top + bias);
                    yTexture =
                        ((s32)((f32)stepY * ((f32)rounded - top)) + 0x10) >> 5;
                    if (flags & 0x100) {
                        yTexture += 0x10;
                    }
                    if (fixedY != 0) {
                        yTexture -= (s32)(32.0f * (bottom - top));
                    }
                }
                xStart = 0;
                xEnd = span;
            }

            left = (f32)x - halfWidth + (f32)xStart * scaleX;
            right = (f32)x - halfWidth + (f32)xEnd * scaleX;
            if (reverseX != 0) {
                xTexture = (xEnd - xStart - 1) << 5;
                if (fixedX != 0) {
                    xTexture += (s32)(32.0f * (right - left));
                }
            } else {
                rounded = (s32)(left + bias);
                xTexture =
                    ((s32)((f32)stepX * ((f32)rounded - left)) + 0x10) >> 5;
                if (flags & 0x100) {
                    xTexture += 0x10;
                }
            }

            if (strip->data != 0) {
                func_8003BAB0(
                    &output, resource, strip, left, top, right, bottom,
                    (s16)arg6, (s16)arg7, xTexture, yTexture, stepX,
                    stepY, reverseX, reverseY == 0, cosine, sine, flags);
                bias = D_800AAB1C;
            }

            if (reverseX != 0) {
                xEnd -= span;
            } else {
                xStart += span;
            }
            stripIndex++;
            if (stripIndex >= resource->stripCount) {
                break;
            }
            strip++;
            if (strip->span <= 0) {
                break;
            }
        }
    }

    if (resource->type == 2) {
        EMIT_COMMAND(0xE3001001, 0);
    }
    D_801217B0 = output;
}
