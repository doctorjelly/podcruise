/* Independently written from specs/functions/recovered/medium_resource_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x4];
    /* 0x004 */ s16 unk04;
    /* 0x006 */ u8 pad006[0x60 - 0x6];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 pad064[0x344 - 0x64];
    /* 0x344 */ void **unk344;
    /* 0x348 */ u8 pad348[0x350 - 0x348];
    /* 0x350 */ f32 unk350[10][4][4];
} Craft800738D4;

extern f32 D_800A6664;
extern f32 D_800AD930;
extern f64 D_800AD938;
extern f32 D_800AD940;

extern void func_80015288(f32 *, f32 *);
extern f32 func_800153C0(f32 *);
extern f32 func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80017520(f32 (*)[4], f32, f32, f32);
extern void func_80017580(f32 (*)[4], f32, f32, f32);
extern void func_80017874(f32 (*)[4]);
extern void func_80017BA8(void *, f32 (*)[4]);
extern void func_800181BC(void *, s32, s32, s32, s32);

void func_800738D4(Craft800738D4 *craft, s32 mode, f32 *from, f32 *to) {
    f32 direction[3];
    f32 up[3];
    f32 matrix[4][4];
    f32 length;
    f32 amount;
    f32 strength;
    f32 spread;
    s32 first;
    s32 second;

    if (craft->unk344 == 0) {
        return;
    }
    if (mode == 1) {
        first = 6;
        second = 7;
    } else {
        first = 8;
        second = 9;
    }
    if ((craft->unk60 & 0xF) == 2) {
        D_800A6664 = 1000.0f;
    }
    amount = D_800A6664 - (f32)craft->unk04 * D_800AD930;
    if (0.0f < amount) {
        amount = amount * amount;
    }
    if ((f64)amount < D_800AD938) {
        if (craft->unk344[first] != 0) {
            func_800181BC(craft->unk344[first], 2, -4, 0x10, 3);
        }
        func_80017580(craft->unk350[first], (f32)0.0, (f32)0.0, -100000.0f);
        func_80017874(craft->unk350[second]);
        return;
    }

    spread = amount * 8.0f;
    if (1.0f < spread) {
        spread = 1.0f;
    }
    strength = amount * D_800AD930;
    if (1.0f < strength) {
        strength = 1.0f;
    }

    direction[0] = from[0] - to[0];
    direction[1] = from[1] - to[1];
    direction[2] = from[2] - to[2];
    length = func_800153C0(direction);
    func_800155C0(direction, 1.0f / length, direction);

    up[0] = direction[1];
    up[1] = -direction[0];
    up[2] = 0.0f;
    func_800154D0(up);

    func_80015538(matrix[0], direction, up);
    func_80015288(matrix[2], direction);
    func_80015288(matrix[1], up);
    matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
    func_800155C0(matrix[3], 0.5f, from);
    func_800155EC(matrix[3], matrix[3], 0.5f, to);

    func_800156DC(craft->unk350[first], matrix);
    func_80017520(matrix, strength * D_800AD940, strength, spread * length / 20.0f);
    func_800156DC(craft->unk350[second], matrix);

    if (craft->unk344[first] != 0) {
        func_800181BC(craft->unk344[first], 2, 3, 0x10, 2);
    }
    if (craft->unk344[second] != 0) {
        func_80017BA8(craft->unk344[second], craft->unk350[second]);
    }
    if (craft->unk344[first] != 0) {
        func_80017BA8(craft->unk344[first], craft->unk350[first]);
    }
}
