/* Independently written from specs/functions/recovered/func_8006C0D4.md. */

#include "podcruise/types.h"

typedef struct PcCraft {
    u8 unk000[0x30];
    f32 unk030;
    f32 unk034;
    f32 unk038;
    u8 unk03C[0x4];
    f32 unk040[3];
    u8 unk04C[0x14];
    u32 unk060;
    u32 unk064;
    u8 unk068[0x10];
    f32 unk078;
    f32 unk07C;
    u8 unk080[0xEC];
    f32 unk16C[3];
    u8 unk178[0x28];
    f32 unk1A0;
    f32 unk1A4;
    u8 unk1A8[0xC4];
    s32 unk26C;
    u8 unk270[0x5C];
    f32 unk2CC[3];
    f32 unk2D8[3];
    f32 unk2E4[3];
    u8 unk2F0[0x18];
    f32 unk308;
    f32 unk30C;
    f32 unk310;
    u8 unk314[0x1684];
    s32 unk1998;
    u8 unk199C[0x53C];
    f32 unk1ED8;
} PcCraft;

extern f64 D_80120BF0;
extern f32 D_800AD5F4;

extern void func_80005B1C(s32 selector, s32 value);
extern s32 func_80005B44(s32 selector);
extern f32 func_800151C0(const f32 *vector);
extern f32 func_800153C0(const f32 *vector);
extern void func_800155C0(f32 *output, f32 scale, const f32 *source);
extern void func_80031C04(void *arg0);
extern void func_80066A80(void *arg0);
extern void func_80067AB4(void *body, void *context, f32 blend, void *owner);
extern void func_80067C70(void *arg0, f32 *arg1, void *arg2);
extern void func_80068AAC(void *obj);
extern f32 func_8006A49C(void *racer, f32 *point, void *ctx, f32 *out, void *owner);
extern f32 func_8006A9D4();
extern void func_8006ABD0(void *obj, f32 *origin);
extern void func_8006AF48(void *obj, f32 *arg1);
extern void func_8006BB50(void *actor, f32 arg1, f32 arg2);
extern void func_8006BC74(void *self);

void func_8006C0D4(PcCraft *craft) {
    f32 velocity[3];
    f32 push[3];
    f32 blend;
    f32 ratio;
    u32 flags;
    s32 airborne;
    s32 handle5;
    s32 handle3;
    f32 oldSpeed;
    f32 delta[3];

    handle5 = func_80005B44(5);
    if (150.0f < craft->unk1A0) {
        func_80005B1C(5, handle5 | 4);
    }
    handle3 = func_80005B44(3);
    func_80005B1C(3, craft->unk26C);

    if ((craft->unk060 & 0x02000000) != 0) {
        airborne = 1;
    } else {
        airborne = 0;
    }

    velocity[0] = craft->unk2CC[0];
    velocity[1] = craft->unk2CC[1];
    velocity[2] = craft->unk2CC[2];
    craft->unk064 = craft->unk064 & 0xDFFFFFFF;
    func_8006BC74(craft);

    if (airborne != 0) {
        func_800155C0(push, 1.0f, craft->unk040);
        blend = func_8006A9D4(craft, velocity, craft->unk16C, push, craft->unk2E4);
    } else {
        blend = func_8006A49C(craft, velocity, craft->unk16C, push, craft->unk2E4);
    }

    craft->unk2CC[0] = velocity[0];
    craft->unk2CC[1] = velocity[1];
    craft->unk2CC[2] = velocity[2];
    oldSpeed = craft->unk1A0;
    delta[0] = velocity[0] - craft->unk16C[0];
    delta[1] = velocity[1] - craft->unk16C[1];
    delta[2] = velocity[2] - craft->unk16C[2];

    flags = craft->unk060;
    if ((flags & 0x5000) != 0) {
        craft->unk1A0 = 0.0f;
    } else {
        if (airborne != 0 || (flags & 0x04000000) != 0) {
            craft->unk1A0 = func_800153C0(delta) / (f32)D_80120BF0;
        } else {
            craft->unk1A0 = func_800151C0(delta) / (f32)D_80120BF0;
        }
        if ((delta[0] * craft->unk030 + delta[1] * craft->unk034) + delta[2] * craft->unk038 < 0.0f) {
            craft->unk1A0 = -craft->unk1A0;
        }
    }

    if ((craft->unk064 & 0x4000) != 0) {
        craft->unk310 = (f32)((f64)craft->unk310 - D_80120BF0);
        if (craft->unk1A0 < 200.0f) {
            craft->unk060 |= 0x1000;
        }
        if (craft->unk310 < 0.0f) {
            craft->unk060 |= 0x1000;
        }
    }

    if ((craft->unk060 & 0x80) != 0 && (craft->unk064 & 0x04000000) == 0) {
        craft->unk064 = craft->unk064 & 0xEFFFFFFF;
    } else {
        func_8006BB50(craft, oldSpeed, oldSpeed - craft->unk1A0);
    }

    flags = craft->unk060;
    if ((flags & 0x00040000) != 0) {
        craft->unk060 = flags & 0xFFFBFFFF;
        if (0.0f < craft->unk1A4) {
            if (craft->unk07C < craft->unk1A0) {
                craft->unk1A4 = D_800AD5F4;
            } else {
                if (craft->unk1A0 < 0.0f) {
                    ratio = 0.0f;
                } else {
                    ratio = (craft->unk1A0 * craft->unk078) / (craft->unk07C - craft->unk1A0);
                }
                if (ratio < craft->unk1A4) {
                    craft->unk1A4 = ratio;
                }
            }
        }
    }

    func_80068AAC(craft);

    if (airborne == 0) {
        if ((f64)(((f32)craft->unk1998 - 400.0f) / 600.0f) < 1.0 || (craft->unk060 & 0x20) != 0 ||
            (craft->unk064 & 0x04000000) != 0) {
            func_80067AB4(craft, push, blend, craft->unk2E4);
        }
        craft->unk2E4[0] = craft->unk2E4[0] - craft->unk2D8[0];
        craft->unk2E4[1] = craft->unk2E4[1] - craft->unk2D8[1];
        craft->unk2E4[2] = craft->unk2E4[2] - craft->unk2D8[2];
    }

    if ((craft->unk060 & 0x04000000) != 0 || airborne != 0) {
        func_8006AF48(craft, velocity);
    } else {
        func_80067C70(craft, velocity, craft->unk2E4);
    }

    func_80066A80(craft);
    func_8006ABD0(craft, velocity);

    if (0.0f < craft->unk308) {
        craft->unk308 = (f32)((f64)craft->unk308 - D_80120BF0);
    }
    if (0.0f < craft->unk30C) {
        craft->unk30C = (f32)((f64)craft->unk30C - D_80120BF0);
    }

    if ((craft->unk060 & 0x2000) != 0) {
        if (craft->unk30C <= 0.0f) {
            craft->unk060 &= ~0x2000;
            craft->unk064 = craft->unk064 | 0x00200000;
        }
    } else if ((craft->unk060 & 0x4000) != 0) {
        if ((craft->unk060 & 0x80) != 0) {
            if (craft->unk30C <= 0.0f) {
                craft->unk060 &= ~0x4000;
                craft->unk060 |= 0x2000;
                craft->unk30C = 3.0f;
            }
        }
    }

    if (airborne == 0) {
        flags = craft->unk060;
        if ((flags & 0x04000000) != 0) {
            if (blend < 12.0f) {
                craft->unk060 = flags & 0xFBFFFFFF;
            }
        }
    }

    craft->unk1ED8 = 0.0f;
    flags = craft->unk060;
    if ((flags & 0x20) != 0) {
        func_80031C04(craft);
    }
    func_80005B1C(5, handle5);
    func_80005B1C(3, handle3);
}
