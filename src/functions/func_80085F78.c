/* Independently written from the specification for the field-of-view scale update. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x134];
    /* 0x134 */ f32 unk134;
    /* 0x138 */ u8 pad138[0x10];
    /* 0x148 */ f32 unk148;
    /* 0x14C */ u8 pad14C[0x4];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
} ViewParams;

void func_80085F78(ViewParams *view) {
    f32 ratio;

    ratio = 45.0f / view->unk134;
    view->unk154 = view->unk148 * (1.0f + view->unk150 * (ratio - 1.0f));
}
