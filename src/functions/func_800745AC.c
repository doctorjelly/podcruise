/* Implements specs/functions/recovered/remaining_medium_audit_tranche.md. */
#include "podcruise/types.h"

extern void func_80017824(void *dst, f32 angle, f32 x, f32 y, f32 z, void *src);

void func_800745AC(u8 *obj) {
    f32 vel;
    f32 level;
    f32 prev;
    f32 a;
    s32 i;
    u8 *part;
    f32 add;
    f32 b;

    i = 1;
    level = 0;
    vel = *(f32 *)(obj + 0x2FC);
    if (vel < 0.0f) {
        level = vel * -15.0f;
    }
    if (*(f32 *)(obj + 0x1A0) < 100.0f) {
        level = 0.0f;
    }
    prev = *(f32 *)(obj + 0x19B8);
    level = prev + (level - prev) * 0.1f;
    *(f32 *)(obj + 0x19B8) = level;

    a = *(f32 *)(obj + 0x204) / 45.0f;
    b = -a;
    if (a < 0.0f || 2.0f < a) {
        a = 0.0f;
    } else if (1 < a) {
        a = 2.0f - a;
    }
    if (b < 0.0f || 2.0f < b) {
        b = 0.0f;
    } else if (1.0f < b) {
        b = 2.0f - b;
    }

    if (*(s32 *)(*(u8 **)(obj + 0x344) + i * 4) != 0) {
        part = obj + i * 0x40;
        func_80017824(part + 0x350, (a * 0.5f + 1) * level, 1.0f, 0, 0, part + 0x350);
        *(f32 *)(part + 0x388) = *(f32 *)(part + 0x388) + level * 0.01f;
    }
    i = 2;
    if (*(s32 *)(*(u8 **)(obj + 0x344) + i * 4) != 0) {
        part = obj + i * 0x40;
        add = level * 0.01f;
        func_80017824(part + 0x350, (b * 0.5f + 1.0f) * level, 1.0f, 0, 0, part + 0x350);
        *(f32 *)(part + 0x388) = *(f32 *)(part + 0x388) + add;
    }
}
