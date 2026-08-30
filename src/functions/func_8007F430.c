/* Independently written from specs/functions/recovered/func_8007F430.md. */

#include "podcruise/types.h"

typedef struct {
    void *source;
    s32 unk04;
    f32 position;
} Track8007F430;

typedef struct {
    s16 flags;
} Item8007F430;

typedef struct {
    u8 unk00[0x3C];
    s16 value;
} Object8007F430;

typedef struct {
    u8 bytes[0x30];
} Cursor8007F430;

extern void *D_8011DCF8[];

extern Cursor8007F430 *func_8007EE4C(Cursor8007F430 *, void *);
extern void func_8007EE98(Cursor8007F430 *, s32);
extern s32 func_8003A568(Track8007F430 *, s32);
extern void func_8003B02C(void *, f32 *);
extern Item8007F430 *func_800183A8(void *);
extern void func_8007F24C(Cursor8007F430 *, f32 *);
extern f32 func_800153EC(const f32 *, const f32 *);

void func_8007F430(void *arg0, f32 scale, s32 arg2, s32 arg3) {
    Track8007F430 *track;
    Cursor8007F430 cursor;
    Cursor8007F430 *active;
    Object8007F430 *object;
    Item8007F430 *item;
    f32 first[16];
    f32 second[16];
    f32 target[3];
    s32 index;

    track = arg0;
    (void)arg2;
    (void)arg3;
    active = func_8007EE4C(&cursor, track->source);
    index = (s32)(((f32)func_8003A568(track, 0) + track->position) * scale);
    object = D_8011DCF8[index];
    if (object == 0) {
        return;
    }
    item = func_800183A8(object);
    if ((item != 0) && (item->flags & 8)) {
        return;
    }
    if (object->value == 0) {
        return;
    }

    func_8007EE98(active, object->value);
    func_8003B02C(track, first);
    target[0] = first[4] * -0.5f + first[12];
    target[1] = first[5] * -0.5f + first[13];
    target[2] = first[6] * -0.5f + first[14];
    func_8007F24C(active, target);
    func_8003B02C(active, second);
    func_800153EC(&first[12], &second[12]);
}
