/* Independently written from specs/functions/recovered/medium_world_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    /* 0x000 */ u8 pad000[0x20];
    /* 0x020 */ PcVec3f unk20;
    /* 0x02C */ u8 pad02C[0x04];
    /* 0x030 */ PcVec3f unk30;
    /* 0x03C */ u8 pad03C[0x04];
    /* 0x040 */ PcVec3f unk40;
    /* 0x04C */ u8 pad04C[0x04];
    /* 0x050 */ PcVec3f unk50;
    /* 0x05C */ u8 pad05C[0x04];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 pad064[0x48];
    /* 0x0AC */ u8 unkAC[0x58];
    /* 0x104 */ f32 unk104;
    /* 0x108 */ u8 pad108[0xE4];
    /* 0x1EC */ f32 unk1EC;
    /* 0x1F0 */ f32 unk1F0;
    /* 0x1F4 */ u8 pad1F4[0x10];
    /* 0x204 */ f32 unk204;
    /* 0x208 */ f32 unk208;
    /* 0x20C */ u8 pad20C[0x10];
    /* 0x21C */ f32 unk21C;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ u8 pad224[0xC8];
    /* 0x2EC */ f32 unk2EC;
} Obj8006AF48;

extern f64 D_80120BF0;
extern f32 D_800AD5BC;
extern f32 D_800AD5C4;
extern f32 D_800AD5C8;
extern f32 D_800AD5CC;
extern f64 D_800AD5D0;
extern f64 D_800AD5D8;
extern f32 D_800AD5E0;

extern void func_8003B184(void *source, void *context, f32 offset);
extern void func_80015288(PcVec3f *output, PcVec3f *source);
extern void func_8001535C(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern f32 func_800154D0(PcVec3f *vector);
extern void func_80015538(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern void func_800155EC(PcVec3f *output, PcVec3f *base, f32 scale, PcVec3f *offset);
extern void func_80017824(PcVec3f *output, f32 angle, f32 axisX, f32 axisY, f32 axisZ, PcVec3f *source);

void func_8006AF48(Obj8006AF48 *obj, PcVec3f *arg1) {
    PcVec3f workE;
    PcVec3f workD;
    PcVec3f workC;
    PcVec3f workB;
    f32 adjust;
    PcVec3f workA;
    f32 matrix[16];

    if (obj->unk104 < D_800AD5BC) {
        obj->unk104 = D_800AD5BC;
    }
    if (obj->unk104 > 2.0f) {
        obj->unk104 = 2.0f;
    }

    func_8003B184(obj->unkAC, matrix, 0.0f);
    workA.x = matrix[12];
    workA.y = matrix[13];
    workA.z = matrix[14];
    func_8003B184(obj->unkAC, matrix, obj->unk104);
    adjust = D_800AD5C4;
    if (((workA.z - matrix[14]) * (workA.z - matrix[14]) +
                ((workA.x - matrix[12]) * (workA.x - matrix[12]) +
                 (workA.y - matrix[13]) * (workA.y - matrix[13]))) < D_800AD5C8) {
        obj->unk104 = obj->unk104 + adjust;
    } else if (D_800AD5CC < ((workA.z - matrix[14]) * (workA.z - matrix[14]) +
                ((workA.x - matrix[12]) * (workA.x - matrix[12]) +
                 (workA.y - matrix[13]) * (workA.y - matrix[13])))) {
        obj->unk104 = obj->unk104 - adjust;
    }

    workA.x = matrix[12];
    workA.y = matrix[13];
    workA.z = matrix[14];
    func_8001535C(&workB, &workA, &obj->unk50);
    func_800154D0(&workB);
    func_8001535C(&workE, &workB, &obj->unk30);
    func_800155EC(&workC, &obj->unk30, 0.2f, &workE);

    if (obj->unk60 & 0x04000000) {
        obj->unk21C = obj->unk2EC * 10.0f;
    } else {
        obj->unk21C = obj->unk21C + obj->unk1F0 * -2.0f * (f32)D_80120BF0;
        obj->unk21C = obj->unk21C + obj->unk208 * 1000.0f * (f32)D_80120BF0;
        if (obj->unk21C > D_800AD5D0) {
            obj->unk21C = 180.0f;
        }
        if (obj->unk21C < D_800AD5D8) {
            obj->unk21C = -180.0f;
        }
        obj->unk21C = obj->unk21C * D_800AD5E0;
    }

    func_80015288(&workD, arg1);
    func_80015288(&obj->unk30, &workC);
    func_80015538(&obj->unk20, &obj->unk30, &obj->unk40);
    func_80015538(&obj->unk40, &obj->unk20, &obj->unk30);
    func_800154D0(&obj->unk20);
    func_800154D0(&obj->unk30);
    func_800154D0(&obj->unk40);
    func_80017824(&obj->unk20, obj->unk1EC * 1.5f * (f32)D_80120BF0, 0.0f, 0.0f, 1.0f, &obj->unk20);
    func_80017824(&obj->unk20, obj->unk220 * 1.5f * (f32)D_80120BF0, 1.0f, 0.0f, 0.0f, &obj->unk20);
    func_80017824(&obj->unk20, obj->unk21C * (f32)D_80120BF0, 0.0f, 1.0f, 0.0f, &obj->unk20);
    func_80015288(&obj->unk50, &workD);
    obj->unk204 = 0.0f;
}
