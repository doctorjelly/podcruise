/* Recovered from specification specs/func_800366DC.md (uncovered-split worker unc_03). */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 w0;
    /* 0x4 */ u8 *w1;
} GfxCmd;

extern s32 D_800A3FE8;
extern f32 *D_80112C94;
extern GfxCmd *D_80112C90;
extern f32 D_800AAAE0;
extern f32 D_800AAAE4;
extern f32 D_800AAAE8;

extern void func_80034374(f32 matrix[4][4]);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *output, f32 *left, f32 *right);

void func_800366DC(u8 *light) {
    f32 matrix[4][4];
    f32 offset[3];
    f32 first[3];
    f32 second[3];

    if (D_800A3FE8 == 0) {
        return;
    }

    func_80034374(matrix);
    offset[0] = matrix[3][0] - D_80112C94[0x28];
    offset[1] = matrix[3][1] - D_80112C94[0x29];
    offset[2] = matrix[3][2] - D_80112C94[0x2A];

    if (func_800154D0(offset) < D_800AAAE0) {
        second[0] = 0.0f;
        second[1] = 0.0f;
        second[2] = 1.0f;
        first[0] = 1.0f;
        first[1] = 0.0f;
        first[2] = 0.0f;
    } else if (D_800AAAE4 < offset[2]) {
        second[0] = 0.0f;
        second[1] = 1.0f;
        second[2] = 0.0f;
        first[0] = 1.0f;
        first[1] = 0.0f;
        first[2] = 0.0f;
    } else if (offset[2] < D_800AAAE8) {
        second[0] = 0.0f;
        second[1] = -1.0f;
        second[2] = 0.0f;
        first[0] = -1.0f;
        first[1] = 0.0f;
        first[2] = 0.0f;
    } else {
        first[0] = offset[1];
        first[1] = -offset[0];
        first[2] = 0.0f;
        func_800154D0(first);
        func_80015538(second, first, offset);
    }

    light[8] = (s32)(first[0] * 128.0f < 127.0f ? first[0] * 128.0f : 127.0f);
    light[9] = (s32)(first[1] * 128.0f < 127.0f ? first[1] * 128.0f : 127.0f);
    light[10] = (s32)(first[2] * 128.0f < 127.0f ? first[2] * 128.0f : 127.0f);
    light[24] = (s32)(second[0] * 128.0f < 127.0f ? second[0] * 128.0f : 127.0f);
    light[25] = (s32)(second[1] * 128.0f < 127.0f ? second[1] * 128.0f : 127.0f);
    light[26] = (s32)(second[2] * 128.0f < 127.0f ? second[2] * 128.0f : 127.0f);

    light[0] = 0;
    light[1] = 0;
    light[2] = 0;
    light[3] = 0;
    light[4] = 0;
    light[5] = 0;
    light[6] = 0;
    light[7] = 0;
    light[16] = 0;
    light[17] = 128;
    light[18] = 0;
    light[19] = 0;
    light[20] = 0;
    light[21] = 128;
    light[22] = 0;
    light[23] = 0;

    {
        GfxCmd *gfx = D_80112C90++;
        gfx->w1 = light;
        gfx->w0 = 0xDC08000A;
    }
    {
        GfxCmd *gfx = D_80112C90++;
        gfx->w1 = light + 16;
        gfx->w0 = 0xDC08030A;
    }
}
