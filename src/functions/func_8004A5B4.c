/* Independently written from scratchpad spec specs/func_8004A5B4.md. */

#include "podcruise/types.h"

extern f32 D_800AB0D4;
extern f32 D_8011A240;
extern f32 D_80118E50[3];
extern void **D_8011A520;

extern void func_80015288(void *destination, void *source);
extern void func_8001745C(f32 matrix[4][4], f32 x, f32 y, f32 z);
extern void func_80017918(f32 destination[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, void *source);
extern void func_800181BC(void *object, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80028D60(void);

void func_8004A5B4(s32 arg0) {
    f32 scale;
    void *object;
    f32 matrix[4][4];
    f32 position[3];

    (void)arg0;

    object = D_8011A520[0];
    if (object == 0) {
        return;
    }
    if (object != 0) {
        func_800181BC(object, 2, -4, 0x10, 3);
    }
    func_80028D60();
    func_8001745C(matrix, 10.080002f, 0.0f, 180.0f);
    func_80015288(position, D_80118E50);
    func_80015288(matrix[3], position);
    scale = D_800AB0D4 * D_8011A240;
    func_80017918(matrix, scale, scale, scale, matrix);
    func_80017BA8(object, matrix);
    if (object != 0) {
        func_800181BC(object, 2, 3, 0x10, 2);
    }
}
