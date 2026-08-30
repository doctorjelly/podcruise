/* Independently written from specs/functions/recovered/func_8006B568.md. */
#include "podcruise/types.h"

typedef struct Obj8006B568 {
    u8 pad000[0x20];
    f32 unk20[4];
    f32 unk30[4];
    f32 unk40[4];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[0x60 - 0x5C];
    s32 unk60;
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    f32 unk70;
    u8 pad74[0xEC - 0x74];
    s32 unkEC;
    u8 padF0[0x140 - 0xF0];
    s32 unk140;
    u8 pad144[0x16C - 0x144];
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x194 - 0x178];
    f32 unk194[3];
    f32 unk1A0;
    u8 pad1A4[0x1EC - 0x1A4];
    f32 unk1EC;
    f32 unk1F0;
    f32 unk1F4;
    f32 unk1F8;
    f32 unk1FC;
    u8 pad200[0x208 - 0x200];
    f32 unk208;
    u8 pad20C[0x220 - 0x20C];
    f32 unk220;
    f32 unk224;
    u8 pad228[0x22C - 0x228];
    f32 unk22C;
    u8 pad230[0x244 - 0x230];
    f32 unk244;
    f32 unk248;
    u8 pad24C[0x26C - 0x24C];
    s32 unk26C;
    u8 pad270[0x2CC - 0x270];
    f32 unk2CC;
    f32 unk2D0;
    f32 unk2D4;
    f32 unk2D8;
    f32 unk2DC;
    f32 unk2E0;
    f32 unk2E4;
    f32 unk2E8;
    f32 unk2EC;
} Obj8006B568;

extern s32 D_800A5B5C;
extern f32 D_800AD5E4;
extern f32 D_8011C850;
extern f64 D_80120BF0;

extern void func_80005B1C(s32, s32);
extern s32 func_80005B44(s32);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_80033328(f32 *, f32 *, f32, f32, f32, f32);
extern void func_80065CD0(f32 *, f32 *, f32 *, f32 *);
extern void func_80065E18(Obj8006B568 *);
extern void func_8006907C(Obj8006B568 *, f32 *, f32 *, f32 *);
extern void func_8006B304(Obj8006B568 *);
extern s32 func_8006C708(Obj8006B568 *);
extern f32 func_80081700(f32, f32);

void func_8006B568(Obj8006B568 *obj) {
    f32 result[3];
    s32 handleA;
    s32 handleB;
    s32 detached;
    f32 *origin;
    f32 *offset;

    handleA = func_80005B44(5);
    if (obj->unk1A0 > 150.0f) {
        func_80005B1C(5, handleA | 4);
    }
    if (D_800A5B5C != 0) {
        func_8006B304(obj);
    }
    handleB = func_80005B44(3);
    func_80005B1C(3, obj->unk26C);
    D_8011C850 = obj->unk1F8;
    if ((obj->unk60 << 6) < 0) {
        detached = 1;
    } else {
        detached = 0;
    }
    if (detached != 0) {
        func_800155C0(obj->unk194, -1.0f, obj->unk40);
        obj->unk2E4 = 0.0f;
        obj->unk2E8 = 0.0f;
        obj->unk2EC = 0.0f;
        origin = obj->unk30;
        offset = &obj->unk2E4;
    } else {
        func_80065E18(obj);
        origin = obj->unk30;
        offset = &obj->unk2E4;
        func_80065CD0(obj->unk30, obj->unk20, obj->unk194, &obj->unk2E4);
    }
    obj->unk16C = obj->unk50;
    obj->unk170 = obj->unk54;
    obj->unk174 = obj->unk58;
    obj->unk2D8 = obj->unk2E4;
    obj->unk2DC = obj->unk2E8;
    obj->unk2E0 = obj->unk2EC;
    if (func_8006C708(obj) != 0) {
        obj->unk1F0 = obj->unk1F0 * D_800AD5E4;
    } else if ((obj->unk60 << 8) < 0) {
        obj->unk1F0 = obj->unk1F0 * 0.5f;
    } else if (detached == 0) {
        obj->unk1F0 = obj->unk1F0 *
                      (1.0f - ((obj->unk208 < 0.0f) ? -obj->unk208 : obj->unk208) * 0.5f);
    }
    if ((obj->unk64 & 0x400) != 0) {
        obj->unk1F0 = obj->unk1F0 * 0.5f;
        func_80033328(&obj->unk1EC, offset, obj->unk1F0, obj->unk70 * obj->unk22C, obj->unk1F4,
                      obj->unk1FC);
        if (obj->unk1F8 > 0.0f) {
            obj->unk2E4 = obj->unk2E4 + obj->unk1F8;
        } else if (obj->unk1F8 < 0.0f) {
            obj->unk2E4 = obj->unk2E4 + obj->unk1F8;
        }
    } else {
        func_80033328(&obj->unk1EC, offset, obj->unk1F0, obj->unk70 * obj->unk22C, obj->unk1F4,
                      obj->unk1F8 + obj->unk1FC);
    }
    obj->unk1F4 = obj->unk1F4 * func_80081700(1.5f, (f32)D_80120BF0);
    if ((obj->unk1F4 < 0.5f) && (-obj->unk1F4 < 0.5f)) {
        obj->unk1F4 = 0.0f;
    }
    if (detached != 0) {
        if (obj->unk224 < obj->unk220) {
            obj->unk220 = (f32)((f64)obj->unk220 -
                                D_80120BF0 * (f64)obj->unk70 * (f64)obj->unk22C);
            if (obj->unk220 < obj->unk224) {
                obj->unk220 = obj->unk224;
            }
        } else {
            obj->unk220 = (f32)((f64)obj->unk220 +
                                D_80120BF0 * (f64)obj->unk70 * (f64)obj->unk22C);
            if (obj->unk220 > obj->unk224) {
                obj->unk220 = obj->unk224;
            }
        }
    }
    func_8006907C(obj, &obj->unk16C, result, origin);
    if (detached != 0) {
        obj->unk64 = obj->unk64 | 0x20000000;
        obj->unk244 = 1.0f;
        obj->unk248 = 1.0f;
        obj->unk140 = obj->unkEC;
    }
    obj->unk2CC = result[0];
    obj->unk2D0 = result[1];
    obj->unk2D4 = result[2];
    obj->unk50 = result[0];
    obj->unk54 = result[1];
    obj->unk58 = result[2];
    func_80005B1C(5, handleA);
    func_80005B1C(3, handleB);
}
