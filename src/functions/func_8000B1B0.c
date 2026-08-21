/* Independently written from specs/func_8000B1B0.md. */

#include "podcruise/types.h"

struct Obj8009B790 {
    s32 unk00;
    u8 unk04[0x78];
};

extern struct Obj8009B790 *D_8009B790;
extern struct Obj8009B790 *D_8009B794;
extern s32 D_8009B798;
extern s32 D_8009B79C;

void func_8000B1B0(s16 arg0) {
    if (D_8009B798 != -1) {
        D_8009B790[D_8009B798].unk00 &= ~1;
    }
    if (arg0 == -1) {
        D_8009B798 = arg0;
        return;
    }
    D_8009B798 = arg0;
    D_8009B794 = &D_8009B790[arg0];
    D_8009B790[D_8009B798].unk00 |= 1;
    D_8009B79C = 0;
}
