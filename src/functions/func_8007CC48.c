/* Implements the specification in specs/func_8007CC48.md */
#include "podcruise/types.h"

typedef struct Anchor8007CC48 {
    /* 0x00 */ u8 pad00[0x20];
    /* 0x20 */ void *source;
    /* 0x24 */ u8 pad24[0x2];
    /* 0x26 */ s16 flags26;
} Anchor8007CC48;

typedef struct Owner8007CC48 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u32 flags0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ u8 pad14[0x38];
    /* 0x4C */ Anchor8007CC48 *anchor;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ void *unk54;
} Owner8007CC48;

extern void *D_8011C910[];

extern void func_80017BA8(void *target, f32 (*matrix)[4]);
extern void func_80017C18(void *source, f32 (*matrix)[4]);
extern s32 func_800181BC(void *target, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8003FD7C(Owner8007CC48 *owner);
extern void *func_8007B430(void *target);
extern void func_8007B6CC(s32 index);
extern s32 func_8007B7BC(s32 index);

void func_8007CC48(Owner8007CC48 *owner, s32 index) {
    f32 matrix[4][4];

    if (func_8007B7BC(index) == 0) {
        func_8003FD7C(owner);
        return;
    }

    owner->flags0C |= 1;
    owner->anchor->flags26 |= 1;
    func_80017C18(owner->anchor->source, matrix);

    func_80017BA8(D_8011C910[index], matrix);
    if (D_8011C910[index] != 0) {
        func_800181BC(D_8011C910[index], 2, 3, 0x10, 2);
    }
    func_8007B6CC(index);

    owner->unk50 = 0;
    if (D_8011C910 == &D_8011C910[index]) {
        owner->unk54 = func_8007B430(D_8011C910[index]);
    } else {
        owner->unk54 = 0;
    }
    owner->unk10 = 0.0f;
}
