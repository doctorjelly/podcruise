/* Recovered from specification specs/functions/func_800408D0.md (batch_04). */
#include "podcruise/types.h"

extern f32 func_800154D0(f32 *vector);
extern f64 D_80120BF0;

typedef struct {
    s32 flags;
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 d[3];
} Frame800408D0;

typedef struct {
    u8 unk0[0xA];
    s16 flags;
    u8 axis[6];
    u8 unk12[2];
    f32 b[3];
    f32 d[3];
} Source800408D0;

typedef struct {
    u8 unk0[0x2E4];
    s32 state;
    u8 unk2E8[0x48];
    Frame800408D0 current;
    Frame800408D0 target;
    f32 scale;
} Object800408D0;

void func_800408D0(Object800408D0 *object, s32 arg1, Source800408D0 *source) {
    (void)arg1;

    if ((source == 0) || (source->flags == 0)) {
        object->current = object->target;
    } else {
        if (source->flags & 0x10) {
            object->target.a[0] = (f32)(u32)source->axis[0];
            object->target.a[1] = (f32)(u32)source->axis[1];
            object->target.a[2] = (f32)(u32)source->axis[2];
            object->target.c[0] = (f32)(u32)source->axis[3];
            object->target.c[1] = (f32)(u32)source->axis[4];
            object->target.c[2] = (f32)(u32)source->axis[5];
            object->target.b[0] = source->b[0];
            object->target.b[1] = source->b[1];
            object->target.b[2] = source->b[2];
            object->target.d[0] = source->d[0];
            object->target.d[1] = source->d[1];
            object->target.d[2] = source->d[2];
            func_800154D0(object->target.d);
            if (source->flags & 4) {
                object->target.flags |= 8;
            } else {
                object->target.flags &= ~8;
                func_800154D0(object->target.b);
            }
            if (source->flags & 8) {
                object->target.flags |= 4;
            } else {
                object->target.flags &= ~4;
            }
            object->current = object->target;
        } else {
            object->current.a[0] = (f32)(u32)source->axis[0];
            object->current.a[1] = (f32)(u32)source->axis[1];
            object->current.a[2] = (f32)(u32)source->axis[2];
            object->current.c[0] = (f32)(u32)source->axis[3];
            object->current.c[1] = (f32)(u32)source->axis[4];
            object->current.c[2] = (f32)(u32)source->axis[5];
            object->current.b[0] = source->b[0];
            object->current.b[1] = source->b[1];
            object->current.b[2] = source->b[2];
            object->current.d[0] = source->d[0];
            object->current.d[1] = source->d[1];
            object->current.d[2] = source->d[2];
            func_800154D0(object->current.d);
            if (source->flags & 4) {
                object->current.flags |= 8;
            } else {
                object->current.flags &= ~8;
                func_800154D0(object->current.b);
            }
            if (source->flags & 8) {
                object->current.flags |= 4;
            } else {
                object->current.flags &= ~4;
            }
        }
    }

    object->state = object->state & ~0xC;
    object->state = object->state | object->current.flags;
    object->scale = (f32)(D_80120BF0 / 0.5 + 1.0);
    object->state = object->state | 3;
}
