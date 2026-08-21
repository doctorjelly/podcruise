/* Independently written from specs/func_8007B828.md (worker batch_03). */
#include "podcruise/types.h"

typedef struct {
    s32 unused0[2];
    s32 kind;
    s32 flags;
    s32 unused10[14];
    void *display;
    struct { s32 unused24[9]; s16 unused24b; s16 state; } *record;
} Object8007B828;

extern void *D_8011C910[];
extern void *D_8011C918;

extern void func_8007B744(s32 group);
extern void func_800181BC(void *object, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8003FD7C(void *object);

void func_8007B828(Object8007B828 *obj) {
    s32 group;

    group = -1;
    if (obj->kind == 0x64) {
        group = 0;
    } else if (obj->kind == 0x66) {
        group = 0;
    } else if (obj->kind == 0xC9) {
        group = 0;
    } else if (obj->kind == 0xCA) {
        group = 1;
    } else if (obj->kind == 0xD4) {
        group = 0;
    } else if (obj->kind == 0x13A) {
        group = 0;
    } else if (obj->kind == 0x1F5) {
        group = 5;
    }

    if (obj->kind == 0x13A || obj->kind == 0x1F5) {
        obj->record->state &= ~1;
    } else {
        obj->record->state |= 1;
    }

    if (group != -1) {
        func_8007B744(group);
        if (D_8011C910[group] != 0) {
            func_800181BC(D_8011C910[group], 2, -4, 0x10, 3);
        }
        obj->flags &= ~1;
        func_8003FD7C(obj);
    }

    if (obj->kind == 0x6C) {
        func_8007B744(2);
        if (D_8011C918 != 0) {
            func_800181BC(D_8011C918, 2, -4, 0x10, 3);
        }
        if (obj->display != 0) {
            func_800181BC(obj->display, 2, 3, 0x10, 2);
        }
        obj->flags &= ~1;
        func_8003FD7C(obj);
    }
}
