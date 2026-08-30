/* Independently written from specs/functions/recovered/func_8000BC10.md. */

#include "podcruise/types.h"

#define ABSOLUTE(value) (((value) < 0.0f) ? -(value) : (value))

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 *unk8;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 *unk10;
    /* 0x14 */ f32 unk14[16];
    /* 0x54 */ f32 unk54[3];
    /* 0x60 */ f32 unk60[3];
    /* 0x6C */ f32 unk6C[3];
    /* 0x78 */ s32 unk78;
} Node8009B790;

extern Node8009B790 *D_8009B790;
extern s32 D_8009B798;
extern s32 D_8009B79C;
extern void *D_800A68B4;
extern f32 D_800D6960[3];
extern f32 D_800D696C[3];

extern void func_8000B254(s32 mode, f32 *source, f32 *output);
extern void func_8000B318(void *object);
extern void func_80015C30(f32 *matrix, f32 *other);
extern void func_80016BF4(f32 *output, f32 *vector, f32 *matrix);
extern void func_80016F0C(f32 *matrix, f32 *output);
extern void func_8001745C(f32 *matrix, f32 first, f32 second, f32 third);
extern void func_800174B8(f32 *matrix, f32 *source);
extern s32 func_80017EE4(void *object);
extern s32 func_80017EF4(void *object);
extern s32 func_80017F20(void);
extern void *func_80017F28(s32 index);
extern void func_80017F64(void *object, f32 *first, f32 *second);
extern void func_80017FD0(void *object, f32 *input);
extern void func_80082624(f32 *from, f32 *to, f32 *matrix, f32 *out, f32 roll);

void func_8000BC10(void) {
    f32 lean;
    f32 spare;
    f32 offset[3];
    f32 rotation[3];
    f32 target[3];
    f32 angles[9];
    f32 result[16];
    f32 local[4][4];
    Node8009B790 *node;
    void *object;
    s32 index;
    s32 slot;
    s16 i;

    (void)spare;
    object = 0;
    for (i = 0; i < 32; i++) {
        D_8009B790[i].unk0 &= ~2;
    }
    for (i = 0; i < func_80017F20(); i++) {
        object = func_80017F28(i);
        if (object != 0) {
            index = func_80017EE4(object);
            if (func_80017EF4(object) & 1) {
                if ((index >= 0) && (index < 32)) {
                    D_8009B790[index].unk0 |= 2;
                }
            }
        }
    }
    for (i = 0; i < 32; i++) {
        node = &D_8009B790[i];
        if ((node->unk4 != 0) && ((node->unk0 & 1) || (node->unk0 & 2))) {
            if (node->unk6 == 0) {
                node->unk14[0] = node->unk8[0];
                node->unk14[1] = node->unk8[1];
                node->unk14[2] = node->unk8[2];
                node->unk14[3] = node->unk8[3];
                node->unk14[4] = node->unk8[4];
                node->unk14[5] = node->unk8[5];
                node->unk14[6] = node->unk8[6];
                node->unk14[7] = node->unk8[7];
                node->unk14[8] = node->unk8[8];
                node->unk14[9] = node->unk8[9];
                node->unk14[10] = node->unk8[10];
                node->unk14[11] = node->unk8[11];
                node->unk14[12] = node->unk8[12];
                node->unk14[13] = node->unk8[13];
                node->unk14[14] = node->unk8[14];
                node->unk14[15] = node->unk8[15];
            } else if (node->unk6 == 1) {
                func_800174B8(node->unk14, node->unk8);
            } else {
                func_8000B254(node->unk6, node->unk8, node->unk14);
            }
            offset[0] = node->unk54[0];
            offset[1] = node->unk54[1];
            offset[2] = node->unk54[2];
            if ((offset[0] != 0.0f) || (offset[1] != 0.0f) || (offset[2] != 0.0f)) {
                func_80016BF4(offset, offset, node->unk14);
                node->unk14[12] += offset[0];
                node->unk14[13] += offset[1];
                node->unk14[14] += offset[2];
            }
            rotation[0] = node->unk60[0];
            rotation[1] = node->unk60[1];
            rotation[2] = node->unk60[2];
            if ((rotation[0] != 0.0f) || (rotation[1] != 0.0f) || (rotation[2] != 0.0f)) {
                func_8001745C(&result[0], rotation[0], rotation[1], rotation[2]);
                func_80015C30(node->unk14, &result[0]);
            }
            if ((node->unk4 == 2) || (node->unk4 == 3) || (node->unk4 == 4)) {
                func_80016F0C(node->unk14, angles);
                if (node->unkC == 1) {
                    target[0] = node->unk10[0] + node->unk6C[0];
                    target[1] = node->unk10[1] + node->unk6C[1];
                    target[2] = node->unk10[2] + node->unk6C[2];
                } else {
                    if (node->unkC == 0) {
                        local[0][0] = node->unk10[0];
                        local[0][1] = node->unk10[1];
                        local[0][2] = node->unk10[2];
                        local[0][3] = node->unk10[3];
                        local[1][0] = node->unk10[4];
                        local[1][1] = node->unk10[5];
                        local[1][2] = node->unk10[6];
                        local[1][3] = node->unk10[7];
                        local[2][0] = node->unk10[8];
                        local[2][1] = node->unk10[9];
                        local[2][2] = node->unk10[10];
                        local[2][3] = node->unk10[11];
                        local[3][0] = node->unk10[12];
                        local[3][1] = node->unk10[13];
                        local[3][2] = node->unk10[14];
                        local[3][3] = node->unk10[15];
                    } else {
                        func_8000B254(node->unkC, node->unk10, &local[0][0]);
                    }
                    target[0] = local[3][0] + node->unk6C[0];
                    target[1] = local[3][1] + node->unk6C[1];
                    target[2] = local[3][2] + node->unk6C[2];
                    if (node->unk4 == 4) {
                        lean = local[1][2];
                        target[0] = local[1][0] * (1.0 + 40.0 * ABSOLUTE(lean)) + target[0];
                        target[1] = local[1][1] * (1.0 + 40.0 * ABSOLUTE(lean)) + target[1];
                        target[2] = lean * (1.0 + 40.0 * ABSOLUTE(lean)) + target[2];
                    }
                }
                func_80082624(&node->unk14[12], target, node->unk14, angles, angles[5]);
                if (node->unk4 == 3) {
                    if (node->unk6 == 0) {
                        node->unk8[0] = node->unk14[0];
                        node->unk8[1] = node->unk14[1];
                        node->unk8[2] = node->unk14[2];
                        node->unk8[3] = node->unk14[3];
                        node->unk8[4] = node->unk14[4];
                        node->unk8[5] = node->unk14[5];
                        node->unk8[6] = node->unk14[6];
                        node->unk8[7] = node->unk14[7];
                        node->unk8[8] = node->unk14[8];
                        node->unk8[9] = node->unk14[9];
                        node->unk8[10] = node->unk14[10];
                        node->unk8[11] = node->unk14[11];
                        node->unk8[12] = node->unk14[12];
                        node->unk8[13] = node->unk14[13];
                        node->unk8[14] = node->unk14[14];
                        node->unk8[15] = node->unk14[15];
                    } else if (node->unk6 == 1) {
                        node->unk8[3] = angles[3];
                        node->unk8[4] = angles[4];
                        node->unk8[5] = angles[5];
                    }
                }
            }
        }
    }
    if (func_80017F20() == 0) {
        index = D_8009B798;
        object = D_800A68B4;
        if (index == -1) {
            func_8000B318(object);
        } else {
            if (D_8009B79C == 0) {
                D_8009B79C = 1;
            }
            result[0] = D_8009B790[index].unk14[0];
            result[1] = D_8009B790[index].unk14[1];
            result[2] = D_8009B790[index].unk14[2];
            result[3] = D_8009B790[index].unk14[3];
            result[4] = D_8009B790[index].unk14[4];
            result[5] = D_8009B790[index].unk14[5];
            result[6] = D_8009B790[index].unk14[6];
            result[7] = D_8009B790[index].unk14[7];
            result[8] = D_8009B790[index].unk14[8];
            result[9] = D_8009B790[index].unk14[9];
            result[10] = D_8009B790[index].unk14[10];
            result[11] = D_8009B790[index].unk14[11];
            result[12] = D_8009B790[index].unk14[12];
            result[13] = D_8009B790[index].unk14[13];
            result[14] = D_8009B790[index].unk14[14];
            result[15] = D_8009B790[index].unk14[15];
            if (object != 0) {
                func_80017FD0(object, &result[0]);
            }
        }
        if (object != 0) {
            func_80017F64(object, D_800D6960, D_800D696C);
        }
    } else {
        for (slot = 0; slot < func_80017F20(); slot++) {
            object = func_80017F28(slot);
            if (object != 0) {
                index = func_80017EE4(object);
                if (func_80017EF4(object) & 1) {
                    if (index == -1) {
                        func_8000B318(object);
                    } else {
                        if (D_8009B79C == 0) {
                            D_8009B79C = 1;
                        }
                                    result[0] = D_8009B790[index].unk14[0];
                        result[1] = D_8009B790[index].unk14[1];
                        result[2] = D_8009B790[index].unk14[2];
                        result[3] = D_8009B790[index].unk14[3];
                        result[4] = D_8009B790[index].unk14[4];
                        result[5] = D_8009B790[index].unk14[5];
                        result[6] = D_8009B790[index].unk14[6];
                        result[7] = D_8009B790[index].unk14[7];
                        result[8] = D_8009B790[index].unk14[8];
                        result[9] = D_8009B790[index].unk14[9];
                        result[10] = D_8009B790[index].unk14[10];
                        result[11] = D_8009B790[index].unk14[11];
                        result[12] = D_8009B790[index].unk14[12];
                        result[13] = D_8009B790[index].unk14[13];
                        result[14] = D_8009B790[index].unk14[14];
                        result[15] = D_8009B790[index].unk14[15];
                        func_80017FD0(object, &result[0]);
                    }
                }
            }
        }
        if (object != 0) {
            func_80017F64(object, D_800D6960, D_800D696C);
        }
    }
}
