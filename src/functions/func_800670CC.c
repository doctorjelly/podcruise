/* Recovered per specs/func_800670CC.md (podcruise worker specification). */
#include "podcruise/types.h"

typedef struct Vec3800670CC {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3800670CC;

typedef struct Ray800670CC {
    /* 0x00 */ Vec3800670CC origin;
    /* 0x0C */ Vec3800670CC direction;
    /* 0x18 */ f32 reach;
} Ray800670CC;

typedef struct Owner800670CC {
    /* 0x000 */ u8 pad000[0x64];
    /* 0x064 */ u32 flags;
    /* 0x068 */ u8 pad068[0xEC - 0x68];
    /* 0x0EC */ void *nearScene;
    /* 0x0F0 */ u8 pad0F0[0x13C - 0xF0];
    /* 0x13C */ void *scene;
    /* 0x140 */ s32 stamp;
    /* 0x144 */ u8 pad144[0x160 - 0x144];
    /* 0x160 */ Vec3800670CC forward;
    /* 0x16C */ u8 pad16C[0x188 - 0x16C];
    /* 0x188 */ f32 height;
    /* 0x18C */ u8 pad18C[0x194 - 0x18C];
    /* 0x194 */ Vec3800670CC down;
} Owner800670CC;

extern f32 D_800AD4B8;
extern f32 D_800AD4BC;
extern f32 D_800AD4C0;

extern void func_800155EC(Vec3800670CC *output, Vec3800670CC *base, f32 scale,
                          Vec3800670CC *offset);
extern void func_8000052C(void);
extern s32 func_80000538(void);
extern f32 func_80005240(void *scene, Ray800670CC *ray, Vec3800670CC *hit,
                         Vec3800670CC *normal);
extern f32 func_80004FB0(void *scene, Ray800670CC *ray, Vec3800670CC *hit,
                         Vec3800670CC *normal);

f32 func_800670CC(Owner800670CC *owner, Vec3800670CC *origin,
                  Vec3800670CC *output) {
    Vec3800670CC start;
    f32 pad0;
    f32 distance;
    Vec3800670CC hit;
    Vec3800670CC normal;
    f32 pad1;
    Ray800670CC ray;
    Vec3800670CC direction;

    (void)pad0;
    (void)pad1;
    if (owner->flags & 0x400) {
        direction.x = -owner->forward.x;
        direction.y = -owner->forward.y;
        direction.z = -owner->forward.z;
    } else {
        direction.x = owner->down.x;
        direction.y = owner->down.y;
        direction.z = owner->down.z;
    }
    func_800155EC(&start, origin, -2.0f, &direction);
    ray.reach = D_800AD4B8;
    ray.direction.x = direction.x;
    ray.direction.y = direction.y;
    ray.direction.z = direction.z;
    ray.origin.x = start.x; ray.origin.y = start.y; ray.origin.z = start.z;
    func_8000052C();
    if (!(owner->flags & 0x80)) {
        distance = func_80005240(owner->nearScene, &ray, &hit, &normal);
    } else {
        distance = -1.0f;
    }
    if (distance < 0.0f) {
        distance = func_80004FB0(owner->scene, &ray, &hit, &normal);
    }
    if ((owner->flags & 0x400) && distance < 0.0f) {
        direction.x = owner->down.x;
        direction.y = owner->down.y;
        direction.z = owner->down.z;
        ray.direction.x = direction.x;
        ray.direction.y = direction.y;
        ray.direction.z = direction.z;
        distance = func_80004FB0(owner->scene, &ray, &hit, &normal);
    }
    owner->stamp = func_80000538();
    if (distance < 0.0f) {
        output->x = 0.0f;
        output->y = 0.0f;
        output->z = 1.0f;
        owner->height = D_800AD4BC;
        return D_800AD4C0;
    }
    output->x = normal.x;
    output->y = normal.y;
    output->z = normal.z;
    owner->height = hit.z;
    return distance - 2.0f;
}
