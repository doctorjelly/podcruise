/* Recovered per scratchpad spec specs/func_8007B06C.md. */
#include "podcruise/types.h"

typedef struct PcScrollState PcScrollState;

typedef struct {
    /* 0x00 */ s32 unk00[8];
    /* 0x20 */ f32 unk20[4][4];
    /* 0x60 */ s32 unk60[2];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 unk71;
    /* 0x72 */ u8 unk72;
    /* 0x73 */ u8 unk73;
    /* 0x74 */ PcScrollState *unk74;
    /* 0x78 */ void *unk78;
} Obj8007B06C;

extern f64 D_80120BF0;

extern void func_8000E9BC(u8 **owner, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, const void *source);
extern void func_8003E0A0(PcScrollState *state, f32 stepU, f32 stepV);

void func_8007B06C(Obj8007B06C *obj) {
    struct { f32 m[4][4]; } mtx;
    f32 k2 = 2.0f;
    f32 k35 = 3.5f;
    f32 k05 = 0.5f;
    f32 k6 = 6.0f;
    f32 ratio;
    f32 scale;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (obj->unk78 == 0) {
        return;
    }
    if (obj->unk6C == 0.0f) {
        return;
    }
    ratio = obj->unk68 / obj->unk6C;
    if (obj->unk74 != 0) {
        a = obj->unk70;
        b = obj->unk71;
        c = obj->unk72;
        d = obj->unk73;
        if (ratio < 0.25f) {
            d = (s32)((f32)d * (ratio * 4.0f));
        }
        a = (a > 0) ? ((a < 255) ? a : 254) : 1;
        b = (b > 0) ? ((b < 255) ? b : 254) : 1;
        c = (c > 0) ? ((c < 255) ? c : 254) : 1;
        d = (d > 0) ? ((d < 255) ? d : 254) : 1;
        func_8000E9BC((u8 **)obj->unk74, 0, 0, a, b, c, d);
        func_8003E0A0(obj->unk74, 0.0f, (k2 * k35 + k05) * (f32)D_80120BF0);
    }
    scale = k6 * (1.0f - ratio) + 0.5f;
    func_80017918(mtx.m, 2.0f, scale, scale, obj->unk20);
    func_80017BA8(obj->unk78, &mtx);
}
