/* Recovered from specification $S/specs/func_8008C390.md */
#include "podcruise/types.h"

typedef struct Sub8008C390 {
    s32 unk00;
    s32 unk04;
} Sub8008C390;

typedef struct Obj8008C390 {
    u16 unk00;
    u16 unk02;
    s32 unk04;
    Sub8008C390 *unk08;
    s32 unk0C;
} Obj8008C390;

extern Obj8008C390 *D_800A7F54;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);

void func_8008C390(s32 arg0) {
    register s32 interruptState;

    interruptState = func_8008CA80();
    if (arg0 & 0x1) {
        D_800A7F54->unk0C |= 0x8;
    }
    if (arg0 & 0x2) {
        D_800A7F54->unk0C &= ~0x8;
    }
    if (arg0 & 0x4) {
        D_800A7F54->unk0C |= 0x4;
    }
    if (arg0 & 0x8) {
        D_800A7F54->unk0C &= ~0x4;
    }
    if (arg0 & 0x10) {
        D_800A7F54->unk0C |= 0x10;
    }
    if (arg0 & 0x20) {
        D_800A7F54->unk0C &= ~0x10;
    }
    if (arg0 & 0x40) {
        D_800A7F54->unk0C |= 0x10000;
        D_800A7F54->unk0C &= ~0x300;
    }
    if (arg0 & 0x80) {
        D_800A7F54->unk0C &= ~0x10000;
        D_800A7F54->unk0C |= D_800A7F54->unk08->unk04 & 0x300;
    }
    D_800A7F54->unk00 |= 0x8;
    func_8008CAA0(interruptState);
}
