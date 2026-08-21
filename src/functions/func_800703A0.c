/* Implements the specification in specs/func_800703A0.md */
#include "podcruise/types.h"

typedef struct Vec3800703A0 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3800703A0;

typedef struct Ray800703A0 {
    /* 0x00 */ Vec3800703A0 origin;
    /* 0x0C */ Vec3800703A0 direction;
    /* 0x18 */ f32 reach;
} Ray800703A0;

typedef struct Owner800703A0 {
    /* 0x000 */ u8 pad000[0xAC];
    /* 0x0AC */ u8 placement[0x90];
    /* 0x13C */ void *scene;
} Owner800703A0;

extern f32 D_800AD800;

extern void func_8003B184(void *source, f32 (*matrix)[4], f32 offset);
extern void func_800155EC(Vec3800703A0 *output, const Vec3800703A0 *base,
                          f32 scale, const Vec3800703A0 *offset);
extern f32 func_80004FB0(void *scene, Ray800703A0 *ray, Vec3800703A0 *hit,
                         Vec3800703A0 *normal);

void func_800703A0(Vec3800703A0 *output, Owner800703A0 *owner) {
    f32 matrix[4][4];
    Ray800703A0 ray;
    Vec3800703A0 probe;
    Vec3800703A0 hit;
    Vec3800703A0 normal;
    f32 distance;

    func_8003B184(owner->placement, matrix, 1.0f);
    func_800155EC(&probe, (Vec3800703A0 *)matrix[3], 50.0f,
                  (Vec3800703A0 *)matrix[0]);
    probe.z = probe.z + 1000.0f;
    ray.reach = D_800AD800;
    ray.direction.x = 0.0f;
    ray.direction.y = 0.0f;
    ray.direction.z = -1.0f;
    ray.origin.x = probe.x; ray.origin.y = probe.y; ray.origin.z = probe.z;
    distance = func_80004FB0(owner->scene, &ray, &hit, &normal);
    if (distance < 0.0f) {
        output->x = matrix[3][0];
        output->y = matrix[3][1];
        output->z = matrix[3][2];
    } else {
        hit.z = hit.z + 20.0f;
        output->x = hit.x;
        output->y = hit.y;
        output->z = hit.z;
    }
}
