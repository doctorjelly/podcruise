/* Specification: $S/specs/func_800410D4.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad[0x74];
    s32 unk74;
    u8 pad78[4];
    s32 unk7C;
} Obj800410D4;

extern void func_80040CE8(Obj800410D4 *);

void func_800410D4(Obj800410D4 *arg0) {
    if (arg0->unk7C != 0) {
        if (arg0->unk74 >= 0) {
            func_80040CE8(arg0);
        }
    }
}
