/* Independently written from specs/func_8000B02C.md. */

#include "podcruise/types.h"

struct Obj8009B790 {
    u8 unk00[0xC];
    s16 unk0C;
    u8 unk0E[0x2];
    s32 unk10;
    u8 unk14[0x68];
};

extern struct Obj8009B790 *D_8009B790;

void func_8000B02C(s16 arg0, s32 arg1, s16 arg2) {
    D_8009B790[arg0].unk0C = arg2;
    D_8009B790[arg0].unk10 = arg1;
}
