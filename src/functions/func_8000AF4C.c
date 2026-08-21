/* Independently written from specs/func_8000AF4C.md. */

#include "podcruise/types.h"

struct Obj8009B790 {
    u8 unk00[0x54];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    u8 unk6C[0x10];
};

extern struct Obj8009B790 *D_8009B790;

void func_8000AF4C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                   f32 arg6) {
    D_8009B790[arg0].unk54 = arg1;
    D_8009B790[arg0].unk58 = arg2;
    D_8009B790[arg0].unk5C = arg3;
    D_8009B790[arg0].unk60 = arg4;
    D_8009B790[arg0].unk64 = arg5;
    D_8009B790[arg0].unk68 = arg6;
}
