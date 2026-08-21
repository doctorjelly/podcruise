/* Implements the specification in specs/func_80031560.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[6];
    u16 unk06;
    u8 unk08[4];
    s32 unk0C;
    u8 unk10[12];
} Slot80031560;

extern Slot80031560 D_800DB8A0[];

void func_80031560(s32 index) {
    s32 i;

    if (index == -1) {
        for (i = 0; i < 4; i++) {
            func_80031560(i);
        }
        return;
    }
    D_800DB8A0[index].unk0C = 1;
    D_800DB8A0[index].unk06 = 0x8000;
}
