/* Independently written from specs/functions/func_80004160.md (batch_04). */

#include "podcruise/vector_math.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern f32 func_800154D0(f32 *vector);
extern void func_80015538(PcVec3f *output, const PcVec3f *left,
                          const PcVec3f *right);

extern s32 D_8009A280;
extern f32 D_800A813C;
extern f32 D_800AE8B0;
extern PcVec3f D_800AE8B8;
extern PcVec3f D_800AE8C8;
extern s32 D_800AE8D8;
extern f32 D_800AE8DC;

s32 func_80004160(PcVec3f *position, f32 first_offset, PcVec3f *direction,
                  f32 second_offset, f32 third_offset, PcVec3f *normal,
                  PcVec3f *tangent, PcVec3f *contact) {
    PcVec3f delta;
    PcVec3f sum;
    PcVec3f unused0;
    PcVec3f plane;
    PcVec3f scaled_first;
    PcVec3f scaled_second;
    PcVec3f cross0;
    f32 unused1[2];
    PcVec3f edge_first;
    PcVec3f edge_second;
    PcVec3f cross_first;
    PcVec3f cross_second;
    f32 length;



    (void)unused0;
    (void)unused1;

    if (D_800AE8B0 < D_800AE8DC) {
        normal->x = D_800AE8C8.x;
        normal->y = D_800AE8C8.y;
        normal->z = D_800AE8C8.z;
        delta.x = position->x - D_800AE8B8.x;
        delta.y = position->y - D_800AE8B8.y;
        delta.z = position->z - D_800AE8B8.z;
        func_800154D0((f32 *)&delta);
        func_80015538(&cross0, &delta, direction);
        func_80015538(&plane, &cross0, direction);
        length = func_800153C0(&plane);
        if (length < D_800A813C) {
            if (direction->z * delta.z +
                    (delta.x * direction->x + delta.y * direction->y) <
                0.0f) {
                func_800155C0(&delta, -(second_offset - sqrtf(D_800AE8B0)),
                              normal);
            } else {
                func_800155C0(&delta, -third_offset - sqrtf(D_800AE8B0),
                              normal);
            }
            position->x = position->x + delta.x;
            position->y = position->y + delta.y;
            position->z = position->z + delta.z;
            tangent->x = -normal->x;
            tangent->y = -normal->y;
            tangent->z = -normal->z;
        } else {
            func_800155C0(&plane, 1.0f / length, &plane);
            func_800155C0(&scaled_first,
                          sqrtf(D_800AE8DC - second_offset * second_offset),
                          &plane);
            func_800155EC(&edge_first, &scaled_first, second_offset, direction);
            func_800155C0(&scaled_second,
                          sqrtf(D_800AE8DC - third_offset * third_offset),
                          &plane);
            func_800155EC(&edge_second, &scaled_second, third_offset,
                          direction);
            func_80015538(&cross_first, &edge_first, &delta);
            func_80015538(&cross_second, &edge_second, &delta);
            if (cross_second.z * cross_first.z +
                    (cross_first.x * cross_second.x +
                     cross_first.y * cross_second.y) <
                0.0f) {
                func_800155C0(&delta, first_offset - sqrtf(D_800AE8B0),
                              &delta);
                position->x = position->x + delta.x;
                position->y = position->y + delta.y;
                position->z = position->z + delta.z;
                tangent->x = -normal->x;
                tangent->y = -normal->y;
                tangent->z = -normal->z;
            } else {
                if (0.0f < normal->z * direction->z +
                         (direction->x * normal->x +
                          direction->y * normal->y)) {
                    sum.x = edge_second.x + position->x;
                    sum.y = edge_second.y + position->y;
                    sum.z = edge_second.z + position->z;
                    tangent->x = edge_second.x;
                    tangent->y = edge_second.y;
                    tangent->z = edge_second.z;
                } else {
                    sum.x = edge_first.x + position->x;
                    sum.y = edge_first.y + position->y;
                    sum.z = edge_first.z + position->z;
                    tangent->x = edge_second.x;
                    tangent->y = edge_second.y;
                    tangent->z = edge_second.z;
                }
                func_800154D0((f32 *)tangent);
                func_800155EC(position, position,
                              ((D_800AE8B8.x * normal->x +
                                D_800AE8B8.y * normal->y) +
                               D_800AE8B8.z * normal->z) -
                                  (normal->z * sum.z +
                                   (sum.x * normal->x + sum.y * normal->y)),
                              normal);
            }
        }
        contact->x = D_800AE8B8.x;
        contact->y = D_800AE8B8.y;
        contact->z = D_800AE8B8.z;
        if (D_800AE8D8 != 0) {
            D_8009A280 = D_800AE8D8;
        }
        return 1;
    }
    return 0;
}
