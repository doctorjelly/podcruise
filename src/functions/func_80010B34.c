/* Recovered from specs/functions/recovered/extended_runtime_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

extern s32 D_8009B86C;
extern f32 D_800A3FDC[3];
extern f32 D_800A86AC;
extern PcVec3f D_800D5898[];
extern s32 D_800D5958[];
extern s32 D_800D5988[];
extern s32 D_800D5F80[];
extern s32 D_800D6070[];
extern s16 D_80114470;
extern s16 D_80114472;

extern void func_8000A920(s32 arg0, s32 arg1);
extern void func_8000AAC0(s32 arg0, f32 arg1, f32 arg2);
extern void func_8000AAF8(s32 arg0, f32 arg1);
extern void func_8000AB24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8000E680(s32 arg0, s32 arg1, s32 arg2);
extern void func_8000EBE8(s16 *obj, f32 *pos, f32 *outX, f32 *outY, f32 *outZ, f32 *outW, s32 mode);
extern s32 func_8001004C(s32 arg0);
extern f32 func_80015470(const PcVec3f *from, const PcVec3f *to);

void func_80010B34(s16 *arg0) {
    f32 padTop[2];
    f32 screenX;
    f32 screenY;
    f32 distance;
    f32 cutoff;
    f32 zero;
    f32 one;
    f32 farLimit;
    f32 alphaScale;
    f32 *selected;
    f32 depthScale;
    f32 spare;
    s32 index;
    s32 depth;
    s32 limit;
    s32 alpha;

    (void)padTop;
    for (index = 0; index < D_8009B86C; index++) {
        alphaScale = 255.0f;
        farLimit = 400.0f;
        one = 1.0f;
        zero = 0.0f;
        cutoff = D_800A86AC;
        D_800D5958[index] = -1000;
        D_800D5988[index] = -1000;
        distance = func_80015470(&D_800D5898[index], (const PcVec3f *)D_800A3FDC);
        if (distance < cutoff) {
            selected = (distance < farLimit) ? &depthScale : &depthScale;
            func_8000EBE8(arg0, (f32 *)&D_800D5898[index], &screenX, &screenY,
                          selected, &spare, 0);
            if (-4.0f < screenX && screenX < (f32)D_80114470 && zero < screenY &&
                screenY < (f32)D_80114472) {
                D_800D5958[index] = (s32)screenX;
                D_800D5988[index] = (s32)screenY;
                depth = (s32)((depthScale * (f32)arg0[10] + (f32)arg0[14]) * 256.0f);
                limit = func_8001004C(D_800D6070[index]);
                if (depth < 0 || depth < limit) {
                    if (D_800D5F80[index] != -1) {
                        alpha = (u8)(u32)alphaScale;
                        func_8000A920((s16)D_800D5F80[index], 1);
                        func_8000E680((s16)D_800D5F80[index], (s16)(s32)screenX,
                                      (s16)(s32)screenY);
                        func_8000AAF8((s16)D_800D5F80[index], zero);
                        func_8000AAC0((s16)D_800D5F80[index], one, one);
                        func_8000AB24((s16)D_800D5F80[index], 0xFF, 0xFF, 0xFF, alpha);
                    }
                }
            }
        }
    }
}
