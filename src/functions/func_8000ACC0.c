/* Recovered per specs/func_8000ACC0.md (boundary corrected from 0x8000ACC4). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s16 unk04;
    s16 unk06;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    f32 unk14[4][4];
    s32 unk54[6];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    s32 unk78;
} Obj8000ACC0;

typedef struct {
    s32 unk00;
    s16 unk04;
    s16 unk06;
    s32 unk08[6];
    f32 unk20;
    f32 unk24;
    f32 unk28[4][4];
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    s32 unk74[3];
    s16 unk80;
    s16 unk82;
    s32 unk84;
} Obj800D4B20;

extern Obj8000ACC0 *D_8009B790;
extern Obj8000ACC0 *D_8009B794;
extern s32 D_8009B798;
extern Obj800D4B20 D_800D4B20;
extern void func_8000AED4(s32, s32);

void func_8000ACC0(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        D_8009B790[i].unk14[0][0] = 1.0f;
        D_8009B790[i].unk14[0][1] = 0.0f;
        D_8009B790[i].unk14[0][2] = 0.0f;
        D_8009B790[i].unk14[0][3] = 0.0f;
        D_8009B790[i].unk14[1][0] = 0.0f;
        D_8009B790[i].unk14[1][1] = 1.0f;
        D_8009B790[i].unk14[1][2] = 0.0f;
        D_8009B790[i].unk14[1][3] = 0.0f;
        D_8009B790[i].unk14[2][0] = 0.0f;
        D_8009B790[i].unk14[2][1] = 0.0f;
        D_8009B790[i].unk14[2][2] = 1.0f;
        D_8009B790[i].unk14[2][3] = 0.0f;
        D_8009B790[i].unk14[3][0] = 0.0f;
        D_8009B790[i].unk14[3][1] = 0.0f;
        D_8009B790[i].unk14[3][2] = 0.0f;
        D_8009B790[i].unk14[3][3] = 1.0f;
        D_8009B790[i].unk08 = 0;
        D_8009B790[i].unk04 = 0;
        D_8009B790[i].unk6C = 0.0;
        D_8009B790[i].unk70 = 0.0;
        D_8009B790[i].unk74 = 0.0;
    }

    D_8009B794 = D_8009B790;
    D_8009B798 = 0;

    D_800D4B20.unk00 &= ~1;
    D_800D4B20.unk04 = 0;
    D_800D4B20.unk06 = 0;
    D_800D4B20.unk20 = 0.0;
    D_800D4B20.unk80 = 0;
    D_800D4B20.unk84 = 0;
    D_800D4B20.unk28[0][0] = 1.0f;
    D_800D4B20.unk28[0][1] = 0.0f;
    D_800D4B20.unk28[0][2] = 0.0f;
    D_800D4B20.unk28[0][3] = 0.0f;
    D_800D4B20.unk28[1][0] = 0.0f;
    D_800D4B20.unk28[1][1] = 1.0f;
    D_800D4B20.unk28[1][2] = 0.0f;
    D_800D4B20.unk28[1][3] = 0.0f;
    D_800D4B20.unk28[2][0] = 0.0f;
    D_800D4B20.unk28[2][1] = 0.0f;
    D_800D4B20.unk28[2][2] = 1.0f;
    D_800D4B20.unk28[2][3] = 0.0f;
    D_800D4B20.unk28[3][0] = 0.0f;
    D_800D4B20.unk28[3][1] = 0.0f;
    D_800D4B20.unk28[3][2] = 0.0f;
    D_800D4B20.unk28[3][3] = 1.0f;
    D_800D4B20.unk68 = 0.0;
    D_800D4B20.unk6C = 0.0;
    D_800D4B20.unk70 = 0.0;
    D_800D4B20.unk24 = 10.0f;
    func_8000AED4(1, 4);
}
