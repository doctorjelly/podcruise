/* Independently written from $S/specs/func_800672D4.md. */
#include "podcruise/types.h"

typedef struct Racer {
    /* 0x000 */ u8 unk000[0x28];
    /* 0x028 */ f32 unk028;
    /* 0x02C */ u8 unk02C[0x34];
    /* 0x060 */ u32 unk060;
    /* 0x064 */ u32 unk064;
    /* 0x068 */ u8 unk068[0x2C];
    /* 0x094 */ f32 unk094;
    /* 0x098 */ u8 unk098[0xC];
    /* 0x0A4 */ f32 unk0A4;
    /* 0x0A8 */ f32 unk0A8;
    /* 0x0AC */ u8 unk0AC[0xB4];
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16C */ u8 unk16C[0x24];
    /* 0x190 */ f32 unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19C */ f32 unk19C;
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ u8 unk1A4[0xC];
    /* 0x1B0 */ f32 unk1B0;
    /* 0x1B4 */ f32 unk1B4;
    /* 0x1B8 */ u8 unk1B8[0x110];
    /* 0x2C8 */ f32 unk2C8;
    /* 0x2CC */ u8 unk2CC[0x30];
    /* 0x2FC */ f32 unk2FC;
} Racer;

typedef struct Message {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ f32 unk8;
} Message;

extern void func_8003F99C(Racer *racer, Message *message);
extern void func_80081700(f32 a, f32 b);
extern f64 D_80120BF0;
extern f32 D_800AD4C4;
extern f32 D_800AD4C8;

void func_800672D4(Racer *racer, f32 *output, f32 amount) {
    f32 span;
    f32 base;
    f32 lean;
    f32 reach;
    f32 pitch;
    f32 grip;
    f32 previous;
    f32 rate;
    f32 force;
    f32 scratch[4];
    Message message;
    f32 spare[3];
    f32 direction[3];

    (void)scratch;
    (void)spare;

    if (racer->unk064 & 0x400) {
        direction[0] = -racer->unk160;
        direction[1] = -racer->unk164;
        direction[2] = -racer->unk168;
    } else {
        direction[0] = racer->unk194;
        direction[1] = racer->unk198;
        direction[2] = racer->unk19C;
    }

    span = racer->unk094 - racer->unk0A4;
    base = amount - racer->unk0A4;
    reach = base;
    pitch = racer->unk028;
    grip = racer->unk0A8;
    lean = ((pitch < 0.0f) ? -pitch : pitch) * grip;
    if (3.0f < lean) {
        reach = base - (lean - 3.0f);
    }

    if (D_800AD4C4 < amount) {
        racer->unk2C8 = racer->unk2C8 + (f32)D_80120BF0;
        if (0.0f < racer->unk2C8) {
            racer->unk060 = racer->unk060 | 0x1000;
        }
    } else {
        racer->unk2C8 = 0.0f;
    }

    if (30.0f < amount) {
        racer->unk064 = racer->unk064 | 0x200;
    } else {
        racer->unk064 = racer->unk064 & ~0x200;
    }

    if (12.0f < reach) {
        if (0.0f <= racer->unk1A0) {
            racer->unk1B4 = (f32)(racer->unk1B4 + D_80120BF0);
        } else {
            racer->unk1B4 = (f32)(racer->unk1B4 + 2.0 * D_80120BF0);
        }
    } else {
        racer->unk1B4 = racer->unk1B4 + (1.0f - (12.0f - reach) / (12.0f - span)) * (f32)D_80120BF0;
        if (span < reach) {
            if (racer->unk1B4 < 0.0f) {
                func_80081700(4.0f, (f32)D_80120BF0);
                racer->unk1B4 = racer->unk1B4 * 12.0f;
            }
        }
    }

    racer->unk1B0 = (f32)D_80120BF0 * 30.0f * racer->unk190 * racer->unk1B4;
    if (racer->unk2FC < 0.0f) {
        if (0.0f <= racer->unk1A0) {
            if (0.0f < racer->unk1B0) {
                racer->unk1B0 = racer->unk1B0 * (racer->unk2FC * D_800AD4C8 + 1.0f);
            }
        }
    }

    if (reach < racer->unk1B0) {
        previous = (f32)(racer->unk1B0 / D_80120BF0);
        rate = racer->unk1B4;
        racer->unk1B0 = reach;
        force = rate * 8.0f;
        if (0.0f < rate) {
            racer->unk1B4 = -(rate / 5.0f);
        }
        if (4.0f < force) {
            if (!(racer->unk060 & 0x1000000)) {
                message.unk0 = 0x48697474;
                message.unk4 = 0x426F746D;
                message.unk8 = previous * 0.5f;
                func_8003F99C(racer, &message);
            }
        }
        racer->unk060 = racer->unk060 | 0x1000000;
    } else {
        racer->unk060 = racer->unk060 & ~0x1000000;
    }

    output[0] = output[0] + direction[0] * racer->unk1B0;
    output[1] = output[1] + direction[1] * racer->unk1B0;
    output[2] = output[2] + direction[2] * racer->unk1B0;
}
