/* Independently written from specs/functions/recovered/func_80041F40.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x18];
    s32 *unk18;
} PodTrack;

typedef struct {
    u8 unk00[0x20];
    f32 unk20[4][4];
    u32 unk60;
    u8 unk64[0xA8 - 0x64];
    f32 unkA8;
    u8 unkAC[0x1A0 - 0xAC];
    f32 unk1A0;
    u8 unk1A4[0x1E8 - 0x1A4];
    f32 unk1E8;
    u8 unk1EC[0x250 - 0x1EC];
    f32 unk250;
    u8 unk254[0x19B4 - 0x254];
    f32 unk19B4;
    u8 unk19B8[0x1E70 - 0x19B8];
    PodTrack *unk1E70;
} Pod;

typedef struct {
    u8 unk00[0x20];
    f32 unk20[4][4];
    u8 unk60[0x7C - 0x60];
    s32 unk7C;
    u8 unk80[0xF4 - 0x80];
    Pod *unkF4;
    u8 unkF8[0x108 - 0xF8];
    f32 unk108[4][4];
    f32 unk148;
    f32 unk14C;
    u8 unk150[0x224 - 0x150];
    f32 unk224[4][4];
    f32 unk264[4][4];
    u8 unk2A4[0x2B0 - 0x2A4];
    f32 unk2B0;
} Actor;

typedef struct {
    u8 unk00[0x4C];
    f32 unk4C;
    f32 unk50;
    u8 unk54[0x6C - 0x54];
} Course;

extern s32 D_800A4ADC;
extern Course D_800A5CA0[];
extern f64 D_800AAC68;
extern f64 D_800AAC70;
extern f32 D_800AAC78;
extern f32 D_800AAC7C;
extern f32 D_800AAC80;
extern f32 D_800AAC84;
extern f32 D_800AAC88;
extern f32 D_800AAC8C;
extern f32 D_800AAC90;
extern f64 D_80120BF0;

extern void func_80015288(f32 *output, f32 *source);
extern void func_8001535C(f32 *output, f32 *left, f32 *right);
extern f32 func_800153C0(f32 *vector);
extern f32 func_800154D0(f32 *vector);
extern void func_800155C0(f32 *output, f32 scale, f32 *source);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *offset);
extern void func_800156DC(f32 output[4][4], f32 source[4][4]);
extern void func_80016F0C(f32 matrix[4][4], f32 *output);
extern void func_8001745C(f32 *matrix, f32 first, f32 second, f32 third);
extern s32 func_80051FF4(void);

void func_80041F40(Actor *actor) {
    Pod *pod;
    f32 blend;
    s32 flagB;
    s32 flagA;
    f32 mtxB[4][4];
    f32 mtxA[4][4];
    f32 vecP[3];
    f64 quarter;
    f32 x;
    f32 y;
    f32 w;
    f32 dot;
    f32 vecQ[3];
    f32 vecR[3];
    f32 lean;
    f32 unit;
    f32 cube;
    f32 euler[6];
    s32 notB;
    f64 absQuarter;
    f32 delta[3];

    notB = 0;
    pod = actor->unkF4;
    if (pod == 0) {
        return;
    }
    if (!(pod->unk60 & 0x20)) {
        flagA = 1;
    } else {
        flagA = 0;
    }
    if (pod->unk60 & 0x20) {
        if (pod->unk1A0 < 50.0f) {
            func_800155EC(actor->unk224[3], actor->unk224[3],
                          (f32)(-20.0f * D_80120BF0), pod->unk20[1]);
        }
    }
    if (pod->unk60 & 0x06000000) {
        flagB = 1;
    } else {
        flagB = 0;
    }
    if (flagB == 0) {
        notB = 1;
    }
    actor->unk2B0 = 100.0f;
    if (notB != 0) {
        x = D_800A5CA0[*pod->unk1E70->unk18].unk4C;
        y = (f32)(D_800A5CA0[*pod->unk1E70->unk18].unk50 +
                  pod->unk19B4 * 0.75);
    } else {
        actor->unk148 = D_800A5CA0[*pod->unk1E70->unk18].unk4C;
        x = actor->unk148;
        actor->unk14C = D_800A5CA0[*pod->unk1E70->unk18].unk50;
        actor->unk14C = (f32)(actor->unk14C + pod->unk19B4 * 0.75);
        y = actor->unk14C;
    }
    w = y;
    if (actor->unk7C == 2) {
        x = x * (f32)2.0;
        y = y * (f32)2.0;
        if (30.0f < x) {
            x = 30.0f;
        }
        if (15.0f < y) {
            y = 15.0f;
        }
        w = 8.0f;
    }
    blend = (f32)((pod->unk1A0 - 200.0f) / D_800AAC68);
    if (blend < 0.0) {
        blend = 0.0f;
    }
    if (blend > 1.0) {
        blend = 1.0f;
    }
    blend = (f32)(blend * D_800AAC70 + 0.75);
    x = x * blend;
    y = y * blend;
    w = w * blend;
    if (func_80051FF4() == 2) {
        x = x * D_800AAC78;
    }
    delta[0] = actor->unk264[3][0] - actor->unk224[3][0];
    delta[1] = actor->unk264[3][1] - actor->unk224[3][1];
    delta[2] = actor->unk264[3][2] - actor->unk224[3][2];
    func_800154D0(delta);
    dot = actor->unkF4->unk20[1][1] * delta[1] +
          actor->unkF4->unk20[1][0] * delta[0];
    dot = delta[2] * actor->unkF4->unk20[1][2] + dot;
    x = x * ((1.0f - dot) * 0.5f + 1.0f);
    if (notB != 0) {
        actor->unk148 = (actor->unk148 + x) * 0.5f;
        actor->unk14C = (actor->unk14C + y) * 0.5f;
    }
    func_800156DC(mtxA, actor->unkF4->unk20);
    mtxA[3][2] = mtxA[3][2] + pod->unk250;
    func_800156DC(mtxB, mtxA);
    func_8001535C(vecP, actor->unk224[3], mtxB[3]);
    if (flagB == 0) {
        vecP[2] = 0.0f;
        func_800153C0(vecP);
        func_800154D0(vecP);
        if (flagA != 0) {
            switch (D_800A4ADC) {
            case 0:
                mtxB[3][0] = mtxB[3][0] + x * D_800AAC7C;
                mtxB[3][2] = mtxB[3][2] + y;
                break;
            case 1:
                mtxB[3][1] = mtxB[3][1] + x * D_800AAC80;
                mtxB[3][2] = mtxB[3][2] + y;
                break;
            case 2:
                mtxB[3][0] = mtxB[3][0] - x * D_800AAC84;
                mtxB[3][2] = mtxB[3][2] + y;
                break;
            case 3:
            default:
                mtxB[3][1] = mtxB[3][1] - x * D_800AAC88;
                mtxB[3][2] = mtxB[3][2] + y;
                break;
            }
        } else {
            func_800155EC(mtxB[3], mtxB[3], x, vecP);
            mtxB[3][2] = mtxB[3][2] + y;
        }
        func_80015288(vecQ, mtxB[3]);
        vecR[0] = mtxA[3][0];
        vecR[1] = mtxA[3][1];
        vecR[2] = mtxA[3][2];
        vecR[2] = vecR[2] + w;
        func_800155EC(vecR, vecR, (f32)(pod->unk1E8 * 20.0), mtxA[1]);
    } else {
        func_800155EC(vecP, vecP,
                      -(mtxA[2][2] * vecP[2] +
                        (vecP[0] * mtxA[2][0] + vecP[1] * mtxA[2][1])),
                      mtxA[2]);
        func_800153C0(vecP);
        func_800154D0(vecP);
        func_800155EC(mtxB[3], mtxB[3], x, vecP);
        func_800155EC(mtxB[3], mtxB[3], y, mtxA[2]);
        func_80015288(vecQ, mtxB[3]);
        vecR[0] = mtxA[3][0];
        vecR[1] = mtxA[3][1];
        vecR[2] = mtxA[3][2];
        func_800155EC(vecR, vecR, w, mtxA[2]);
    }
    if (flagB == 0) {
        if (mtxA[1][2] < 0.0) {
            lean = mtxA[1][2] * (30.0f * mtxA[1][2]);
            if (lean > 20.0) {
                lean = 20.0f;
            }
            vecQ[2] = vecQ[2] + lean;
        }
    }
    func_80016F0C(actor->unkF4->unk20, euler);
    unit = euler[5] / 180.0f;
    if (flagB == 0) {
        cube = unit * unit * unit * 180.0f;
        quarter = euler[5] * 0.25;
        if (quarter < 0.0) {
            absQuarter = -quarter;
        } else {
            absQuarter = quarter;
        }
        if ((f64)(cube < 0.0f ? -cube : cube) <= absQuarter) {
            cube = (f32)quarter;
        }
    } else {
        cube = unit * 180.0f;
    }
    func_8001745C(mtxB[0], 0.0f, 0.0f, cube);
    func_80015288(mtxB[3], vecQ);
    func_800156DC(actor->unk224, mtxB);
    func_800156DC(mtxB, actor->unkF4->unk20);
    func_80015288(mtxB[3], vecR);
    func_800156DC(actor->unk264, mtxB);

    actor->unk20[0][0] = actor->unk224[0][0];
    actor->unk20[0][1] = actor->unk224[0][1];
    actor->unk20[0][2] = actor->unk224[0][2];
    actor->unk20[0][3] = actor->unk224[0][3];
    actor->unk20[1][0] = actor->unk224[1][0];
    actor->unk20[1][1] = actor->unk224[1][1];
    actor->unk20[1][2] = actor->unk224[1][2];
    actor->unk20[1][3] = actor->unk224[1][3];
    actor->unk20[2][0] = actor->unk224[2][0];
    actor->unk20[2][1] = actor->unk224[2][1];
    actor->unk20[2][2] = actor->unk224[2][2];
    actor->unk20[2][3] = actor->unk224[2][3];
    actor->unk20[3][0] = actor->unk224[3][0];
    actor->unk20[3][1] = actor->unk224[3][1];
    actor->unk20[3][2] = actor->unk224[3][2];
    actor->unk20[3][3] = actor->unk224[3][3];
    actor->unk108[0][0] = actor->unk264[0][0];
    actor->unk108[0][1] = actor->unk264[0][1];
    actor->unk108[0][2] = actor->unk264[0][2];
    actor->unk108[0][3] = actor->unk264[0][3];
    actor->unk108[1][0] = actor->unk264[1][0];
    actor->unk108[1][1] = actor->unk264[1][1];
    actor->unk108[1][2] = actor->unk264[1][2];
    actor->unk108[1][3] = actor->unk264[1][3];
    actor->unk108[2][0] = actor->unk264[2][0];
    actor->unk108[2][1] = actor->unk264[2][1];
    actor->unk108[2][2] = actor->unk264[2][2];
    actor->unk108[2][3] = actor->unk264[2][3];
    actor->unk108[3][0] = actor->unk264[3][0];
    actor->unk108[3][1] = actor->unk264[3][1];
    actor->unk108[3][2] = actor->unk264[3][2];
    actor->unk108[3][3] = actor->unk264[3][3];

    if (pod->unk60 & 0x00100000) {
        func_800156DC(mtxA, pod->unk20);
        mtxA[3][2] = mtxA[3][2] + pod->unk250;
        func_800156DC(actor->unk20, mtxA);
        func_800156DC(actor->unk108, mtxA);
        func_800155C0(actor->unk20[1], -1.0f, actor->unk20[1]);
        func_800155C0(actor->unk20[0], -1.0f, actor->unk20[0]);
        func_800155EC(actor->unk108[3], actor->unk108[3], -1.0f, mtxA[1]);
        func_800155EC(actor->unk20[3], actor->unk20[3],
                      pod->unkA8 + pod->unkA8, mtxA[1]);
        func_800155EC(actor->unk108[3], actor->unk108[3],
                      pod->unkA8 * D_800AAC8C, mtxA[2]);
        func_800155EC(actor->unk20[3], actor->unk20[3],
                      pod->unkA8 * D_800AAC90, mtxA[2]);
    }
}
