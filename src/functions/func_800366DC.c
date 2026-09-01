/* Specification: specs/functions/recovered/func_800366DC.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800366DC;

typedef struct {
    u8 col[4];
    u8 colc[4];
    s8 dir[4];
    u8 pad[4];
} Light800366DC;

typedef struct {
    u8 unk00[0xA0];
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
} View800366DC;

extern s32 D_800A3FE8;
extern f32 D_800AAAE0;
extern f32 D_800AAAE4;
extern f32 D_800AAAE8;
extern Gfx800366DC *D_80112C90;
extern View800366DC *D_80112C94;
extern void func_80034374(f32 dest[4][4]);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *out, f32 *left, f32 *right);

#define PACK(v) (((v) * 128.0f < 127.0f) ? ((v) * 128.0f) : 127.0f)

void func_800366DC(Light800366DC *lights) {
    f32 matrix[4][4];
    f32 diff[3];
    f32 vecB[3];
    f32 vecA[3];
    Gfx800366DC *gfx;
    f32 distance;
    f32 value;

    if (D_800A3FE8 != 0) {
        func_80034374(matrix);
        diff[0] = matrix[3][0] - D_80112C94->unkA0;
        diff[1] = matrix[3][1] - D_80112C94->unkA4;
        diff[2] = matrix[3][2] - D_80112C94->unkA8;
        distance = func_800154D0(diff);
        if (distance < D_800AAAE0) {
            vecA[0] = 0.0f;
            vecA[1] = 0.0f;
            vecA[2] = 1.0f;
            vecB[0] = 1.0f;
            vecB[1] = 0.0f;
            vecB[2] = 0.0f;
        } else if (D_800AAAE4 < diff[2]) {
            vecA[0] = 0.0f;
            vecA[1] = 1.0f;
            vecA[2] = 0.0f;
            vecB[0] = 1.0f;
            vecB[1] = 0.0f;
            vecB[2] = 0.0f;
        } else if (diff[2] < D_800AAAE8) {
            vecA[0] = 0.0f;
            vecA[1] = -1.0f;
            vecA[2] = 0.0f;
            vecB[0] = -1.0f;
            vecB[1] = 0.0f;
            vecB[2] = 0.0f;
        } else {
            vecB[0] = diff[1];
            vecB[1] = -diff[0];
            vecB[2] = 0.0f;
            func_800154D0(vecB);
            func_80015538(vecA, vecB, diff);
        }

        value = PACK(vecB[0]); lights[0].dir[0] = value;
        value = PACK(vecB[1]); lights[0].dir[1] = value;
        value = PACK(vecB[2]); lights[0].dir[2] = value;
        value = PACK(vecA[0]); lights[1].dir[0] = value;
        value = PACK(vecA[1]); lights[1].dir[1] = value;
        value = PACK(vecA[2]); lights[1].dir[2] = value;

        lights[0].col[0] = 0;
        lights[0].col[1] = 0;
        lights[0].col[2] = 0;
        lights[0].col[3] = 0;
        lights[0].colc[0] = 0;
        lights[0].colc[1] = 0;
        lights[0].colc[2] = 0;
        lights[0].colc[3] = 0;
        lights[1].col[0] = 0;
        lights[1].col[1] = 0x80;
        lights[1].col[2] = 0;
        lights[1].col[3] = 0;
        lights[1].colc[0] = 0;
        lights[1].colc[1] = 0x80;
        lights[1].colc[2] = 0;
        lights[1].colc[3] = 0;

        gfx = D_80112C90++; gfx->w0 = 0xDC08000A; gfx->w1 = (u32)(unsigned long)&lights[0];
        gfx = D_80112C90++; gfx->w0 = 0xDC08030A; gfx->w1 = (u32)(unsigned long)&lights[1];
    }
}
