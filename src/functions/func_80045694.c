/* Independently written from specs/functions/recovered/func_80045694.md. */

#include "podcruise/types.h"

typedef struct PcTriple {
    f32 x;
    f32 y;
    f32 z;
} PcTriple;

typedef struct PcQuad {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} PcQuad;

typedef struct PcFlagged {
    u8 unk00[0x10];
    u32 unk10;
} PcFlagged;

typedef struct PcModel {
    u8 unk00[0x4];
    PcFlagged *unk04;
    PcFlagged *unk08;
    u8 unk0C[0x8];
    PcFlagged *unk14;
    u8 unk18[0x10];
    void *unk28;
    void *unk2C;
    u8 unk30[0xBC];
    void *unkEC;
    u8 unkF0[0x8];
    PcFlagged *unkF8;
    void *unkFC;
    void *unk100;
} PcModel;

typedef struct PcSlot {
    void *unk00;
    void *unk04;
    u8 unk08[0x8];
    void *unk10;
    void *unk14;
    u8 unk18[0x8];
    void *unk20;
    void *unk24;
    u8 unk28[0x8];
    s32 unk30;
} PcSlot;

typedef struct PcNode {
    u8 unk00[0x14];
    s32 unk14;
    void *unk18;
    u8 unk1C[0x3C];
} PcNode;

typedef struct PcStage {
    u8 unk0000[0xD4];
    s32 unkD4[6];
    PcSlot *unkEC[6];
    u8 unk0104[0xF90];
    PcNode unk1094[6][3];
    u8 unk16C4[0x4C];
    PcNode unk1710[6][2];
} PcStage;

extern PcTriple D_800A4B14;
extern PcQuad D_800A4B20;
extern f32 D_800AAD14;
extern f32 D_800AAD18;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80017520(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void *func_800305E8(s32 index);
extern void func_80030A7C(u32 *displayList, u32 *patchList);
extern void func_80045634(void *table, void *previous, void *replacement);
extern void func_800833B4(void *arg0, f32 *arg1);
extern void func_800834F0(void *, f32 *, f32 *, f32, f32, f32, f32, s32);

void func_80045694(PcStage *stage) {
    PcModel *model;
    PcModel *helper;
    f32 unit;
    f32 matrix[16];
    PcTriple triple;
    PcQuad quad;
    f32 vecA[3];
    f32 vecB[3];
    s32 kind;
    s32 i;
    f32 level;

    triple = D_800A4B14;
    quad = D_800A4B20;
    unit = D_800AAD14;

    for (i = 0; i < 6; i++) {
        kind = stage->unkD4[i];
        if (-1 == kind) {
            stage->unkEC[i] = 0;
        } else {
            kind &= 0x0FFFFFFF;
            stage->unkD4[i] = kind;
            if (kind == 2) {
                model = func_800305E8(6);
                helper = func_800305E8(5);
            } else if (kind == 3) {
                model = func_800305E8(8);
                helper = func_800305E8(7);
            } else if (kind == 11) {
                model = func_800305E8(0x18);
                helper = func_800305E8(0x17);
            } else if (kind == 5) {
                model = func_800305E8(0xC);
                helper = func_800305E8(0xB);
            } else if (kind == 0) {
                model = func_800305E8(2);
                helper = func_800305E8(0);
            } else if (1 == kind) {
                model = func_800305E8(4);
                helper = func_800305E8(3);
            } else if (kind == 10) {
                model = func_800305E8(0x16);
                helper = func_800305E8(0x15);
            } else if (kind == 4) {
                model = func_800305E8(9);
                helper = func_800305E8(0xA);
            } else if (kind > 100) {
                stage->unkD4[i] = -1;
            } else {
                stage->unkD4[i] = -1;
            }
        }

        if (stage->unkD4[i] != -1) {
            func_80030A7C((u32 *)model, (u32 *)helper);
            if (model->unk08 != 0) {
                model->unk08->unk10 |= 1;
            }
            func_80045634(stage->unkEC[i]->unk00, stage->unkEC[i]->unk04, model->unk08);
            func_800833B4(model->unk08, &triple.x);
            func_80045634(stage->unkEC[i]->unk10, stage->unkEC[i]->unk14, model->unk04);
            func_800833B4(model->unk04, &triple.x);
            func_80045634(stage->unkEC[i]->unk20, stage->unkEC[i]->unk24, model->unk14);
            func_800833B4(model->unk14, &quad.x);
            func_80017520(matrix, 250.0f, -250.0f, -250.0f);
            func_80017BA8(model->unk04, matrix);
            func_80017520(matrix, 250.0f, 250.0f, 250.0f);
            func_80017BA8(model->unk08, matrix);
            func_80017520(matrix, 250.0f, 250.0f, 250.0f);
            func_80017BA8(model->unk14, matrix);
            if (model->unkEC != 0) {
                func_800181BC(model->unkEC, 2, 0xFFFFFFFC, 0x10, 3);
            }
            level = D_800AAD18;
            model->unkF8->unk10 |= 1;
            func_80017520(matrix, level, level, unit);
            func_80017BA8(model->unkF8, matrix);
            if (model->unkF8 != 0) {
                func_800181BC(model->unkF8, 2, 3, 0x10, 2);
            }
            func_80017520(matrix, unit, unit, unit);
            func_80017BA8(model->unkFC, matrix);
            if (model->unkFC != 0) {
                func_800181BC(model->unkFC, 2, 3, 0x10, 2);
            }
            func_80017520(matrix, unit, unit, unit);
            func_80017BA8(model->unk100, matrix);
            if (model->unk100 != 0) {
                func_800181BC(model->unk100, 2, 3, 0x10, 2);
            }
            stage->unk1094[i][0].unk14 = 1;
            stage->unk1094[i][0].unk18 = &model->unkFC;
            stage->unk1094[i][1].unk14 = 1;
            stage->unk1094[i][1].unk18 = &model->unkF8;
            stage->unk1094[i][2].unk14 = 1;
            stage->unk1094[i][2].unk18 = &model->unk100;
            func_80015268(vecA, 0.0f, 0.0f, 0.0f);
            func_80015268(vecB, 0.0f, 0.0f, 0.0f);
            stage->unk1710[i][0].unk14 = 1;
            stage->unk1710[i][0].unk18 = &model->unk28;
            func_800834F0(model->unk28, vecA, vecB, 0.3f, 1.0f, 0.0, 50.0f, 0);
            stage->unk1710[i][1].unk14 = 1;
            stage->unk1710[i][1].unk18 = &model->unk2C;
            func_800834F0(model->unk2C, vecA, vecB, 0.3f, 1.0f, 0.0, 50.0f, 0);
            if (stage->unkEC[i]->unk30 != 0) {
                if (model->unkEC != 0) {
                    func_800181BC(model->unkEC, 2, 3, 0x10, 2);
                }
            }
        }
    }
}
