/* Independently written from specs/functions/recovered/medium_leaf_tranche.md. */

#include "podcruise/types.h"

extern void func_80005F54(f32 *result, void *object, f32 position, s32 index);
extern void func_800175E0(f32 *matrix, f32 angle, f32 x, f32 y, f32 z);
extern void func_80017B34(void *node, f32 x, f32 y, s32 z);
extern void func_80017BA8(void *node, f32 *matrix);
extern void func_80017C18(void *node, f32 *matrix);
extern void func_80081814(f32 *matrix, f32 *translation, f32 *rotation, f32 *scale);
extern void func_80081948(f32 *matrix, f32 *translation, f32 *rotation, f32 *scale);
extern void func_800827E0(f32 *from, f32 *to, f32 blend, f32 *result);
extern void func_800829F4(f32 *result, f32 *quaternion);
extern void func_80082B38(f32 *quaternion, f32 *rotation);

extern f64 D_800A8140;
extern f64 D_800A8148;

void func_8000630C(u8 *object) {
    f32 current[4];
    f32 other[4];
    f32 blended[4];
    f32 quaternionA[4];
    f32 quaternionB[4];
    f32 matrix[16];
    f32 rotation[16];
    f32 translation[3];
    f32 scale[3];


    func_80005F54(current, object, *(f32 *)(object + 0x114), *(s32 *)(object + 0x118));

    if ((*(s32 *)(object + 0x100) << 2) < 0) {
        func_80005F54(other, object, (f32)*(s32 *)(object + 0xEC), *(s32 *)(object + 0xE8));
        func_80082B38(quaternionA, other);
        func_80082B38(quaternionB, current);
        func_800827E0(quaternionA, quaternionB, *(f32 *)(object + 0xE4), blended);
        func_800829F4(current, blended);
    }

    if (*(void **)(object + 0x124) != 0) {
        if ((f64)current[3] < D_800A8140 && D_800A8148 < (f64)current[3]) {
            func_80017B34(*(void **)(object + 0x124), 0.0f, 0.0f, 0);
        } else {
            func_80017C18(*(void **)(object + 0x124), matrix);
            func_80081814(matrix, translation, rotation, scale);
            func_800175E0(rotation, current[3], current[0], current[1], current[2]);
            func_80081948(matrix, translation, rotation, scale);
            func_80017BA8(*(void **)(object + 0x124), matrix);
        }
    }
}
