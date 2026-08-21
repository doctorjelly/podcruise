/* Independently written from scratchpad spec specs/func_8004611C.md. */

#include "podcruise/types.h"

typedef struct Group8004611C {
    u8 unk00[0x14];
    s32 count;      /* 0x14 */
    void *children; /* 0x18 */
} Group8004611C;    /* 0x1C */

typedef struct Scene8004611C {
    u8 unk000[0xC8];
    s32 unk0C8;
    s32 unk0CC;
    s32 unk0D0;
    s32 unk0D4[6];                       /* 0xD4 */
    s32 *unk0EC[6];           /* 0xEC */
    u8 unk104[0xB24 - 0x104];
    s32 unkB24;
    u8 unkB28[0xB6C - 0xB28];
    s32 unkB6C;
    u8 unkB70[0xB94 - 0xB70];
    Group8004611C unkB94;                /* 0xB94 */
    s32 unkBB0[6];                       /* 0xBB0 */
} Scene8004611C;

extern s32 D_800A4B00;
extern s32 D_800A4B04;
extern s32 D_800A4B08;
extern s32 D_800A4B0C;

extern void func_80018324(void *object, u32 kind);
extern s32 *func_800305E8(s32 index);
extern void *func_80030964(s32 *data);
extern void func_800454A8(Scene8004611C *scene, void *entities);
extern void func_80045588(Scene8004611C *scene);
extern void func_80045694(Scene8004611C *scene);
extern void func_80045C88(Scene8004611C *scene);
extern void func_80045DA0(Scene8004611C *scene);
extern void func_80045E80(Scene8004611C *scene);
extern void func_80045F60(Scene8004611C *scene);
extern void func_80087754(void *object);

void func_8004611C(Scene8004611C *scene) {
    Group8004611C *group;
    s32 *data;
    s32 i;
    void *entities;

    group = &scene->unkB94;
    func_80018324(group, 0x5064);
    group->count = 6;
    group->children = scene->unkBB0;
    for (i = 0; i < 6; i++) { scene->unkBB0[i] = 0; }

    if (D_800A4B04 != -1) {
        data = func_800305E8(D_800A4B04);
        scene->unkBB0[1] = data[0];
        scene->unkBB0[0] = data[2];
    } else {
        scene->unkBB0[1] = 0;
        scene->unkBB0[0] = 0;
    }

    if (D_800A4B00 != 0) {
        func_80045C88(scene);
        func_80045DA0(scene);
        func_80045E80(scene);
    }

    data = func_800305E8(D_800A4B08);
    entities = func_80030964(data);
    scene->unkBB0[3] = data[0];
    scene->unk0C8 = data[0];
    scene->unk0CC = data[1];
    scene->unk0D0 = data[2];
    scene->unkB24 = data[3];
    scene->unkB6C = data[4];

    if (D_800A4B00 != 0) {
        for (i = 0; i < 6; i++) {
            scene->unk0D4[i] = data[i + 86];
            scene->unk0EC[i] = &data[(i * 13) + 5];
        }
    }

    if (D_800A4B0C != -1) {
        func_80045588(scene);
    }
    func_800454A8(scene, entities);
    if (D_800A4B00 != 0) {
        func_80045694(scene);
        func_80045F60(scene);
    }
    func_80087754(group);
}
