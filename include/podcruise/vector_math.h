#ifndef PODCRUISE_VECTOR_MATH_H
#define PODCRUISE_VECTOR_MATH_H

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
} PcVec2f;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    PcVec3f value;
    f32 padding;
} PcVec3fSlot;

void func_8001514C(PcVec2f *output, const PcVec2f *left, const PcVec2f *right);
void func_80015170(PcVec2f *output, f32 scale, const PcVec2f *source);
void func_80015190(PcVec2f *output, const PcVec2f *base, f32 scale,
                   const PcVec2f *offset);
f32 func_800151C0(const PcVec2f *vector);
void func_800152A4(PcVec3f *output, const PcVec3f *source);
void func_80015630(PcVec3f *output, f32 first_scale, const PcVec3f *second,
                   f32 second_scale, const PcVec3f *first);
u8 func_800152CC(const PcVec3f *left, const PcVec3f *right);
void func_80015268(PcVec3f *output, f32 x, f32 y, f32 z);
void func_80015288(PcVec3f *output, const PcVec3f *source);
void func_80015328(PcVec3f *output, const PcVec3f *left, const PcVec3f *right);
void func_8001535C(PcVec3f *output, const PcVec3f *left, const PcVec3f *right);
f32 func_80015390(const PcVec3f *left, const PcVec3f *right);
f32 func_800153C0(const PcVec3f *vector);
f32 func_800153EC(const PcVec3f *left, const PcVec3f *right);
void func_800155C0(PcVec3f *output, f32 scale, const PcVec3f *source);
void func_800155EC(PcVec3f *output, const PcVec3f *base, f32 scale,
                   const PcVec3f *offset);
void func_80015694(PcVec3fSlot *slots, s32 index, const PcVec3f *source);
void func_800156B8(const PcVec3fSlot *slots, s32 index, PcVec3f *output);
void func_800156DC(PcVec3fSlot *output, const PcVec3fSlot *source);

#endif
