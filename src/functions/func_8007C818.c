/* Implements the specification in specs/func_8007C818.md (impact effect setup). */
#include "podcruise/types.h"

typedef struct Holder {
    u8 pad00[0x8];
    s32 kind;
    s32 flags;
    f32 unk10;
    u8 pad14[0x4];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x3C - 0x30];
    void *unk3C;
    u8 pad40[0x4C - 0x40];
    f32 *unk4C;
    void *unk50;
    void *unk54;
} Holder;

typedef struct Actor {
    u8 pad00[0x20];
    u8 unk20;
    u8 pad21[0x50 - 0x21];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[0x4];
    s32 unk60;
    u8 pad64[0x16C - 0x64];
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0x1A4 - 0x178];
    f32 unk1A4;
} Actor;

typedef struct Notice {
    u32 tag0;
    u32 tag1;
    f32 value;
} Notice;

/* Stand-in for the eight bytes of neighbouring constant pool that precede
   this function's own two double literals in the original translation unit. */
static const f64 padPool[1] = {1.0};

extern void *D_8011C910[];
extern f64 D_80120BF0;

extern void func_80008BC4(s32, s32, f32, f32, void *, s32, s32, f32, f32);
extern void func_80017520(f32 (*)[4], f32, f32, f32);
extern void func_80017B7C(void *, f32, f32, f32);
extern void func_80017BA8(void *, f32 (*)[4]);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_8003F99C(Actor *, Notice *);
extern void *func_8007B430(void *);
extern void func_8007B6CC(s32);
extern f32 func_80081700(f32, f32);
extern s32 func_80082BE0(void);

void func_8007C818(Holder *holder, Actor *actor) {
    f32 delta[3];
    s32 spare0[1];
    Notice notice;
    s32 spare1[1];
    s32 index;
    f32 spare2[1];
    s32 spare3;
    f32 scale;
    f32 matrix[4][4];

#if defined(__GNUC__)
    (void)padPool;
#endif
    (void)spare0;
    (void)spare1;
    (void)spare2;
    (void)spare3;
    notice.tag0 = 0x48697474;
    notice.tag1 = 0x54323031;

    if (holder->kind == 0xC9) {
        scale = func_80081700(25.0f, (f32)D_80120BF0);
        actor->unk1A4 = actor->unk1A4 * scale;
        notice.value = 100.0f;
        func_8003F99C(actor, &notice);
        index = 0;
    }
    if (holder->kind == 0xCA) {
        scale = func_80081700(2.5f, (f32)D_80120BF0);
        actor->unk1A4 = actor->unk1A4 * scale;
        notice.value = 600.0f;
        func_8003F99C(actor, &notice);
        index = 1;
    }
    if (holder->kind == 0x64) {
        index = 0;
    }
    if (holder->kind == 0x66) {
        index = 0;
        scale = func_80081700(2.5f, (f32)D_80120BF0);
        actor->unk1A4 = actor->unk1A4 * scale;
        notice.value = 300.0f;
        func_8003F99C(actor, &notice);
    }
    if (holder->kind == 0xD4) {
        index = 0;
    }
    if (holder->unk3C != 0) {
        func_800181BC(holder->unk3C, 2, -4, 0x10, 3);
    }
    holder->flags |= 2;
    holder->flags |= 1;
    func_800181BC(holder->unk3C, 0, -3, 0x10, 3);

    if (holder->kind == 0x66) {
        if (actor->unk60 & 0x80) {
            func_80017520(matrix, 8.0f, 8.0f, 8.0f);
            matrix[3][0] = holder->unk4C[0];
            matrix[3][1] = holder->unk4C[1];
            matrix[3][2] = holder->unk4C[2];
            func_80017BA8(D_8011C910[index], matrix);
        } else {
            func_80017B7C(D_8011C910[index], holder->unk4C[0], holder->unk4C[1], holder->unk4C[2]);
        }
    } else {
        func_80017B7C(D_8011C910[index], holder->unk4C[0], holder->unk4C[1], holder->unk4C[2]);
    }

    if (D_8011C910[index] != 0) {
        func_800181BC(D_8011C910[index], 2, 3, 0x10, 2);
    }
    func_8007B6CC(index);
    func_80008BC4(0x39, 6, (f32)((f32)func_80082BE0() / (f32)2147483648.0 * 0.15000000000000002 + 0.25), 1.0f,
                  &actor->unk50, 0, 0, 10.0f, 500.0f);

    delta[0] = actor->unk50 - actor->unk16C;
    delta[1] = actor->unk54 - actor->unk170;
    delta[2] = actor->unk58 - actor->unk174;

    holder->unk24 = holder->unk4C[0];
    holder->unk28 = holder->unk4C[1];
    holder->unk2C = holder->unk4C[2];
    holder->unk18 = (f32)(delta[0] * (0.800000011920929 / D_80120BF0));
    holder->unk1C = (f32)(delta[1] * (0.800000011920929 / D_80120BF0));
    holder->unk20 = (f32)(delta[2] * (0.800000011920929 / D_80120BF0));

    if (holder->kind != 0x66 || !(actor->unk60 & 0x80)) {
        holder->unk50 = &actor->unk20;
    } else {
        holder->unk50 = 0;
    }
    holder->unk54 = func_8007B430(D_8011C910[index]);
    holder->unk10 = 0.0f;
}
