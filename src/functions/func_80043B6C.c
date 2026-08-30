/* Independently written from scratchpad spec specs/func_80043B6C.md. */
#include "podcruise/types.h"

typedef struct Object80043B6C {
    u8 unk00[0x58];
    f32 unk58;
    u8 unk5C[0x74 - 0x5C];
    s32 unk74;
    u8 unk78[0x7C - 0x78];
    s32 unk7C;
    u8 unk80[0x140 - 0x80];
    f32 unk140;
    u8 unk144[0x2A4 - 0x144];
    void *unk2A4;
    u8 unk2A8[0x39C - 0x2A8];
    f32 unk39C;
    f32 unk3A0;
    f32 unk3A4;
} Object80043B6C;

extern f64 D_80120BF0;
extern s32 D_800A4AB0;

extern void func_80043598(void *object);
extern void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_800319F4(s32 arg0, s32 arg1);
extern s32 func_80051FF4(void);
extern void func_800438BC(void *object);

void func_80043B6C(Object80043B6C *object) {
    register Object80043B6C *o;

    o = object;
    func_80043598(o);
    if (o->unk3A4 > 0) {
        o->unk39C = (f32)((f64)o->unk39C + (f64)o->unk3A0 * D_80120BF0);
        if (o->unk3A4 < o->unk39C || o->unk3A4 < -o->unk39C) {
            o->unk3A0 = -o->unk3A0;
            if (o->unk39C > 0.0f) {
                o->unk39C = o->unk3A4;
            } else {
                o->unk39C = -o->unk3A4;
            }
        }
        o->unk140 += o->unk39C;
        o->unk58 += o->unk39C / 2.0f;
        func_80008B14(7, 7, 0.25f, 1.0f, 1);
        func_800319F4(0, 0xA);
        if (func_80051FF4() >= 2) {
            func_800319F4(1, 0xA);
        }
    }
    if (o->unk7C != 0 && o->unk74 >= 0 && D_800A4AB0 != 0) {
        func_800438BC(o->unk2A4);
    }
}
