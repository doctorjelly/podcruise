/* Implements specs/functions/recovered/remaining_medium_audit_tranche.md. */
#include "podcruise/types.h"

extern f32 D_800AD97C;
extern f32 D_800AD980;
extern f32 D_800AD984;
extern void func_80017824(void *dst, f32 angle, f32 x, f32 y, f32 z, void *src);

void func_800745AC(u8 *obj) {
    f32 target;
    f32 level;
    f32 a;
    f32 b;
    u8 *part[1];

    target = 0.0f;
    if (*(f32 *)(obj + 0x2FC) < 0.0f) {
        target = *(f32 *)(obj + 0x2FC) * 100.0f;
    }
    if (*(f32 *)(obj + 0x1A0) < 100.0f) {
        target = 0.0f;
    }
    level = *(f32 *)(obj + 0x19B8);
    level = (target - level) * D_800AD97C + level;
    *(f32 *)(obj + 0x19B8) = level;

    a = *(f32 *)(obj + 0x204) / 45.0f;
    b = -a;
    if (a < 0.0f || 2.0f < a) {
        a = 0.0f;
    } else if (1.0f < a) {
        a = 2.0f - a;
    }
    if (b < 0.0f || 2.0f < b) {
        b = 0.0f;
    } else if (1.0f < b) {
        b = 2.0f - b;
    }

    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x4) != 0) {
        part[0] = obj + 0x40;
        func_80017824(part[0] + 0x350, (a * 0.5f + 1.0f) * level, 1.0f, 0.0f, 0.0f, part[0] + 0x350);
        *(f32 *)(part[0] + 0x388) = *(f32 *)(part[0] + 0x388) + level * D_800AD980;
    }
    if (*(s32 *)(*(u8 **)(obj + 0x344) + 0x8) != 0) {
        part[0] = obj + 0x80;
        func_80017824(part[0] + 0x350, (b * 0.5f + 1.0f) * level, 1.0f, 0.0f, 0.0f, part[0] + 0x350);
        *(f32 *)(part[0] + 0x388) = *(f32 *)(part[0] + 0x388) + level * D_800AD984;
    }
}
