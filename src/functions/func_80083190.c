/* Recovered from specification specs/func_80083190.md (worker batch 04). */
#include "podcruise/types.h"

typedef struct Node80083190 {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u8 unk0E[0xE];
    /* 0x1C */ f32 unk1C[4][3];
    /* 0x4C */ f32 unk4C[3];
} Node80083190;

extern s32 func_80017DA4(Node80083190 *node);
extern void func_80015724(f32 (*dst)[4], f32 (*src)[4], f32 (*acc)[4]);

void func_80083190(Node80083190 **list, f32 (*out)[4]) {
    Node80083190 *obj;
    f32 pad1[17];
    f32 matrix[4][4];
    f32 (*src)[3];
    s32 type;
    s32 i;

    (void)pad1;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;
    out[1][0] = 0.0f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;
    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][3] = 0.0f;
    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[0][0] = 1.0f;
    out[1][1] = 1.0f;
    out[2][2] = 1.0f;
    out[3][3] = 1.0f;
    while (*list != 0) {
        type = func_80017DA4(*list);
        if (type & 0x8000) {
            if (type == 0xD065) {
                obj = *list;
                src = obj->unk1C;
            } else {
                src = (*list)->unk1C;
            }
            matrix[0][0] = src[0][0];
            matrix[0][1] = src[0][1];
            matrix[0][2] = src[0][2];
            matrix[1][0] = src[1][0];
            matrix[1][1] = src[1][1];
            matrix[1][2] = src[1][2];
            matrix[2][0] = src[2][0];
            matrix[2][1] = src[2][1];
            matrix[2][2] = src[2][2];
            matrix[3][0] = src[3][0];
            matrix[3][1] = src[3][1];
            matrix[3][2] = src[3][2];
            matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0;
            matrix[3][3] = 1.0;
            if ((*list)->unk0C & 0x10) {
                for (i = 0; i < 3; i++) {
                    matrix[3][i] += -obj->unk4C[0] * src[0][i];
                    matrix[3][i] += -obj->unk4C[1] * src[1][i];
                    matrix[3][i] += -obj->unk4C[2] * src[2][i];
                    matrix[3][i] += obj->unk4C[i];
                }
            }
            func_80015724(out, matrix, out);
        }
        list++;
    }
}
