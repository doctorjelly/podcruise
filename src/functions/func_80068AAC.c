/* Implements the specification in specs/func_80068AAC.md (timed effect slot refresh). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x60];
    u32 unk60;
    u32 unk64;
    u8 pad68[0x8C - 0x68];
    f32 unk8C;
    f32 unk90;
    u8 pad94[0x208 - 0x94];
    f32 unk208;
    u8 pad20C[0x218 - 0x20C];
    f32 unk218;
    u8 pad21C[0x2A0 - 0x21C];
    s32 unk2A0[1];
} Obj80068AAC;

extern f64 D_80120BF0;
extern s32 func_80082BE0(void);
extern void func_80075648(Obj80068AAC *, s32, f32 *, f32);

void func_80068AAC(Obj80068AAC *obj) {
    f32 vec[3];
    s32 ret;
    s32 index;

    ret = 0;
    if (obj->unk64 & 0x40000) {
        obj->unk218 -= 20.0f * (f32)D_80120BF0;
        if (obj->unk208 < -0.5f) {
            ret = -1;
        } else if (0.5f < obj->unk208) {
            ret = 1;
        }
    } else if (obj->unk60 & 0x800000) {
        obj->unk218 -= obj->unk8C * (f32)D_80120BF0;
    } else {
        obj->unk218 += obj->unk90 * (f32)D_80120BF0;
    }

    if (100.0f <= obj->unk218) {
        obj->unk218 = 100.0f;
    }

    if (obj->unk218 <= 0.0f) {
        obj->unk218 = 0.0f;
        if (ret < 0) {
            index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 3.0f);
        } else if (ret > 0) {
            index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 3.0f) + 3;
        } else {
            index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 6.0f);
        }
        if (!(obj->unk2A0[index] & 8)) {
            vec[0] = 0.0;
            vec[1] = 0.0;
            vec[2] = 0.0;
            func_80075648(obj, 2 - index / 3, vec, 0.1f);
        }
        obj->unk2A0[index] |= 8;
        obj->unk60 &= 0xFF7FFFFF;
    }
}
