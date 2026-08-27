/* Independently written from specs/func_80004160.md. */

#include "podcruise/vector_math.h"

extern f32 func_800154D0(f32 *vector);
extern void func_80015538(PcVec3f *output, const PcVec3f *left,
                          const PcVec3f *right);
extern f32 sqrtf(f32 value);
#ifdef __sgi
#pragma intrinsic (sqrtf)
#endif

extern f32 D_800A813C;
extern s32 D_8009A280;
extern f32 D_800AE8B0;
extern PcVec3f D_800AE8B8;
extern PcVec3f D_800AE8C8;
extern s32 D_800AE8D8;
extern f32 D_800AE8DC;

s32 func_80004160(PcVec3f *position, f32 bias, PcVec3f *axis, f32 first,
                  f32 second, PcVec3f *normal, PcVec3f *contact,
                  PcVec3f *centre) {
    PcVec3f delta;
    PcVec3f slid;
    PcVec3f spare;
    PcVec3f plane;
    PcVec3f firstOffset;
    PcVec3f secondOffset;
    PcVec3f edge;
    f32 dot;
    f32 length;
    PcVec3f firstPoint;
    PcVec3f secondPoint;
    PcVec3f firstCross;
    PcVec3f secondCross;

    (void)&spare;
    if (D_800AE8B0 < D_800AE8DC) {
        normal->x = D_800AE8C8.x;
        normal->y = D_800AE8C8.y;
        normal->z = D_800AE8C8.z;
        delta.x = position->x - D_800AE8B8.x;
        delta.y = position->y - D_800AE8B8.y;
        delta.z = position->z - D_800AE8B8.z;
        func_800154D0((f32 *)&delta);
        func_80015538(&edge, &delta, axis);
        func_80015538(&plane, &edge, axis);
        length = func_800153C0(&plane);
        if (length < D_800A813C) {
            dot = delta.x * axis->x + delta.y * axis->y + delta.z * axis->z;
            if (dot < 0.0f) {
                func_800155C0(&delta, -(first - sqrtf(D_800AE8B0)), normal);
            } else {
                func_800155C0(&delta, -second - sqrtf(D_800AE8B0), normal);
            }
            position->x = position->x + delta.x;
            position->y = position->y + delta.y;
            position->z = position->z + delta.z;
            contact->x = -normal->x;
            contact->y = -normal->y;
            contact->z = -normal->z;
        } else {
            func_800155C0(&plane, 1.0f / length, &plane);
            func_800155C0(&firstOffset, sqrtf(D_800AE8DC - first * first),
                          &plane);
            func_800155EC(&firstPoint, &firstOffset, first, axis);
            func_800155C0(&secondOffset, sqrtf(D_800AE8DC - second * second),
                          &plane);
            func_800155EC(&secondPoint, &secondOffset, second, axis);
            func_80015538(&firstCross, &firstPoint, &delta);
            func_80015538(&secondCross, &secondPoint, &delta);
            if (firstCross.x * secondCross.x + firstCross.y * secondCross.y +
                    secondCross.z * firstCross.z <
                0.0f) {
                func_800155C0(&delta, bias - sqrtf(D_800AE8B0), &delta);
                position->x = position->x + delta.x;
                position->y = position->y + delta.y;
                position->z = position->z + delta.z;
                contact->x = -normal->x;
                contact->y = -normal->y;
                contact->z = -normal->z;
            } else {
                if (0.0f < axis->x * normal->x + axis->y * normal->y +
                               axis->z * normal->z) {
                    slid.x = secondPoint.x + position->x;
                    slid.y = secondPoint.y + position->y;
                    slid.z = secondPoint.z + position->z;
                    contact->x = secondPoint.x;
                    contact->y = secondPoint.y;
                    contact->z = secondPoint.z;
                } else {
                    slid.x = firstPoint.x + position->x;
                    slid.y = firstPoint.y + position->y;
                    slid.z = firstPoint.z + position->z;
                    contact->x = secondPoint.x;
                    contact->y = secondPoint.y;
                    contact->z = secondPoint.z;
                }
                func_800154D0((f32 *)contact);
                func_800155EC(position, position,
                              (D_800AE8B8.x * normal->x +
                               D_800AE8B8.y * normal->y +
                               D_800AE8B8.z * normal->z) -
                                  (slid.x * normal->x + slid.y * normal->y +
                                   normal->z * slid.z),
                              normal);
            }
        }
        centre->x = D_800AE8B8.x;
        centre->y = D_800AE8B8.y;
        centre->z = D_800AE8B8.z;
        if (D_800AE8D8 != 0) {
            D_8009A280 = D_800AE8D8;
        }
        return 1;
    }
    return 0;
}
