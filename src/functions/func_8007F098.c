/* Independently written from specs/functions/recovered/func_8007F098.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ f32 position;
} Track8007F098;

typedef struct {
    f32 m[4][4];
} Matrix8007F098;

typedef struct {
    /* 0x00 */ f32 origin[3];
    /* 0x0C */ f32 heading[3];
    /* 0x18 */ f32 reach;
} Probe8007F098;

typedef struct {
    /* 0x00 */ u8 unk00[0x3C];
    /* 0x3C */ s16 tableIndex;
} Object8007F098;

typedef struct {
    /* 0x00 */ s16 flags;
} Item8007F098;

typedef struct {
    u8 unused[8];
    Probe8007F098 probe;
    Matrix8007F098 matrix;
} Locals8007F098;

extern f32 D_800ADC50;
extern void *D_800A6708;
extern Object8007F098 *D_8011DCF8[];

extern void func_80000520(s32 enabled);
extern Object8007F098 *func_80005134(void *space, Probe8007F098 *probe);
extern Item8007F098 *func_800183A8(void *object);
extern void func_800183B0(void *object, void *item);
extern s32 func_8003A568(Track8007F098 *track, s32 index);
extern void func_8003B02C(Track8007F098 *track, Matrix8007F098 *matrix);

void func_8007F098(Track8007F098 *track, f32 scale, void *space, s16 *samples) {
    Locals8007F098 locals;
    Item8007F098 *item;
    s32 lane;
    s32 tableIndex;
    Object8007F098 *object;
    s16 previousIndex;
    s16 currentSample;
    s32 conflict;

    locals.probe.heading[0] = 0.0f;
    locals.probe.heading[1] = 0.0f;
    locals.probe.heading[2] = -1.0f;
    locals.probe.reach = D_800ADC50;
    func_8003B02C(track, &locals.matrix);
    locals.probe.origin[0] = locals.matrix.m[3][0];
    locals.probe.origin[1] = locals.matrix.m[3][1];
    locals.probe.origin[2] = locals.matrix.m[3][2];

    func_80000520(1);
    object = func_80005134(space, &locals.probe);
    if (object == 0) {
        locals.probe.heading[2] = 1.0f;
        object = func_80005134(space, &locals.probe);
    }
    func_80000520(0);

    lane = func_8003A568(track, 0);
    conflict = 0;
    tableIndex = (s32)(((f32)lane + track->position) * scale);
    currentSample = samples[lane];
    D_8011DCF8[tableIndex] = object;
    if (object != 0) {
        previousIndex = object->tableIndex;
        if (previousIndex == 0) {
            object->tableIndex = tableIndex;
        } else if (currentSample != samples[(s32)((f32)previousIndex / scale)]) {
            conflict = 1;
        }
    }

    if (conflict != 0) {
        item = func_800183A8(object);
        if (item == 0) {
            func_800183B0(object, &D_800A6708);
        } else {
            item->flags |= 8;
        }
    }
}
