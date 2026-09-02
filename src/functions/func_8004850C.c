/* Independently written from the specification in scratchpad specs/func_8004850C.md. */
#include "podcruise/types.h"

typedef struct Vec3f8004850C {
    f32 x;
    f32 y;
    f32 z;
} Vec3f8004850C;

typedef struct Ent8004850C {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 pad01[3];
    /* 0x04 */ f32 unk04[3];
    /* 0x10 */ u8 pad10[0x28 - 0x10];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ u8 pad30[0x38 - 0x30];
} Ent8004850C;

extern s16 D_800A219C;
extern s32 D_800A21A4;
extern u8 D_800A2DE3[];
extern f32 D_800A4B50;
extern s32 D_800A4BC4;
extern s32 D_800A4BEC;
extern Vec3f8004850C D_800A51D0;
extern f32 D_800AAFA8;
extern f32 D_800AAFAC;
extern f32 D_800AAFB0;
extern f32 D_800AAFB4;
extern f32 D_80118D60[4][4];
extern f32 D_80118D70[3];
extern f32 D_80118D80[3];
extern f32 D_80118D90[3];
extern Ent8004850C D_801198A8[];
extern s32 D_8011A26C;
extern s32 D_8011A270;
extern void **D_8011A508[];
extern void **D_8011A740[];

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 [4][4], f32 [4][4]);
extern void func_8001745C(f32 *, f32, f32, f32);
extern void func_800174B8(f32 *, f32 *);
extern void func_800178C4(f32 *, f32 *, f32, f32, f32, f32);
extern void func_80017918(f32 *, f32, f32, f32, f32 *);
extern void func_80017BA8(void *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80028D60(void);

void func_8004850C(s32 argument) {
    f32 offset[3];
    f32 work[4][4];
    f32 basis[4][4];
    void *target;
    s32 index;
    f32 scale;
    f32 place[3];
    f32 anchor[3];
    Vec3f8004850C snapshot;
    f32 alpha;
    f32 origin[3];
    f32 pivot[3];

    (void)argument;
    snapshot = D_800A51D0;
    (void)snapshot;

    for (index = 0; index < D_8011A26C; index++) {
        target = *D_8011A508[index + 0x62];
        if (target == 0) {
            continue;
        }
        scale = D_800AAFA8; if (target != 0) { func_800181BC(target, 2, -4, 0x10, 3); }
        func_80015288(anchor, D_801198A8[index].unk04);
        func_80015268(place, D_801198A8[index].unk28, D_801198A8[index].unk2C, 0.0f);
        func_800174B8(work[0], anchor);
        if (index == D_8011A270 && (D_800A21A4 != 0 || D_800A4BEC != 0)) {
            alpha = D_800AAFAC * D_800AAFB0;
            func_800156DC(basis, D_80118D60);
            func_800156DC(work, D_80118D60);
            func_80015288(work[3], D_801198A8[index].unk04);
            if (D_800A21A4 != 0 && D_800A4BEC == 0) {
                func_800178C4(work[0], work[0], D_800A4B50 * 4.0f, basis[2][0], basis[2][1], basis[2][2]);
                func_800178C4(work[0], work[0], 45.0f, basis[1][0], basis[1][1], basis[1][2]);
                func_800178C4(work[0], work[0], D_800A4B50 * -1.0f, basis[2][0], basis[2][1], basis[2][2]);
            } else if (D_800A4BEC != 0) {
                func_8001745C(work[0], D_801198A8[index].unk28, 0, 0.0f);
            }
            scale = alpha;
            func_80015288(work[3], D_801198A8[index].unk04);
        }
        func_80017918(work[0], scale, scale, scale, work[0]);
        func_80017BA8(target, work[0]);
        if (target != 0) {
            func_800181BC(target, 2, 3, 0x10, 2);
        }
    }

    if (D_800A21A4 != 0 && D_800A4BC4 != 0 && D_800A219C == 0) {
        target = *D_8011A740[D_800A2DE3[D_801198A8[D_8011A270].unk00 * 16]];
        if (target != 0) {
            if (target != 0) {
                func_800181BC(target, 2, -4, 0x10, 3);
            }
            func_80028D60();
            func_800156DC(basis, D_80118D60);
            func_80015288(offset, D_80118D90);
            func_800155EC(offset, offset, 6.0f, D_80118D60[0]);
            func_800155EC(offset, offset, 30.0f, D_80118D70);
            func_800155EC(offset, offset, 3.5f, D_80118D80);
            func_80015288(pivot, offset);
            func_80015268(origin, 0, 0, 0);
            func_800174B8(work[0], pivot);
            func_800178C4(work[0], work[0], D_800A4B50 * 4.0f, basis[2][0], basis[2][1], basis[2][2]);
            func_800178C4(work[0], work[0], 45.0f, basis[1][0], basis[1][1], basis[1][2]);
            func_800178C4(work[0], work[0], D_800A4B50 * -1.0f, basis[2][0], basis[2][1], basis[2][2]);
            func_80017918(work[0], D_800AAFB4, D_800AAFB4, D_800AAFB4, work[0]);
            func_80015288(work[3], offset);
            func_80017BA8(target, work[0]);
            if (target != 0) {
                func_800181BC(target, 2, 3, 0x10, 2);
            }
        }
    }
}
