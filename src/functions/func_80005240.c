/* Recovered from specs/functions/recovered/medium_pipeline_tranche.md. */
#include "podcruise/types.h"

typedef struct View80005240 {
    f32 a[3];
    f32 b[3];
    f32 unk18;
} View80005240;

extern void func_800026BC(void);
extern void func_800020D8(void);
extern void func_800035BC(void *object);
extern void func_800155EC(f32 *output, const f32 *base, f32 scale, const f32 *offset);
extern s32 func_80017E88(const void *object, s32 selector);
extern u32 func_80017EDC(const void *object);

extern s32 D_8009A270;
extern s32 D_8009A274;
extern s32 D_8009A278;
extern s32 D_8009A280;
extern f32 D_800AE8B0;
extern f32 D_800AE8B8[3];
extern f32 D_800AE8C8[3];
extern s32 D_800AE8D8;
extern View80005240 D_800AE8E8;
extern f32 D_800AE918[3];
extern f32 D_800AE928[3];
extern u16 D_800AE934;
extern void (*D_800AE93C)(void);
extern void (*D_800AE940)(void);

f32 func_80005240(void *object, View80005240 *view, f32 *out0, f32 *out1) {
    f32 mixed[3];
    s32 state;

    if (object == 0) {
        D_800AE8B0 = -1.0f;
    } else {
        D_800AE8B0 = view->unk18 + 200.0f;
        D_800AE8E8.unk18 = view->unk18;
        D_800AE8E8.b[0] = view->b[0];
        D_800AE8E8.b[1] = view->b[1];
        D_800AE8E8.b[2] = view->b[2];
        D_800AE8E8.a[0] = view->a[0];
        D_800AE8E8.a[1] = view->a[1];
        D_800AE8E8.a[2] = view->a[2];
        D_800AE934 = 1;
        D_800AE93C = func_800026BC;
        D_800AE940 = func_800020D8;
        func_800155EC(mixed, D_800AE8E8.a, D_800AE8E8.unk18, D_800AE8E8.b);
        if (D_800AE8E8.b[0] < 0.0f) {
            D_800AE918[0] = D_800AE8E8.a[0];
            D_800AE928[0] = mixed[0];
        } else {
            D_800AE928[0] = D_800AE8E8.a[0];
            D_800AE918[0] = mixed[0];
        }
        if (D_800AE8E8.b[1] < 0.0f) {
            D_800AE918[1] = D_800AE8E8.a[1];
            D_800AE928[1] = mixed[1];
        } else {
            D_800AE928[1] = D_800AE8E8.a[1];
            D_800AE918[1] = mixed[1];
        }
        if (D_800AE8E8.b[2] < 0.0f) {
            D_800AE918[2] = D_800AE8E8.a[2];
            D_800AE928[2] = mixed[2];
        } else {
            D_800AE928[2] = D_800AE8E8.a[2];
            D_800AE918[2] = mixed[2];
        }
        if (D_8009A270 != 0) {
            D_8009A278 = 1;
            D_8009A274 = 1;
        } else {
            state = func_80017E88((void *)(long)func_80017EDC(object), 1);
            if (state == 1 || state == 3) {
                D_8009A278 = 0;
            } else {
                D_8009A278 = 1;
            }
            if (state == 2 || state == 3) {
                D_8009A274 = 0;
            } else {
                D_8009A274 = 1;
            }
        }
        func_800035BC(object);
        if (view->unk18 < D_800AE8B0) {
            D_800AE8B0 = -1.0f;
        } else {
            out0[0] = D_800AE8B8[0];
            out0[1] = D_800AE8B8[1];
            out0[2] = D_800AE8B8[2];
            out1[0] = D_800AE8C8[0];
            out1[1] = D_800AE8C8[1];
            out1[2] = D_800AE8C8[2];
        }
    }
    if (D_800AE8D8 != 0) {
        D_8009A280 = D_800AE8D8;
    }
    return D_800AE8B0;
}
