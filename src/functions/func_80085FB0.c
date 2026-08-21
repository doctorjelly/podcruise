/* Recovered per specs/func_80085FB0.md (perspective frustum matrix build). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x20];
    /* 0x020 */ s32 left;
    /* 0x024 */ s32 top;
    /* 0x028 */ s32 right;
    /* 0x02C */ s32 bottom;
    /* 0x030 */ u8 pad030[0xC0];
    /* 0x0F0 */ f32 matrix[4][4];
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13C */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
} ViewParams;

extern f32 D_800ADD64;
extern f32 func_80014D20(f32);
extern f32 func_80014F54(f32, f32);
extern void func_80085F78(ViewParams *);

void func_80085FB0(ViewParams *view) {
    f32 aspect;
    f32 far;
    f32 right;
    f32 top;
    f32 left;
    f32 bottom;
    f32 horizontal;
    f32 vertical;
    register f32 near;
    f32 angle;

    aspect = view->unk138 * (f32)(view->right - view->left) /
             (f32)(view->bottom - view->top);
    if (aspect < D_800ADD64) {
        angle = 3.0f;
    } else {
        angle = func_80014F54(func_80014D20(view->unk134 * 0.5f), aspect) * (f32)2.0;
    }

    far = view->unk144;
    near = view->unk140;
    top = func_80014D20(angle * 0.5f) * near;
    right = top * aspect;
    bottom = -top;
    left = -right;
    horizontal = (right + left) / (right - left);
    vertical = (top + bottom) / (top - bottom);

    view->matrix[0][1] = 0.0f;
    view->matrix[0][2] = 0.0f;
    view->matrix[0][3] = 0.0f;
    view->matrix[1][0] = 0.0f;
    view->matrix[1][2] = 0.0f;
    view->matrix[1][3] = 0.0f;
    view->matrix[3][0] = 0.0f;
    view->matrix[3][1] = 0.0f;
    view->matrix[3][3] = 0.0f;
    view->matrix[0][0] = 2.0f * near / (right - left);
    view->matrix[1][1] = 2.0f * near / (top - bottom);
    view->matrix[2][0] = horizontal;
    view->matrix[2][1] = vertical;
    view->matrix[2][2] = -((far + near) / (far - near));
    view->matrix[2][3] = -1.0f;
    view->matrix[3][2] = -2.0f * far * near / (far - near);
    func_80085F78(view);
}
