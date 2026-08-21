/* Recovered from specs/functions/recovered/extended_runtime_tranche.md. */
#include "podcruise/vector_math.h"

extern f64 D_800AD988;
extern f64 D_800AD990;
extern f64 D_80120BF0;

extern f32 func_800154D0(f32 *vector);
extern void func_80017824(void *dst, f32 angle, f32 x, f32 y, f32 z, void *src);
extern void func_80017BA8(void *destination, const void *source);

void func_800747E4(u8 *obj) {
    PcVec3f axis;
    PcVec3f pivot;
    PcVec3f origin;
    PcVec3fSlot mtx[4];
    s32 index;
    f32 dir;
    u8 *part;

    if (!(*(u32 *)(obj + 0x60) & 0x20) && !(*(u32 *)(obj + 0x64) & 0x04000000)) {
        return;
    }
    if (*(u32 *)(obj + 0x64) & 0x8000) {
        dir = -1.0f;
    } else if (*(u32 *)(obj + 0x64) & 0x10000) {
        dir = 1.0f;
    } else {
        *(f32 *)(obj + 0x340) = 0.0f;
        *(f32 *)(obj + 0x33C) = 0.0f;
        *(f32 *)(obj + 0x338) = 0.0f;
        dir = 0.0f;
    }
    if (dir == 0.0f) {
        return;
    }


    *(f32 *)(obj + 0x340) = *(f32 *)(obj + 0x340) + D_80120BF0 * 0.5;
    if (1.0f < *(f32 *)(obj + 0x340)) {
        *(f32 *)(obj + 0x340) = 1.0f;
    }
    if (dir > 0.0f) {
        index = 1;
    } else {
        index = 2;
    }
    *(f32 *)(obj + 0x338) = *(f32 *)(obj + 0x338) +
        dir * D_800AD988 * *(f32 *)(obj + 0x340) * D_80120BF0;

    part = obj + index * 0x40;
    func_800156DC(mtx, (PcVec3fSlot *)(part + 0x350));
    func_800155EC(&axis, &mtx[1].value, 0.0f, &mtx[0].value);
    func_80015288(&axis, &mtx[1].value);
    func_80015268(&axis, 0.0f, 1.0f, 0.0f);
    func_800154D0((f32 *)&axis);
    func_80015288(&origin, (PcVec3f *)(part + 0x380));
    func_80017824(part + 0x350, *(f32 *)(obj + 0x338), axis.x, axis.y, axis.z,
                  part + 0x350);
    func_80015288((PcVec3f *)(part + 0x380), &origin);
    if (*(u8 **)(*(u8 **)(obj + 0x344) + index * 4) != 0) {
        func_80017BA8(*(u8 **)(*(u8 **)(obj + 0x344) + index * 4), part + 0x350);
    }

    *(f32 *)(obj + 0x33C) = *(f32 *)(obj + 0x33C) +
        dir * D_800AD990 * *(f32 *)(obj + 0x340) * D_80120BF0;

    part = obj + 0x140;
    func_800156DC(mtx, (PcVec3fSlot *)(part + 0x350));
    func_800155EC(&pivot, &mtx[1].value, 0.0f, &mtx[0].value);
    func_80015288(&pivot, &mtx[1].value);
    func_80015268(&pivot, dir * 0.5, 1.0f, 0.0f);
    func_800154D0((f32 *)&pivot);
    func_80015288(&origin, (PcVec3f *)(part + 0x380));
    func_80017824(part + 0x350, *(f32 *)(obj + 0x33C), pivot.x, pivot.y, pivot.z,
                  part + 0x350);
    func_80015288((PcVec3f *)(part + 0x380), &origin);
    if (*(u8 **)(*(u8 **)(obj + 0x344) + 0x14) != 0) {
        func_80017BA8(*(u8 **)(*(u8 **)(obj + 0x344) + 0x14), part + 0x350);
    }
}
