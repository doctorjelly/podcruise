/* Recovered from specs/func_8000C77C.md (telemetry query dispatcher). */
#include "podcruise/types.h"

typedef struct Unk8000C77C_Inner2 {
    u8 unk00[0x14];
    s32 unk14;
    s32 unk18;
} Unk8000C77C_Inner2;

typedef struct Unk8000C77C_Inner1 {
    u8 unk00[0x18];
    Unk8000C77C_Inner2 *unk18;
} Unk8000C77C_Inner1;

typedef struct Unk8000C77C_Object {
    u8 unk000[0x6C];
    f32 unk06C;
    f32 unk070;
    f32 unk074;
    f32 unk078;
    f32 unk07C;
    f32 unk080;
    f32 unk084;
    f32 unk088;
    f32 unk08C;
    f32 unk090;
    f32 unk094;
    f32 unk098;
    f32 unk09C;
    f32 unk0A0;
    u8 unk0A4[0x4];
    f32 unk0A8;
    u8 unk0AC[0x108 - 0xAC];
    f32 unk108;
    u8 unk10C[0x1E70 - 0x10C];
    Unk8000C77C_Inner1 *unk1E70;
} Unk8000C77C_Object;

static const u32 D_800A8560[1] = { 0x0A000000 };

extern s32 D_8009B7E0;
extern u8 D_800A82B0[];
extern u8 D_800A82BC[];
extern u8 D_800A82C8[];
extern u8 D_800A82D8[];
extern u8 D_800A82E8[];
extern u8 D_800A82F8[];
extern u8 D_800A8304[];
extern u8 D_800A8314[];
extern u8 D_800A8320[];
extern u8 D_800A8330[];
extern u8 D_800A833C[];
extern u8 D_800A8348[];
extern u8 D_800A8358[];
extern u8 D_800A8364[];
extern u8 D_800A8370[];
extern u8 D_800A8380[];
extern u8 D_800A8390[];
extern u8 D_800A83A0[];

extern Unk8000C77C_Object *func_8003F714();
extern void func_8008A6B4();
extern f32 sqrtf(f32 value);
#ifdef __sgi
#pragma intrinsic (sqrtf)
#endif

s32 func_8000C77C(s32 arg0, void *arg1, u8 *arg2, s32 *arg3, f32 *arg4) {
    Unk8000C77C_Object *object;
    Unk8000C77C_Inner2 *inner;

    *arg2 = 0;
    object = func_8003F714(0x54657374, D_8009B7E0);
    if (object == 0) {
        return 0;
    }
    *arg3 = -10000;
    switch (arg0) {
    case 0:
        inner = object->unk1E70->unk18;
        func_8008A6B4(arg1, D_800A82B0, inner->unk14, inner->unk18);
        *arg4 = -99999.0f;
        break;
    case 1:
        func_8008A6B4(arg1, D_800A82BC);
        *arg4 = (object != 0) ? object->unk06C : -1.0f;
        break;
    case 2:
        func_8008A6B4(arg1, D_800A82C8);
        *arg4 = (object != 0) ? object->unk070 : -1.0f;
        break;
    case 3:
        func_8008A6B4(arg1, D_800A82D8);
        *arg4 = (object != 0) ? object->unk074 : -1.0f;
        break;
    case 4:
        func_8008A6B4(arg1, D_800A82E8);
        *arg4 = (object != 0) ? object->unk078 : -1.0f;
        break;
    case 5:
        func_8008A6B4(arg1, D_800A82F8);
        *arg4 = (object != 0) ? object->unk07C : -1.0f;
        break;
    case 6:
        func_8008A6B4(arg1, D_800A8304);
        *arg4 = (object != 0) ? object->unk080 : -1.0f;
        break;
    case 7:
        func_8008A6B4(arg1, D_800A8314);
        *arg4 = (object != 0) ? object->unk084 : -1.0f;
        break;
    case 8:
        func_8008A6B4(arg1, D_800A8320);
        *arg4 = (object != 0) ? object->unk088 : -1.0f;
        break;
    case 9:
        func_8008A6B4(arg1, D_800A8330);
        *arg4 = (object != 0) ? object->unk08C : -1.0f;
        break;
    case 10:
        func_8008A6B4(arg1, D_800A833C);
        *arg4 = (object != 0) ? object->unk090 : -1.0f;
        break;
    case 11:
        func_8008A6B4(arg1, D_800A8348);
        *arg4 = (object != 0) ? object->unk094 : -1.0f;
        break;
    case 12:
        func_8008A6B4(arg1, D_800A8358);
        *arg4 = (object != 0) ? object->unk098 : -1.0f;
        break;
    case 13:
        func_8008A6B4(arg1, D_800A8364);
        *arg4 = (object != 0) ? object->unk09C : -1.0f;
        break;
    case 14:
        func_8008A6B4(arg1, D_800A8370);
        *arg4 = (object != 0) ? object->unk0A0 : -1.0f;
        break;
    case 15:
        func_8008A6B4(arg1, D_800A8380);
        *arg4 = (object != 0) ? object->unk0A8 : -1.0f;
        break;
    case 16:
        func_8008A6B4(arg1, D_800A8390);
        *arg4 = (object != 0) ? sqrtf(object->unk108) : -1.0f;
        break;
    default:
        func_8008A6B4(arg1, D_800A83A0);
        *arg4 = -0.0f;
        return 0;
    }
    return 1;
}
