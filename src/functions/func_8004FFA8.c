/* Recovered per scratchpad spec specs/func_8004FFA8.md */
#include "podcruise/types.h"

typedef struct PcCamSetup {
    f32 unk[6];
} PcCamSetup;

typedef struct PcPlacement50 {
    /* 0x00 */ f32 first[3];
    /* 0x0C */ f32 second[3];
    /* 0x18 */ u8 pad18[0x8];
} PcPlacement50;

typedef struct PcScene {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 pad0C[0x8];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x8];
    /* 0x20 */ void *unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ void *unk28;
    /* 0x2C */ void *unk2C;
    /* 0x30 */ void *unk30;
} PcScene;

extern PcCamSetup D_800A5248;
extern PcPlacement50 D_800A4C00[];
extern f32 D_800A508C[];
extern void **D_8011A508[];

extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, const void *source);
extern void func_80015288(f32 *output, f32 *source);
extern f32 func_80014F54(f32 x, f32 y);
extern void func_80030298(s32 arg0, s32 arg1);
extern void func_8003FC94(s32 arg0);
extern void func_80046670(s32 arg0, s32 arg1, s32 slot, s32 arg3);
extern void func_800517D8(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
extern void func_80051898();
extern void func_80063084(s32, s32, f32 *, f32 *, f32, f32);
extern void func_8004B868(void);

void func_8004FFA8(PcScene *scene, f32 scale) {
    f32 matrix[4][4];
    PcCamSetup setup;
    f32 position[4];
    void *object;
    f32 heading;

    setup = D_800A5248;
    func_800174B8(matrix[0], setup.unk);
    func_80017918(matrix, scale, scale, scale, matrix);

    if (scene->unk8 != 0) {
        func_80051898(1);
    }
    scene->unk14 |= 2;
    func_80030298(0x456C6D6F, 0x3C);
    func_8003FC94(0x456C6D6F);

    func_80046670(0x53, -1, 2, 0);
    if (D_8011A508[2] != 0) {
        object = D_8011A508[2][0];
        scene->unk20 = object;
        if (object != 0) {
            func_80017BA8(object, matrix);
        }
    }

    func_80046670(0x54, -1, 0, 0);
    if (D_8011A508[0] != 0) {
        object = D_8011A508[0][0];
        scene->unk24 = object;
        if (object != 0) {
            func_80017BA8(object, matrix);
        }
    }

    func_80046670(0x55, -1, 1, 0);
    if (D_8011A508[1] != 0) {
        object = D_8011A508[1][0];
        scene->unk2C = object;
        if (object != 0) {
            func_80017BA8(object, matrix);
        }
    }

    func_80046670(0x96, -1, 3, 0);
    if (D_8011A508[3] != 0) {
        object = D_8011A508[3][0];
        scene->unk28 = object;
        if (object != 0) {
            func_80017BA8(object, matrix);
        }
    }

    func_800517D8(0xAA, 4, 6, -1.0f);
    if (D_8011A508[4] != 0) {
        scene->unk30 = D_8011A508[4][0];
        func_80015288(position, D_800A508C);
        position[2] = -60.0f;
        heading = func_80014F54(D_800A4C00[36].second[0] - D_800A4C00[36].first[0],
                                D_800A4C00[36].first[1] - D_800A4C00[36].second[1]) + 180.0f;
        func_80063084(4, 0x43, position, position, heading, heading);
    }

    func_8004B868();
    func_80051898(2);
}
