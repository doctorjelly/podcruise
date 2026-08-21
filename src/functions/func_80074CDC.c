/* Independently written from $S/specs/func_80074CDC.md (control-surface update). */

#include "podcruise/types.h"

extern f32 D_800A5CA4[];
extern f32 D_800AD998;
extern f32 D_800AD99C;
extern f32 D_800AD9A0;
extern f32 D_800AD9A4;
extern f32 D_800AD9A8;
extern f32 D_800AD9AC;
extern f32 D_800AD9B0;
extern f32 D_800AD9B4;
extern f64 D_80120BF0;

extern f32 func_800154D0(f32 *vector);
extern void func_80014CC0(f32 angle, f32 *outB, f32 *outA);
extern void func_800155EC(f32 *out, f32 *base, f32 scale, f32 *offset);
extern void func_800745AC(u8 *obj);
extern void func_800747E4(u8 *obj);

void func_80074CDC(u8 *obj) {
    s32 i;
    u8 *part;
    f32 *out;
    s32 idx;
    f32 power;
    f32 sc[2];
    f32 coef;
    f32 mixed;
    f32 dot;
    f32 value;
    f32 wingA;
    f32 wingB;
    f32 limit;
    f32 vec[3];
    f32 mag;
    f32 d[3];

    if (*(s32 *)(obj + 0x344) == 0) {
        return;
    }
    idx = *(s32 *)(*(u8 **)(*(u8 **)(obj + 0x1E70) + 0x18));

    *(f32 *)(obj + 0x199C) = *(f32 *)(obj + 0x199C) + (f32)D_80120BF0;
    *(f32 *)(obj + 0x19A0) = *(f32 *)(obj + 0x19A0) + (f32)D_80120BF0;
    *(f32 *)(obj + 0x19A4) = *(f32 *)(obj + 0x19A4) + (f32)D_80120BF0;
    *(f32 *)(obj + 0x19A8) = *(f32 *)(obj + 0x19A8) + (f32)D_80120BF0;
    if (*(u32 *)(obj + 0x60) & 0x1000000) {
        *(f32 *)(obj + 0x19AC) = 1.0f;
    }
    if (200.0f < *(f32 *)(obj + 0x1A0)) {
        *(f32 *)(obj + 0x19AC) = *(f32 *)(obj + 0x19AC) - 0.5f * (f32)D_80120BF0;
    } else {
        *(f32 *)(obj + 0x19AC) = *(f32 *)(obj + 0x19AC) + 0.5f * (f32)D_80120BF0;
    }

    coef = D_800AD998;
    if (*(f32 *)(obj + 0x19AC) < coef) {
        *(f32 *)(obj + 0x19AC) = coef;
    } else if (1.0f < *(f32 *)(obj + 0x19AC)) {
        *(f32 *)(obj + 0x19AC) = 1.0f;
    }

    vec[0] = *(f32 *)(obj + 0x1DC) + *(f32 *)(obj + 0x1D0);
    vec[1] = *(f32 *)(obj + 0x1E0) + *(f32 *)(obj + 0x1D4);
    vec[2] = *(f32 *)(obj + 0x1E4) + *(f32 *)(obj + 0x1D8);
    mag = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
    if (0.5f < mag) {
        func_800154D0(vec);
        coef = D_800AD99C;
    } else {
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = 0.0f;
    }
    power = *(f32 *)(obj + 0x19AC) * coef;

    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x4) != 0) {
        func_80014CC0(*(f32 *)(obj + 0x199C) * D_800AD9A0 * 360.0f, &sc[1], &sc[0]);
        part = obj + 0x40;
        out = (f32 *)(part + 0x380);
        func_800155EC(out, out, power * sc[1], (f32 *)(part + 0x370));
        dot = vec[0] * *(f32 *)(part + 0x350) + vec[1] * *(f32 *)(part + 0x354) +
              *(f32 *)(part + 0x358) * vec[2];
        if (dot < 0.0f) {
            func_800155EC(out, out, mag / (mag + 30.0f), vec);
        }
        wingA = power * sc[1];
        power = *(f32 *)(obj + 0x19AC) * D_800AD9A4;
    }

    coef = D_800AD9A8;
    mixed = coef * D_800AD9AC;
    i = 1;
    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x8) != 0) {
        func_80014CC0(*(f32 *)(obj + i * 4 + 0x199C) * mixed * 360.0f, &sc[1], &sc[0]);
        part = obj + 0x80;
        out = (f32 *)(part + 0x380);
        func_800155EC(out, out, power * sc[1], (f32 *)(part + 0x370));
        dot = vec[0] * *(f32 *)(part + 0x350) + vec[1] * *(f32 *)(part + 0x354) +
              *(f32 *)(part + 0x358) * vec[2];
        if (0.0f < dot) {
            func_800155EC(out, out, mag / (mag + 30.0f), vec);
        }
        wingB = power * sc[1];
        coef = D_800AD9B0;
    }
    power = *(f32 *)(obj + 0x19AC) * coef;
    mixed = coef * D_800AD9B4;
    i = i + 1;

    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x14) != 0) {
        func_80014CC0(*(f32 *)(obj + i * 4 + 0x199C) * mixed * 360.0f, &sc[1], &sc[0]);
        part = obj + 0x140;
        func_800155EC((f32 *)(part + 0x380), (f32 *)(part + 0x380), power * sc[1], (f32 *)(part + 0x370));
    }
    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0xC) != 0) {
        part = obj + 0xC0;
        func_800155EC((f32 *)(part + 0x380), (f32 *)(part + 0x380), (wingA + wingA + wingB) * 0.5f,
                      (f32 *)(part + 0x370));
    }
    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x10) != 0) {
        part = obj + 0x100;
        func_800155EC((f32 *)(part + 0x380), (f32 *)(part + 0x380), (wingB + wingB + wingA) * 0.5f,
                      (f32 *)(part + 0x370));
    }

    func_800745AC(obj);
    func_800747E4(obj);

    if (*(s32 *)(*(u8 **)(*(u8 **)(obj + 0x1E70) + 0x18)) != 14) {
        part = obj + 0x140;
        value = D_800A5CA4[idx * 27] * 1.5f;
        if (value < 0.0f) {
            limit = -value;
        } else {
            limit = value;
        }
        if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x14) != 0) {
            d[0] = *(f32 *)(obj + 0x50) - *(f32 *)(part + 0x380);
            d[1] = *(f32 *)(obj + 0x54) - *(f32 *)(part + 0x384);
            d[2] = *(f32 *)(obj + 0x58) - *(f32 *)(part + 0x388);
            mag = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
            if (limit * limit < mag) {
                func_800155EC((f32 *)(part + 0x380), (f32 *)(part + 0x380),
                              func_800154D0(d) - limit, d);
            }
        }
    }
}
