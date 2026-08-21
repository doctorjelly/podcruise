/* Recovered from the specification in specs/func_8000B318.md (worker batch 08). */
#include "podcruise/types.h"

typedef struct Ent8009B790 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[0x10];
    /* 0x14 */ f32 unk14[19];
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ u8 pad6C[0xC];
    /* 0x78 */ void *unk78;
} Ent8009B790;

typedef struct Cam800D4B20 {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28[16];
    /* 0x68 */ u8 pad68[0x18];
    /* 0x80 */ s16 unk80;
    /* 0x82 */ u8 pad82[2];
    /* 0x84 */ f32 *unk84;
} Cam800D4B20;

extern void func_80016F0C(f32 *matrix, f32 *output);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *direction);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80017FD0(void *object, f32 *input);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern void func_80082624(f32 *from, f32 *to, f32 *matrix, f32 *out, f32 roll);
extern void func_8000B1B0(s16 arg0);
extern void func_8000B254(s32 arg0, f32 *arg1, f32 *arg2);

extern Ent8009B790 *D_8009B790;
extern Cam800D4B20 D_800D4B20;
extern f32 D_800D4B48[16];
extern f64 D_80120BF0;

void func_8000B318(void *arg0) {
    f32 anglesA[6];
    f32 anglesB[6];
    f32 blend[6];
    f32 posB[3];
    f32 posA[3];
    f32 delta[3];
    f32 matrixOut[16];
    f32 matrixTmp[16];
    f32 ratio;

    func_80016F0C(D_8009B790[D_800D4B20.unk04].unk14, anglesA);
    func_80016F0C(D_8009B790[D_800D4B20.unk06].unk14, anglesB);
    posB[0] = D_8009B790[D_800D4B20.unk04].unk60;
    posB[1] = D_8009B790[D_800D4B20.unk04].unk64;
    posB[2] = D_8009B790[D_800D4B20.unk04].unk68;
    posA[0] = D_8009B790[D_800D4B20.unk06].unk60;
    posA[1] = D_8009B790[D_800D4B20.unk06].unk64;
    posA[2] = D_8009B790[D_800D4B20.unk06].unk68;
    ratio = D_800D4B20.unk20 / D_800D4B20.unk24;
    func_80016F0C(D_800D4B48, blend);
    blend[0] = anglesB[0] - anglesA[0];
    blend[1] = anglesB[1] - anglesA[1];
    blend[2] = anglesB[2] - anglesA[2];
    func_800155EC(blend, anglesA, ratio, blend);
    if (D_800D4B20.unk84 == 0) {
        if (ratio > 0.0f) {
            delta[0] = anglesA[3] - D_800D4B20.unk08;
            delta[2] = anglesA[5] - D_800D4B20.unk10;
            if (delta[0] > 180.0f) {
                anglesA[3] = anglesA[3] - 360.0f;
            }
            if (delta[0] < -180.0f) {
                anglesA[3] = anglesA[3] + 360.0f;
            }
            if (delta[2] > 180.0f) {
                anglesA[5] = anglesA[5] - 360.0f;
            }
            if (delta[2] < -180.0f) {
                anglesA[5] = anglesA[5] + 360.0f;
            }
            delta[0] = anglesB[3] - D_800D4B20.unk14;
            delta[1] = anglesB[4] - D_800D4B20.unk18;
            delta[2] = anglesB[5] - D_800D4B20.unk1C;
            if (delta[0] > 180.0f) {
                anglesB[3] = anglesB[3] - 360.0f;
            }
            if (delta[0] < -180.0f) {
                anglesB[3] = anglesB[3] + 360.0f;
            }
            if (delta[2] > 180.0f) {
                anglesB[5] = anglesB[5] - 360.0f;
            }
            if (delta[2] < -180.0f) {
                anglesB[5] = anglesB[5] + 360.0f;
            }
        } else {
            delta[0] = anglesB[3] - anglesA[3];
            delta[1] = anglesB[4] - anglesA[4];
            delta[2] = anglesB[5] - anglesA[5];
            if (delta[0] > 180.0f) {
                anglesB[3] = anglesB[3] - 360.0f;
            }
            if (delta[0] < -180.0f) {
                anglesB[3] = anglesB[3] + 360.0f;
            }
            if (delta[2] > 180.0f) {
                anglesB[5] = anglesB[5] - 360.0f;
            }
            if (delta[2] < -180.0f) {
                anglesB[5] = anglesB[5] + 360.0f;
            }
        }
        D_800D4B20.unk08 = anglesA[3];
        D_800D4B20.unk0C = anglesA[4];
        D_800D4B20.unk10 = anglesA[5];
        D_800D4B20.unk14 = anglesB[3];
        D_800D4B20.unk18 = anglesB[4];
        D_800D4B20.unk1C = anglesB[5];
        blend[5] = anglesB[5] - anglesA[5];
        blend[3] = anglesB[3] - anglesA[3];
        blend[4] = anglesB[4] - anglesA[4];
        func_800155EC(&blend[3], &anglesA[3], ratio, &blend[3]);
        func_800174B8(D_800D4B48, blend);
    } else if (D_800D4B20.unk80 == 1) {
        func_80082624(blend, D_800D4B20.unk84, D_800D4B48, blend, blend[5]);
    } else if (D_800D4B20.unk80 == 0) {
            matrixTmp[0] = D_800D4B20.unk84[0];
            matrixTmp[1] = D_800D4B20.unk84[1];
            matrixTmp[2] = D_800D4B20.unk84[2];
            matrixTmp[3] = D_800D4B20.unk84[3];
            matrixTmp[4] = D_800D4B20.unk84[4];
            matrixTmp[5] = D_800D4B20.unk84[5];
            matrixTmp[6] = D_800D4B20.unk84[6];
            matrixTmp[7] = D_800D4B20.unk84[7];
            matrixTmp[8] = D_800D4B20.unk84[8];
            matrixTmp[9] = D_800D4B20.unk84[9];
            matrixTmp[10] = D_800D4B20.unk84[10];
            matrixTmp[11] = D_800D4B20.unk84[11];
            matrixTmp[12] = D_800D4B20.unk84[12];
            matrixTmp[13] = D_800D4B20.unk84[13];
            matrixTmp[14] = D_800D4B20.unk84[14];
            matrixTmp[15] = D_800D4B20.unk84[15];
        func_80082624(blend, &matrixTmp[12], D_800D4B48, blend, blend[5]);
    } else {
        func_8000B254(D_800D4B20.unk80, D_800D4B20.unk84, matrixTmp);
        func_80082624(blend, &matrixTmp[12], D_800D4B48, blend, blend[5]);
    }
    matrixOut[0] = D_800D4B20.unk28[0]; matrixOut[1] = D_800D4B20.unk28[1]; matrixOut[2] = D_800D4B20.unk28[2]; matrixOut[3] = D_800D4B20.unk28[3];
    matrixOut[4] = D_800D4B20.unk28[4]; matrixOut[5] = D_800D4B20.unk28[5]; matrixOut[6] = D_800D4B20.unk28[6]; matrixOut[7] = D_800D4B20.unk28[7];
    matrixOut[8] = D_800D4B20.unk28[8]; matrixOut[9] = D_800D4B20.unk28[9]; matrixOut[10] = D_800D4B20.unk28[10]; matrixOut[11] = D_800D4B20.unk28[11];
    matrixOut[12] = D_800D4B20.unk28[12]; matrixOut[13] = D_800D4B20.unk28[13]; matrixOut[14] = D_800D4B20.unk28[14]; matrixOut[15] = D_800D4B20.unk28[15];
    func_80017FD0(arg0, matrixOut);
    if (D_8009B790[D_800D4B20.unk04].unk78 != 0) {
        func_800181BC(D_8009B790[D_800D4B20.unk04].unk78, 2, 1, 0x10, 2);
    }
    if (D_8009B790[D_800D4B20.unk06].unk78 != 0) {
        func_800181BC(D_8009B790[D_800D4B20.unk06].unk78, 2, 1, 0x10, 2);
    }
    D_800D4B20.unk20 = D_800D4B20.unk20 + D_80120BF0;
    if (D_800D4B20.unk24 <= D_800D4B20.unk20) {
        if (D_8009B790[D_800D4B20.unk06].unk78 != 0) {
            func_800181BC(D_8009B790[D_800D4B20.unk06].unk78, 2, -2, 0x10, 3);
        }
        func_8000B1B0(D_800D4B20.unk06);
        D_8009B790[D_800D4B20.unk04].unk00 &= ~1;
    }
    (void)posA;
    (void)posB;
    (void)delta;
}
