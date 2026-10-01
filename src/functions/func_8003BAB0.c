/* Independently written from specs/functions/recovered/func_8003BAB0.md. */

#include "podcruise/types.h"

typedef struct Gfx8003BAB0 {
    u32 w0;
    u32 w1;
} Gfx8003BAB0;

typedef struct Strip8003BAB0 {
    /* 0x00 */ s16 span;
    /* 0x02 */ s16 crossSpan;
    /* 0x04 */ void *data;
} Strip8003BAB0;

typedef struct Resource8003BAB0 {
    /* 0x00 */ s16 width;
    /* 0x02 */ s16 height;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 format;
    /* 0x06 */ u8 pad06[2];
    /* 0x08 */ void *palette;
    /* 0x0C */ s16 stripCount;
    /* 0x0E */ s16 defaultCrossSpan;
    /* 0x10 */ Strip8003BAB0 *strips;
} Resource8003BAB0;

extern u32 D_800A48D0;
extern s32 D_80114540;
extern s32 D_80114544;
extern s32 D_80114548;
extern s32 D_8011454C;

extern void func_8003B324(
    Gfx8003BAB0 **, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_8003B860(
    Gfx8003BAB0 **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

#define EMIT_COMMAND(first, second)                       \
    do {                                                  \
        Gfx8003BAB0 *command = output++;                  \
        command->w0 = (u32)(first);                       \
        command->w1 = (u32)(unsigned long)(second);       \
    } while (0)

#define IMGFMT ((u32)(resource->type & 7) << 21)
#define TILE_A ((u32)(clampT & 3) << 18)
#define TILE_B ((u32)(maskT & 15) << 14)
#define TILE_C ((u32)(clampS & 3) << 8)
#define TILE_D ((u32)(maskS & 15) << 4)

#define DXT(lw) (((lw) > 0 ? (lw) : 1) + 0x7FF) / ((lw) > 0 ? (lw) : 1)

#define TEX_LOAD(loadSize, renderSize, loadCountExpr, dxtExpr, tileLineExpr)  \
    do {                                                                       \
        s32 loadCount;                                                         \
        EMIT_COMMAND(0xFD000000 | IMGFMT | (loadSize),                         \
            (u32)(unsigned long)strip->data);                                  \
        EMIT_COMMAND(0xF5000000 | IMGFMT | (loadSize),                         \
            TILE_A | 0x07000000 | TILE_B | TILE_C | TILE_D);                   \
        EMIT_COMMAND(0xE6000000, 0);                                           \
        loadCount = (loadCountExpr) < 0x7FF ? (loadCountExpr) : 0x7FF;         \
        EMIT_COMMAND(0xF3000000, 0x07000000 | (u32)((dxtExpr) & 0xFFF) |       \
            ((u32)(loadCount & 0xFFF) << 12));                                 \
        EMIT_COMMAND(0xE7000000, 0);                                           \
        EMIT_COMMAND(0xF5000000 | IMGFMT | (renderSize) |                      \
            ((u32)((tileLineExpr) & 0x1FF) << 9),                              \
            TILE_A | TILE_B | TILE_C | TILE_D);                                \
        EMIT_COMMAND(0xF2000000,                                               \
            ((u32)(((alignedWidth - 1) * 4) & 0xFFF) << 12) |                  \
            (u32)(((tileHeight - 1) * 4) & 0xFFF));                            \
    } while (0)

void func_8003BAB0(
    Gfx8003BAB0 **listPointer, Resource8003BAB0 *resource,
    Strip8003BAB0 *strip, f32 left, f32 top, f32 right, f32 bottom,
    s32 pivotX, s32 pivotY, s32 textureS, s32 textureT,
    s32 derivativeS, s32 derivativeT, s16 reverseS, s16 reverseT,
    f32 cosine, f32 sine, s32 flags) {
    s32 texS;
    s32 texT;
    s32 fixedPivotX;
    s32 fixedPivotY;
    s32 fixedLeft;
    s32 fixedTop;
    s32 fixedRight;
    s32 fixedBottom;
    s32 signedDerivativeS;
    s32 signedDerivativeT;
    Gfx8003BAB0 *output;
    s32 alignedWidth;
    s32 tileHeight;
    s32 clipLeft;
    s32 clipTop;
    s32 clipRight;
    s32 clipBottom;
    s32 clampS;
    s32 clampT;
    s32 maskS;
    s32 maskT;
    s32 alignmentMask;
    s32 *addrW;
    s32 *addrH;
    s32 usePivot;

    addrW = &alignedWidth;
    addrH = &tileHeight;
    (void)addrW;
    (void)addrH;
    alignedWidth = strip->span;
    tileHeight = resource->defaultCrossSpan;
    switch (resource->format) {
        case 0:
            alignmentMask = 15;
            break;
        case 1:
            alignmentMask = 7;
            break;
        case 2:
            alignmentMask = 3;
            break;
        case 3:
            alignmentMask = 1;
            break;
        default:
            break;
    }
    alignedWidth = (alignedWidth + alignmentMask) & ~alignmentMask;
    output = *listPointer;

    clipRight = D_80114540;
    clipBottom = D_80114544;
    clipLeft = D_80114548;
    clipTop = D_8011454C;
    if ((clipRight <= left) || (clipBottom <= top) ||
        (right < clipLeft) || (bottom < clipTop)) {
        *listPointer = output;
        return;
    }

    usePivot = flags & 0x00400000;
    if (usePivot) {
        fixedPivotX = pivotX;
        fixedPivotY = pivotY;
        if (fixedPivotX < clipLeft) {
            fixedPivotX = clipLeft * 4;
        }
        if (clipRight < fixedPivotX) {
            fixedPivotX = clipRight * 4;
        }
        if (fixedPivotY < clipTop) {
            fixedPivotY = clipTop * 4;
        }
        if (clipBottom < fixedPivotY) {
            fixedPivotY = clipBottom * 4;
        }
        fixedPivotX *= 4;
        fixedPivotY *= 4;
    }

    if (left < clipLeft) {
        fixedLeft = clipLeft * 4;
        texS = textureS + (((clipLeft - (s32)left) * derivativeS) >> 5);
    } else {
        texS = textureS;
        fixedLeft = (s32)(left * 4.0f);
    }
    if (top < clipTop) {
        fixedTop = clipTop * 4;
        texT = textureT - (((clipTop - (s32)top) * derivativeT) >> 5);
    } else {
        texT = textureT;
        fixedTop = (s32)(top * 4.0f);
    }
    if (clipRight <= right) {
        fixedRight = clipRight * 4;
    } else {
        fixedRight = (s32)(right * 4.0f);
    }
    if (clipBottom <= bottom) {
        fixedBottom = clipBottom * 4;
    } else {
        fixedBottom = (s32)(bottom * 4.0f);
    }

    if (flags & 0x01000000) {
        clampS = 0;
        if (resource->width < 8) {
            maskS = 2;
        } else if (resource->width < 16) {
            maskS = 3;
        } else {
            maskS = 4;
        }
    } else if (flags & 0x04000000) {
        clampS = 0;
        maskS = 5;
    } else {
        clampS = 2;
        maskS = 0;
    }

    if (flags & 0x02000000) {
        clampT = 0;
        if (resource->height < 8) {
            maskT = 2;
        } else if (resource->height < 16) {
            maskT = 3;
        } else {
            maskT = 4;
        }
    } else if (flags & 0x08000000) {
        clampT = 0;
        maskT = 5;
    } else {
        clampT = 2;
        maskT = 0;
    }

    if (D_800A48D0 != (u32)(unsigned long)strip->data) {
        switch (resource->format) {
            case 0:
                if (flags & 0x400) {
                    TEX_LOAD(0x00100000, 0, ((alignedWidth * tileHeight + 3) >> 2) - 1, 0, ((alignedWidth >> 1) + 7) >> 3);
                } else {
                    TEX_LOAD(0x00100000, 0, ((alignedWidth * tileHeight + 3) >> 2) - 1, DXT(alignedWidth / 16), ((alignedWidth >> 1) + 7) >> 3);
                }
                break;
            case 1:
                if (flags & 0x400) {
                    TEX_LOAD(0x00100000, 0x00080000, ((alignedWidth * tileHeight + 1) >> 1) - 1, 0, (alignedWidth + 7) >> 3);
                } else {
                    TEX_LOAD(0x00100000, 0x00080000, ((alignedWidth * tileHeight + 1) >> 1) - 1, DXT(alignedWidth / 8), (alignedWidth + 7) >> 3);
                }
                break;
            case 2:
                if (flags & 0x400) {
                    TEX_LOAD(0x00100000, 0x00100000, alignedWidth * tileHeight - 1, 0, ((alignedWidth * 2) + 7) >> 3);
                } else {
                    TEX_LOAD(0x00100000, 0x00100000, alignedWidth * tileHeight - 1, DXT((alignedWidth * 2) / 8), ((alignedWidth * 2) + 7) >> 3);
                }
                break;
            case 3:
                if (flags & 0x400) {
                    TEX_LOAD(0x00180000, 0x00180000, alignedWidth * tileHeight - 1, 0, ((alignedWidth * 2) + 7) >> 3);
                } else {
                    TEX_LOAD(0x00180000, 0x00180000, alignedWidth * tileHeight - 1, DXT((alignedWidth * 4) / 8), ((alignedWidth * 2) + 7) >> 3);
                }
                break;
            default:
                break;
        }
        D_800A48D0 = (u32)(unsigned long)strip->data;
    }

    signedDerivativeS = reverseS ? -derivativeS : derivativeS;
    signedDerivativeT = reverseT ? -derivativeT : derivativeT;
    if (flags & 0x00C00000) {
        s32 sLeft;
        s32 sRight;
        s32 tTop;
        s32 tBottom;

        if (reverseS) {
            sLeft = alignedWidth << 6;
            sRight = 0;
        } else {
            sLeft = 0;
            sRight = alignedWidth << 6;
        }
        if (reverseT) {
            tTop = tileHeight << 6;
            tBottom = 0;
        } else {
            tTop = 0;
            tBottom = tileHeight << 6;
        }

        if (usePivot) {
            func_8003B860(
                &output, fixedLeft, fixedRight, fixedTop, fixedBottom,
                fixedPivotX, fixedPivotY, sLeft, sRight, tTop, tBottom);
        } else {
            func_8003B324(
                &output, fixedLeft, fixedRight, fixedTop, fixedBottom,
                sLeft, sRight, tTop, tBottom, cosine, sine);
        }
        EMIT_COMMAND(0xE7000000, 0);
    } else {
        EMIT_COMMAND(
            0xE4000000 | ((u32)(fixedRight & 0xFFF) << 12) |
                (u32)(fixedBottom & 0xFFF),
            ((u32)(fixedLeft & 0xFFF) << 12) |
                (u32)(fixedTop & 0xFFF));
        EMIT_COMMAND(
            0xE1000000,
            ((u32)texS << 16) | (u32)(texT & 0xFFFF));
        EMIT_COMMAND(
            0xF1000000,
            ((u32)signedDerivativeS << 16) |
                (u32)(signedDerivativeT & 0xFFFF));
        EMIT_COMMAND(0xE7000000, 0);
    }

    *listPointer = output;
}
