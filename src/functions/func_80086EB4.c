/* Implements the specification in specs/func_80086EB4.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x10];
    u8 vp[0x10];
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
    u8 unk30[0x100];
    u16 perspNorm;
    u8 pad132[0x3E];
} View;

extern void func_80038D5C(u32 **);
extern s16 D_80114470[];
extern View D_80120DF0[];
extern u32 *D_801217B0;

#define SHIFTL(v, s, w) (((u32)((v) & ((1 << (w)) - 1))) << (s))
#define SCALE(v) ((s32)((f32)(v) * 4.0f))
#define PUSH(w0, w1) { u32 *_g = D_801217B0; D_801217B0 = _g + 2; _g[0] = (u32)(w0); _g[1] = (u32)(w1); }
#define VIEWPORT(v) PUSH(0xDC080008, (u32)(unsigned long)(v))
#define SCISSOR(ulx, uly, lrx, lry) PUSH(0xED000000 | SHIFTL(SCALE(ulx), 12, 12) | SHIFTL(SCALE(uly), 0, 12), SHIFTL(SCALE(lrx), 12, 12) | SHIFTL(SCALE(lry), 0, 12))
#define PERSPNORM(s) PUSH(0xDB0E0000, (u32)(s))

void func_80086EB4(s32 arg0) {
    s32 *index;
    View *view;
    f64 xScale;
    f64 yScale;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;

    index = &arg0;
    VIEWPORT((view = &D_80120DF0[*index])->vp);
    xScale = (f64)D_80114470[0] / 320.0;
    yScale = (f64)D_80114470[1] / 240.0;
    ulx = (s32)((f64)view->ulx * xScale); uly = (s32)((f64)view->uly * yScale); lrx = (s32)((f64)view->lrx * xScale); lry = (s32)((f64)view->lry * yScale);
    SCISSOR(ulx, uly, lrx, lry);
    PERSPNORM(view->perspNorm);
    func_80038D5C(&D_801217B0);
}
