/* Independently written from specs/functions/recovered/func_8006DB1C.md. */
#include "podcruise/types.h"

typedef struct PodMode {
    u8 pad00[0x5C];
    s16 unk5C;
} PodMode;

typedef struct Pod {
    u8 pad00[0x60];
    s32 unk60;
    s32 unk64;
    u8 pad68[0x8];
    f32 unk70;
    f32 unk74;
    u8 pad78[0x90];
    f32 unk108;
    u8 pad10C[0x20];
    f32 unk12C;
    f32 unk130;
    f32 unk134;
    f32 unk138;
    u8 pad13C[0xF0];
    f32 unk22C;
    f32 unk230;
    f32 unk234;
    s32 unk238;
    s32 unk23C;
    u8 pad240[0x1C30];
    PodMode *unk1E70;
} Pod;

extern f32 D_800A5B60;
extern f32 D_800A5B64;
extern f32 D_800A5B68;
extern f32 D_800AD6B8;
extern f32 D_800AD6BC;
extern f32 D_800AD6C0;
extern f32 D_800AD6C4;
extern f32 D_800AD6C8;
extern f32 D_800AD6CC;
extern f32 D_800AD6D0;
extern f32 D_800AD6D4;
extern f32 D_800AD6D8;
extern f32 D_800AD6DC;
extern f32 D_800AD6E0;
extern f32 D_800AD6E4;
extern f32 D_800AD6E8;
extern f32 D_800AD6EC;
extern f32 D_800AD6F0;
extern f32 D_800AD6F4;
extern f64 D_800AD6F8;
extern f64 D_800AD700;
extern f64 D_80120BF0;
extern f32 func_8007EE40(void);
extern s32 func_80082BE0(void);

void func_8006DB1C(Pod *pod) {
    f32 spare[4];
    f32 scaleA;
    f32 scaleB;
    f32 product;
    f32 value;
    f32 limit;
    s32 count;

    (void)spare;
    pod->unk230 = D_800A5B64;
    if (pod->unk64 & 0x2000000) {
        pod->unk230 = D_800AD6BC;
        if (pod->unk108 > D_800AD6B8) {
            pod->unk108 = pod->unk108 - 100.0 * D_80120BF0;
        } else {
            pod->unk108 = D_800AD6B8;
        }
        pod->unk70 = D_800AD6C0;
        pod->unk74 = 400.0f;
    } else {
        scaleA = D_800AD6C4 / func_8007EE40();
        scaleB = D_800A5B68 / D_800AD6C8;
        product = scaleB * scaleA;
        if (pod->unk60 & 0x100) {
            pod->unk138 = 0.0f;
            if (pod->unk1E70->unk5C == 1) {
                pod->unk230 = pod->unk230 * D_800AD6CC;
            } else if (product * 3.0f < pod->unk130) {
                pod->unk230 = pod->unk230 * D_800AD6D0;
            } else {
                pod->unk230 = pod->unk230 * D_800AD6D4;
            }
        } else if (pod->unk1E70->unk5C == 1) {
            pod->unk138 = 0.0f;
        } else {
            pod->unk234 = pod->unk234 - D_80120BF0;
            if (pod->unk234 < 0.0f) {
                pod->unk234 = ((f32)func_80082BE0() / (f32)2147483648.0) * 10.0f + 8.0f;
                value = (f32)func_80082BE0() / (f32)2147483648.0;
                if (value < D_800AD6D8) {
                    count = pod->unk23C - 1;
                    pod->unk23C = count;
                    if (count < 2 || count - pod->unk238 >= 3 || -(count - pod->unk238) >= 3) {
                        pod->unk23C = count + 1;
                    }
                } else if (D_800AD6DC < value) {
                    count = pod->unk23C + 1;
                    pod->unk23C = count;
                    if (count - pod->unk238 >= 3 || -(count - pod->unk238) >= 3) {
                        pod->unk23C = count - 1;
                    }
                }
            }
            if (0.0f < D_800A5B60) {
                pod->unk230 = pod->unk230 * D_800AD6E0;
                pod->unk230 = pod->unk230 * (1.0f - ((f32)pod->unk23C - 1.0f) * D_800A5B60);
            } else {
                pod->unk138 = (((f32)pod->unk23C - 1.0f) * scaleB + D_800AD6E4) * scaleA;
                if (product * 0.25f < pod->unk12C && (pod->unk60 & 0x18000)) {
                    if (pod->unk60 & 0x8000) {
                        limit = pod->unk130;
                    } else {
                        limit = pod->unk134;
                    }
                    if (0.0f < limit) {
                        value = D_800AD6E8 * limit;
                    } else {
                        value = D_800AD6EC * limit;
                    }
                } else {
                    value = (pod->unk12C - pod->unk138) * 10.0f;
                }
                value = value * 40.0f / scaleA + D_800AD6F4;
                if (D_800AD6F0 < value) {
                    value = D_800AD6F0;
                }
                if (value < 0.5f) {
                    value = 0.5f;
                }
                pod->unk230 = value;
            }
        }
    }
    if (pod->unk22C < pod->unk230) {
        pod->unk22C = pod->unk22C + D_800AD6F8 * D_80120BF0;
        if (pod->unk230 < pod->unk22C) {
            pod->unk22C = pod->unk230;
        }
    } else if (pod->unk230 < pod->unk22C) {
        pod->unk22C = pod->unk22C - D_800AD700 * D_80120BF0;
        if (pod->unk22C < pod->unk230) {
            pod->unk22C = pod->unk230;
        }
    }
}
