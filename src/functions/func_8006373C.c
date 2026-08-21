/* Independently written from scratchpad spec specs/func_8006373C.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    s32 pad00[2];
    s32 unk08;
    s32 pad0C[14];
    PcVec3f unk44;
    PcVec3f unk50;
    s32 pad5C[3];
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    s32 pad78[8];
    f32 unk98;
    f32 unk9C;
    s32 unkA0;
} PcTurner;

extern s32 D_800A5B34;
extern f32 D_800A5124[];
extern f32 D_80120BF8;

extern void func_8001535C(PcVec3f *out, PcVec3f *left, PcVec3f *right);
extern f32 func_800153C0(PcVec3f *vector);
extern f32 func_80014F54(f32 x, f32 y);
extern s32 func_800636D0(PcTurner *entry);
extern void func_80060DE4(PcTurner *entry, s32 code);

void func_8006373C(PcTurner *entry) {
    PcVec3f delta;
    f32 angle;
    f32 diff;
    f32 rate;
    f32 quotient;

    if (D_800A5B34 > 0) {
        D_800A5B34 = D_800A5B34 - 1;
        return;
    }

    func_8001535C(&delta, &entry->unk50, &entry->unk44);
    if (entry->unk08 == 2) {
        delta.z = 0.0f;
    }
    if (func_800153C0(&delta) <= 35.0f) {
        if (entry->unk44.z == -145.0f) {
            entry->unkA0 = 1;
        }
    }

    if (entry->unkA0 != 0) {
        angle = entry->unk6C;
    } else {
        angle = func_80014F54(-delta.x, delta.y);
        func_800636D0(entry);
    }

    diff = angle - entry->unk68;
    if (diff < -180.0f) {
        diff = diff + 360.0f;
    }
    if (diff > 180.0f) {
        diff = diff - 360.0f;
    }
    if (entry->unk44.z == -60.0f) {
        rate = 2.0f;
    } else {
        rate = 1.0f;
    }

    if ((diff > 5.0f) || (diff < -5.0f)) {
        entry->unk98 = diff * 2.0f / (f32)180.0 * rate;
        if (entry->unk98 < 0.0f) {
            entry->unk98 = -entry->unk98;
        }
        entry->unk9C = (f32)0.0;
        entry->unk74 = diff;
        entry->unk70 = entry->unk68;
    } else {
        entry->unk68 = angle;
        if (entry->unk08 == 2) {
            if (entry->unkA0 != 0) {
                func_80060DE4(entry, 0x11);
            } else {
                func_80060DE4(entry, 0x13);
            }
        } else if (entry->unk08 == 3) {
            if (entry->unkA0 != 0) {
                if (entry->unk50.x == D_800A5124[0]) {
                    func_80060DE4(entry, 0x1F);
                } else {
                    func_80060DE4(entry, 0x1D);
                }
            } else {
                func_80060DE4(entry, 0x1E);
            }
        } else if (entry->unk08 == 1) {
            func_80060DE4(entry, 0xA);
        }
        return;
    }

    if (entry->unk9C < entry->unk98) {
        entry->unk9C = entry->unk9C + D_80120BF8;
        if (entry->unk9C > entry->unk98) {
            entry->unk9C = entry->unk98;
        }
        quotient = entry->unk70 + entry->unk74 * (entry->unk9C / entry->unk98);
        entry->unk68 = quotient;
        if (entry->unk68 < -180.0f) {
            entry->unk68 = entry->unk68 + 360.0f;
        }
        if (entry->unk68 > 180.0f) {
            entry->unk68 = entry->unk68 - 360.0f;
        }
    }
}
