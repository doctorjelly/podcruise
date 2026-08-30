/* Independently written from specs/functions/recovered/func_80043598.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x60];
    u32 flags60;
} Linked80043598;

typedef struct {
    u8 pad000[0x20];
    f32 matrix20[4][4];
    u8 pad060[0x14];
    s32 player74;
    s32 handle78;
    s32 state7C;
    u8 pad080[0x74];
    Linked80043598 *linkedF4;
    u8 pad0F8[0x40];
    f32 position138[3];
    u8 pad144[0x164];
    u32 flags2A8;
    s32 value2AC;
    f32 value2B0;
    f32 value2B4;
    f32 value2B8;
} Obj80043598;

extern s32 D_800A5998;
extern f32 D_800A4AD8;
extern s32 D_800A4ADC;
extern s16 D_800A4AE0[];
extern f64 D_80120BF0;

extern s32 func_80082BE0(void);
extern void func_80041D14(void *);
extern void func_80041F40(void *);
extern void func_80042970(void *);
extern void func_80041258(void *);
extern void func_800419EC(void *);
extern void func_80016F0C(f32 matrix[4][4], f32 output[6]);
extern void func_80082624(f32 from[6], f32 *to, f32 matrix[4][4],
                          f32 output[6], f32 roll);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern s32 func_8000BB78(s32);
extern void *func_80017F28(s32);
extern void func_8001811C(void *, s32, s32);
extern void func_80042EEC(void *);
extern void func_800117F0(void);
extern void func_80011814(void);
extern void func_80042BB8(void *);

void func_80043598(void *arg0) {
    Obj80043598 *obj;
    Linked80043598 *linked;
    f32 original[6];
    f32 facing[6];
    f32 matrix[4][4];
    s32 active;

    obj = arg0;
    if (obj->state7C == 0 || obj->player74 < 0) {
        return;
    }

    linked = obj->linkedF4;
    if (linked != 0) {
        if (D_800A5998 != 0) {
            obj->state7C = 4;
            linked->flags60 &= ~0x100000;
        } else {
            if ((linked->flags60 & 0x20) == 0) {
                active = 1;
            } else {
                active = 0;
            }
            if (D_800A5998 != 0) {
                active = 1;
            }
            if (active != 0) {
                D_800A4AD8 = (f32)((f64)D_800A4AD8 - D_80120BF0);
                if (D_800A4AD8 <= 0.0f) {
                    D_800A4AD8 = ((f32)func_80082BE0() / 2147483648.0f) * 7.0f + 3.0f;
                    D_800A4ADC += ((f32)func_80082BE0() / 2147483648.0f) * 7.0f;
                    D_800A4ADC %= 7;
                    obj->state7C = D_800A4AE0[D_800A4ADC];
                    linked->flags60 &= ~0x100000;
                    if (D_800A4ADC == 6) {
                        linked->flags60 |= 0x100000;
                    }
                }
            }
        }
    }

    obj->value2B8 = 100.0f;
    obj->value2B4 = 5.0f;
    switch (obj->state7C) {
        case 4:
        case 5:
            func_80041D14(obj);
            break;
        case 1:
        case 2:
            func_80041F40(obj);
            break;
        case 6:
            func_80042970(obj);
            break;
        case 7:
            func_80041258(obj);
            break;
        case 8:
        case 9:
            func_800419EC(obj);
            break;
    }

    func_80016F0C(obj->matrix20, original);
    func_80082624(original, obj->position138, matrix, facing, original[5]);
    func_800156DC(obj->matrix20, matrix);

    if (func_8000BB78(obj->handle78) != 0) {
        if (D_800A5998 != 0) {
            func_8001811C(func_80017F28(obj->player74), 4, -0x100);
        } else {
            func_8001811C(func_80017F28(obj->player74), 4, obj->value2AC);
        }
        func_8001811C(func_80017F28(obj->player74), 3, obj->value2AC);
        func_80042EEC(obj);
        if ((obj->flags2A8 & 8) != 0) {
            func_800117F0();
        } else {
            func_80011814();
        }
        func_80042BB8(obj);
    }
}
