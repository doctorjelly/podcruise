/* Independently written from scratchpad spec specs/func_8006CA2C.md. */

#include "podcruise/types.h"

typedef struct Unk8006CA2CSub {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x18 - 0x11];
    /* 0x18 */ s32 *unk18;
} Unk8006CA2CSub;

typedef struct Unk8006CA2C {
    /* 0x0000 */ u8 pad0[0x60];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad68[0x98 - 0x68];
    /* 0x0098 */ f32 unk98;
    /* 0x009C */ u8 pad9C[0x270 - 0x9C];
    /* 0x0270 */ f32 unk270[6];
    /* 0x0288 */ f32 unk288[6];
    /* 0x02A0 */ s32 unk2A0[6];
    /* 0x02B8 */ u8 pad2B8[0x2BC - 0x2B8];
    /* 0x02BC */ f32 unk2BC;
    /* 0x02C0 */ f32 unk2C0;
    /* 0x02C4 */ u8 pad2C4[0x1E70 - 0x2C4];
    /* 0x1E70 */ Unk8006CA2CSub *unk1E70;
} Unk8006CA2C;

extern f64 D_80120BF0;
extern f32 D_800AD618;
extern f64 D_800AD628;
extern f32 D_800AD630;
extern u32 D_80000318;

extern void func_80031B70(Unk8006CA2C *, s32);
extern void func_80070764(Unk8006CA2C *, s32);
extern s32 func_80082BE0(void);
extern s32 func_80009524(s32, s32);
extern void func_8000953C(s32, s32);
extern void func_8000955C(s32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);

void func_8006CA2C(Unk8006CA2C *obj) {
    f32 peak;
    f32 base;
    s32 result;
    s32 frontHit;
    s32 rearHit;
    s32 i;
    s32 best;
    s32 fired;
    s32 tint;

    result = 0;
    frontHit = 0;
    rearHit = 0;
    fired = 0;

    obj->unk2BC -= (f32)D_80120BF0;
    if (obj->unk60 & 0x400) {
        obj->unk2BC = D_800AD618;
    }

    best = -1;
    for (i = 0; i < 6; i++) {
        obj->unk2A0[i] &= ~0x10;
        if (obj->unk2A0[i] & 4) {
            best = i;
        }
        obj->unk2A0[i] &= ~4;
    }

    if (obj->unk2BC > 0.0f) {
        if (best < 0) {
            peak = 0.0;
            for (i = 0; i < 6; i++) {
                if (peak < obj->unk288[i] && obj->unk288[i] > 0.5f) {
                    best = i;
                    peak = obj->unk288[i];
                }
            }
        }
        if (best >= 0) {
            if (obj->unk270[best] * 0.5 < obj->unk288[best]) {
                obj->unk2A0[best] |= 4;
            }
        }
        if (!(obj->unk64 & 0x40000)) {
            for (i = 0; i < 6; i++) {
                if (obj->unk2A0[i] & 8) {
                    obj->unk2A0[i] |= 0x10;
                }
            }
        }
    }

    for (i = 0; i < 6; i++) {
        if (obj->unk2A0[i] & 4) {
            base = obj->unk288[i];
            base += (obj->unk270[i] * 0.5f - obj->unk270[i]) * (0.5f * obj->unk98) * (f32)D_80120BF0;
            obj->unk288[i] = base;
            fired = 1;
        }
        if (obj->unk2A0[i] & 0x10) {
            if ((f32)func_80082BE0() / (f32)2147483648.0 < D_800AD628) {
                obj->unk2A0[i] &= ~8;
            }
        }
    }

    if (obj->unk60 & 0x20) {
        if (fired) {
            func_80031B70(obj, 2);
            if ((f32)func_80082BE0() / (f32)2147483648.0 < D_800AD630) {
                if (func_80009524(obj->unk1E70->unk10, 0x10000) == 0) {
                    if (!(D_80000318 < 0x800000) || (obj->unk60 & 0x120)) {
                        tint = obj->unk1E70->unk18[0];
                    } else {
                        tint = -1;
                    }
                    func_800093B0(1, tint, 10, 10, 10, 10, 10);
                    func_8000953C(obj->unk1E70->unk10, 0x10000);
                }
            }
        } else {
            if (func_80009524(obj->unk1E70->unk10, 0x10000)) {
                if (!(D_80000318 < 0x800000) || (obj->unk60 & 0x120)) {
                    tint = obj->unk1E70->unk18[0];
                } else {
                    tint = -1;
                }
                func_800093B0(1, tint, 11, 11, 11, 11, 11);
                func_8000955C(obj->unk1E70->unk10, 0x10000);
            }
        }
    }

    for (i = 0; i < 6; i++) {
        if (obj->unk288[i] >= 1.0) {
            if (i < 3) {
                frontHit = 1;
            } else {
                rearHit = 1;
            }
        }
    }

    if (frontHit || rearHit) {
        obj->unk2C0 -= (f32)D_80120BF0;
        if (obj->unk60 & 0x40000000) {
            obj->unk2C0 = 0.0f;
        }
    } else {
        obj->unk2C0 = (f32)func_80082BE0() / (f32)2147483648.0 * 4.0f + 6.0f;
    }

    if (obj->unk2C0 <= 0.0f) {
        if (frontHit && rearHit) {
            if ((f32)func_80082BE0() / (f32)2147483648.0 < 0.5f) {
                result = 1;
            } else {
                result = 2;
            }
        } else if (frontHit) {
            result = 1;
        } else if (rearHit) {
            result = 2;
        }
        func_80070764(obj, result);
    }
}
