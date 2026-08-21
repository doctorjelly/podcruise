/* Independently written from scratchpad spec specs/func_80045144.md. */

#include "podcruise/types.h"

typedef struct Rig {
    char unk_000[0x50];
    s32 unk_050;
    char unk_054[0x30];
    f32 unk_084[4][4];
    char unk_0C4[4];
    void *unk_0C8;
    void *unk_0CC;
    void *unk_0D0;
    char unk_0D4[0xA50];
    void *unk_B24;
    f32 unk_B28[4][4];
} Rig;

extern void func_80017C18(void *source, f32 (*destination)[4]);
extern void func_80017BA8(void *destination, f32 (*source)[4]);
extern void func_80015724(f32 (*result)[4], f32 (*left)[4], f32 (*right)[4]);
extern void func_800156DC(f32 (*output)[4], f32 (*source)[4]);
extern f32 func_800153C0(f32 *vector);
extern void func_80017824(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4,
                          void *arg5);
extern void func_80044668(void *rig);
extern void func_80044A7C(void *rig);
extern void func_80044CD8(void *rig);
extern void func_80045004(void *rig);

void func_80045144(Rig *rig) {
    f32 pad[18];
    f32 world[4][4];
    f32 local[4][4];
    f32 extra[4][4];
    f32 scale;

    (void)pad;

    if (rig->unk_B24 != 0) {
        func_80017C18(rig->unk_B24, world);
    } else {
        world[0][0] = 0.0;
        world[0][1] = 0.0;
        world[0][2] = 0.0;
        world[0][3] = 0.0;
        world[1][0] = 0.0;
        world[1][1] = 0.0;
        world[1][2] = 0.0;
        world[1][3] = 0.0;
        world[2][0] = 0.0;
        world[2][1] = 0.0;
        world[2][2] = 0.0;
        world[2][3] = 0.0;
        world[3][0] = 0.0;
        world[3][1] = 0.0;
        world[3][2] = 0.0;
        world[3][3] = 0.0;
        world[0][0] = 1.0;
        world[1][1] = 1.0;
        world[2][2] = 1.0;
        world[3][3] = 1.0;
    }

    if (rig->unk_0CC != 0) {
        func_80017C18(rig->unk_0CC, local);
    } else {
        local[0][0] = 1.0;
        local[0][1] = 0.0;
        local[0][2] = 0.0;
        local[0][3] = 0.0;
        local[1][0] = 0.0;
        local[1][1] = 1.0;
        local[1][2] = 0.0;
        local[1][3] = 0.0;
        local[2][0] = 0.0;
        local[2][1] = 0.0;
        local[2][2] = 1.0;
        local[2][3] = 0.0;
        local[3][0] = 0.0;
        local[3][1] = 0.0;
        local[3][2] = 0.0;
        local[3][3] = 1.0;
    }

    scale = func_800153C0(&local[0][0]);
    world[3][0] = world[3][0] * scale;
    world[3][1] = world[3][1] * scale;
    world[3][2] = world[3][2] * scale;
    func_80017824(world, -90.0f, 1.0f, 0.0f, 0.0f, world);

    if (rig->unk_050 != 0) {
        func_80015724(rig->unk_B28, world, rig->unk_084);
    } else if (rig->unk_0D0 != 0) {
        func_80017C18(rig->unk_0D0, extra);
        func_80015724(rig->unk_B28, world, extra);
    } else {
        func_800156DC(rig->unk_B28, world);
    }

    if (rig->unk_0C8 != 0) {
        func_80017BA8(rig->unk_0C8, rig->unk_084);
    }

    func_80044A7C(rig);
    func_80044CD8(rig);
    func_80044668(rig);
    func_80045004(rig);
}
