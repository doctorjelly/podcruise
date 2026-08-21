/* Independently written from the specification for the view transform refresh (specs/func_80086930.md). */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x70];
    /* 0x070 */ f32 unk070[4][4];
    /* 0x0B0 */ u8 pad0B0[0x40];
    /* 0x0F0 */ f32 unk0F0[4][4];
    /* 0x130 */ s16 unk130;
    /* 0x132 */ u8 pad132[0xA];
    /* 0x13C */ f32 unk13C;
    /* 0x140 */ u8 pad140[0x30];
} ViewParams;

extern ViewParams D_80120DF0[];
extern void func_80086178(ViewParams *);
extern void func_80085FB0(ViewParams *);
extern void func_800156DC(f32 [4][4], f32 [4][4]);
extern void func_8008681C(f32 [4][4], f32 [4][4]);
extern void func_80015724(f32 [4][4], f32 [4][4], f32 [4][4]);
extern void func_80033E40(f32 *, f32 *);

void func_80086930(s32 index) {
    f32 world[4][4];
    f32 rotation[4][4];
    f32 translation[3];
    f32 combined[4][4];
    ViewParams *view;

    view = &D_80120DF0[index];
    func_80086178(view);
    func_80085FB0(view);
    func_800156DC(world, view->unk070);
    translation[0] = world[3][0];
    translation[1] = world[3][1];
    translation[2] = world[3][2];
    world[3][2] = 0.0f;
    world[3][1] = 0.0f;
    world[3][0] = 0.0f;
    func_8008681C(rotation, world);
    func_80015724(combined, rotation, view->unk0F0);
    func_80033E40(&combined[0][0], translation);
    if (view->unk13C > 0.0) {
        view->unk130 = 65536.0 / view->unk13C;
    }
}
