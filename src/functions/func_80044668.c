/* Independently written from specs/functions/recovered/func_80044668.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *head;
    /* 0x04 */ u8 rest[0x2C];
} ListSlot44668; /* 0x30 */

typedef struct {
    /* 0x00 */ u8 data[0x58];
} NodeSlot44668;

typedef struct {
    /* 0x0000 */ u8 unk0000[0xEC];
    /* 0x00EC */ s32 enabled[6];
    /* 0x0104 */ ListSlot44668 lists[3][6];
    /* 0x0464 */ u8 unk0464[0x718];
    /* 0x0B7C */ f32 result[6];
    /* 0x0B94 */ u8 unk0B94[0x20];
    /* 0x0BB4 */ s32 handle;
    /* 0x0BB8 */ u8 unk0BB8[0x4DC];
    /* 0x1094 */ NodeSlot44668 nodes[6][3];
} Ctx44668;

extern void func_80000520(s32 mode);
extern f32 func_80004FB0(s32 handle, f32 *ray, f32 *hit, f32 *normal);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *output, f32 *left, f32 *right);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern void func_80083190(void *list, f32 (*out)[4]);

void func_80044668(Ctx44668 *ctx) {
    s32 handle;
    f32 distance;
    f32 hit[3];
    f32 normal[3];
    f32 ray[7];
    s32 i;
    f32 matrix[4][4];

    handle = ctx->handle;
    ray[6] = 1000.0f;
    ray[3] = 0.0f;
    ray[4] = 0.0f;
    ray[5] = -1.0f;
    for (i = 0; i < 6; i++) {
        if (ctx->enabled[i] != 0) {
            func_80083190(&ctx->lists[0][i].head, matrix);
            ray[0] = matrix[3][0];
            ray[1] = matrix[3][1];
            ray[2] = matrix[3][2];
            func_80000520(1);
            distance = func_80004FB0(handle, ray, hit, normal);
            func_80000520(0);
            if (0.0f < distance) {
                matrix[2][0] = normal[0];
                matrix[2][1] = normal[1];
                matrix[2][2] = normal[2];
                func_800154D0(matrix[1]);
                func_80015538(matrix[0], matrix[1], matrix[2]);
                func_80015538(matrix[1], matrix[2], matrix[0]);
                matrix[3][0] = hit[0];
                matrix[3][1] = hit[1];
                matrix[3][2] = hit[2];
                func_80017BA8(((u8 *)ctx + 0x1094 + i * 0x108), matrix);
                if (((u8 *)ctx + 0x1094 + i * 0x108) != 0) {
                    func_800181BC(((u8 *)ctx + 0x1094 + i * 0x108), 2, 3, 0x10, 2);
                }
            } else if (((u8 *)ctx + 0x1094 + i * 0x108) != 0) {
                func_800181BC(((u8 *)ctx + 0x1094 + i * 0x108), 2, -4, 0x10, 3);
            }

            func_80083190(&ctx->lists[1][i].head, matrix);
            ray[0] = matrix[3][0];
            ray[1] = matrix[3][1];
            ray[2] = matrix[3][2];
            func_80000520(1);
            distance = func_80004FB0(handle, ray, hit, normal);
            func_80000520(0);
            if (0.0f < distance) {
                matrix[2][0] = normal[0];
                matrix[2][1] = normal[1];
                matrix[2][2] = normal[2];
                func_800154D0(matrix[1]);
                func_80015538(matrix[0], matrix[1], matrix[2]);
                func_80015538(matrix[1], matrix[2], matrix[0]);
                matrix[3][0] = hit[0];
                matrix[3][1] = hit[1];
                matrix[3][2] = hit[2];
                func_80017BA8(((u8 *)ctx + 0x10EC + i * 0x108), matrix);
                if (((u8 *)ctx + 0x10EC + i * 0x108) != 0) {
                    func_800181BC(((u8 *)ctx + 0x10EC + i * 0x108), 2, 3, 0x10, 2);
                }
            } else if (((u8 *)ctx + 0x10EC + i * 0x108) != 0) {
                func_800181BC(((u8 *)ctx + 0x10EC + i * 0x108), 2, -4, 0x10, 3);
            }

            func_80083190(&ctx->lists[2][i].head, matrix);
            ray[0] = matrix[3][0];
            ray[1] = matrix[3][1];
            ray[2] = matrix[3][2];
            func_80000520(1);
            distance = func_80004FB0(handle, ray, hit, normal);
            func_80000520(0);
            ctx->result[i] = distance;
            if (0.0f < distance) {
                matrix[2][0] = normal[0];
                matrix[2][1] = normal[1];
                matrix[2][2] = normal[2];
                func_800154D0(matrix[1]);
                func_80015538(matrix[0], matrix[1], matrix[2]);
                func_80015538(matrix[1], matrix[2], matrix[0]);
                matrix[3][0] = hit[0];
                matrix[3][1] = hit[1];
                matrix[3][2] = hit[2];
                func_80017BA8(((u8 *)ctx + 0x1144 + i * 0x108), matrix);
                if (((u8 *)ctx + 0x1144 + i * 0x108) != 0) {
                    func_800181BC(((u8 *)ctx + 0x1144 + i * 0x108), 2, 3, 0x10, 2);
                }
            } else if (((u8 *)ctx + 0x1144 + i * 0x108) != 0) {
                func_800181BC(((u8 *)ctx + 0x1144 + i * 0x108), 2, -4, 0x10, 3);
            }
        }
    }
}
