/* Implements the specification in specs/func_8000EBE8.md (world point to screen box mapping). */
#include "podcruise/types.h"

extern f32 D_800A3FDC[3];
extern f64 D_800A8680;
extern s32 D_800D697C;
extern f32 D_80112E20[16];

extern void func_80081730(f32 *result, f32 *point, f32 (*matrix)[4]);

void func_8000EBE8(s16 *obj, f32 *pos, f32 *outX, f32 *outY, f32 *outZ, f32 *outW, s32 mode) {
    f32 m[16];
    f32 pad0;
    f32 res[4];
    f32 point[3];
    f32 y;
    f32 x;
    s32 c;
    s32 e;
    f32 q[2];
    f32 dA;
    f32 dB;
    f32 sz[2];
    s32 a;
    s32 b;

    m[0] = D_80112E20[0]; m[1] = D_80112E20[1]; m[2] = D_80112E20[2]; m[3] = D_80112E20[3];
    m[4] = D_80112E20[4]; m[5] = D_80112E20[5]; m[6] = D_80112E20[6]; m[7] = D_80112E20[7];
    m[8] = D_80112E20[8]; m[9] = D_80112E20[9]; m[10] = D_80112E20[10]; m[11] = D_80112E20[11];
    m[12] = D_80112E20[12]; m[13] = D_80112E20[13]; m[14] = D_80112E20[14]; m[15] = D_80112E20[15];
    a = obj[8];
    b = obj[9];
    a = a / 2;
    b = b / 2;
    sz[1] = (f32)a;
    sz[0] = (f32)b;
    q[1] = sz[1] * 0.5f;
    q[0] = sz[0] * 0.5f;
    c = obj[12];
    e = obj[13];
    *outX = -1000.0f;
    dA = (f32)(c / 4) - q[1];
    *outY = -1000.0f;
    dB = (f32)(e / 4) - q[0];
    if (mode == 0) {
        point[0] = pos[0] - D_800A3FDC[0];
        point[1] = pos[1] - D_800A3FDC[1];
        point[2] = pos[2] - D_800A3FDC[2];
        func_80081730(res, point, (f32 (*)[4])m);
    } else {
        func_80081730(res, pos, (f32 (*)[4])m);
    }
    if (D_800D697C & 0x4000) {
        res[0] = -res[0];
    }
    if (res[3] > D_800A8680) {
        y = (1.0f - res[1] / res[3]) * q[0] + dB;
        x = (res[0] / res[3] + 1.0f) * q[1] + dA;
        *outZ = res[2] / res[3];
        *outW = res[3];
        if (dA - 8.0f < x && x < sz[1] + dA + 8.0f && dB - 8.0f < y && y < sz[0] + dB + 8.0f) {
            *outX = x;
            *outY = y;
        }
    }
    (void)pad0;
}
