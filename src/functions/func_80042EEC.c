/* Recovered from specification: specs/func_80042EEC.md (scratchpad) */
#include "podcruise/types.h"

typedef struct {
    u8 unk_000[0x74];
    s32 unk_074;
    u8 unk_078[0x2A8 - 0x78];
    s32 unk_2A8;
    u8 unk_2AC[0x2B0 - 0x2AC];
    f32 unk_2B0;
    f32 unk_2B4;
    f32 unk_2B8;
    s32 unk_2BC;
    s32 unk_2C0;
    s32 unk_2C4;
    s32 unk_2C8;
    s32 unk_2CC;
    s32 unk_2D0;
    f32 unk_2D4;
    f32 unk_2D8;
    f32 unk_2DC;
    f32 unk_2E0;
} Actor;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} Record;

extern s32 D_800A4AB4;
extern s32 D_800A4AB8;
extern s32 D_800A4ABC;
extern f32 D_800A4AC0;
extern f32 D_800A4AC4;
extern f32 D_800A4AC8;
extern s32 D_800A4ACC;
extern s32 D_800A4AD0;
extern s32 D_800A52B8;
extern s32 D_800A6950;
extern f64 D_80120BF0;
extern s32 D_801210D0;
extern Record D_80148B48[];

extern void func_80038DBC(s32 arg0);
extern void func_80038DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_80060C6C(void *arg0, u32 flags);
extern void func_80086730(s32 index, f32 fov, f32 aspect, f32 near, f32 far, f32 scale);
extern void func_80086CC8(s32 first, s32 second, s32 third);

/* Eight bytes of stand-in constant pool: in the retail object the double
 * literals below are preceded by a neighbouring unit's constants, which is
 * what places this pool at a non-16-aligned address. */
static const f64 D_padStandIn[1] = { 0.0 };
static const f64 *const D_padStandInRef = D_padStandIn;

void func_80042EEC(Actor *actor) {
    f32 fade;
    f32 bright;
    f32 shake;
    f32 tilt;
    s32 flash;
    s32 flashValue;

    if (D_800A4AB8 != 0) {
        tilt = D_800A4AC8;
        fade = D_800A4AC4;
    } else {
        if (actor->unk_2A8 & 1) {
            if (actor->unk_2D8 > 0.0f) {
                if (actor->unk_2D4 > actor->unk_2D8) {
                    actor->unk_2D4 = actor->unk_2D4 - 2000.0 * D_80120BF0;
                    if (actor->unk_2D4 < actor->unk_2D8) {
                        actor->unk_2D4 = actor->unk_2D8;
                        actor->unk_2D8 = -1.0f;
                    }
                } else {
                    actor->unk_2D4 = actor->unk_2D4 + 2000.0 * D_80120BF0;
                    if (actor->unk_2D4 > actor->unk_2D8) {
                        actor->unk_2D4 = actor->unk_2D8;
                        actor->unk_2D8 = -1.0f;
                    }
                }
            }
            fade = actor->unk_2D4;
        } else {
            fade = -1.0f;
        }
        tilt = actor->unk_2B4;
        D_800A4AC8 = tilt;
        D_800A4AC4 = fade;
    }

    if (D_800A4ABC != 0) {
        bright = D_800A4AC0;
    } else {
        bright = actor->unk_2B0;
        D_800A4AC0 = bright;
    }

    shake = actor->unk_2B8;

    if (D_800A4AB4 != 0) {
        flash = D_800A4ACC;
        flashValue = D_800A4AD0;
    } else {
        flash = actor->unk_2A8 & 2;
        if (flash != 0) {
            if (actor->unk_2E0 >= 0.0f) {
                if (actor->unk_2DC > actor->unk_2E0) {
                    actor->unk_2DC = actor->unk_2DC - 5.0 * D_80120BF0;
                    if (actor->unk_2DC < actor->unk_2E0) {
                        actor->unk_2DC = actor->unk_2E0;
                        actor->unk_2E0 = -1.0f;
                    }
                } else {
                    actor->unk_2DC = actor->unk_2DC + 5.0 * D_80120BF0;
                    if (actor->unk_2DC > actor->unk_2E0) {
                        actor->unk_2DC = actor->unk_2E0;
                        actor->unk_2E0 = -1.0f;
                    }
                }
            }
        }
        flashValue = actor->unk_2DC;
        D_800A4ACC = flash;
        D_800A4AD0 = flashValue;
    }

    if (bright >= 0.0 || shake >= 0.0 || tilt >= 0.0 || fade >= 0.0) {
        if (D_800A52B8 != 0 && (D_801210D0 & 1)) {
            func_80086730(actor->unk_074, 120.0f, -1.0f, tilt, fade, shake);
        } else {
            func_80086730(actor->unk_074, bright, -1.0f, tilt, fade, shake);
        }
    }

    if (actor->unk_2A8 & 0x10) {
        actor->unk_2BC = actor->unk_2C8;
        actor->unk_2C0 = actor->unk_2CC;
        actor->unk_2C4 = actor->unk_2D0;
    } else {
        if (actor->unk_2BC > actor->unk_2C8) {
            actor->unk_2BC = actor->unk_2BC - 195.0 * D_80120BF0;
            if (actor->unk_2BC < actor->unk_2C8) {
                actor->unk_2BC = actor->unk_2C8;
            }
        } else if (actor->unk_2BC < actor->unk_2C8) {
            actor->unk_2BC = actor->unk_2BC + 195.0 * D_80120BF0;
            if (actor->unk_2BC > actor->unk_2C8) {
                actor->unk_2BC = actor->unk_2C8;
            }
        }
        if (actor->unk_2C0 > actor->unk_2CC) {
            actor->unk_2C0 = actor->unk_2C0 - 195.0 * D_80120BF0;
            if (actor->unk_2C0 < actor->unk_2CC) {
                actor->unk_2C0 = actor->unk_2CC;
            }
        } else if (actor->unk_2C0 < actor->unk_2CC) {
            actor->unk_2C0 = actor->unk_2C0 + 195.0 * D_80120BF0;
            if (actor->unk_2C0 > actor->unk_2CC) {
                actor->unk_2C0 = actor->unk_2CC;
            }
        }
        if (actor->unk_2C4 > actor->unk_2D0) {
            actor->unk_2C4 = actor->unk_2C4 - 195.0 * D_80120BF0;
            if (actor->unk_2C4 < actor->unk_2D0) {
                actor->unk_2C4 = actor->unk_2D0;
            }
        } else if (actor->unk_2C4 < actor->unk_2D0) {
            actor->unk_2C4 = actor->unk_2C4 + 195.0 * D_80120BF0;
            if (actor->unk_2C4 > actor->unk_2D0) {
                actor->unk_2C4 = actor->unk_2D0;
            }
        }
    }

    if (flash != 0) {
        actor->unk_2A8 = actor->unk_2A8 & ~0x10;
        func_80038DBC(1);
        func_80038DF8(flashValue, 1000, actor->unk_2BC, actor->unk_2C0, actor->unk_2C4, 255);
        func_80086CC8(actor->unk_2BC, actor->unk_2C0, actor->unk_2C4);
    } else {
        func_80038DBC(0);
    }
    func_80060C6C(&actor->unk_000[0x50], actor->unk_2A8);

    if (D_800A6950 != 0) {
        if (actor->unk_2A8 & 4) {
            D_80148B48[actor->unk_074 - 1].unk_0A = 0;
        } else {
            D_80148B48[actor->unk_074 - 1].unk_0A = 1;
        }
        if (flash != 0) {
            D_80148B48[actor->unk_074 - 1].unk_00 = 1;
            D_80148B48[actor->unk_074 - 1].unk_02 = flashValue;
            D_80148B48[actor->unk_074 - 1].unk_04 = actor->unk_2BC;
            D_80148B48[actor->unk_074 - 1].unk_06 = actor->unk_2C0;
            D_80148B48[actor->unk_074 - 1].unk_08 = actor->unk_2C4;
        } else {
            D_80148B48[actor->unk_074 - 1].unk_00 = 0;
        }
    }
}
