/* Recovered from specs/functions/recovered/medium_state_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3;

typedef struct {
    f32 m[4][4];
} PcMtx;

typedef struct {
    s32 unk0;
} Kind80041D14;

typedef struct {
    u8 pad0[0x18];
    Kind80041D14 *unk18;
} Holder80041D14;

typedef struct {
    u8 pad0[0x20];
    PcMtx unk20;
    u32 unk60;
    u32 unk64;
    u8 pad68[0x40];
    f32 unkA8;
    u8 padAC[0x1A4];
    f32 unk250;
    u8 pad254[0x23C];
    u8 unk490[0x19E0];
    Holder80041D14 *unk1E70;
} Craft80041D14;

typedef struct {
    u8 pad0[0x20];
    PcMtx unk20;
    u8 pad60[0x1C];
    s32 unk7C;
    u8 pad80[0x74];
    Craft80041D14 *unkF4;
    u8 padF8[0x10];
    PcMtx unk108;
    u8 pad148[0x168];
    f32 unk2B0;
} Rider80041D14;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Angles80041D14;

extern f32 D_800AAC5C;
extern f32 D_800AAC60;

extern void func_800155C0(PcVec3 *output, f32 scale, const PcVec3 *source);
extern void func_800155EC(PcVec3 *output, const PcVec3 *base, f32 scale,
                          const PcVec3 *offset);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_80016F0C(void *arg0, Angles80041D14 *arg1);
extern void func_80017824(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4,
                          void *arg5);

void func_80041D14(Rider80041D14 *rider) {
    s32 flag;
    f64 spare;
    f32 mtx[4][4];
    Angles80041D14 angles;
    Craft80041D14 *craft;
    f32 scale;

    (void)spare;
    craft = rider->unkF4;
    if (craft == 0) {
        return;
    }

    if ((craft->unk60 & 0x6000000) != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    rider->unk2B0 = 100.0f;
    if (rider->unk7C == 5) {
        rider->unk2B0 = 120.0f;
    }
    func_800156DC(mtx, craft->unk20.m);
    mtx[3][2] = mtx[3][2] + craft->unk250;
    scale = (craft->unkA8 - 3.0f) * 0.5f;
    if (rider->unk7C != 5) {
        scale = scale * D_800AAC5C;
        if (craft->unk1E70->unk18->unk0 == 14) {
            scale = scale * D_800AAC60;
        }
    }
    if (craft->unk1E70->unk18->unk0 == 14) {
        func_800155EC((PcVec3 *)mtx[3], (PcVec3 *)mtx[3], scale,
                      (PcVec3 *)mtx[2]);
    } else {
        scale *= craft->unk20.m[2][2];
        if (flag == 0) {
            mtx[3][2] = mtx[3][2] + scale;
        }
    }
    if (craft->unk1E70->unk18->unk0 == 10) {
        func_800155EC((PcVec3 *)mtx[3], (PcVec3 *)mtx[3], 3.0f,
                      (PcVec3 *)mtx[1]);
    }
    if ((craft->unk64 & 0x18000) != 0) {
        func_80016F0C(craft->unk490, &angles);
        func_80017824(mtx, angles.unk14, 0.0f, 1.0f, 0.0f, mtx);
    }
    func_800156DC(rider->unk20.m, mtx);
    func_800156DC(rider->unk108.m, mtx);
    if ((craft->unk60 & 0x100000) != 0) {
        func_800155EC((PcVec3 *)rider->unk108.m[3], (PcVec3 *)mtx[3], -1.0f,
                      (PcVec3 *)mtx[1]);
        func_800155C0((PcVec3 *)rider->unk20.m[1], -1.0f,
                      (PcVec3 *)rider->unk20.m[1]);
        func_800155C0((PcVec3 *)rider->unk20.m[0], -1.0f,
                      (PcVec3 *)rider->unk20.m[0]);
    } else {
        func_800155EC((PcVec3 *)rider->unk108.m[3], (PcVec3 *)mtx[3], 1.0f,
                      (PcVec3 *)mtx[1]);
    }
}
