/* Specification: scratchpad specs/func_80065074.md (worker-authored). */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x50];
    f32 unk50[3];
    u8 pad5C[0xC];
    f32 unk68;
    u8 pad6C[0x4];
    s32 unk70;
    f32 unk74[3];
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    u8 padAC[0x8];
    f32 unkB4;
    f32 unkB8;
    f32 unkBC;
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    f32 unkD4;
    f32 unkD8;
    f32 unkDC[6];
    void *unkF4[8];
} Obj65074;

extern void *func_8000E8C4(void *arg0);
extern void func_8000E9BC(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
extern f32 func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_80017824(f32 *, f32, f32, f32, f32, f32 *);
extern void func_80017874(f32 *);
extern void func_80017BA8(void *, f32 *);
extern s32 func_800181BC(void *, s32, s32, s32, s32);
extern void func_8003E0A0(void *, f32, f32);

extern f64 D_80120BF0;

void func_80065074(Obj65074 *arg0) {
    s32 i;
    f32 spareTop[16];
    f32 matrix[4][4];
    f32 spareMid[121];
    f32 forward[3];
    f32 side[3];
    f32 up[3];
    void *node;
    void *owner;
    f32 t;
    f32 axis;
    f32 sizeA;
    f32 sizeB;
    f32 spin;
    f32 magnitude;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 whole;
    f32 spareLow[12];

    (void)spareTop;
    (void)spareMid;
    (void)spareLow;
    for (i = 0; i < arg0->unk70; i++) {
        if (arg0->unkF4[i] != 0) {
            t = arg0->unk68 / arg0->unkA8 + (f32)i / (f32)arg0->unk70;
            whole = (s32)(t < 0 ? t - 0.999999f : t);
            t = t - (f32)whole;
            t = 1.0f - t;
            if (t < 0.0f) {
                t = 0.0f;
            }
            if (1.0f < t) {
                t = 1.0f;
            }
            sizeA = arg0->unk88 + (arg0->unk8C - arg0->unk88) * (t * t);
            sizeB = arg0->unk90 + (arg0->unk94 - arg0->unk90) * (t * t);
            forward[0] = arg0->unk74[0];
            forward[1] = arg0->unk74[1];
            forward[2] = arg0->unk74[2];
            func_800154D0(forward);
            axis = forward[2] < 0 ? -forward[2] : forward[2];
            if (axis > 0.9) {
                up[0] = 0.0f;
                up[1] = 1.0f;
                up[2] = 0.0f;
            } else {
                up[0] = 0.0f;
                up[1] = 0.0f;
                up[2] = 1.0f;
            }
            func_80015538(side, up, forward);
            func_80015538(up, forward, side);
            func_800154D0(up);
            func_800154D0(side);
            func_80017874(matrix[0]);
            spin = sizeA * 0.01f;
            func_800155C0(matrix[0], spin, side);
            func_800155C0(matrix[1], spin, up);
            func_800155C0(matrix[2], sizeB * 0.01f, forward);
            arg0->unkDC[i] = (f32)((f64)arg0->unkDC[i] +
                                   D_80120BF0 * (f64)((arg0->unk9C - arg0->unk98) * t + arg0->unk98));
            func_80017824(matrix[0], arg0->unkDC[i], 0.0f, 0.0f, 1.0f, matrix[0]);
            func_800155EC(matrix[3], arg0->unk50, t, arg0->unk74);
            red = (s32)((arg0->unkB4 + (arg0->unkC4 - arg0->unkB4) * t) * 255.0f);
            green = (s32)((arg0->unkB8 + (arg0->unkC8 - arg0->unkB8) * t) * 255.0f);
            blue = (s32)((arg0->unkBC + (arg0->unkCC - arg0->unkBC) * t) * 255.0f);
            alpha = (s32)((arg0->unkC0 + (arg0->unkD0 - arg0->unkC0) * t) * 255.0f);
            if (t < arg0->unk80 && 0.0f < arg0->unk80) {
                alpha = (s32)((f32)alpha * (t / arg0->unk80));
            }
            if (arg0->unk84 < t && arg0->unk84 < 1.0f) {
                alpha = (s32)((f64)(-alpha) * ((f64)(t - arg0->unk84) / (1.0 - (f64)arg0->unk84)) + (f64)alpha);
            }
            if (arg0->unkD8 < t) {
                alpha = (s32)((f32)alpha * (1.0f - (t - arg0->unkD8) * 4.0f));
            }
            if (t < arg0->unkD8) {
                alpha = (s32)((f32)alpha * (1.0f - (arg0->unkD4 - t) * 4.0f));
            }
            if (red < 0) {
                red = 0;
            }
            if (red > 255) {
                red = 255;
            }
            if (green < 0) {
                green = 0;
            }
            if (green > 255) {
                green = 255;
            }
            if (blue < 0) {
                blue = 0;
            }
            if (blue > 255) {
                blue = 255;
            }
            if (alpha < 0) {
                alpha = 0;
            }
            if (alpha > 255) {
                alpha = 255;
            }
            magnitude = (f32)((f64)(arg0->unkA0 + (arg0->unkA4 - arg0->unkA0) * t) * D_80120BF0);
            func_80017BA8(arg0->unkF4[i], matrix[0]);
            node = arg0->unkF4[i];
            if (node != 0) {
                func_800181BC(node, 2, 3, 0x10, 2);
                node = arg0->unkF4[i];
            }
            if (alpha < 2) {
                if (node != 0) {
                    func_800181BC(node, 2, -4, 0x10, 3);
                    node = arg0->unkF4[i];
                }
            }
            owner = func_8000E8C4(node);
            if (owner != 0) {
                func_8000E9BC(owner, 0, 0, red, green, blue, alpha);
                func_8003E0A0(owner, 0, magnitude);
            }
        }
    }
}
