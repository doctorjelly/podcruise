/* Implements the specification in specs/func_800387F8.md (frame counter reset and accumulation). */
#include "podcruise/types.h"

typedef struct Context {
    u8 pad0[0x168];
    s32 unk168;
} Context;

extern s32 D_800A3D28;
extern s32 D_800A3D2C;
extern s32 D_800A3D60;
extern s16 D_800A3FD8;
extern s32 D_800D697C;
extern s32 D_80112C50[16];
extern s32 D_80112C90;
extern Context *D_80112C94;

extern s32 func_8003483C(void);
extern s32 func_80038388(s32);

void func_800387F8(s32 *result, Context *context) {
    s32 index;

    D_80112C90 = *result;
    D_80112C94 = context;
    D_800A3FD8 = 0;
    func_8003483C();
    D_800A3D2C++;
    D_800A3D28 = 0;

    for (index = 0; index < 16; index++) {
        D_80112C50[index] = 0;
    }

    if (D_800D697C & 0x4000) {
        D_800A3D60 = 1;
    } else {
        D_800A3D60 = 0;
    }

    func_80038388(context->unk168);

    for (index = 1; index < 16; index++) {
        D_80112C50[0] = D_80112C50[index] + D_80112C50[0];
    }

    *result = D_80112C90;
}
