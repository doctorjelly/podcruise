/* Recovered from specs/functions/recovered/extended_runtime_tranche.md. */
#include "podcruise/vector_math.h"

typedef struct Pose800419EC {
    f32 row[4][3];
} Pose800419EC;

extern f64 D_80120BF0;
extern f64 D_800AAC50;
extern f32 D_800AAC58;

extern void func_80041214(u8 *record);
extern void func_8003B02C(void *track, void *matrix);
extern f32 func_800154D0(f32 *vector);

void func_800419EC(u8 *obj) {
    f32 first[4][4];
    f32 second[4][4];
    PcVec3f axis;
    f32 blend;
    PcVec3f offset;
    PcVec3f base;
    u8 *link;
    s32 state;
    f32 tailpad[2];

    (void)tailpad;
    (void)first;
    (void)second;
    link = *(u8 **)(obj + 0xF4);
    if (link == 0) {
        func_80041214(obj);
        return;
    }
    *(f32 *)(obj + 0x70) = *(f32 *)(obj + 0x70) - D_80120BF0;
    state = *(s32 *)(obj + 0x6C);
    if (state == 0) {
        if (*(f32 *)(obj + 0x70) < 0.0f) {
            *(s32 *)(obj + 0x6C) = 2;
            *(f32 *)(obj + 0x70) = 1.5f;
            *(Pose800419EC *)(obj + 0x1B4) = *(Pose800419EC *)(link + 0xAC);
            *(f32 *)(obj + 0x1B8) = 0.0f;
            *(f32 *)(obj + 0x1BC) = *(f32 *)(obj + 0x1BC) - D_800AAC50;
            func_8003B02C(obj + 0x1B4, obj + 0x1E4);
            *(f32 *)(obj + 0x1B8) = D_800AAC58;
            blend = 1.0f;
        } else {
            blend = 1.0 - *(f32 *)(obj + 0x70) / 1.0;
        }
        func_8001535C(&axis, (PcVec3f *)(obj + 0x168), (PcVec3f *)(obj + 0x15C));
        func_800154D0((f32 *)&axis);
        func_800155EC(&offset, (PcVec3f *)(obj + 0x15C), 30.0f * blend, &axis);
        *(f32 *)(obj + 0x18C) = offset.x;
        *(f32 *)(obj + 0x190) = offset.y;
        *(f32 *)(obj + 0x194) = offset.z;
        func_80015288(&base, (PcVec3f *)(obj + 0x15C));
    } else if (state == 2) {
        if (*(f32 *)(obj + 0x70) < 0.0f) {
            *(f32 *)(obj + 0x70) = 0.0f;
            *(s32 *)(obj + 0x6C) = 3;
        }
        func_8003B02C(obj + 0x1B4, obj + 0x1E4);
        func_80015288(&base, (PcVec3f *)(link + 0x50));
        offset.x = *(f32 *)(obj + 0x214);
        offset.y = *(f32 *)(obj + 0x218);
        offset.z = *(f32 *)(obj + 0x21C);
    } else if (state == 3) {
        *(u32 *)(link + 0x60) = *(u32 *)(link + 0x60) & ~0x4000;
        *(u32 *)(link + 0x60) = *(u32 *)(link + 0x60) | 0x2000;
        *(f32 *)(link + 0x30C) = 3.0f;
        func_80041214(obj);
        offset.x = *(f32 *)(obj + 0x50);
        offset.y = *(f32 *)(obj + 0x54);
        offset.z = *(f32 *)(obj + 0x58);
        base.x = *(f32 *)(obj + 0x138);
        base.y = *(f32 *)(obj + 0x13C);
        base.z = *(f32 *)(obj + 0x140);
    }
    *(f32 *)(obj + 0x20) = 1.0f;
    *(f32 *)(obj + 0x24) = 0.0f;
    *(f32 *)(obj + 0x28) = 0.0f;
    *(f32 *)(obj + 0x2C) = 0.0f;
    *(f32 *)(obj + 0x30) = 0.0f;
    *(f32 *)(obj + 0x34) = 1.0f;
    *(f32 *)(obj + 0x38) = 0.0f;
    *(f32 *)(obj + 0x3C) = 0.0f;
    *(f32 *)(obj + 0x40) = 0.0f;
    *(f32 *)(obj + 0x44) = 0.0f;
    *(f32 *)(obj + 0x48) = 1.0f;
    *(f32 *)(obj + 0x4C) = 0.0f;
    *(f32 *)(obj + 0x50) = 0.0f;
    *(f32 *)(obj + 0x54) = 0.0f;
    *(f32 *)(obj + 0x58) = 0.0f;
    *(f32 *)(obj + 0x5C) = 1.0f;
    *(f32 *)(obj + 0x108) = 1.0f;
    *(f32 *)(obj + 0x10C) = 0.0f;
    *(f32 *)(obj + 0x110) = 0.0f;
    *(f32 *)(obj + 0x114) = 0.0f;
    *(f32 *)(obj + 0x118) = 0.0f;
    *(f32 *)(obj + 0x11C) = 1.0f;
    *(f32 *)(obj + 0x120) = 0.0f;
    *(f32 *)(obj + 0x124) = 0.0f;
    *(f32 *)(obj + 0x128) = 0.0f;
    *(f32 *)(obj + 0x12C) = 0.0f;
    *(f32 *)(obj + 0x130) = 1.0f;
    *(f32 *)(obj + 0x134) = 0.0f;
    *(f32 *)(obj + 0x138) = 0.0f;
    *(f32 *)(obj + 0x13C) = 0.0f;
    *(f32 *)(obj + 0x140) = 0.0f;
    *(f32 *)(obj + 0x144) = 1.0f;
    *(f32 *)(obj + 0x50) = offset.x;
    *(f32 *)(obj + 0x54) = offset.y;
    *(f32 *)(obj + 0x58) = offset.z;
    *(f32 *)(obj + 0x138) = base.x;
    *(f32 *)(obj + 0x13C) = base.y;
    *(f32 *)(obj + 0x140) = base.z;
}
