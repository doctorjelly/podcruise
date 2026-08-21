/* Specification: specs/func_8001DD48.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x10];
    s32 unk10;
} Obj8001DD48;

extern s32 D_800A4BBC;
extern s32 D_800A2198;

extern void func_8001DDA8(Obj8001DD48 *arg0);
extern void func_8001E6C0(Obj8001DD48 *arg0);

void func_8001DD48(Obj8001DD48 *arg0) {
    if (D_800A4BBC != 0) {
        arg0->unk10 = 0;
    }
    if ((arg0->unk10 == 0) || (D_800A2198 != -1)) {
        func_8001DDA8(arg0);
    } else {
        func_8001E6C0(arg0);
    }
}
