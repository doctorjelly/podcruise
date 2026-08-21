/* Implements the specification in specs/func_8004AFD4.md (rebind three slot ranges per entry). */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x28];
    s32 unk28;
    u8 unk2C[0x8];
} Entry8004AFD4;

extern Entry8004AFD4 D_800A31E0[];

extern s32 func_80030154(s32);
extern void func_8000A44C(s16, s32);

void func_8004AFD4(void) {
    s16 i;
    s32 value;

    for (i = 0; i < 0x17; i++) {
        value = func_80030154(D_800A31E0[i].unk28);
        func_8000A44C(i, value);
        func_8000A44C(i + 0x17, value);
        func_8000A44C(i + 0x2E, value);
    }
}
