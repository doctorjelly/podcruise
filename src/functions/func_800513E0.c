/* Recovered from specification specs/func_800513E0.md (batch 10). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    PcVec3f unk_00;
    PcVec3f unk_0C;
    u8 unk_18[0x8];
} PcTrackNode;

typedef struct {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0C[0x28];
    s32 unk_34;
    s32 unk_38;
} PcRider;

extern PcVec3f D_800A5298;
extern PcTrackNode D_800A4C00[];
extern PcVec3f D_800A5080;
extern PcVec3f D_800A4FCC;
extern PcVec3f D_801195F0;
extern f32 D_801195F8;
extern s16 D_800A4BC0;
extern s32 D_800A4BC4;
extern s32 D_800A4BE0;

extern void func_80015288(PcVec3f *destination, PcVec3f *source);
extern void func_80015328(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern void func_8001535C(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern f32 func_800154D0(PcVec3f *vector);
extern void func_80015538(PcVec3f *output, PcVec3f *left, PcVec3f *right);
extern void func_800155C0(PcVec3f *output, f32 scale, PcVec3f *source);

void func_800513E0(PcRider *rider, s32 mirrored) {
    PcVec3f origin;
    PcVec3f heading;
    PcVec3f side;
    PcVec3f up;
    PcVec3f reference;
    PcVec3f offset;
    s32 pad[2];

    (void)pad;
    reference = D_800A5298;
    func_80015288(&origin, &D_800A4C00[rider->unk_34].unk_00);
    func_80015288(&heading, &D_800A4C00[rider->unk_34].unk_0C);

    if (rider->unk_34 == 0x24) {
        func_80015288(&D_801195F0, &D_800A5080);
        if (D_800A4BE0 != 0) {
        }
    } else if (rider->unk_08 == 8) {
        func_80015288(&D_801195F0, &D_800A4FCC);
        if (D_800A4BE0 != 0) {
        }
    } else if ((D_800A4BC4 != 0) && (mirrored == 0) && (rider->unk_08 == 7) &&
               ((D_800A4BC0 == 0) || (D_800A4BC0 == 5))) {
        func_80015288(&D_801195F0, &heading);
    } else {
        func_8001535C(&side, &heading, &origin);
        if (mirrored == 0) {
            func_80015538(&up, &reference, &side);
        } else {
            func_80015538(&up, &side, &reference);
        }
        func_800154D0(&up);
        func_800154D0(&side);
        func_800155C0(&side, 3.0f, &side);
        func_80015328(&offset, &side, &up);
        func_800155C0(&offset, 60.0f, &offset);
        func_80015328(&offset, &origin, &offset);
        func_80015288(&D_801195F0, &offset);
    }

    switch (rider->unk_38) {
    case 2:
        D_801195F8 = -157.0f;
        break;
    case 0:
    case 3:
        D_801195F8 = -60.0f;
        break;
    case 1:
        D_801195F8 = -145.0f;
        break;
    }
}
