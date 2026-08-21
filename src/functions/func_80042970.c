/* Specification: specs/func_80042970.md (camera follow update) */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    Vec3f nodes[4];
} NodeGroup;

typedef struct {
    u8 pad0[0x20];
    f32 base[4][4];
    u8 pad60[0x4C];
    NodeGroup nodes;
    u8 padDC[0x174];
    f32 offset;
} Source;

typedef struct {
    u8 pad0[0x20];
    f32 view[4][4];
    u8 pad60[0x24];
    NodeGroup nodes;
    f32 frame[4][4];
    Source *source;
    u8 padF8[0x10];
    f32 result[4][4];
    u8 pad148[0x168];
    f32 timer;
} Target;

extern f64 D_800AAC98;
extern f32 D_800AACA0;
extern Source *func_8003F714(s32, s32);
extern void func_800156DC(f32 [4][4], f32 [4][4]);
extern void func_8003B02C(Vec3f *, f32 [4][4]);
extern void func_8003B184(Vec3f *, f32 [4][4], f32);

void func_80042970(Target *target) {
    Source *source;
    f32 unusedA[2];
    f32 result[4][4];
    f32 current[4][4];
    f32 probe[4][4];
    f32 unusedB[3];
    f32 delta[3];
    f32 unusedC[14];
    f32 lengthSquared;
    f32 baseProjection;
    f32 blend;

    (void)unusedA;
    (void)unusedB;
    (void)unusedC;
    source = target->source;
    if (source == 0) {
        target->source = func_8003F714(0x54657374, 0);
        return;
    }

    func_800156DC(current, source->base);
    current[3][2] += source->offset;
    target->nodes = source->nodes;
    target->nodes.nodes[0].y = 0.0f;
    func_8003B02C(target->nodes.nodes, target->frame);
    func_8003B184(target->nodes.nodes, probe, -0.01f);

    delta[0] = probe[3][0] - target->frame[3][0];
    delta[1] = probe[3][1] - target->frame[3][1];
    delta[2] = probe[3][2] - target->frame[3][2];
    baseProjection = target->frame[3][0] * delta[0] + target->frame[3][1] * delta[1] + delta[2] * target->frame[3][2];
    lengthSquared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (lengthSquared <= D_800AAC98) {
        blend = 0.0f;
    } else {
        blend = (current[3][0] * delta[0] + current[3][1] * delta[1] + delta[2] * current[3][2] - baseProjection) / lengthSquared;
        if (blend > 1.0f) {
            blend = 1.0f;
        }
    }
    target->nodes.nodes[0].z -= D_800AACA0 * blend;
    func_8003B02C(target->nodes.nodes, target->frame);
    func_800156DC(result, target->frame);
    result[3][2] = current[3][2] + 5.0;
    result[3][0] = result[3][0] + 7.0;
    func_800156DC(target->view, result);
    func_800156DC(result, target->source->base);
    func_800156DC(target->result, result);
    target->timer = 60.0f;
}
