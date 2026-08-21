/* Independently written from the specification for the view parameter setter (specs/func_80086730.md). */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x134];
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13C */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ u8 pad148[0x28];
} ViewParams;

extern ViewParams D_80120DF0[];
extern void func_80085F78(ViewParams *);

void func_80086730(s32 index, f32 fov, f32 aspect, f32 near, f32 far, f32 scale) {
    ViewParams *view;
    s32 i;

    i = index;

    if (fov > 0.0) {
        D_80120DF0[i].unk134 = fov;
    }
    view = &D_80120DF0[i];
    if (aspect > 0.0) {
        view->unk138 = aspect;
    }
    if (near > 0.0) {
        view->unk140 = near;
    }
    if (far > 0.0) {
        view->unk144 = far;
    }
    if (scale >= 0.0) {
        view->unk13C = scale;
    }
    func_80085F78(view);
}
