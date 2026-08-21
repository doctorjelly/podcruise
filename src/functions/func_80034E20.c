/* Independently written from scratchpad spec specs/func_80034E20.md. */

#include "podcruise/types.h"

typedef struct Slot80033E08 {
    u8 data[0x40];
} Slot80033E08;

typedef struct Gfx80034E20 {
    u32 w0;
    u32 w1;
} Gfx80034E20;

typedef f32 Mat43[4][3];

extern Slot80033E08 *func_80033E08(void);
extern void func_800344F4(s16 *destination, f32 source[4][4]);
extern void func_80034650(s16 *destination, f32 source[4][3]);

extern f32 D_800A3FDC[3];
extern s32 D_800A3FEC;
extern s32 D_800A3FF0;
extern Gfx80034E20 *D_80112C90;
extern f32 D_80112E20[4][4];
extern Mat43 D_80112EA0[];

#define GFX_APPEND(command, argument) { Gfx80034E20 *gfx = D_80112C90++; gfx->w0 = (u32)(command); gfx->w1 = (u32)(unsigned long)(argument); }

void func_80034E20(void) {
    f32 (*object)[3];
    f32 output[4][4];
    s16 *matrix;

    object = D_80112EA0[D_800A3FF0 - 1];

    if (D_800A3FEC != 0) {
        object[3][0] = object[3][0] - D_800A3FDC[0];
        object[3][1] = object[3][1] - D_800A3FDC[1];
        object[3][2] = object[3][2] - D_800A3FDC[2];
    }

    output[0][0] = D_80112E20[0][0] * object[0][0] + D_80112E20[1][0] * object[0][1] + D_80112E20[2][0] * object[0][2];
    output[0][1] = D_80112E20[0][1] * object[0][0] + D_80112E20[1][1] * object[0][1] + D_80112E20[2][1] * object[0][2];
    output[0][2] = D_80112E20[0][2] * object[0][0] + D_80112E20[1][2] * object[0][1] + D_80112E20[2][2] * object[0][2];
    output[0][3] = D_80112E20[0][3] * object[0][0] + D_80112E20[1][3] * object[0][1] + D_80112E20[2][3] * object[0][2];
    output[1][0] = D_80112E20[0][0] * object[1][0] + D_80112E20[1][0] * object[1][1] + D_80112E20[2][0] * object[1][2];
    output[1][1] = D_80112E20[0][1] * object[1][0] + D_80112E20[1][1] * object[1][1] + D_80112E20[2][1] * object[1][2];
    output[1][2] = D_80112E20[0][2] * object[1][0] + D_80112E20[1][2] * object[1][1] + D_80112E20[2][2] * object[1][2];
    output[1][3] = D_80112E20[0][3] * object[1][0] + D_80112E20[1][3] * object[1][1] + D_80112E20[2][3] * object[1][2];
    output[2][0] = D_80112E20[0][0] * object[2][0] + D_80112E20[1][0] * object[2][1] + D_80112E20[2][0] * object[2][2];
    output[2][1] = D_80112E20[0][1] * object[2][0] + D_80112E20[1][1] * object[2][1] + D_80112E20[2][1] * object[2][2];
    output[2][2] = D_80112E20[0][2] * object[2][0] + D_80112E20[1][2] * object[2][1] + D_80112E20[2][2] * object[2][2];
    output[2][3] = D_80112E20[0][3] * object[2][0] + D_80112E20[1][3] * object[2][1] + D_80112E20[2][3] * object[2][2];
    output[3][0] = ((D_80112E20[0][0] * object[3][0] + D_80112E20[1][0] * object[3][1]) + D_80112E20[2][0] * object[3][2]) + D_80112E20[3][0];
    output[3][1] = ((D_80112E20[0][1] * object[3][0] + D_80112E20[1][1] * object[3][1]) + D_80112E20[2][1] * object[3][2]) + D_80112E20[3][1];
    output[3][2] = ((D_80112E20[0][2] * object[3][0] + D_80112E20[1][2] * object[3][1]) + D_80112E20[2][2] * object[3][2]) + D_80112E20[3][2];
    output[3][3] = ((D_80112E20[0][3] * object[3][0] + D_80112E20[1][3] * object[3][1]) + D_80112E20[2][3] * object[3][2]) + D_80112E20[3][3];

    if (D_800A3FEC != 0) {
        object[3][0] = object[3][0] + D_800A3FDC[0];
        object[3][1] = object[3][1] + D_800A3FDC[1];
        object[3][2] = object[3][2] + D_800A3FDC[2];
    }

    matrix = (s16 *)func_80033E08();
    func_80034650(matrix, object);
    GFX_APPEND(0xDA380003, matrix)

    matrix = (s16 *)func_80033E08();
    func_800344F4(matrix, output);
    GFX_APPEND(0xDC38000E, matrix)
    GFX_APPEND(0xDB0C0000, 0x00010000)

}
