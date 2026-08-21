/* Recovered from specification specs/functions/func_8003B324.md (batch_07). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8003B324;

extern u8 D_800A4920[];
extern f32 D_800AAB10;
extern s16 D_80114470[2];

#define EMIT(pkt, a, b) { Gfx8003B324 *g_ = (pkt); g_->w0 = (u32)(a); g_->w1 = (u32)(unsigned long)(b); }

void func_8003B324(Gfx8003B324 **listPointer, s32 left, s32 right, s32 top, s32 bottom,
                   s32 sLeft, s32 sRight, s32 tTop, s32 tBottom, f32 cosine, f32 sine) {
    Gfx8003B324 *list;
    f32 centerX;
    f32 centerY;
    f32 scaleX;
    f32 scaleY;
    f32 skew;
    f32 dx0;
    f32 dy0;
    f32 dx1;
    f32 dy1;
    f32 baseX;
    f32 baseY;
    f32 negCosine;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    s32 x3;
    s32 y3;

    list = *listPointer;
    centerX = (f32)(right + left) * 0.5f;
    centerY = (f32)(bottom + top) * 0.5f;

    EMIT(list++, 0x01004008, D_800A4920);
    EMIT(list++, 0x021C0000, 0);
    EMIT(list++, 0x021C0002, 0);
    EMIT(list++, 0x021C0004, 0);
    EMIT(list++, 0x021C0006, 0);

    dx0 = (f32)left - centerX;
    dy0 = (f32)top - centerY;
    scaleY = (f32)D_80114470[1] / 240.0f;
    scaleX = (f32)D_80114470[0] / 320.0f;
    skew = scaleY / scaleX - 1.0f;

    if (skew > D_800AAB10 || -skew > D_800AAB10) {
        baseX = centerX / scaleX;
        baseY = centerY / scaleY;
        dy0 = dy0 / scaleY;
        dx1 = ((f32)right - centerX) / scaleX;
        dx0 = dx0 / scaleX;
        dy1 = ((f32)bottom - centerY) / scaleY;
        negCosine = -cosine;
        x0 = (s32)((dx0 * sine + baseX + dy0 * cosine) * scaleX + 0.5f);
        y0 = (s32)((dy0 * sine + baseY + dx0 * negCosine) * scaleY + 0.5f);
        x1 = (s32)((dx1 * sine + baseX + dy0 * cosine) * scaleX + 0.5f);
        y1 = (s32)((dy0 * sine + baseY + dx1 * negCosine) * scaleY + 0.5f);
        x2 = (s32)((dx1 * sine + baseX + dy1 * cosine) * scaleX + 0.5f);
        y2 = (s32)((dy1 * sine + baseY + dx1 * negCosine) * scaleY + 0.5f);
        x3 = (s32)((dx0 * sine + baseX + dy1 * cosine) * scaleX + 0.5f);
        y3 = (s32)((dy1 * sine + baseY + dx0 * negCosine) * scaleY + 0.5f);
    } else {
        negCosine = -cosine;
        x0 = (s32)(dx0 * sine + centerX + dy0 * cosine + 0.5f);
        y0 = (s32)(dy0 * sine + centerY + dx0 * negCosine + 0.5f);
        dx1 = (f32)right - centerX;
        x1 = (s32)(dx1 * sine + centerX + dy0 * cosine + 0.5f);
        y1 = (s32)(dy0 * sine + centerY + dx1 * negCosine + 0.5f);
        dy1 = (f32)bottom - centerY;
        x2 = (s32)(dx1 * sine + centerX + dy1 * cosine + 0.5f);
        y2 = (s32)(dy1 * sine + centerY + dx1 * negCosine + 0.5f);
        x3 = (s32)(dx0 * sine + centerX + dy1 * cosine + 0.5f);
        y3 = (s32)(dy1 * sine + centerY + dx0 * negCosine + 0.5f);
    }

    EMIT(list++, 0x02180000, (x0 << 16) | (y0 & 0xFFFF));
    EMIT(list++, 0x02180002, (x1 << 16) | (y1 & 0xFFFF));
    EMIT(list++, 0x02180004, (x2 << 16) | (y2 & 0xFFFF));
    EMIT(list++, 0x02180006, (x3 << 16) | (y3 & 0xFFFF));
    EMIT(list++, 0x02140000, (sLeft << 16) | (tTop & 0xFFFF));
    EMIT(list++, 0x02140002, (sRight << 16) | (tTop & 0xFFFF));
    EMIT(list++, 0x02140004, (sRight << 16) | (tBottom & 0xFFFF));
    EMIT(list++, 0x02140006, (sLeft << 16) | (tBottom & 0xFFFF));
    EMIT(list++, 0x06000402, 0x00000604);
    *listPointer = list;
}
