/* Independently written from scratchpad spec specs/func_80050C00.md. */

#include "podcruise/types.h"

extern f32 sqrtf(f32 value);

#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

typedef struct {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s32 unk08;
} Actor80050C00;

extern s32 D_800A2198;
extern s32 D_800A4BDC;
extern f32 D_800A4BF4;
extern s32 D_800A5274;
extern f32 D_800AB354;
extern f32 D_800AB358;
extern f32 D_800AB35C;
extern f32 D_800AB360;
extern f32 D_80120BF8;

extern void func_80015288(f32 *, f32 *);
extern void func_8001535C(f32 *, f32 *, f32 *);
extern f32 func_80015390(f32 *, f32 *);
extern f32 func_800153C0(f32 *);
extern f32 func_800154D0(f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);

s32 func_80050C00(Actor80050C00 *actor, f32 *value, f32 *pointA, f32 *pointB,
                  f32 *pointC, f32 step) {
    f32 scaleA;
    f32 scaleB;
    f32 spanAB[3];
    f32 pushed[3];
    f32 spanAC[3];
    f32 spanCB[3];
    f32 half;
    f32 limit;
    f32 span;
    f32 current;
    f32 start[3];
    s32 kind;
    s32 flag;

    current = *value;
    scaleB = D_800AB354 * D_80120BF8;
    scaleA = 1600.0f;
    kind = actor->unk08;
    if (kind == 0x11 || kind == 0x12 || (kind == 8 && 5.0f <= D_800A4BF4)) {
        scaleA = 1600.0f * D_800AB358;
        scaleB = scaleB * D_800AB358;
    } else if (kind == 3) {
        if (D_800A4BDC == 0) {
            scaleA = 1600.0f * D_800AB35C;
            scaleB = scaleB * D_800AB35C;
        }
    } else if (kind == 0x10) {
        scaleA = 1600.0f * D_800AB360;
        scaleB = scaleB * D_800AB360;
    }

    func_80015288(start, pointB);
    scaleA = scaleA * step;
    D_800A5274 = 0;
    scaleB = scaleB * step;
    func_8001535C(spanAC, pointA, pointC);
    half = func_800153C0(spanAC) * 0.5f;
    func_8001535C(spanCB, pointC, pointB);
    func_800153C0(spanCB);
    func_8001535C(spanAB, pointA, pointB);
    span = func_800153C0(spanAB);

    flag = D_800A5274;
    limit = scaleB * 6.0f;
    if (half < limit) {
        limit = half;
    }
    if (limit <= span && current < scaleB) {
        current = current + 2000.0f * D_80120BF8 * step;
        if (scaleB < current) {
            current = scaleB;
        }
        if (flag == 0) {
        }
    } else if (limit <= span && scaleB <= current) {
        if (flag == 0) {
        }
    } else if (span < limit) {
        if (1.0f < span) {
            if (D_800A2198 != -1 && actor->unk08 != 0x12) {
                D_800A5274 = flag;
                return 1;
            }
            current = sqrtf(span / scaleA) * scaleA;
        }
    }

    D_800A5274 = flag;
    if (1.0f < span) {
        func_800154D0(spanAB);
        func_800155EC(pointB, pointB, current * D_80120BF8, spanAB);
        func_8001535C(pushed, pointA, pointB);
        if (func_80015390(spanAB, pushed) < 0.0f) {
            func_80015288(pointB, pointA);
            *value = 0.0f;
            return 1;
        }
        *value = current;
        return 0;
    }
    func_80015288(pointB, pointA);
    *value = 0.0f;
    return 1;
}
