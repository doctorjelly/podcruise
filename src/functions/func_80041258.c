/* Independently written from specs/functions/recovered/func_80041258.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x20];
    /* 0x020 */ f32 unk020[4][4];
    /* 0x060 */ u8 pad060[0x10];
    /* 0x070 */ f32 unk070;
    /* 0x074 */ u8 pad074[0x80];
    /* 0x0F4 */ void *unk0F4;
    /* 0x0F8 */ u8 pad0F8[0x10];
    /* 0x108 */ f32 unk108[4][4];
    /* 0x148 */ u8 pad148[0x168];
    /* 0x2B0 */ f32 unk2B0;
} Frame;

typedef struct {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 *unk18;
} Holder;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x20];
    /* 0x0020 */ f32 unk0020[4][4];
    /* 0x0060 */ u8 pad0060[0x1F0];
    /* 0x0250 */ f32 unk0250;
    /* 0x0254 */ u8 pad0254[0x1760];
    /* 0x19B4 */ f32 unk19B4;
    /* 0x19B8 */ u8 pad19B8[0x4B8];
    /* 0x1E70 */ Holder *unk1E70;
} Rider;

typedef struct {
    /* 0x00 */ f32 unk00[3];
    /* 0x0C */ f32 unk0C[3];
    /* 0x18 */ f32 unk18[3];
    /* 0x24 */ u8 pad24[0x18];
    /* 0x3C */ f32 unk3C[3];
    /* 0x48 */ f32 unk48[3];
    /* 0x54 */ u8 pad54[0x18];
} Anchor;

extern Anchor D_800A5CA0[];
extern Anchor D_800A62D0;
extern f64 D_800AAC48;
extern f64 D_80120BF0;

extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_80015288(f32 *output, const f32 *source);
extern void func_80015328(f32 *output, f32 *left, f32 *right);
extern void func_8001535C(f32 *output, f32 *left, f32 *right);
extern f32 func_800154D0(f32 *vector);
extern void func_800155C0(f32 *output, f32 scale, f32 *source);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *direction);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80014CC0(f32 angle, f32 *outB, f32 *outA);
extern f32 func_80014D4C(f32 value);
extern f32 func_80014F54(f32 first, f32 second);
extern void func_80016CAC(f32 *destination, f32 *source, f32 transform[4][4]);
extern void func_8001745C(f32 matrix[4][4], f32 first, f32 second, f32 third);
extern void func_80017874(f32 destination[4][4]);
extern void func_8004110C(Frame *frame, s32 value);

void func_80041258(Frame *arg0) {
    Rider *rider;
    f32 sp420[3];
    f32 sp414[3];
    f32 sp408[3];
    f32 target[16][3];
    f32 origin[16][3];
    f32 spare[42];
    f32 second[3];
    f32 first[3];
    s32 slot;
    s32 index;
    s32 spare3;
    f32 blend;
    f32 sine;
    f32 cosine;
    f32 length[16];
    f32 heading[16];
    f32 pitch[16];
    f32 spare4[2];
    f32 span;
    f32 spare5;
    f32 scale;
    f32 spare6;
    f32 output[4][4];
    f32 matrix[4][4];
    s32 gap;
    f32 offset[3];
    f32 middle[3];
    s32 finished;
    s32 tail[3];

    arg0->unk2B0 = -1.0f;
    finished = 0;
    rider = arg0->unk0F4;
    if (rider != 0) {
        func_800156DC(matrix, rider->unk0020);
        matrix[3][2] += rider->unk0250;
        arg0->unk070 = arg0->unk070 + D_80120BF0;
        slot = *rider->unk1E70->unk18;
        func_80015288(sp420, D_800A5CA0[slot].unk00);
        func_80015328(sp420, sp420, D_800A5CA0[slot].unk18);
        func_80015288(sp414, D_800A5CA0[slot].unk0C);
        func_80015328(sp414, sp414, D_800A5CA0[slot].unk3C);
        sp414[0] = sp414[0] * D_800AAC48;
        func_80015288(sp408, D_800A5CA0[slot].unk48);
        sp408[2] = sp408[2] + rider->unk19B4 * 0.75;
        sp408[1] = sp408[1] * -1.0f;
        func_800155C0(sp408, 0.75f, sp408);

        func_80015288(target[0], sp420);
        target[0][0] = target[0][0] + 2.0;
        target[0][1] = target[0][1] - 2.0;
        target[0][2] = target[0][2] - 1.0;
        if (&D_800A5CA0[slot] == &D_800A62D0) {
            target[0][0] = target[0][0] + 2.0;
            target[0][1] = target[0][1] - 2.0;
            target[0][2] = target[0][2] + 4.0;
        }
        func_80016CAC(target[0], target[0], matrix);
        func_80015288(origin[0], sp420);
        origin[0][2] -= 2.0f;
        func_80016CAC(origin[0], origin[0], matrix);

        index = 1;
        func_80015288(target[index], sp420);
        target[index][0] = target[index][0] - 0.5;
        target[index][1] = target[index][1] + 2.5;
        target[index][2] = target[index][2] - 1.0;
        if (&D_800A5CA0[slot] == &D_800A62D0) {
            target[index][0] = target[index][0] + 0.0;
            target[index][1] = target[index][1] + 2.0;
            target[index][2] = target[index][2] + 4.0;
        }
        func_80016CAC(target[index], target[index], matrix);
        func_80015288(origin[index], sp420);
        origin[index][2] -= 2.0f;
        func_80016CAC(origin[index], origin[index], matrix);

        func_80015288(target[index + 1], sp414);
        target[index + 1][1] += 5.0f;
        target[index + 1][2] += 0.5f;
        func_80016CAC(target[index + 1], target[index + 1], matrix);
        func_80015288(origin[index + 1], sp420);
        func_80016CAC(origin[index + 1], origin[index + 1], matrix);

        func_80015288(target[index + 2], sp408);
        func_80016CAC(target[index + 2], target[index + 2], matrix);
        func_80015268(origin[index + 2], 0.0f, 0.0f, sp408[2]);
        func_80016CAC(origin[index + 2], origin[index + 2], matrix);

        if (arg0->unk070 < 3.0) {
            scale = arg0->unk070 / 3.0;
            index = 0;
        } else if (arg0->unk070 < 6.0) {
            scale = (arg0->unk070 - 3.0) / 3.0;
            index = 1;
        } else if (arg0->unk070 < 8.0) {
            scale = (arg0->unk070 - 6.0) * 0.5;
            index = 2;
        } else {
            scale = 1.0f;
            index = 2;
            finished = 1;
        }
        if (scale < 0.0) {
            scale = 0.0f;
        }
        if (1.0 < scale) {
            scale = 1.0f;
        }

        func_80014CC0(scale * 180.0f - 90.0f, &sine, &cosine);
        blend = sine * 0.5f + 0.5f;
        func_80015268(offset, 0.0f, 0.0f, 0.0f);
        func_800155EC(offset, offset, 1.0 - blend, origin[index]);
        func_800155EC(offset, offset, blend, origin[index + 1]);
        func_8001535C(first, target[index], offset);
        func_8001535C(second, target[index + 1], offset);
        length[0] = func_800154D0(first);
        length[1] = func_800154D0(second);
        heading[0] = func_80014F54(-first[0], first[1]);
        heading[1] = func_80014F54(-second[0], second[1]);
        pitch[0] = func_80014D4C(first[2]);
        pitch[1] = func_80014D4C(second[2]);
        func_8001745C(output, heading[0] + (heading[1] - heading[0]) * blend,
                      pitch[0] + (pitch[1] - pitch[0]) * blend, 0.0f);
        span = length[0] + (length[1] - length[0]) * blend;
        func_800155EC(middle, offset, span, output[1]);
        func_80017874(output);
        func_80015288(output[3], middle);
        func_800156DC(arg0->unk020, output);
        func_80017874(output);
        func_80015288(output[3], offset);
        func_800156DC(arg0->unk108, output);
    }
    if (finished != 0) {
        func_8004110C(arg0, 1);
    }
    (void)spare; (void)tail; (void)gap; (void)spare3; (void)spare4; (void)spare5; (void)spare6;
}
