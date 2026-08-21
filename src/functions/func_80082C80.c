/* Recovered from specification $S/specs/func_80082C80.md */
#include "podcruise/types.h"

typedef struct Mtx80082C80 {
    f32 m[4][4];
} Mtx80082C80;

extern u32 func_80017DA4(const void *object);
extern s32 func_80017DAC(const void *object);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_80015724(f32 output[4][4], const f32 left[4][4],
                          const f32 right[4][4]);

void func_80082C80(u8 *root, Mtx80082C80 *out, u8 *node, Mtx80082C80 *parent) {
    s32 type;
    s32 count;
    f32 (*src)[3];
    u8 *anchor;
    u8 *holder;
    s32 i;
    Mtx80082C80 world;
    Mtx80082C80 local;
    s32 index;

    if (node == 0) {
        return;
    }
#if defined(__GNUC__)
    holder = node;
#endif
    type = func_80017DA4(node);
    func_800156DC(world.m, parent->m);

    if (type == 0x5064) {
        goto merged;
    }
    if (type != 0xD064 && type != 0xD065) {
        goto unknown;
    }
        src = (f32 (*)[3])(node + 0x1C);
        if (type == 0xD065) {
            anchor = node;
        } else {
            anchor = holder;
        }
        local.m[0][0] = src[0][0];
        local.m[0][1] = src[0][1];
        local.m[0][2] = src[0][2];
        local.m[1][0] = src[1][0];
        local.m[1][1] = src[1][1];
        local.m[1][2] = src[1][2];
        local.m[2][0] = src[2][0];
        local.m[2][1] = src[2][1];
        local.m[2][2] = src[2][2];
        local.m[3][0] = src[3][0];
        local.m[3][1] = src[3][1];
        local.m[3][2] = src[3][2];
        local.m[0][3] = 0.0f;
        local.m[1][3] = 0.0f;
        local.m[2][3] = 0.0f;
        local.m[3][3] = 1.0f;
        if (*(u16 *)(node + 0xC) & 0x10) {
            for (i = 0; i < 3; i++) {
                local.m[3][i] = -*(f32 *)(anchor + 0x4C) * src[0][i] + local.m[3][i];
                local.m[3][i] = -*(f32 *)(anchor + 0x50) * src[1][i] + local.m[3][i];
                local.m[3][i] = -*(f32 *)(anchor + 0x54) * src[2][i] + local.m[3][i];
                local.m[3][i] = *(f32 *)(anchor + 0x4C + i * 4) + local.m[3][i];
            }
        }
        func_80015724(world.m, local.m, parent->m);
merged:
    if (root == node) {
        out->m[0][0] = world.m[0][0];
        out->m[0][1] = world.m[0][1];
        out->m[0][2] = world.m[0][2];
        out->m[0][3] = world.m[0][3];
        out->m[1][0] = world.m[1][0];
        out->m[1][1] = world.m[1][1];
        out->m[1][2] = world.m[1][2];
        out->m[1][3] = world.m[1][3];
        out->m[2][0] = world.m[2][0];
        out->m[2][1] = world.m[2][1];
        out->m[2][2] = world.m[2][2];
        out->m[2][3] = world.m[2][3];
        out->m[3][0] = world.m[3][0];
        out->m[3][1] = world.m[3][1];
        out->m[3][2] = world.m[3][2];
        out->m[3][3] = world.m[3][3];
    }
    count = func_80017DAC(node);
    for (index = 0; index < count; index++) {
        if (((u8 **)*(u8 **)(node + 0x18))[index] != 0) {
            func_80082C80(root, out, ((u8 **)*(u8 **)(node + 0x18))[index], &world);
        }
    }
    return;

unknown:
    if (root == node) {
        out->m[0][0] = world.m[0][0];
        out->m[0][1] = world.m[0][1];
        out->m[0][2] = world.m[0][2];
        out->m[0][3] = world.m[0][3];
        out->m[1][0] = world.m[1][0];
        out->m[1][1] = world.m[1][1];
        out->m[1][2] = world.m[1][2];
        out->m[1][3] = world.m[1][3];
        out->m[2][0] = world.m[2][0];
        out->m[2][1] = world.m[2][1];
        out->m[2][2] = world.m[2][2];
        out->m[2][3] = world.m[2][3];
        out->m[3][0] = world.m[3][0];
        out->m[3][1] = world.m[3][1];
        out->m[3][2] = world.m[3][2];
        out->m[3][3] = world.m[3][3];
    }
}
